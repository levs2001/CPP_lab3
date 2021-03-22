#pragma once
#include<string>
#include<vector>

using namespace std;

class MyMenu;

class classXY {
public:
	size_t x;
	size_t y;
	classXY(size_t x, size_t y) :x(x), y(y) {}
	classXY(const classXY& size) :x(size.x), y(size.y) {};
};

class MyButton {
public:
	MyButton(size_t num, string name = "but", classXY size = classXY(30, 30), classXY coord = classXY(0, 0),  MyMenu* submenu = nullptr) 
		: num(num), name(name), size(size), coord(coord), submenu(submenu) {}

	void Draw(bool selected);

private:
	size_t num;
	string name;
	classXY size;
	//Left up corner
	classXY coord;
	MyMenu* submenu;
};

class MyMenu {
public:
	MyMenu(string name, classXY size = classXY(100, 100), classXY coord = classXY(0, 0)) : name(name), size(size), coord(coord){}
	void AddBut(MyButton& but);
	void Draw();
private:
	string name;
	classXY size;
	//Left up corner
	classXY coord;
	vector<MyButton> buts;
};