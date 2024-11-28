#include"Figure.h"

void Figure::move(int newX, int newY) {
	hide();
	x = newX;
	y = newY;
	draw();
}