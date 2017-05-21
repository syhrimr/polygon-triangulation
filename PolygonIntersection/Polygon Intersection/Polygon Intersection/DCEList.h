#pragma once
#include <vector>
using namespace std;

enum EventType {
	START, END, SPLIT, MERGE, REGULAR
};

class Edge;
class Face;

class Vertex {
public:
	EventType eventType;
	Edge *incidentEdge;
	double x, y;

	Vertex(double x, double y) {
		this->x = x;
		this->y = y;
	}
};

class Face {
public:
	vector<Face> face;
	Edge *edge;
};

class Edge {
public:
	Edge *halfEdge;
	Vertex *origin;
	Edge *twin;
	Face *incidentFace;
	Edge *next;
	Edge *previous;

	Edge(Edge *halfEdge, Vertex *origin, Edge *twin, Face *incidentFace, Edge *next, Edge *previous) {
		this->halfEdge = halfEdge;
		this->origin = origin;
		this->twin = twin;
		this->incidentFace = incidentFace;
		this->next = next;
		this->previous = previous;
	}
};

class DCEList {
public:
	vector<Vertex*> vertices;
	vector<Edge*> helper;
	
	DCEList();
	~DCEList();
	void initPolygon();
	void setVertexStatus();
	void makeMonotone();
	// Handler vertex events
	void handleStart();
	void handleEnd();
	void handleSplit();
	void handleMerge();
	void handleRegular();
};
