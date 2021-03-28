#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "MenuComponents\MenuComponents.h"
#include "TextSystem\TextSystem.h"

MyMenu* pMenu_g;

void SysMenuInit(vector<MenuBlock>& newMenues) {
	pMenu_g = new MyMenu;
	pMenu_g->Init(newMenues);
}

void SysMenuDelete() {
	delete pMenu_g;
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	pMenu_g->Draw();
	
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


int main(int argc, char* argv[]) {
	TextSystem sys;
	sys.Init("..\\test.xml");

	SysMenuInit(sys.GetMenues());
	
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