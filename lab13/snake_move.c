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
// output the cells of the grid
void output(void);
// outs when gameoverr
int gameover(void);
//判断游戏是否结束
char map[12][12] = { //画出贪吃蛇的游戏框大小及蛇的初始位置
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
int snake_location_x[5] = { 1, 2, 3, 4, 5 }; //定义蛇的位置
int snake_location_y[5] = { 1, 1, 1, 1, 1 };
int snake_length = 5;//定义蛇的长度

int main() {
	char choice;
	output();
	while (1) { //WHILE not Gameover Do
		scanf(" %c", &choice);// choice = 输入
		snake_move();//进行蛇的移动
		switch (choice) {// switch（输入）
		case'W':
		case'w': // ('w' || 'W'):上前进一步，break
			snake_location_y[4] -= 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
		case 'S':
		case 's':// ('S' || 's'):下前进一步，break
			snake_location_y[4] += 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
		case 'A':
		case 'a': // ('A' || 'a'):左前进一步，break
			snake_location_x[4] -= 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
		case'D':
		case'd': // ('D' || 'd'):右前进一步，break
			snake_location_x[4] += 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
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
	map[snake_location_y[0]][snake_location_x[0]] = ' ';
	for (i = 0; i < 4; i++) {
		snake_location_x[i] = snake_location_x[i + 1]; //WHILE not 游戏结束 DO 蛇在x轴移动
		snake_location_y[i] = snake_location_y[i + 1]; //WHILE not 游戏结束 DO 蛇在y轴移动
		map[snake_location_y[i]][snake_location_x[i]] = 'X'; // 在地图上蛇身体的位置放置‘X’
	}
}

int gameover() {//判断游戏是否结束
	int i=0;
	if (snake_location_x[4] == 11 || snake_location_x[4] == 0) { //if 蛇撞墙 DO gameover
		return 0;
	}
	if (snake_location_y[4] == 11 || snake_location_y[4] == 0) { //if 蛇撞墙 DO gameover
		return 0;
	}
	for (i=0; i < 4; i++) {
		if (snake_location_x[4] == snake_location_x[i] && snake_location_y[4] == snake_location_y[i]) {
			//if 蛇头和自己身体的坐标重合 DO gameover
			return 0;
		}
	}
	return 1;
}

void output() { //WHILE not gameover DO print 字符矩阵
	int i=0,j=0;
	system("cls");//将界面清零、刷新
	for (i=0; i <= 11; i++) {
		for (j = 0; j <= 11; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
