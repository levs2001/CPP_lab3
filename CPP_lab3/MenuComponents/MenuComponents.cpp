#include "MenuComponents.h"
#include <Vector>
#include <String>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include"MenuComponents.h"

#define L_WIDTH 4
#define NOT_ACT_BUT -1


void Primitives::DisplayText(classXY coord, const char* string) {
	int j = strlen(string);
	glColor3f(0, 0, 0);
	glRasterPos2f(coord.x, coord.y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void Primitives::BlLine(classXY coord1, classXY coord2) {
	glColor3ub(0, 0, 0);
	glLineWidth(L_WIDTH);
	glBegin(GL_LINES);
	glVertex2f(coord1.x, coord1.y);
	glVertex2f(coord2.x, coord2.y);
	glEnd();
}

void Primitives::Rectangle(classXY coord, classXY size) {

	Primitives::BlLine(coord, classXY(coord.x + size.x, coord.y));
	Primitives::BlLine(classXY(coord.x + size.x, coord.y), classXY(coord.x + size.x, coord.y - size.y));
	Primitives::BlLine(classXY(coord.x + size.x, coord.y - size.y), classXY(coord.x, coord.y - size.y));
	Primitives::BlLine(classXY(coord.x, coord.y - size.y), coord);
}

void Primitives::FillRectangle(classXY coord, classXY size) {
	glColor3ub(239, 211, 52);
	glRectf(coord.x, coord.y, coord.x + size.x, coord.y - size.y);
}


void MyButton::Draw(bool selected) {
	if (selected) {
		Primitives::FillRectangle(coord, size);
		if (submenu != nullptr)
			submenu->Draw(NOT_ACT_BUT);
	}
	Primitives::Rectangle(coord, size);
	Primitives::DisplayText(classXY(coord.x + (float)L_WIDTH / 300, coord.y - size.y + (float)L_WIDTH / 300), name.c_str());
}


void MenuBlock::AddBut(MyButton& but) {
	buts.push_back(but);
}

void MenuBlock::Draw(int selBut_num) {
	Primitives::Rectangle(coord, size);
	for (auto but : buts) {
		but.Draw(selBut_num == but.GetNum());
	}
}


void MyMenu::Init(vector<MenuBlock> newMenues) {
	activeBut = 0;
	menues = newMenues;
	menuWay.push_back(&(menues.front()));
}

void MyMenu::Init() {
	for (int i = 0; i < 2; i++) {
		menues.push_back(MenuBlock("name", classXY(-1 + 0.2 * i, 1), classXY(0.2, 1)));
	}

	MyButton but(0, "but1", classXY(-1 + 0.2 * 0, 1), classXY(0.2, 0.1), &(menues.at(1)));
	menues.at(0).AddBut(but);

	but.Change(1, "but2", classXY(-1 + 0.2 * 0, 1 - 0.1 * 1), classXY(0.2, 0.1));
	menues.at(0).AddBut(but);

	but.Change(0, "but3", classXY(-1 + 0.2 * 1, 1), classXY(0.2, 0.1));
	menues.at(1).AddBut(but);

	but.Change(1, "but4", classXY(-1 + 0.2 * 1, 1 - 0.1 * 1), classXY(0.2, 0.1));
	menues.at(1).AddBut(but);

	activeBut = 0;
	menuWay.push_back(&(menues.front()));
}

void MyMenu::Draw() {
	for (MenuBlock* pMenu : menuWay) {
		pMenu->Draw(menuWay.back() == pMenu ? activeBut : NOT_ACT_BUT);
	}
}