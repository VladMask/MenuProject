#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include "CommandHandler.h"

const short X_COORD = 50;
const short Y_COORD = 8;
const short UP_CHAR_RUS = -26;
const short DOWN_CHAR_RUS = -21;
const short UP_CHAR_EN = 119;
const short DOWN_CHAR_EN = 115;
const short UP_DIGIT = 56;
const short DOWN_DIGIT = 50;
const short UP_ARROW = 72;
const short DOWN_ARROW = 80;
const short ENTER = 13;
const short ESC = 27;

using namespace std;

void GoToXY(short x, short y);

void ConsoleCursorVisible(bool show, short size);

void PrintMenu(short activeItem, vector<string> menu);

void DownKeyPressed(short* activeItem, vector<string> menu);

void UpKeyPressed(short* activeItem, vector<string> menu);

short Menu(vector<string> menu);

void Await();