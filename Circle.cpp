#include"Circle.h"

void Circle::draw() {
	if ((x - radius <= rt.left)||(y-radius<=rt.top)) {
		throw BorderException("окружность: координаты " + std::to_string(x) + " "+
		std::to_string(y)+" радиус "+std::to_string(radius));
	}
	if (x <= 0 || y <= 0 || radius <= 0) {
		throw NegativeNumbers("окружность: координаты " + std::to_string(x) + " " +
			std::to_string(y) + " радиус " + std::to_string(radius));
	}
	HPEN pen = CreatePen(PS_SOLID, 2, bordercolor);
	HBRUSH brush = CreateSolidBrush(bkcolor);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(pen);
	DeleteObject(brush);
}

void Circle::hide() {
	if ((x - radius <= rt.left) || (y - radius <= rt.top)) {
		throw BorderException("окружность: координаты " + std::to_string(x) + " " +
			std::to_string(y) + ", радиус " + std::to_string(radius));
	}
	if (x <= 0 || y <= 0 || radius <= 0) {
		throw NegativeNumbers("окружность: координаты " + std::to_string(x) + " " +
			std::to_string(y) + " радиус " + std::to_string(radius));
	}
	HPEN pen = CreatePen(PS_SOLID, 2, GetBkColor(hdc));
	HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	DeleteObject(pen);
	DeleteObject(brush);
}