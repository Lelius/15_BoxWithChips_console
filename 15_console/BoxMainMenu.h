#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <Windows.h>
#include <conio.h>

#include "BoxWithChips.h"

class BoxMainMenu
{
public:
	BoxMainMenu();
	~BoxMainMenu();

	void startMainMenu();
	void boxWithChipsGameLoop(BoxWithChips *);
	bool isNumber(std::string);
	void boxWithChipsOnScreen(BoxWithChips *);

private:
	std::string str;
	int xNumBox;
	int yNumBox;
};

