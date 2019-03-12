// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace std;

bool GameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup() {
	GameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;

}

void Draw() {
	system("cls");

	for (int i = 0; i < width+1; i++) cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++){
		
		for (int j = 0; j < width; j++) {
			
			if (j==0 || j == width - 1){
				cout << "#";
			}
			
			if (i == y && j == x)
				cout << "0";
			
			else if (i == fruitY && j == fruitX)
			{
				cout << "F";
			}
			
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width+1; i++) cout << "#";

	cout << endl;
	cout << "Score is " << score << endl;
}

void Input() {

	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case'x':
			GameOver = true;
			break;
		}
	}

}

void Logic() {

	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}

	if (x>width||x<0||y>height||y<0)
	{
		GameOver = true;
	}

	if (x==fruitX&&y==fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}

}

int main()
{
	Setup();

	while (!GameOver) {
		Draw();
		Input();
		Logic();
	}


    return 0; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
