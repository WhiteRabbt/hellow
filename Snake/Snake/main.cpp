// Snake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <deque>
#include "Sence.h"
#include <time.h>

using namespace std;
int main()
{
    srand(time(0));
    Sence sence;
    int i = 0;
    clock_t preTime = clock();

    while (1)
    {
        while (clock() - preTime < 500)
        {
            sence.Keyboard();
        }
   
        sence.GameLogic();
        preTime = clock();

    }
    std::cout << "Hello World!\n";
}

