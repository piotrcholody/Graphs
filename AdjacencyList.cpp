#include <iostream>
#include <limits>
#include "AdjacencyList.h"
#include "IncidenceMatrix.h"

AdjacencyList::AdjacencyList() {}
/******************************************************************/
AdjacencyList::AdjacencyList(const IncidenceMatrix& matrix) {
	int vertex_one, vertex_two;
	for (int i = 0; i < matrix.getEdge(); ++i) {
		matrix.getTopsOfEdge(i, vertex_one, vertex_two);
		addNeighbours(vertex_one, vertex_two);
	}
}
/******************************************************************/
void AdjacencyList::initList() {
	int number;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

	std::cout << "Podaj liczbę wierzchołków: ";
	std::cin >> number;
	for (int vert = 1; vert <= number; ++vert) {
		_vertTable.push_back(std::vector< int >());
		_vertTable[vert - 1].push_back(vert);
		std::cout << "Stworzyłem kolejną listę dla wierzchołka: " << _vertTable[vert - 1][0] << std::endl;
	}
	getList();
}
/******************************************************************/
void AdjacencyList::initList(int number) {
	for (int vert = 1; vert <= number; ++vert) {
		_vertTable.push_back(std::vector< int >());
		_vertTable[vert - 1].push_back(vert);
		std::cout << "Stworzyłem kolejną listę dla wierzchołka: " << _vertTable[vert - 1][0] << std::endl;
	}
	getList();
}
/******************************************************************/
void AdjacencyList::addNeighbours(int vertex_one, int vertex_two) {
	if (isThisVert(vertex_one) && isThisVert(vertex_two)) {
		if (isAddingNeighbourPossible(vertex_one, vertex_two) && isAddingNeighbourPossible(vertex_two, vertex_one)) {
			_vertTable[vertex_one - 1].push_back(vertex_two);
			_vertTable[vertex_two - 1].push_back(vertex_one);
		}
	}
}
/******************************************************************/
bool AdjacencyList::isAddingNeighbourPossible(int vert, int toAdd) {
	if (!(toAdd != _vertTable[vert][0] && toAdd <= (int)_vertTable.size() && toAdd > 0))
		return 0;
	for (int i = 0; i < (int)_vertTable[vert].size(); ++i) {
		if (toAdd == _vertTable[vert][i])
			return 0;
	}
	return 1;
}		
/******************************************************************/
void AdjacencyList::getGraph(int counter) {
	int temp;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');

	std::cout << "Wpisz sąsiadów wierzchołka: " << _vertTable[counter][0] << std::endl;

	std::cout << "Wpisz jego sąsiadów: ";
	while (std::cin >> temp) {
		if (isAddingNeighbourPossible(counter, temp))
			_vertTable[counter].push_back(temp);
	}

	if (_vertTable[counter].size() > 1) {	
		std::cout << "Dodano następujących sąsiadów do wierzchołka nr " << _vertTable[counter][0] << ": " << std::endl;
		for (int i = 1; i < (int)_vertTable[counter].size(); ++i) {
			std::cout << _vertTable[counter][i] << "  " << std::endl;
		}
	}
	else
		std::cout << "Nie dodano żadnych sąsiadów do wierzchołka nr " << _vertTable[counter][0] << std::endl;
}
/*******************************************************************/
void AdjacencyList::getList() {
	for (int i = 0; i < (int)_vertTable.size(); ++i) {
		getGraph(i);
	}
	fillList();
}
/******************************************************************/
void AdjacencyList::fillList() {
	int temp;
	for (int j = 0; j < (int)_vertTable.size(); ++j) {
		temp = (int)_vertTable[j].size();
		for (int k = 1; k < temp; ++k) {
			/*UWAGA isThisVal pobiera wartość czyli np.
			  2 jako sąsiada, a wartość
			  != indeks w tablicy
			*/
			if (!(isThisVal(_vertTable[j][k], _vertTable[j][0])))
				_vertTable[_vertTable[j][k] - 1].push_back(j + 1);
		}
	}
}
/******************************************************************/
void AdjacencyList::showList() {
	for(int i = 0; i < (int)_vertTable.size(); ++i) {
		std::cout << "Wierzchołek nr: " << _vertTable[i][0] << std::endl;
		std::cout << "Sąsiedzi: ";
		for(int j = 1; j < (int)_vertTable[i].size(); ++j) {
			std::cout << _vertTable[i][j];
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}
/******************************************************************/
std::vector< std::vector<int> > AdjacencyList::retAdjacencyList() const{
	if(_vertTable.size())
		return _vertTable;
	else
		std::cout << "Aby zwrócić listę należy najpierw ją utworzyć" << std::endl;
	return _vertTable;
}	
/******************************************************************/
int AdjacencyList::isThisVal(int vert, int val) {
	for(int i = 1; i < (int)_vertTable[vert - 1].size(); ++i) {
		if(_vertTable[vert - 1][i] == val)
			return i;
	}
	return 0;
}
/******************************************************************/
bool AdjacencyList::isThisVert(int vert) {
	if (vert <= (int)_vertTable.size())
		return 1;
	return 0;
}
/******************************************************************/
bool AdjacencyList::delEdge (int vert1, int vert2) {
	if (isThisVal( vert1, vert2 )) {
		_vertTable[vert1 - 1].erase(_vertTable[vert1 - 1].begin() + isThisVal(vert1, vert2));
		_vertTable[vert2 - 1].erase(_vertTable[vert2 - 1].begin() + isThisVal(vert2, vert1));
		return 1;
	}
	return 0;
}
/******************************************************************/
int AdjacencyList::getL() {
	int counter = 0;
	for (int i = 0; i < (int)_vertTable.size(); ++i)
		counter += _vertTable[i].size();
	return counter / 2;
}
/******************************************************************/
int AdjacencyList::maxL() {
	int max = 0;
	for (int i = 0; i < (int)_vertTable.size() && max != (int)_vertTable.size(); i++) {
		if ((int)_vertTable[i].size() > max)
			max = _vertTable[i].size();

	}
	return max;
}
/******************************************************************/
