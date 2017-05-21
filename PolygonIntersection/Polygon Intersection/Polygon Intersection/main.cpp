#include "DCEList.h"
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Global variables
DCEList *polygon = new DCEList();

void display() {
	int scale = 4;
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 1.0f, 1.0f); //white
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < polygon->vertices.size(); i++) {
		glVertex2f(polygon->vertices[i]->x * scale, polygon->vertices[i]->y * scale);
	}
	glEnd();
	
	for (int i = 0; i < polygon->vertices.size(); i++) {
		glPointSize(10.0f);
		glBegin(GL_POINTS);
		if (polygon->vertices[i]->eventType == EventType::START) {
			glColor3f(1.0f, 1.0f, 1.0f); // white
		}
		if (polygon->vertices[i]->eventType == EventType::SPLIT) {
			glColor3f(1.0f, 0.0f, 0.0f); // red
		}
		if (polygon->vertices[i]->eventType == EventType::END) {
			glColor3f(0.0f, 1.0f, 0.0f); // green
		}
		if (polygon->vertices[i]->eventType == EventType::MERGE) {
			glColor3f(1.0f, 1.0f, 0.0f); // yellow
		}
		if (polygon->vertices[i]->eventType == EventType::REGULAR) {
			glColor3f(0.0f, 0.0f, 1.0f); // blue
		}
		glVertex2f(polygon->vertices[i]->x * scale, polygon->vertices[i]->y * scale);
		glEnd();
		glFlush();
	}

	glFlush(); // update windows
}

int main(int argc, char **argv) {
	polygon->initPolygon();
	if (polygon->vertices.size() > 0) {
		polygon->setVertexStatus();
	}

	// Initialize GLUT
	glutInit(&argc, argv);
	glutCreateWindow("Polygon Triangulation");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
