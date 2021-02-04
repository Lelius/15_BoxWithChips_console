#include "BoxMainMenu.h"

BoxMainMenu::BoxMainMenu() : str{ "" }, xNumBox{ 4 }, yNumBox{ 4 } {}

BoxMainMenu::~BoxMainMenu() {}

void BoxMainMenu::startMainMenu()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(handle, &structCursorInfo);

	while (true)
	{
		char chName[] = "ПЯТНАШКИ";
		unsigned char ch{};

		system("cls");
		std::cout << std::endl;
		for (int i = 0; i < 8; ++i)
		{
			std::cout << chName[i];
			Sleep(300);
		}
		Sleep(1000);

		std::cout << "\n\nEnter - начать игру, управление в игре стрелками." << std::endl;
		std::cout << "Esc - выход из игры.";
		ch = _getch();
		if (ch == 27)
			return;
		if (ch == 13)
		{
			BoxWithChips *box = new BoxWithChips(4, 4);
			boxWithChipsGameLoop(box);
			delete box;
		}
	}
}


void BoxMainMenu::boxWithChipsGameLoop(BoxWithChips *boxWithChips)
{
	do
	{
		boxWithChips->randomChips();
	} while (boxWithChips->isMatchingChips());

	while (true)
	{
		unsigned char ch{};
		system("cls");
		boxWithChipsOnScreen(boxWithChips);
		ch = _getch();
		if (ch == 27)
		{
			std::cout << std::endl << "Прерывание игры." << std::endl;
			return;
		}

		if (ch == 72) { boxWithChips->toTheUpChip(); }
		if (ch == 80) { boxWithChips->toTheBottomChip(); }
		if (ch == 75) { boxWithChips->toTheLeftChip(); }
		if (ch == 77) { boxWithChips->toTheRightChip(); }

		if (boxWithChips->isMatchingChips())
		{
			system("cls");
			boxWithChipsOnScreen(boxWithChips);
			std::cout << std::endl << std::endl << "Поздравляю, вы правильно собрали последовательность.";
			Sleep(5000);
			return;
		}
	}
}


bool BoxMainMenu::isNumber(std::string str)
{
	bool isNumber = true;
	for (std::string::const_iterator k = str.begin(); k != str.end(); ++k)
		isNumber = isdigit(*k);
	return isNumber;
}

void BoxMainMenu::boxWithChipsOnScreen(BoxWithChips *box)
{
	std::cout << std::endl;
	std::cout << "*";
	for (int i = 0; i < box->getXNum() - 1; ++i)
		std::cout << "---";
	std::cout << "--*" << std::endl;

	for (int i = 0; i < box->getYNum(); ++i)
	{
		for (int j = 0; j < box->getXNum(); ++j)
		{
			std::cout << "|";
			int value = *(box->getBoxWithChips() + (j + box->getYNum() * i));
			if (value < 1 || value >(box->getSizeBox() - 1))
				std::cout << "  ";
			else if (value < 10)
				std::cout << " " << value;
			else
				std::cout << value;
		}
		std::cout << "|" << std::endl;
	}

	std::cout << "*";
	for (int i = 0; i < box->getXNum() - 1; ++i)
		std::cout << "---";
	std::cout << "--*" << std::endl;
}
