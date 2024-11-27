#pragma once
#include"Figure.h"

class InscRectangle :public Figure
{
private:
	int width;
public:
	InscRectangle(int x, int y, int r, int _width, COLORREF bkcolor = RGB(0, 0, 255),
		COLORREF bordercolor = RGB(255,0,0)) :
		Figure(x, y, r, bkcolor, bordercolor), width(_width) {};
	void draw() override;
	void hide() override;
	int getwidth() const { return width; };
};