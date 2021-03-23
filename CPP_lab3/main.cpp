#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "Singleton.h"
#include "MenuComponents.h"


MenuBlock* pMenu_g;

void SysMenuInit() {
	pMenu_g = new  MenuBlock[2];
	
	for (int i = 0; i < 2; i++) {
		pMenu_g[i] = MenuBlock("name", classXY(-1 + 0.2 * i, 1), classXY(0.2, 1));
		MyButton but(0, "but", classXY(-1+0.2 * i, 1), classXY(0.2, 0.1), &pMenu_g[i]);
		pMenu_g[i].AddBut(but);
	}
}

void SysMenuDelete() {
	delete[] pMenu_g;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//рисуем треугольник
	//glColor3ub(145, 30, 66);
	//glBegin(GL_TRIANGLES);
	//glVertex3f(0.0f, 0.8f, 0.0f); //верхн€€ вершина
	//glVertex3f(-0.4f, 0.4f, 0.0f); //лева€ вершина
	//glVertex3f(0.4f, 0.4f, 0.0f); //права€ вершина
	//glEnd();
	////////////////////////////////////

	////рисуем пр€моугольник
	//glColor3ub(0, 0, 0);
	//glRectf(-1.0f, 1.0f, 0.0f, 0.0f);
	/////////////////////////////////////
	//Rectangle(classXY(-1.0, 1.0), classXY(0.3, 0.1));
	//рисуем отрезок
	for (int i = 0; i < 2; i++)
		pMenu_g[i].Draw(0);
	glLineWidth(50); //задаем толщину
	glColor3ub(60, 170, 60);
	glBegin(GL_LINES);
	glVertex2f(-0.9, 0.0);
	glVertex2f(0.9, 0);
	glEnd();

	glFlush();
}

void processKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
	case GLUT_KEY_UP:
		break;
	case GLUT_KEY_DOWN:
		break;
	}
}


int main(int argc, char* argv[])
{
	SysMenuInit();
	
	glutInit(&argc, argv);
	glutInitWindowSize(1800, 800);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("OpenGL window");
	glClearColor(1, 1, 1, 1);
	glutDisplayFunc(display);
	glutKeyboardFunc(processKeyboard);
	glutMainLoop();

	SysMenuDelete();
}