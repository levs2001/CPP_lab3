#include "MenuComponents.h"
#include <Vector>
#include <String>
#include <GL\glew.h>
#include <GL\freeglut.h>

void BlRect(classXY size, classXY coord) {
	glColor3ub(255, 255, 255);
	glRectf(coord.x, coord.y, coord.x + size.x, coord.y + size.y);
}

void MyButton::Draw(bool selected) {

}

void MyMenu::AddBut(MyButton& but) {
	buts.push_back(but);
}

void MyMenu::Draw() {

}

