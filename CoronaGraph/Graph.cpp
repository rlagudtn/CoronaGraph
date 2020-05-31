#include "Graph.h"

Graph::Graph(){
	this->size = 2;
	
	this->adjMatrix = new int* [MAX];
	for (int i = 0;i < MAX;i++) {
		this->adjMatrix[i] = new int[MAX];
	}

	for (int i = 0;i < MAX;i++) {
		for (int j = 0;j < MAX;j++) {
			this->adjMatrix[i][j] = 0;
		}
	}

	for (int i = 0;i < 2;i++) {
		Node node(i,Suspected(), 1);
		this->nodes.push_back(node);
		this->edgesNode.push_back(node);

	}
	this->adjMatrix[0][1] = 1;
	this->adjMatrix[1][0] = 1;


}




Graph::~Graph() {
	for (int i = 0;i < MAX;i++) {
		delete[] this->adjMatrix[i];
	}
	delete[] this->adjMatrix;
}

int Graph::addNode(Node node) {
	this->nodes.push_back(node);
	this->size++;

	return this->nodes.size()-1 ;
}
int Graph::addEdgeNode(Node node) {
	this->edgesNode.push_back(node);

	return this->edgesNode.size() - 1;
}

void Graph::connectEdge(int row, int col) {
	int count;
	this->adjMatrix[row][col] = 1;
	this->adjMatrix[col][row] = 1;

	count = this->nodes[row].count;
	count++;
	this->nodes[row].setCount(count);

	count = this->nodes[col].count;
	count++;
	this->nodes[col].setCount(count);

}


int Graph::modifyNode(int index, State state) {
	//delete *this->node[index];
	this->nodes[index].setState(state);

	return index;
}

int Graph::modifyNode(int index, int count) {
	this->nodes[index].setCount(count);
	return index;
}

int Graph::modifyNode(int index, State state, int count) {
	
	return index;
}


void Graph::outputMatrix()const {
	for (int i = 0;i < this->size; i++) {
		for (int j = 0;j < this->size;j++) {
			cout << this->adjMatrix[i][j];
		}
		cout << "\n";
	}
	for (int i = 0;i < this->size;i++) {
		cout << i << "번째 연결 개수 : " << this->nodes[i].getCount()<<"\n";
	}
}
