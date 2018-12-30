#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#define SNAKE_MAX_LENGTH 20
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define SNAKE_FOOD '$'
#define WALL_CELL '*'
//snake stepping: y = -1(up),1(down)，0（no move）; x = -1(left), 1(right), 0 (no move)
void snake_move();
//put a food randomized on a blank cell
void put_money(void);
// output the cells of the grid
void output(void);
// outs when gameoverr
int gameover(void);
char map[12][12]=
{ 	//画出贪吃蛇的游戏框大小
	"************",
	"*XXXXH     *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"*          *",
	"************",
};
int snake_location_x[SNAKE_MAX_LENGTH]={1,2,3,4,5}; //定义蛇的位置
int snake_location_y[SNAKE_MAX_LENGTH]={1,1,1,1,1};
int food_x;//定义食物的位置
int food_y;//
int snake_length=5;//定义蛇的初始长度
int a=0;//吃到食物判定数据

int main(){
	int i;
	char choice;
	put_money(); // DO 投放食物
	output();
	while(1){ //WHILE not Gameover Do
		scanf(" %c", &choice);// choice = 输入
		if(a){//如果吃到食物，身体变长
			for(i=snake_length;i>0;i--)
			{
				snake_location_x[i]=snake_location_x[i-1];
				snake_location_y[i]=snake_location_y[i-1];//相当于，蛇后退一步
			}
			snake_location_x[0]=food_x;
			snake_location_y[0]=food_y;//蛇尾补到食物的位置
			snake_length++;//蛇身体变长
			put_money();//重新投放食物
		}
		snake_move();//进行蛇的移动
		switch (choice) {// switch（输入）
		case'W':
		case'w': // ('w' || 'W'):上前进一步，break
			snake_location_y[snake_length-1]-=1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		case 'S':
		case 's':// ('S' || 's'):下前进一步，break
			snake_location_y[snake_length-1] += 1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		case 'A':
		case 'a': // ('A' || 'a'):左前进一步，break
			snake_location_x[snake_length-1]-=1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		case'D':
		case'd': // ('D' || 'd'):右前进一步，break
			snake_location_x[snake_length-1]+=1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		}
		a=0;//进食状态初始化
		if (snake_location_x[snake_length-1] == food_x && snake_location_y[snake_length-1] == food_y) { //WHILE 蛇头 与 食物 位置重合
			a=1;
		}
		if (!gameover()) { //if蛇撞墙/蛇撞上自己身体 ，printf游戏结束，END；
			printf("Game Over!!!\n");
			return 0;
		}
		else {
			output();// printf 贪吃蛇的字符矩阵
		}
	}
	return 0;
}

void snake_move() {//蛇移动
	int i;// int 计算字符
	map[snake_location_y[0]][snake_location_x[0]]=' ';
	for(i=0;i<snake_length-1;i++){
		snake_location_x[i]=snake_location_x[i + 1]; //WHILE not 游戏结束 DO 蛇在x轴移动
		snake_location_y[i]=snake_location_y[i + 1]; //WHILE not 游戏结束 DO 蛇在y轴移动
		map[snake_location_y[i]][snake_location_x[i]]='X';// WHILE not 游戏结束 DO 蛇的身体移动
	}
}

int gameover()
{
	if(snake_location_x[snake_length-1]==11||snake_location_x[snake_length-1]==0)
	{ //if 蛇撞墙 DO gameover
		return 0;
	}
	if(snake_location_y[snake_length-1]==11||snake_location_y[snake_length-1]==0)
	{	//if 蛇撞墙 DO gameover
		return 0;
	}
	int i;
	for (i = 0; i < snake_length-1; i++) {
		if (snake_location_x[snake_length-1] == snake_location_x[i] && snake_location_y[snake_length-1] == snake_location_y[i])
		{	//if 蛇头和自己身体的坐标重合 DO gameover
			return 0;
		}
	}
	return 1;
}

void output()
{ //WHILE not gameover DO print 字符矩阵
	system("cls");
	int i,j;
	for(i=0;i<=11;i++)
	{
		for(j=0;j<=11;j++)
		{
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}

void put_money(){ //投放食物 $
	srand((unsigned)(time(NULL))); //利用时间函数 随机找空白位置投放食物
	food_x=rand()%10+1; // WHILE not gameover 随机int 食物的x坐标
	food_y=rand()%10+1; // WHILE not gameover 随机int 食物的y坐标
	while(map[food_y][food_x]!=' ')
	{ //WHILE 食物坐标位置不空白 DO 刷新食物
		food_x = rand() % 10 + 1;
		food_y = rand() % 10+ 1;
	}
	map[food_y][food_x]='$'; // // WHILE not gameover DO 输出食物
}
