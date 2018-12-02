// TetrisBox.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include "Sense.h"
#include "Tetris.h"
#include <time.h>
#include <conio.h>
#include <Windows.h>

using namespace std;
void StartGame();
int main()
{
    srand(time(0));
    StartGame();
    //std::cout << "Hello World!\n"; 
}

void StartGame()
{
    //隐藏光标
    CONSOLE_CURSOR_INFO cursorInfo = { 1,0 };
    HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(hWnd, &cursorInfo);



    //初始化状态
    Box tBox;
    Sense tSense;
    tBox.InitBox();
    tSense.InitSense(tBox);
    tSense.SetBox(tBox);
    tSense.ShowBg();
    tSense.ShowBox(tBox);


    int t = 0;
    char ch = '\0';
    int nGameState = 0;

    while (1)
    {
        while (1)
        {

            if (t == 0)
            {
                t = 30000 - tSense.RetLevel() * 5000;
            }
            while (--t)
            {
                if (kbhit())
                {
                    ch = _getwch();
                    if (ch == 
                    break;
                }
            }


            if (t == 0)
            {

                tSense.Down(tBox);
                tSense.ShowBox(tBox);
                nGameState = tSense.GameIsOver();
            }
            else
            {
               /* ch = _getwch();*/

                if ((ch == 'y' || ch == 'Y') && nGameState == 1)
                {
                    system("cls");
                    StartGame();
                    return;
                }
                if ((ch == 'n' || ch == 'N') && nGameState == 1)
                {
                    goto PROC_END;
                }
                switch (ch)
                {
                case 'w':
                case 'W':

                    tSense.Rotate(tBox);
                    tSense.ShowBox(tBox);
                    break;
                case 'a':
                case 'A':

                    tSense.Lfet(tBox);
                    tSense.ShowBox(tBox);
                    break;
                case 'D':
                case 'd':

                    tSense.Right(tBox);
                    tSense.ShowBox(tBox);
                    break;

                case 's':
                case 'S':
                    tSense.Down(tBox);
                    tSense.ShowBox(tBox);
                    nGameState = tSense.GameIsOver();
                    break;
                }
            }
        }
    }
PROC_END:
    return;
}