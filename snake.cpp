#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

bool gameover;
const int height = 15;
const int width = 15;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int ntail;
enum eDirection 
{
	STOP = 0, LEFT, RIGHT, UP, DOWN
};
eDirection dir;

void setup()
{
	gameover = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void draw()
{
    system("cls");

	for (int i = 0; i < width + 2; i++)
	{
		cout << ".";
	}
	cout << endl;

	for (int i = 0; i < height; i++)
	{	for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << ".";
			if (i == y && j == x)
			{
				cout << "0";
			}
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
						cout << "o";
						print = true;
					}
					
				}
				if (!print)
						cout << " ";
			}
			if (j == width - 1)
				cout << ".";
		}
		cout << endl;
	}

	for (int i = 0; i < width + 2; i++)
	{
		cout << ".";
	}
	cout << endl;

	cout << "SCORE: " << score << endl;

}

void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			dir = UP;
			break;
			
		case 's':
			dir = DOWN;
			break;
        case 'a':
		     dir = LEFT;
		     break;

		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameover = true;
			break;

		}
			

		
	}

}

void logic()
{

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


	switch (dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;

	}
	if (x > width || x < 0 || y > height || y < 0)
	{
		gameover = true;
		cout << endl;
		cout << " GAMEOVER " << endl;
		cout << endl;
	}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		ntail++;
	}

}

int main()
{
	
	setup();
	while (!gameover)
	{
		draw();
		input();
		logic();
		Sleep(40);
	} 
	
	system("pause");

}


