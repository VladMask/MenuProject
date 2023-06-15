#include "Menu.h"
#include "CommandHandler.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(console, { x, y });
}

void ConsoleCursorVisible(bool show, short size = 10)
{
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(console, &structCursorInfo);
	structCursorInfo.bVisible = show; // изменяем видимость курсора
	structCursorInfo.dwSize = size;   // изменяем размер курсора
	SetConsoleCursorInfo(console, &structCursorInfo);
}

void PrintMenu(short activeItem, vector<string> menu)
{
	for (int i = 0; i < size(menu); i++)
	{
		GoToXY(X_COORD, Y_COORD + i);
		if (i == activeItem)
			SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		else
			SetConsoleTextAttribute(console, FOREGROUND_BLUE);

		cout << menu[i] << endl;
	}
}

void DownKeyPressed(short* activeItem, vector<string> menu)
{
	system("CLS");
	if (*activeItem > menu.size() - 2)
		*activeItem = 0;
	else
		*activeItem += 1;
	PrintMenu(*activeItem, menu);
}

void UpKeyPressed(short* activeItem, vector<string> menu)
{
	system("CLS");
	if (*activeItem < 1)
		*activeItem = menu.size() - 1;
	else
		*activeItem -= 1;
	PrintMenu(*activeItem, menu);
}

short Menu(vector<string> menu)
{
	short activeItem = 0;
	PrintMenu(activeItem, menu);

	char ch;
	while (true)
	{
		ch = _getch();
		if (ch == -32) ch = _getch(); // Отлавливаем стрелочки
		switch (ch)
		{
		case UP_CHAR_EN: case UP_CHAR_RUS: case UP_ARROW: case UP_DIGIT:
			UpKeyPressed(&activeItem, menu);
			break;
		case DOWN_CHAR_EN: case DOWN_CHAR_RUS: case DOWN_ARROW: case DOWN_DIGIT:
			DownKeyPressed(&activeItem, menu);
			break;
		case ENTER:
			return activeItem;
			break;
		case ESC:
			system("CLS");
			activeItem = 0;
			PrintMenu(activeItem, menu);
		}
	}
}

void Await()
{
	char ch;
	while (true)
	{
		ch = _getch();
		if (ch == ESC)
		{
			system("CLS");
			break;
		}
	}
}