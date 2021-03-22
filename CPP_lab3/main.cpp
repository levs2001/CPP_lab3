#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "Singleton.h"
#include "MenuComponents.h"

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//рисуем треугольник
	glColor3ub(145, 30, 66);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, 0.8f, 0.0f); //верхн€€ вершина
	glVertex3f(-0.4f, 0.4f, 0.0f); //лева€ вершина
	glVertex3f(0.4f, 0.4f, 0.0f); //права€ вершина
	glEnd();
	//////////////////////////////////

	//рисуем пр€моугольник
	glColor3ub(239, 211, 52);
	glRectf(-0.2f, 0.4f, 0.2f, 0.0f);
	///////////////////////////////////

	//рисуем отрезок
	glLineWidth(50); //задаем толщину
	glColor3ub(60, 170, 60);
	glBegin(GL_LINES);
	glVertex3f(-0.9, 0.0, 0.0);
	glVertex3f(0.9, 0, 0);
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
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 140);
	glutCreateWindow("OpenGL window");
	glClearColor(0, 0, 1, 1);
	glutDisplayFunc(display);
	glutKeyboardFunc(processKeyboard);
	glutMainLoop();
}