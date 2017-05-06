#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "IncidenceMatrix.h"
#include <cmath>
#include <cstdlib>
#include <vector>




//Depth First Search Utility for All Connected Components
//przeszukiwanie w glab
void DFSUtilForACC(IncidenceMatrix& graph, int v, bool visited[], std::vector<int>& actualComponent)
{
	visited[v] = true;
	actualComponent.push_back(v); //dodawanie wierzcholka do skladowej
	std::cout << "DFS( pushed v==" << v << std::endl;
	std::vector<int> adjForV = graph.adjForTop(v);

	std::vector<int>::iterator i;
	for (i = adjForV.begin(); i != adjForV.end(); ++i)
		if (!visited[*i]) {
			DFSUtilForACC(graph, *i, visited, actualComponent);
		}
}
/******************************************************************/

	//znajduje wszystkie spojne skladowe i zwraca je w postaci dwuwymiarowego vectora
std::vector<std::vector<int>> findAllConnectedComponents(IncidenceMatrix& graph) {
	std::vector<std::vector<int>> allCC;
	bool *visited = new bool[graph.getTop()];
	for (int v = 0; v < graph.getTop(); v++)
		visited[v] = false;
	int ilosc = 0;
	for (int v = 0; v < graph.getTop(); v++) {
		if (visited[v] == false) {
			std::cout << "Skladowa numer: v==" << v << std::endl;
			allCC.push_back(std::vector< int >()); //dodawanie kolejnych skladowych
			DFSUtilForACC(graph, v, visited, allCC[ilosc]);
			ilosc++;
		}
	}
	delete[] visited;
	return allCC;
}
/******************************************************************/

	//znajduje najwieksza spojna skladowa i zwraca ja w postaci vectora
std::vector<int> findTheLargestConnectedComponent(IncidenceMatrix & graph) {
	std::vector<std::vector<int>> temp = findAllConnectedComponents(graph);
	unsigned int max = 0, index = 0;
	for (unsigned int i = 0; i < temp.size(); i++) {
		if (max < temp[i].size()) {
			max = static_cast<unsigned int>(temp[i].size());
			index = i;
		}
	}

	//tylko wypisanie w konsoli:
	std::cout << "Zwracany vektor: ";
	for (unsigned int i = 0; i < temp[index].size(); i++) {
		std::cout << temp[index][i] << ", ";
	}
	std::cout << std::endl;

	return temp[index];
}
/******************************************************************/
