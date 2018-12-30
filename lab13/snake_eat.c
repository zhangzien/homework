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
//snake stepping: y = -1(up),1(down)��0��no move��; x = -1(left), 1(right), 0 (no move)
void snake_move();
//put a food randomized on a blank cell
void put_money(void);
// output the cells of the grid
void output(void);
// outs when gameoverr
int gameover(void);
char map[12][12]=
{ 	//����̰���ߵ���Ϸ���С
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
int snake_location_x[SNAKE_MAX_LENGTH]={1,2,3,4,5}; //�����ߵ�λ��
int snake_location_y[SNAKE_MAX_LENGTH]={1,1,1,1,1};
int food_x;//����ʳ���λ��
int food_y;//
int snake_length=5;//�����ߵĳ�ʼ����
int a=0;//�Ե�ʳ���ж�����

int main(){
	int i;
	char choice;
	put_money(); // DO Ͷ��ʳ��
	output();
	while(1){ //WHILE not Gameover Do
		scanf(" %c", &choice);// choice = ����
		if(a){//����Ե�ʳ�����䳤
			for(i=snake_length;i>0;i--)
			{
				snake_location_x[i]=snake_location_x[i-1];
				snake_location_y[i]=snake_location_y[i-1];//�൱�ڣ��ߺ���һ��
			}
			snake_location_x[0]=food_x;
			snake_location_y[0]=food_y;//��β����ʳ���λ��
			snake_length++;//������䳤
			put_money();//����Ͷ��ʳ��
		}
		snake_move();//�����ߵ��ƶ�
		switch (choice) {// switch�����룩
		case'W':
		case'w': // ('w' || 'W'):��ǰ��һ����break
			snake_location_y[snake_length-1]-=1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		case 'S':
		case 's':// ('S' || 's'):��ǰ��һ����break
			snake_location_y[snake_length-1] += 1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		case 'A':
		case 'a': // ('A' || 'a'):��ǰ��һ����break
			snake_location_x[snake_length-1]-=1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		case'D':
		case'd': // ('D' || 'd'):��ǰ��һ����break
			snake_location_x[snake_length-1]+=1;
			map[snake_location_y[snake_length-1]][snake_location_x[snake_length-1]]='H';
			break;
		}
		a=0;//��ʳ״̬��ʼ��
		if (snake_location_x[snake_length-1] == food_x && snake_location_y[snake_length-1] == food_y) { //WHILE ��ͷ �� ʳ�� λ���غ�
			a=1;
		}
		if (!gameover()) { //if��ײǽ/��ײ���Լ����� ��printf��Ϸ������END��
			printf("Game Over!!!\n");
			return 0;
		}
		else {
			output();// printf ̰���ߵ��ַ�����
		}
	}
	return 0;
}

void snake_move() {//���ƶ�
	int i;// int �����ַ�
	map[snake_location_y[0]][snake_location_x[0]]=' ';
	for(i=0;i<snake_length-1;i++){
		snake_location_x[i]=snake_location_x[i + 1]; //WHILE not ��Ϸ���� DO ����x���ƶ�
		snake_location_y[i]=snake_location_y[i + 1]; //WHILE not ��Ϸ���� DO ����y���ƶ�
		map[snake_location_y[i]][snake_location_x[i]]='X';// WHILE not ��Ϸ���� DO �ߵ������ƶ�
	}
}

int gameover()
{
	if(snake_location_x[snake_length-1]==11||snake_location_x[snake_length-1]==0)
	{ //if ��ײǽ DO gameover
		return 0;
	}
	if(snake_location_y[snake_length-1]==11||snake_location_y[snake_length-1]==0)
	{	//if ��ײǽ DO gameover
		return 0;
	}
	int i;
	for (i = 0; i < snake_length-1; i++) {
		if (snake_location_x[snake_length-1] == snake_location_x[i] && snake_location_y[snake_length-1] == snake_location_y[i])
		{	//if ��ͷ���Լ�����������غ� DO gameover
			return 0;
		}
	}
	return 1;
}

void output()
{ //WHILE not gameover DO print �ַ�����
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

void put_money(){ //Ͷ��ʳ�� $
	srand((unsigned)(time(NULL))); //����ʱ�亯�� ����ҿհ�λ��Ͷ��ʳ��
	food_x=rand()%10+1; // WHILE not gameover ���int ʳ���x����
	food_y=rand()%10+1; // WHILE not gameover ���int ʳ���y����
	while(map[food_y][food_x]!=' ')
	{ //WHILE ʳ������λ�ò��հ� DO ˢ��ʳ��
		food_x = rand() % 10 + 1;
		food_y = rand() % 10+ 1;
	}
	map[food_y][food_x]='$'; // // WHILE not gameover DO ���ʳ��
}
