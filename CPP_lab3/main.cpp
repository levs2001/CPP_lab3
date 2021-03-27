#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "Singleton.h"
#include "MenuComponents.h"


MyMenu* pMenu_g;

void SysMenuInit() {
	pMenu_g = new MyMenu;
	pMenu_g->Init();
}

void SysMenuDelete() {
	delete pMenu_g;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	pMenu_g->Draw();
	glLineWidth(50); //задаем толщину
	glColor3ub(60, 170, 60);
	glBegin(GL_LINES);
	glVertex2f(-0.9, 0.0);
	glVertex2f(0.9, 0);
	glEnd();
	glFlush();
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		pMenu_g->KeyLeft();
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		pMenu_g->KeyRight();
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		pMenu_g->KeyUp();
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		pMenu_g->KeyDown();
		glutPostRedisplay();
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
	glutSpecialFunc(processSpecialKeys);
	glutMainLoop();

	SysMenuDelete();
}