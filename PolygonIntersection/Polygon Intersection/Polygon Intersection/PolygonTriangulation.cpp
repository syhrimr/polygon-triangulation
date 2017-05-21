#include "PolygonTriangulation.h"
#include <iostream>

void PolygonTriangulation::initPolygon() {
	int size = (sizeof(vertex) / sizeof(vertex[0])) / 2;

	// Input to vertices object
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j <= i + 1; j++) {
			vertices.resize(24);
			vertices.push_back(new Vertex(vertex[i], vertex[j]));
			// Try to debug, showing what is inside vertices
			cout << "value of vec [" << i << "] = " << vertices[i]->x << " " << vertices[i]->y << endl;
			cout << "value of vec [" << j << "] = " << vertices[j]->x << " " << vertices[j]->y << endl;
		}
		i++;
	}
}
