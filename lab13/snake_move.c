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
// output the cells of the grid
void output(void);
// outs when gameoverr
int gameover(void);
//�ж���Ϸ�Ƿ����
char map[12][12] = { //����̰���ߵ���Ϸ���С���ߵĳ�ʼλ��
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
int snake_location_x[5] = { 1, 2, 3, 4, 5 }; //�����ߵ�λ��
int snake_location_y[5] = { 1, 1, 1, 1, 1 };
int snake_length = 5;//�����ߵĳ���

int main() {
	char choice;
	output();
	while (1) { //WHILE not Gameover Do
		scanf(" %c", &choice);// choice = ����
		snake_move();//�����ߵ��ƶ�
		switch (choice) {// switch�����룩
		case'W':
		case'w': // ('w' || 'W'):��ǰ��һ����break
			snake_location_y[4] -= 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
		case 'S':
		case 's':// ('S' || 's'):��ǰ��һ����break
			snake_location_y[4] += 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
		case 'A':
		case 'a': // ('A' || 'a'):��ǰ��һ����break
			snake_location_x[4] -= 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
		case'D':
		case'd': // ('D' || 'd'):��ǰ��һ����break
			snake_location_x[4] += 1;
			map[snake_location_y[4]][snake_location_x[4]] = 'H';
			break;
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
	map[snake_location_y[0]][snake_location_x[0]] = ' ';
	for (i = 0; i < 4; i++) {
		snake_location_x[i] = snake_location_x[i + 1]; //WHILE not ��Ϸ���� DO ����x���ƶ�
		snake_location_y[i] = snake_location_y[i + 1]; //WHILE not ��Ϸ���� DO ����y���ƶ�
		map[snake_location_y[i]][snake_location_x[i]] = 'X'; // �ڵ�ͼ���������λ�÷��á�X��
	}
}

int gameover() {//�ж���Ϸ�Ƿ����
	int i=0;
	if (snake_location_x[4] == 11 || snake_location_x[4] == 0) { //if ��ײǽ DO gameover
		return 0;
	}
	if (snake_location_y[4] == 11 || snake_location_y[4] == 0) { //if ��ײǽ DO gameover
		return 0;
	}
	for (i=0; i < 4; i++) {
		if (snake_location_x[4] == snake_location_x[i] && snake_location_y[4] == snake_location_y[i]) {
			//if ��ͷ���Լ�����������غ� DO gameover
			return 0;
		}
	}
	return 1;
}

void output() { //WHILE not gameover DO print �ַ�����
	int i=0,j=0;
	system("cls");//���������㡢ˢ��
	for (i=0; i <= 11; i++) {
		for (j = 0; j <= 11; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
