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
			int rmax = (int)b / 2;
			if (rmax > 8)
				rmax = 8;
			a = randomint(2, rmax);
			//a = a * 2;
			sequence.push_back(a);
		}
		
		if (checkIfSequenceIsGraphic(sequence)) {
			seq = new IncidenceMatrix(sequence);
            largestComp = findTheLargestConnectedComponent(*seq);
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
/*IncidenceMatrix* createUndirectedEulerGraph() {
	int min = 10, max = 12;
	return createUndirectedEulerGraph(min, max);
}*/
/******************************************************************/

std::vector<int> findCycleInUndirectedEuler(IncidenceMatrix& original) {
	if (isUndirectedEulerGraph(original) != 2) {
		std::cout << "Nie ma sciezki Eulera, poniewaz graf nie jest Eulerowski" << std::endl;
		return std::vector<int>();
	}
	else {
		IncidenceMatrix graph(original);
		std::vector<std::vector<int>> result;
		result.push_back(std::vector<int>()); //obsluga petli
		std::vector<int> visited;
		int edge = graph.getEdge();
		int added = 0;
		int cand;
		int best;
		int bestsize;
		int loopcount = 0; //liczy petle ktorych nie udalo sie polaczyc za pierwszym razem
		bool correct = true;
		if (!added) {
			result[loopcount].push_back(0);
			int last = 0;
			int current = 0;
			while (added < edge) {
				std::vector<int> temp = graph.adjForTop(current);
				for (int i = 0; i < temp.size(); i++) {
					cand = temp[i];
					if (i == 0) { best = cand; bestsize = static_cast<int>(graph.adjForTop(cand).size()); }
					//std::cout << "For na i==" << i << std::endl;
					correct = true;
					for (int j = 0; j < visited.size(); j++) {
						cand = temp[i];
						//std::cout << "For na j==" << j << ";  temp[" << i << "]==" << cand << ", visited[" << j << "]==" << visited[j] << std::endl;
						//std::cout << "graph.whichEdge(temp[i], current) == " << graph.whichEdge(cand, current) << std::endl;
						if (graph.whichEdge(cand, current) == visited[j]) {
							correct = false;
						}
						if (graph.adjForTop(cand).size() == 1)
							correct = false;
					}
					if (correct) {
						if (graph.adjForTop(cand).size() > bestsize) {
							//std::cout << "stary bestsize==" << bestsize << std::endl;
							bestsize = static_cast<int>(graph.adjForTop(cand).size());
							best = cand;
						}
					}
				}
				last = current;
				current = best;
				if (graph.whichEdge(last, current) >= 0) {
					result[loopcount].push_back(current);
					visited.push_back(graph.whichEdge(last, current));
					//std::cout << "push bestsize==" << bestsize << std::endl;
					//std::cout << "_______Push:" << current << ", Visited:" << graph.whichEdge(last, current) << std::endl;
					graph.resetTopsOfEdge(graph.whichEdge(last, current));
					added++;
				}
				else {
					std::vector<int> remains;
					for (int i = 0; i < graph.getTop(); i++) {
						if (graph.adjForTop(i).size() > 0)
							remains.push_back(i);
					}
					int linker = -1;
					for (int i = 0; i < remains.size() && linker < 0; i++) {
						int j = 0;
						while (j < result[loopcount].size()) {
							if (result[loopcount][j] == remains[i]) {
								linker = result[loopcount][j]; //ten wierzcholek jest lacznikiem miedzy mniejszymi cyklami
								current = linker;
								last = result[loopcount][j - 1];
								result.push_back(std::vector<int>());
								loopcount++;
								break;
							}
							j++;
						}
					}
				}
			}


			std::cout << "Visited Edges: ";
			for (int i = 0; i < visited.size(); i++) {
				std::cout << visited[i] << ",";
			}
			std::cout << "\nResult: ";
			for (int i = 0; i < result.size(); i++) {
				if(i != 0)	std::cout << "\n____Next circle: ";
				for (int j = 0; j < result[i].size(); j++)
					std::cout << result[i][j] << ",";
			}
			std::cout << std::endl;
			graph.printEntireMatrix();
			std::cout << "Jesli powyzsza macierz nie ma samych zer; cos poszlo nie tak" << std::endl;
		}
		
		//polacz resulty
		std::vector<int> cycle;
		cycle.insert(cycle.begin(), result[0].begin(), result[0].end());
		
		for (int i = 1; i < result.size(); i++) {
			int shift = 0;
			int linker = result[i][result[i].size() - 1];
			int j = 0;
			while (shift == 0) {
				if (cycle[j] == linker)
					shift = j + 1;
				j++;
			}
			std::cout << "shift: "<<shift << std::endl; //!!!!!!!!!!!!!!!!!!!!!!
			std::vector<int>::iterator where;
			where = cycle.begin() + shift;

			cycle.insert(where, result[i].begin(), result[i].end());

		}
		
		std::cout << "\nPolaczony cykl: ";
		for (int i = 0; i < cycle.size(); i++) {
			std::cout << cycle[i] << ",";
		}
		std::cout<<std::endl;
		return cycle;
	}
}
