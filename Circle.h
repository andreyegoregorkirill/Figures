#pragma once
#include"Figure.h"

class Circle :public Figure
{
public:
	Circle(int x, int y, int radius, COLORREF bkcolor = RGB(0, 255, 0),
		COLORREF bordercolor = RGB(255,0,0)) :
		Figure(x, y, radius, bkcolor, bordercolor) {};
	void draw() override;
	void hide() override;
}; 