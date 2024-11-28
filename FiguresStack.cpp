#include"FiguresStack.h"

void FiguresStack::print() {
	for (auto i : c)
		i->draw();
}

void FiguresStack::remove() {
	c.clear();
}

void FiguresStack::push(Figure* f) {
	std::stack<Figure*, std::vector<Figure*>>::push(f);
}