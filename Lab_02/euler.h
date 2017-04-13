#pragma once

#include <iostream>
#include <vector>
#include "IncidenceMatrix.h"
#include "connected_components.h"

	//zwraca 2 gdy jest Eulerowski i posiada cykl Eulera
	//zwraca 1 gdy jest Poleulerowski i posiada sciezke Eulera
	//zwraca 0 gdy nie jest Eulerowski
int isUndirectedEulerGraph(IncidenceMatrix& original){
	IncidenceMatrix graph(original);
	std::vector<int> toDelete;
	for (int i = 0; i < graph.getTop(); i++) {
		std::vector<int> temp = graph.adjForTop(i);
		if (temp.size() == 0) {
			toDelete.push_back(i);
		}
	}
	std::cout <<"Wierzcholkow izolowanych jest: "<< toDelete.size() << std::endl;
	for (int i = toDelete.size() - 1; i >= 0; i--) {
		//std::cout << "usuwam numer " << toDelete[i] << std::endl;
		graph.deleteTop(toDelete[i]);
	}
	int odd = 0;
	for (int i = 0; i < graph.getTop(); i++) {
		std::vector<int> temp = graph.adjForTop(i);
		if (temp.size()%2 == 1)
			odd += 1;
	}
	bool isCC = false;
	std::vector<int> largestComp = findTheLargestConnectedComponent(graph);
	if (largestComp.size() == graph.getTop())
		isCC = true;
	if (isCC) {
		if (odd == 0) {
			std::cout << "Graf jest Eulerowski; posiada cykl Eulera" << std::endl;
			return 2;
		}
		if (odd <= 2) {
			std::cout << "Graf jest Poleulerowski; posiada sciezke Eulera" << std::endl;
			return 1;
		}
		if (odd > 2) {
			std::cout << "Graf nie jest Eulerowski, ani Poleulerowski, poniewaz ma wiecej niz 2 wierzcholki o stopniu wiekszym niz 2" << std::endl;
			return 0;
		}
	}
	else {
		std::cout << "Graf nie jest Eulerowski ani Poleulerowski, gdyz mimo wyrzucenia wierzcholkow izolowanych ma wiecej niz jedna spojna skladowa" << std::endl;
		return 0;
	}
	return 0;
}


/******************************************************************/

	//zwraca losowy Eulerowski graf nieskierowany 
	//min i max oznaczaja zakres z jakiego losowane jest ilosc wierzcholkow
	//jednak nie uwzglednia to wierzcholkow izolowanych, ktore zostana usuniete
IncidenceMatrix* createUndirectedEulerGraph(int min, int max) {
	if (!(min <= max && min >= 0 && max > 0)) {
		std::cout << "Podano zle wartosci do losowania ilosci wierzcholkow (pamietaj ze wierzcholki izolowane zostana usuniete)" << std::endl;
		std::cout << "Losuje z przedzialu (10, 12)" << std::endl;
		min = 10;
		max = 12;
	}
	srand(static_cast<unsigned int>(time(NULL)));
	int a, b;
	bool status = true;
	std::vector<int> sequence;
	IncidenceMatrix* seq;
	IncidenceMatrix* rewrited;
	std::vector<int> largestComp;

	do {
		b = randomint(min, max);

		while (sequence.size()) sequence.erase(sequence.begin());
		for (int i = 0; i < b; i++) {
			int rmax = (int)(max - 1) / 2;
			if (rmax > 8)
				rmax = 8;
			a = randomint(2, rmax);
			//a = a * 2;
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
/******************************************************************/

//zwraca losowy Eulerowski graf nieskierowany, zazwyczaj 5-7 wierzcholkow
IncidenceMatrix* createUndirectedEulerGraph() {
	int min = 10, max = 12;
	return createUndirectedEulerGraph(min, max);
}
/******************************************************************/




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