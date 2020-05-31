#ifndef _GRAPH_H
#define _GRAPH_H

#include <vector>
#include "State.h"
#include <iostream>
#define MAX 10
#define CONNECT 2
//template <typename T>
class Node {
	friend class Graph;
public:
	Node() :state(Suspected()), count(0), index(0) {}
	Node(State state) {
		this->state = state;
		this->count = 0;
		this->index = 0;
	}
	Node(int index) :index(index), state(Suspected()), count(0) {

	}
	Node( int index,State state, int count) {
		this->state = state;
		this->count = count;
		this->index = index;
	}
	Node(const Node& source) {
		this->state = source.state;
		this->count = source.count;
		this->index = source.index;

	}
	State getState() const {
		return  this->state;
	}
	int getCount() const {
		return this->count;
	}
	int getIndex() const {
		return this->index;
	}
	void setState(State state) {
		this->state = state;
	}
	void setCount(int number) {
		this->count = number;
	}
	Node& operator=(const Node& source) {
		this->state = source.state;
		this->count = source.count;
		return *this;
	}
	~Node() {
	}
private:
	int index;
	int count;
	State state;
};
class Graph {
public:
	
public:
	Graph();
	~Graph();

	int addNode(Node);
	int addEdgeNode(Node node);
	void connectEdge(int row, int col);

	int getTotalEdge() const;
	Node getNodeTotalEdge(int index) const;
	Node getAt(int index) const;
	int getSize() const;
	int modifyNode(int index,State state);
	int modifyNode(int index, int count);
	int modifyNode(int index, State state, int count);

	void outputMatrix() const;

protected:
	int size;
	vector<Node> nodes;
	int** adjMatrix;
	vector<Node> edgesNode;
};

inline int Graph::getTotalEdge() const {
	return this->edgesNode.size();
}
inline Node Graph::getNodeTotalEdge(int index) const {
	return this->edgesNode[index];
}
inline Node Graph::getAt(int index) const {
	return this->nodes[index];
}
inline int Graph::getSize() const {
	return this->size;
}
#endif // _GRAPH_H

