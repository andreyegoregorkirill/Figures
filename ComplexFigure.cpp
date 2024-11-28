#include"ComplexFigure.h"

void ComplexFigure::draw() {
	cir->draw();
	rec->draw();
}

void ComplexFigure::hide() {
	cir->hide();
	rec->hide();
}

void ComplexFigure::move(int newX, int newY) {
	cir->hide();
	Circle* tmp_cr = new Circle( newX, newY, cir->getradius(), cir->getbkcolor(),
								cir->getbordercolor());
	cir = tmp_cr;
	InscRectangle* tmp_rt = new InscRectangle( newX,newY,rec->getradius(),rec->getwidth(),
												rec->getbkcolor(),rec->getbordercolor());
	rec = tmp_rt;
	cir->draw();
	rec->draw();
}

