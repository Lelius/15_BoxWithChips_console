#include "BoxMainMenu.h"

BoxMainMenu::BoxMainMenu() : str{ "" }, xNumBox{ 4 }, yNumBox{ 4 } {}

BoxMainMenu::~BoxMainMenu() {}

void BoxMainMenu::startMainMenu()
{
	while (true)
	{
		std::cout << std::endl;
		std::cout << "������� ����������� �������� ���� (������� 4�4, �������� 6�6) ��� ������� \'�\' ��� ������:" << std::endl;
		std::cout << "- �� ����������� ";
		std::cin >> str;
		if (str == "q" || str == "�")
			return;
		if (!isNumber(str))
			continue;
		xNumBox = std::stoi(str);
		if (xNumBox < 4 || xNumBox > 6)
			continue;

		std::cout << "- �� ��������� ";
		std::cin >> str;
		if (str == "q" || str == "�")
			return;
		if (!isNumber(str))
			continue;
		yNumBox = std::stoi(str);
		if (yNumBox < 4 || yNumBox > 6)
			continue;
		std::cout << std::endl;

		BoxWithChips *box = new BoxWithChips(xNumBox, yNumBox);
		boxWithChipsGameLoop(box);
		delete box;
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
		//std::string str;
		unsigned char ch{};
		boxWithChipsOnScreen(boxWithChips);
		//std::cin >> str;
		ch = _getch();
		if (ch == 'q' || ch == '�')
		{
			std::cout << std::endl << "���������� ����." << std::endl;
			return;
		}
		if (ch == 'w') { boxWithChips->toTheUpChip(); }
		if (ch == 's') { boxWithChips->toTheBottomChip(); }
		if (ch == 'a') { boxWithChips->toTheLeftChip(); }
		if (ch == 'd') { boxWithChips->toTheRightChip(); }

		if (boxWithChips->isMatchingChips())
		{
			boxWithChipsOnScreen(boxWithChips);
			std::cout << std::endl << "����������, �� ��������� ������� ������������������.";
			Sleep(5000);
			return;
		}
	}

	std::cin.get();
	std::cin.get();
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
