#pragma once
#include"Circle.h"
#include"InscRectangle.h"

class ComplexFigure :public Figure {
private:
	Circle* cir;
	InscRectangle* rec;
public:
	ComplexFigure(Circle* _cr, InscRectangle* _rect) :
		Figure(), cir(_cr), rec(_rect) {};
	void draw() override;
	void hide() override;
	void move(int, int) override;
};