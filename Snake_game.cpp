#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int width = 20;
int height = 20;

int snakeX = 10;
int snakeY = 10;

int fruitX = 5;
int fruitY = 5;

int score = 0;

char direction = 'd';

bool gameOver = false;



// Draw the game
void draw()
{
    system("cls");

    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }

    cout << endl;
 
    for (int i = 0; i < height; i++)
    {

        cout << "#";

        for (int j = 0; j < width; j++)
        {

            // Snake
            if (i == snakeY && j == snakeX)
            {
                cout << "O";
            }

            // Fruit
            else if (i == fruitY && j == fruitX)
            {
                cout << "F";
            }

            // Empty space
            else
            {
                cout << " ";
            }
             
        }
        cout << "#";

        cout << endl;
    }
    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }


    cout << "Score: " << score << endl;
}

// Input
void input()
{
    if (_kbhit())
    {
        direction = _getch();
    }
}

// Game logic
void logic()
{
    // Movement
    if (direction == 'w')
        snakeY--;

    else if (direction == 's')
        snakeY++;

    else if (direction == 'a')
        snakeX--;

    else if (direction == 'd')
        snakeX++;

    // Wall collision
    if (snakeX < 0 || snakeX >= width ||
        snakeY < 0 || snakeY >= height)
    {
        gameOver = true;
    }

    // Fruit eaten
    if (snakeX == fruitX && snakeY == fruitY)
    {
        score++;

        // New fruit position
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main()
{
    
    while (!gameOver)
    {
        draw();

        input();

        logic();

        Sleep(100);
    }

    cout << "Game Over!" << endl;

    return 0;
}