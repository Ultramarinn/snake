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
int tailX[100], tailY[100]; //coordinates of a tail
int ntail; 

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
				bool print = false;
				for (int k = 0; k < ntail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "o";
					}
				}
				if (!print)
				{
					cout << " ";
				}
				
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

	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < ntail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}

	switch (dir)    //Controls
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

	//if (x>width||x<0||y>height||y<0) // Game field borders
	//{
	//	GameOver = true;
	//}

	for (int i = 0; i < ntail; i++)
	{
		if (tailX[i] == x && tailY[i] == y)
			GameOver = true;
	}

	if (x >= width-1) x = 0;			//Collision
	else if (x < 0) x = width - 2;

	if (y >= height-1) y = 0;			//Collosion
	else if (y < 0) y = height - 2;

	if (x==fruitX&&y==fruitY) //score 
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++;
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
