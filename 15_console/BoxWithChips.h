#pragma once

#include <time.h>
#include <cstdlib>

class BoxWithChips
{
public:
	BoxWithChips();
	BoxWithChips(int);
	BoxWithChips(int, int);
	~BoxWithChips();

	
	const int *getBoxWithChips();
	const int getSizeBox();
	const int getXNum();
	const int getYNum();

	void randomChips();
	bool searchChip(int);
	bool isMatchingChips();
	int	 getPosEmptyPlace();
	bool toTheLeftChip();
	bool toTheRightChip();
	bool toTheUpChip();
	bool toTheBottomChip();

private:
	bool setSizeBox(int);
	

	int xNum;
	int yNum;
	int sizeBox;
	int *boxWithChips;
};

