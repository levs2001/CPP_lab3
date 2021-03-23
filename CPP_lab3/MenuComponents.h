#pragma once
#include <String>
#include <Vector>
#include <GL\glew.h>
#include <GL\freeglut.h>

using namespace std;

class classXY {
public:
	float x;
	float y;
	classXY(float x, float y) :x(x), y(y) {}
	classXY(const classXY& size) :x(size.x), y(size.y) {};
	classXY() : x(-1), y(1) {};
};

void Rectangle(classXY size, classXY coord);
void BlLine(classXY coord1, classXY coord2);

class MenuBlock;

class MyButton {
public:
	MyButton(size_t num, string name = "but", classXY coord = classXY(-1, 1), classXY size = classXY(0.2, 0.1), MenuBlock* submenu = nullptr)
		: num(num), name(name), coord(coord), size(size), submenu(submenu) {}
	
	MyButton(const MyButton& otherBut) : num(otherBut.num), name(otherBut.name), size(otherBut.size), coord(otherBut.coord), submenu(otherBut.submenu) {}

	MyButton() : num(-1), name("NotInit but"), size(classXY(0.2, 0.1)) {}

	size_t GetNum() {
		return num;
	}
	void Draw(bool selected);

private:
	size_t num;
	string name;
	classXY coord;
	classXY size;
	MenuBlock* submenu;
};

class MenuBlock {
public:
	MenuBlock(string name, classXY coord = classXY(-1, 1), classXY size = classXY(0.2, 1)) : name(name), coord(coord), size(size){}
	MenuBlock() {}
	void AddBut(MyButton& but);
	void Draw(int selBut_num);
private:
	string name;
	classXY coord;
	classXY size;
	vector<MyButton> buts;
};

class MyMenu {
public:
	void SetMenues(vector<MenuBlock> newMenues) {
		menues = newMenues;
	}

	void SetActiveBut(size_t newActiveBut) {
		activeBut = newActiveBut;
	}

	size_t GetActiveBut() {
		return activeBut;
	}

	void wayPush(MenuBlock* pMenu) {
		menuWay.push_back(pMenu);
	}

	void wayPop() {
		menuWay.pop_back();
	}

	void Init() {

	}

	void KeyUp() {

	}

	void KeyDown() {

	}

	void KeyLeft() {

	}

	void KeyRight() {

	}

	void Draw();

private:
	size_t activeBut;
	MenuBlock* pActiveMenu;
	vector<MenuBlock*> menuWay;
	vector<MenuBlock> menues;
};