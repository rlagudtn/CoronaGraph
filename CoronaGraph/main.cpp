#include "Graph.h"
#include <time.h>

//�Լ� ����
void MakeBAModel(Graph& graph);
void Output(Graph& graph);

int main() {
	Graph graph;
	MakeBAModel(graph);
	Output(graph);

	return 0;
}

void MakeBAModel(Graph& graph) {
	int edgeFirst, edgeSec;
	int nodeFirst, nodeSec;
	int addIndex;
	int edgeCount;
	srand(time(NULL));

	//1.������ŭ �ݺ��Ѵ�.

	for(int i = 2;i < MAX;i++) {

		//	1.1.�������� ��� �ΰ��� �����Ѵ�.
		edgeCount = graph.getTotalEdge();
		edgeFirst = rand() % edgeCount;
		edgeSec= rand() % edgeCount;
		
		nodeFirst = graph.getNodeTotalEdge(edgeFirst).getIndex();
		nodeSec = graph.getNodeTotalEdge(edgeSec).getIndex();
		while (nodeFirst == nodeSec) {
			edgeSec = rand() % edgeCount;
			nodeSec = graph.getNodeTotalEdge(edgeSec).getIndex();
		}

		//	1.2.�׷����� �� ��带 �߰��Ѵ�.
		Node node(i);
		addIndex = graph.addNode(node);
		// 1.3. ���� �������ش�.
		// 1.4. ���� �͵鿡 �־��ش�.
		graph.connectEdge(addIndex, nodeFirst);
		graph.addEdgeNode(graph.getAt(addIndex));
		graph.addEdgeNode(graph.getAt(nodeFirst));

		graph.connectEdge(addIndex, nodeSec);
		graph.addEdgeNode(graph.getAt(addIndex));
		graph.addEdgeNode(graph.getAt(nodeSec));



	}
}

void Output(Graph& graph) {
	graph.outputMatrix();
}