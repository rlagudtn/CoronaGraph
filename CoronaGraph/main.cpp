#include "Graph.h"
#include <time.h>

//함수 선언
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

	//1.개수만큼 반복한다.

	for(int i = 2;i < MAX;i++) {

		//	1.1.엣지에서 노드 두개를 선택한다.
		edgeCount = graph.getTotalEdge();
		edgeFirst = rand() % edgeCount;
		edgeSec= rand() % edgeCount;
		
		nodeFirst = graph.getNodeTotalEdge(edgeFirst).getIndex();
		nodeSec = graph.getNodeTotalEdge(edgeSec).getIndex();
		while (nodeFirst == nodeSec) {
			edgeSec = rand() % edgeCount;
			nodeSec = graph.getNodeTotalEdge(edgeSec).getIndex();
		}

		//	1.2.그래프에 새 노드를 추가한다.
		Node node(i);
		addIndex = graph.addNode(node);
		// 1.3. 선을 연결해준다.
		// 1.4. 뽑을 것들에 넣어준다.
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