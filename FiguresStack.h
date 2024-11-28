#pragma once
#include<stack>
#include<vector>
#include<initializer_list>
#include"Figure.h"

class FiguresStack : public std::stack<Figure*, std::vector<Figure*>>
{
public:
	FiguresStack(std::initializer_list<Figure*> il):
		std::stack<Figure*, std::vector<Figure*>>(il) {};
	void print();
	void remove();
	void push(Figure*);
};