#include "main.h"

using namespace std;

/*
	(미로 생성) 가로20 세로20 크기의 2차원 배열 생성
	0 : 벽
	1 : 길
	2 : 시작점
	3 : 도착점
*/


void SetMaze(char Maze[HEIGHT][WIDTH], _PPOINT pPlayerPos, _PPOINT pStartPos
	, _PPOINT pEndPos) {

	pStartPos->x = 0;
	pStartPos->y = 0;
	
	pEndPos->x = 18;
	pEndPos->y = 19;
	
	*pPlayerPos = *pStartPos;
	*pPlayerPos = *pStartPos;


	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111111000000000");
	strcpy_s(Maze[2],  "00001000001000000000");
	strcpy_s(Maze[3],  "00001000001000000000");
	strcpy_s(Maze[4],  "00000011111111110000");
	strcpy_s(Maze[5],  "00000010001000010000");
	strcpy_s(Maze[6],  "00011110001000010000");
	strcpy_s(Maze[7],  "00000000001000000000");
	strcpy_s(Maze[8],  "00000011111111100000");
	strcpy_s(Maze[9],  "00000010001000000000");
	strcpy_s(Maze[10], "00011110001000000000");
	strcpy_s(Maze[11], "00000011111111111000");
	strcpy_s(Maze[12], "00000000001000000000");
	strcpy_s(Maze[13], "00000100001000001000");
	strcpy_s(Maze[14], "00000100001000001000");
	strcpy_s(Maze[15], "00000111111111111000");
	strcpy_s(Maze[16], "00000000001000000000");
	strcpy_s(Maze[17], "00001111111000000000");
	strcpy_s(Maze[18], "00001000001111111110");
	strcpy_s(Maze[19], "00000000000000000030");
}

/*
	미로를 출력한다
*/

void OutPut(char Maze[HEIGHT][WIDTH], _PPOINT pPlayerPos){
	for (int i = 0; i < HEIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {

			if (pPlayerPos->x == j && pPlayerPos->y == i) cout << "☆";

			else if (Maze[i][j] == '0') cout << "■";
			else if (Maze[i][j] == '1') cout << "  ";
			else if (Maze[i][j] == '2') cout << "★";
			else if (Maze[i][j] == '3') cout << "▣";
		}
		cout << endl;
	}
}

/*
	1. 전체 게임크기에서 밖으로 나가지 않게 조건 설정
	2. 이동할려는 좌표가 '0' 벽이 아닌경우에 이동
*/

void MoveUp(char Maze[HEIGHT][WIDTH], _PPOINT pPlayerPos){
	if (pPlayerPos->y - 1 >= 0){
		
		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0') {
			--pPlayerPos-> y;
		}
	}
}

void MoveDown(char Maze[HEIGHT][WIDTH], _PPOINT pPlayerPos){
	if (pPlayerPos->y + 1 < 20) {

		// 벽인지 체크한다.
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0') {
			++pPlayerPos->y;
		}
	}
}

void MoveRight(char Maze[HEIGHT][WIDTH], _PPOINT pPlayerPos) {
	if (pPlayerPos->x + 1 >= 0) {

		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0') {
			++pPlayerPos->x;
		}
	}
}
void MoveLeft(char Maze[HEIGHT][WIDTH], _PPOINT pPlayerPos) {
	if (pPlayerPos->x - 1 >= 0) {

		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0') {
			--pPlayerPos->x;
		}
	}
}



/*
	플레이어 움직임

*/

void MovePlayer(char Maze[HEIGHT][WIDTH], _PPOINT pPlayerPos, char cinput){
	switch (cinput) {
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

bool CheckEndPoint(_PPOINT pPlayerPos, _PPOINT pEndPos) {
	if (pPlayerPos->x == pEndPos->x && pPlayerPos->y == pEndPos->y) {
		return 1;
	}
	return 0;
}

void GameClearMessage() {
	system("cls");
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■□□□□□□□□□□■■■■■■■■■■■■□□□□□□■■■■■■■□□■■■■■■■■■" << endl;
	cout << "■■■■■■■■□□■■■■■■■■■■■■■■■■■□□□□□□□□□□□□■■■■□□■■■■■■■■■" << endl;
	cout << "■■■■■■■■□□■■■■■■■■■■■■■■■■■■■■■□□□■■■■■■■■■□□□□■■■■■■■" << endl;
	cout << "■■■■■■■■□□□□□□□□□□■■■■■■■■■■■■□□■□□■■■■■■■■□□□□■■■■■■■" << endl;
	cout << "■■■■■■■■■■■□□□■■■■■■■■■■■■■■■□□■■■□□■■■■■■■□□■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■□□□■■■■■■■■■■■■■■□□■■■■■□□■■■■■■□□■■■■■■■■■" << endl;
	cout << "■■■■■□□□□□□□□□□□□□□□■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□□□□□□□□□□□■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□□■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□□■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■□□■■■■■■■■■■■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	
}									 
