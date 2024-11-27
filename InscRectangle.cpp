#include"InscRectangle.h"

void InscRectangle::draw() {
	int x_ul = static_cast<int>(x - (width / 2));
	int y_ul = static_cast<int>(y - (sqrt(4 * radius * radius - width * width) / 2));
	int x_dr = static_cast<int>(x + (width / 2));
	int y_dr = static_cast<int>(y + (sqrt(4 * radius * radius - width * width) / 2));
	if (x_ul <= rt.left || y_ul <= rt.left || x_dr <= rt.left || y_dr <= rt.left ||
		x_ul <= rt.top || y_ul <= rt.top || x_dr <= rt.top || y_dr <= rt.top) {
		throw BorderException("прямоугольник: координаты " + std::to_string(x_ul) + " " +
			std::to_string(y_ul) + " " + std::to_string(x_dr) + " " + std::to_string(y_dr));
	}
	if (radius <= 0 || width <= 0) {
		throw NegativeNumbers("прямоугольник: координаты " + std::to_string(x) + " " +
			std::to_string(y) + ", радиус " + std::to_string(radius) + ", ширина " + std::to_string(width));
	}
	HPEN pen = CreatePen(PS_SOLID, 2, bordercolor);
	HBRUSH brush = CreateSolidBrush(bkcolor);
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Rectangle(hdc, x_ul, y_ul, x_dr, y_dr);
	DeleteObject(pen);
	DeleteObject(brush);
}

void InscRectangle::hide() {
	int x_ul = static_cast<int>(x - (width / 2));
	int y_ul = static_cast<int>(y - (sqrt(4 * radius * radius - width * width) / 2));
	int x_dr = static_cast<int>(x + (width / 2));
	int y_dr = static_cast<int>(y + (sqrt(4 * radius * radius - width * width) / 2));
	if (x_ul <= rt.left || y_ul <= rt.left || x_dr <= rt.left || y_dr <= rt.left ||
		x_ul <= rt.top || y_ul <= rt.top || x_dr <= rt.top || y_dr <= rt.top) {
		throw BorderException("прямоугольник: координаты " + std::to_string(x_ul) + " " +
			std::to_string(y_ul) + " " + std::to_string(x_dr) + " " + std::to_string(y_dr));
	}
	if (radius <= 0 || width <= 0) {
		throw NegativeNumbers("прямоугольник: координаты " + std::to_string(x) + " " +
			std::to_string(y) + ", радиус " + std::to_string(radius) + ", ширина " + std::to_string(width));
	}
	HPEN pen = CreatePen(PS_SOLID, 2, GetBkColor(hdc));
	HBRUSH brush = CreateSolidBrush(GetBkColor(hdc));
	SelectObject(hdc, pen);
	SelectObject(hdc, brush);
	Rectangle(hdc, x_ul, y_ul, x_dr, y_dr);
	DeleteObject(pen);
	DeleteObject(brush);
}