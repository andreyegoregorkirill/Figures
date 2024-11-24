#pragma once
#include<iostream>
#include<Windows.h>
#include<string>

class Figure
{
protected:
	int x, y, radius;
	HWND hwnd;
	HDC hdc;
	RECT rt;
	COLORREF bkcolor;
	COLORREF bordercolor;
public:
	Figure() :
		x(0), y(0), radius(0), bkcolor(RGB(255, 255, 255)), bordercolor(RGB(255, 255, 255)) {};
	Figure(int _x, int _y, int _r, COLORREF _bc, COLORREF _brc) :
		x(_x), y(_y), radius(_r), bkcolor(_bc), bordercolor(_brc) {
		hwnd = GetConsoleWindow();
		hdc = GetDC(hwnd);
		GetClientRect(hwnd, &rt);
	};
	virtual void draw() = 0;
	virtual void hide() = 0;
	virtual void move(int, int);
	int getradius() const { return radius; };
	COLORREF getbkcolor() const { return bkcolor; };
	COLORREF getbordercolor() const { return bordercolor; };
	class BorderException {
	private:
		std::string message;
	public:
		BorderException(std::string _message) : message(_message) {};
		void what() const {
			std::string default_m{"‘игура выходит за границы окна: "};
			std::cout << default_m + message + '\n';
		}
	};
	class NegativeNumbers {
	private:
		std::string message;
	public:
		NegativeNumbers(std::string _message) : message(_message) {}
		void what() const {
			std::string default_m{"Ќулевые или отрицательные значени€ параметров: "};
			std::cout << default_m + message + '\n';
		}
	};
	~Figure() { ReleaseDC(hwnd, hdc); };
};