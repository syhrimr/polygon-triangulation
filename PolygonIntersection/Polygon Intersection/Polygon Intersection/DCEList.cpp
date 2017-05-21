#include "DCEList.h"
#include <iostream>
using namespace std;

DCEList::DCEList() {

}

DCEList::~DCEList() {

}

void DCEList::initPolygon() {
	//vertices.resize(24);
	vertices.push_back(new Vertex(0, 0));
	vertices.push_back(new Vertex(0.01353, -0.01733));
	vertices.push_back(new Vertex(-0.04914, -0.06628));
	vertices.push_back(new Vertex(-0.02135, -0.10186));
	vertices.push_back(new Vertex(0.01938, -0.07005));
	vertices.push_back(new Vertex(0.03718, -0.09285));
	vertices.push_back(new Vertex(0.07767, -0.06123));
	vertices.push_back(new Vertex(0.05906, -0.0374));
	vertices.push_back(new Vertex(0.10152, -0.00424));
	vertices.push_back(new Vertex(0.11951, -0.02727));
	vertices.push_back(new Vertex(0.24696, 0.07226));
	vertices.push_back(new Vertex(0.20161, 0.13033));
	vertices.push_back(new Vertex(0.04642, 0.00913));
	vertices.push_back(new Vertex(0.03326, 0.02598));
	vertices.push_back(new Vertex(0.18908, 0.14766));
	vertices.push_back(new Vertex(0.16183, 0.18256));
	vertices.push_back(new Vertex(0.00707, 0.06169));
	vertices.push_back(new Vertex(-0.03771, 0.11903));
	vertices.push_back(new Vertex(-0.07203, 0.09223));
	vertices.push_back(new Vertex(-0.02731, 0.03497));
	vertices.push_back(new Vertex(-0.05052, 0.01684));
	vertices.push_back(new Vertex(-0.09482, 0.07357));
	vertices.push_back(new Vertex(-0.23638, -0.03698));
	vertices.push_back(new Vertex(-0.16554, -0.1277));
}

void DCEList::setVertexStatus() {
	int s = vertices.size() - 1;
	if (vertices.size() > 0) {
		for (int k = 0; k < vertices.size(); k++) {
			if (k == 0) {
				if (vertices[k]->y > vertices[k + 1]->y && vertices[k]->y > vertices[s]->y) {
					if (vertices[k]->x > vertices[s]->x) {
						vertices[k]->eventType = EventType::SPLIT;
					} else {
						vertices[k]->eventType = EventType::START;
					}
				} else if (vertices[k]->y < vertices[k + 1]->y && vertices[k]->y < vertices[s]->y) {
					if (vertices[k]->x < vertices[s]->x) {
						vertices[k]->eventType = EventType::MERGE;
					} else {
						vertices[k]->eventType = EventType::END;
					}
				} else {
					vertices[k]->eventType = EventType::REGULAR;
				}
			} else if (k == s) {
				if (vertices[k]->y > vertices[0]->y && vertices[k]->y > vertices[k - 1]->y) {
					if (vertices[k]->x > vertices[k - 1]->x) {
						vertices[k]->eventType = EventType::SPLIT;
					} else {
						vertices[k]->eventType = EventType::START;
					}
				} else if (vertices[k]->y < vertices[0]->y && vertices[k]->y < vertices[k - 1]->y) {
					if (vertices[k]->x < vertices[k - 1]->x) {
						vertices[k]->eventType = EventType::MERGE;
					} else {
						vertices[k]->eventType = EventType::END;
					}
				} else {
					vertices[k]->eventType = EventType::REGULAR;
				}
			} else {
				if (vertices[k]->y > vertices[k + 1]->y && vertices[k]->y > vertices[k - 1]->y) {
					if (vertices[k]->x > vertices[k - 1]->x) {
						vertices[k]->eventType = EventType::SPLIT;
					} else {
						vertices[k]->eventType = EventType::START;
					}
				} else if (vertices[k]->y < vertices[k + 1]->y && vertices[k]->y < vertices[k - 1]->y) {
					if (vertices[k]->x < vertices[k - 1]->x) {
						vertices[k]->eventType = EventType::MERGE;
					} else {
						vertices[k]->eventType = EventType::END;
					}
				} else {
					vertices[k]->eventType = EventType::REGULAR;
				}
			}

			cout << vertices[k]->x << " " << vertices[k]->y << " ";
			cout << vertices[k]->eventType << endl;
		}
	}
}
