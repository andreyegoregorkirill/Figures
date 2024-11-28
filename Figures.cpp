#include"ComplexFigure.h"
#include"FiguresStack.h"

int main() {
	const int NotUse = system("color F0");
	SetConsoleTitle((LPCWSTR)L"23VP2_11");
	setlocale(LC_ALL, "ru");
	try {
		Circle* cr{ new Circle(120, 120, 55, RGB(0,255,255), RGB(164,164,0)) };
		cr->draw();
		InscRectangle* rc{ new InscRectangle(240, 360, 120, 75) };
		rc->draw();
		Sleep(1200);
		rc->move(450, 240);
		Sleep(1200);
		cr->hide();
		rc->hide();
		Sleep(1200);
		FiguresStack fs{ cr, rc };
		ComplexFigure* cf{ new ComplexFigure(new Circle(360,120,75, RGB(255,255,0), RGB(0,0,0)), new InscRectangle(360,120,75,130, RGB(255,0,255), RGB(0,0,0)))};
		fs.push(cf);
		fs.print();
		Sleep(1200);
		cf->move(400, 120);
		Sleep(1200);
		fs.remove();
	}
	catch (Figure::BorderException err) {
		err.what();
		Sleep(3600);
	}
	catch (Figure::NegativeNumbers err) {
		err.what();
		Sleep(3600);
	}
	catch (std::bad_alloc& ba) {
		std::cout << ba.what() << '\n';
		Sleep(3600);
	}
	return 0;
}
