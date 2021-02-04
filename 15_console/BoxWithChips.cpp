#include "BoxWithChips.h"

BoxWithChips::BoxWithChips() : xNum(4), yNum(4)
{
	setSizeBox(getXNum() * getYNum());
	BoxWithChips::boxWithChips = new int[getSizeBox()]{};
}

BoxWithChips::BoxWithChips(int value) : xNum(value), yNum(value)
{
	setSizeBox(getXNum() * getYNum());
	BoxWithChips::boxWithChips = new int[getSizeBox()]{};
}

BoxWithChips::BoxWithChips(int x, int y) : xNum(x), yNum(y)
{
	setSizeBox(getXNum() * getYNum());
	BoxWithChips::boxWithChips = new int[getSizeBox()]{};
}

BoxWithChips::~BoxWithChips()
{
	delete[] BoxWithChips::boxWithChips;
}

const int BoxWithChips::getSizeBox()
{
	return sizeBox;
}

bool BoxWithChips::setSizeBox(int sizeBox)
{
	if (sizeBox < (2 * 2) || sizeBox > (6 * 6))
		return false;

	this->sizeBox = sizeBox;
	return true;
}

const int BoxWithChips::getXNum()
{
	return xNum;
}

const int BoxWithChips::getYNum()
{
	return yNum;
}

void BoxWithChips::randomChips()
{
	for (int i = 0; i < getSizeBox(); ++i)
		*(boxWithChips + i) = 0;

	for (int i = 0; i < getSizeBox() - 1; ++i)
	{
		int x;
		srand(time(NULL));
		while (searchChip(x = rand() % (getSizeBox() - 1) + 1)) {}
		*(boxWithChips + i) = x;
	}
	*(boxWithChips + (getSizeBox() - 1)) = 0;
}

bool BoxWithChips::searchChip(int chip)
{
	for (int i = 0; i < getSizeBox(); ++i)
	{
		if (*(getBoxWithChips() + i) == chip)
			return true;
	}
	return false;
}

bool BoxWithChips::isMatchingChips()
{
	bool isMatch{ true };
	for (int i = 0; i < (getSizeBox() - 1); ++i)
	{
		int chip = *(getBoxWithChips() + i);
		if (chip != (i + 1))
			isMatch = false;
	}
	return isMatch;
}

int BoxWithChips::getPosEmptyPlace()
{
	int posEmptyPlace{ 0 };
	for (int i = 0; i < getSizeBox(); ++i)
		if (*(boxWithChips + i) == 0)
			posEmptyPlace = i;
	return posEmptyPlace;
}

bool BoxWithChips::toTheLeftChip()
{
	int x = getPosEmptyPlace() % getXNum();
	int y = getPosEmptyPlace() / getYNum();
	if (x >= 0 && x < getXNum() - 1)
	{
		*(boxWithChips + (y * getXNum()) + x) = *(boxWithChips + (y * getXNum()) + x + 1);
		*(boxWithChips + (y * getXNum()) + x + 1) = 0;
		return true;
	}
	else
	{
		return false;
	}
}

bool BoxWithChips::toTheRightChip()
{
	int x = getPosEmptyPlace() % getXNum();
	int y = getPosEmptyPlace() / getYNum();
	if (x > 0 && x <= getXNum() - 1)
	{
		*(boxWithChips + (y * getXNum()) + x) = *(boxWithChips + (y * getXNum()) + x - 1);
		*(boxWithChips + (y * getXNum()) + x - 1) = 0;
		return true;
	}
	else
	{
		return false;
	}
}

bool BoxWithChips::toTheUpChip()
{
	int x = getPosEmptyPlace() % getXNum();
	int y = getPosEmptyPlace() / getYNum();
	if (y >= 0 && y < getYNum() - 1)
	{
		*(boxWithChips + (y * getXNum()) + x) = *(boxWithChips + ((y + 1) * getXNum()) + x);
		*(boxWithChips + ((y + 1) * getXNum()) + x) = 0;
		return true;
	}
	else
	{
		return false;
	}
}

bool BoxWithChips::toTheBottomChip()
{
	int x = getPosEmptyPlace() % getXNum();
	int y = getPosEmptyPlace() / getYNum();
	if (y > 0 && y <= getYNum() - 1)
	{
		*(boxWithChips + (y * getXNum()) + x) = *(boxWithChips + ((y - 1) * getXNum()) + x);
		*(boxWithChips + ((y - 1) * getXNum()) + x) = 0;
		return true;
	}
	else
	{
		return false;
	}
}

const int *BoxWithChips::getBoxWithChips()
{
	return boxWithChips;
}
