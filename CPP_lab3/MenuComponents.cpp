#include "MenuComponents.h"
#include <Vector>
#include <String>
#include <GL\glew.h>
#include <GL\freeglut.h>

void BlRect(classXY size, classXY coord) {
	glColor3ub(0, 0, 0);
	glRectf(-0.2f, 0.4f, 0.2f, 0.0f);
}

void MyButton::Draw(bool selected) {

}

void MyMenu::AddBut(MyButton& but) {
	buts.push_back(but);
}

void MyMenu::Draw() {

}

