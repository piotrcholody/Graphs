#pragma once

#include <iostream>
#include <vector>
#include "IncidenceMatrix.h"
#include "connected_components.h"




void DFSUtil(IncidenceMatrix& graph, int v, bool visited[])
{
	visited[v] = true;

	std::vector<int> adj = graph.adjForTop(v);
	std::vector<int>::iterator i;
	for (i = adj.begin(); i != adj.end(); ++i)
	{
		if (!visited[*i])
		{
			std::cout << v << ", ";
			DFSUtil(graph, *i, visited);
		}
	}
}



bool isConnected(IncidenceMatrix& graph, std::vector<int>& result)
{
	bool* visited = new bool[graph.getTop()];
	std::vector<int> adj;
	int i;
	for (i = 0; i < graph.getTop(); i++)
	{
		visited[i] = false;
	}
	for (i = 0; i < graph.getTop(); i++)
	{
		adj = graph.adjForTop(i);
		if (adj.size() != 0)
		{
			break;
		}
	}
	if (i == graph.getTop())
	{
		return true;
	}
	DFSUtil(graph, i, visited);
	for (i = 0; i < graph.getTop(); i++)
	{
		if (visited[i] == false && adj.size() > 0)
		{
			return false;
		}
	}
	return true;
}

std::vector<int> isEulerGraph(IncidenceMatrix& graph) {
	std::vector<int> result;
	std::vector<int> adj;
	if (isConnected(graph, result)){
		return result;	
	}
	else {
		std::cout << "Nie udalo sie";
		return result;
	}
}





IncidenceMatrix* createEulerGraph() {
	srand(static_cast<unsigned int>(time(NULL)));
	int a, b;
	bool status = true;
	std::vector<int> sequence;
	IncidenceMatrix* seq;
	IncidenceMatrix* rewrited;
	std::vector<int> largestComp;



	do {
		b = randomint(10, 12);

		while (sequence.size()) sequence.erase(sequence.begin());
		for (int i = 0; i < b; i++) {
			a = randomint(1, 4);
			a = a * 2;
			sequence.push_back(a);
		}
		
		if (checkIfSequenceIsGraphic(sequence)) {
			seq = new IncidenceMatrix(sequence);
			largestComp = findTheLargestConnectedComponent(IncidenceMatrix(sequence));
			for (int i = 0; i < static_cast<int>(largestComp.size()); i++)
				std::cout << largestComp[i] << ", ";
			std::cout << std::endl;

			rewrited = new IncidenceMatrix(b, largestComp.size());
			int x, y;
			for (unsigned int i = 0; i < largestComp.size(); i++) {
				seq->getTopsOfEdge(largestComp[i], x, y);
				rewrited->setTopsOfEdge(i, x, y);
			}
			delete seq;
			for (int j = 0; j < rewrited->getTop(); j++) {
				std::vector<int> temp = rewrited->adjForTop(j);
				if (temp.size()%2==1) {
					status = true;
					delete rewrited;
					break;
				}
				else status = false;
			}
			
		}
		else status = true;

	} while (status);
	
	rewrited->printEntireMatrix();

	std::vector<int> toDelete;
	for (int i = 0; i < rewrited->getTop(); i++) {
		std::vector<int> temp = rewrited->adjForTop(i);
		if (temp.size() == 0) {
			toDelete.push_back(i);
		}
	}
	//std::cout <<"size "<< toDelete.size() << std::endl;
	for (int i = toDelete.size() - 1; i >= 0; i--) {
		//std::cout << "usuwam numer " << toDelete[i] << std::endl;
		rewrited->deleteTop(toDelete[i]);
	}

	rewrited->printEntireMatrix();
	return rewrited;
}


/*
0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0
0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1
0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0
0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0
1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0
1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1
0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0
*/


/*
0  0  0  0  1  0  1  0  0  0  0
0  1  0  0  0  0  0  1  0  0  0
0  0  0  0  0  0  0  0  0  1  1
1  1  0  1  0  0  1  0  1  0  1
0  0  0  1  0  1  0  0  0  0  0
1  0  1  0  1  1  0  1  0  1  0
0  0  1  0  0  0  0  0  1  0  0
*/


/*
0  0  1  0  0  1  0  0  0  0  0
0  0  0  0  0  0  1  0  0  1  0
0  0  0  1  0  0  0  1  0  0  0
0  1  0  0  1  0  0  0  0  0  0
1  1  0  0  0  1  0  1  1  1  0
1  0  1  1  1  0  1  0  0  0  1
0  0  0  0  0  0  0  0  1  0  1
*/