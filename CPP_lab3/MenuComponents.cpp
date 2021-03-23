#include "MenuComponents.h"
#include <Vector>
#include <String>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include"MenuComponents.h"

#define L_WIDTH 4
#define NOT_ACT_BUT -1

void DisplayText(classXY coord, const char* string) {
	int j = strlen(string);
	glColor3f(0, 0, 0);
	glRasterPos2f(coord.x, coord.y);
	for (int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void BlLine(classXY coord1, classXY coord2) {
	glColor3ub(0, 0, 0);
	glLineWidth(L_WIDTH);
	glBegin(GL_LINES);
	glVertex2f(coord1.x, coord1.y);
	glVertex2f(coord2.x, coord2.y);
	glEnd();
}

void Rectangle(classXY coord, classXY size) {

	BlLine(coord, classXY(coord.x + size.x, coord.y));
	BlLine(classXY(coord.x + size.x, coord.y), classXY(coord.x + size.x, coord.y - size.y));
	BlLine(classXY(coord.x + size.x, coord.y - size.y), classXY(coord.x, coord.y - size.y));
	BlLine(classXY(coord.x, coord.y - size.y), coord);
}

void MyButton::Draw(bool selected) {
	Rectangle(coord, size);
	DisplayText(classXY(coord.x + (float)L_WIDTH / 300, coord.y - size.y + (float)L_WIDTH / 300), name.c_str());
}

void MenuBlock::AddBut(MyButton& but) {
	buts.push_back(but);
}

void MenuBlock::Draw(int selBut_num) {
	Rectangle(coord, size);
	for (auto but : buts) {
		but.Draw(selBut_num==but.GetNum());
	}
}

void MyMenu::Draw() {
	for (MenuBlock* pMenu : menuWay) {
		pMenu->Draw(pActiveMenu == pMenu ? activeBut : NOT_ACT_BUT);
	}
}