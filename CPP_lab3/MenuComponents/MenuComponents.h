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
	friend bool operator== (const classXY& c1, const classXY& c2) {
		return (c1.x == c2.x && c1.y == c2.y);
	}
};


namespace Primitives {
	void Rectangle(classXY size, classXY coord);
	void BlLine(classXY coord1, classXY coord2);
	void DisplayText(classXY coord, const char* string);
	void FillRectangle(classXY coord, classXY size);
}


class MenuBlock;

class MyButton {
public:
	MyButton(/*size_t num, */string name = "NotInit but", classXY coord = classXY(-1, 1), classXY size = classXY(0.2, 0.1), MenuBlock* submenu = nullptr)
		: /*num(num),*/ name(name), coord(coord), size(size), submenu(submenu) {}

	MyButton(const MyButton& otherBut) : num(otherBut.num), name(otherBut.name), size(otherBut.size), coord(otherBut.coord), submenu(otherBut.submenu) {}

	//MyButton() : num(-1), name("NotInit but"), size(classXY(0.2, 0.1)) {}

	void Change(/*size_t num, */string name = "but", classXY coord = classXY(-1, 1), classXY size = classXY(0.2, 0.1), MenuBlock* submenu = nullptr) {
		/*this->num = num;*/
		this->name = name;
		this->coord = coord;
		this->size = size;
		this->submenu = submenu;
	}

	void SetNum(size_t num) {
		this->num = num;
	}

	size_t GetNum() {
		return num;
	}
	void Draw(bool selected);
	
	MenuBlock* GetSubmenu() {
		return submenu;
	}

	string GetName() const {
		return name;
	}
private:
	size_t num;
	string name;
	classXY coord;
	classXY size;
	MenuBlock* submenu;
};

class MenuBlock {
public:
	MenuBlock(string name, classXY coord = classXY(-1, 1), classXY size = classXY(0.2, 1)) : name(name), coord(coord), size(size) {}
	MenuBlock() {}

	friend bool operator== (const MenuBlock& m1, const MenuBlock& m2) {
		return (m1.GetName() == m2.GetName() && m1.GetCoord() == m2.GetCoord());
	}

	void AddBut(MyButton& but);
	void Draw(int selBut_num);

	size_t ButCount() {
		return buts.size();
	}

	string GetName() const {
		return name;
	}

	classXY GetCoord() const {
		return coord;
	}

	classXY GetSize() const {
		return size;
	}

	MyButton& GetBut(size_t num) {
		return buts.at(num);
	}

	void SetName(string name) {
		this->name = name;
	}

	void SetCoord(classXY coord) {
		this->coord = coord;
	}
	
	void SetSize(classXY size) {
		this->size = size;
	}

private:
	string name;
	classXY coord;
	classXY size;
	vector<MyButton> buts;
};

class MyMenu {
public:
	void Init(vector<MenuBlock>& newMenues);
	void Init();

	void SetActiveBut(size_t newActiveBut) {
		activeBut = newActiveBut;
	}

	size_t GetActiveBut() {
		return activeBut;
	}

	void KeyUp() {
		if (activeBut > 0)
			activeBut--;
	}

	void KeyDown() {
		if (activeBut < menuWay.back()->ButCount() - 1)
			activeBut++;
	}

	void KeyLeft() {
		if (menuWay.size() > 1) {
			menuWay.pop_back();
			activeBut = 0;
		}
	}

	void KeyRight() {
		if (menuWay.back()->GetBut(activeBut).GetSubmenu() != nullptr) {
			menuWay.push_back(menuWay.back()->GetBut(activeBut).GetSubmenu());
			activeBut = 0;
		}
	}

	void Draw();

private:
	size_t activeBut;
	vector<MenuBlock*> menuWay;
	vector<MenuBlock> menues;
};

