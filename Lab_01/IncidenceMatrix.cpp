#include "IncidenceMatrix.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
#include <limits>
#include <cstdlib>
 

/******************************************************************/
IncidenceMatrix::IncidenceMatrix(int numberOfTops, int numberOfEdges)
	:top(numberOfTops),
	edge(numberOfEdges)
{
	matrix = allocateMatrix(numberOfTops, numberOfEdges);
}
/******************************************************************/
IncidenceMatrix::IncidenceMatrix(const ConnectionMatrix<int>& conn)
{
	top = conn.getN();
	edge = conn.getL();
	matrix = allocateMatrix(top, edge);
	int i, j, e=0;
	for (i = 0; i < top; i++)
		for (j = i + 1; j < top; j++)
			if (conn(i, j) == 1) {
				setTopsOfEdge(e, i, j);
				e++;
			}
}
/******************************************************************/
bool IncidenceMatrix::setTopsOfEdge(int selectedEdge, int newOwner1, int newOwner2) {
	if (possibleEdge(newOwner1, newOwner2)) {
		if (edgeIndexExist(selectedEdge)) {
			if (!isThisEdgeFree(newOwner1, newOwner2)) {
				for (int t = 0; t < top; t++)
					matrix[t][selectedEdge] = 0;
				matrix[newOwner1][selectedEdge] = 1;
				matrix[newOwner2][selectedEdge] = 1;
				return 0;
			}
			else {
				std::cout << "setTopsOfEdge(" << selectedEdge << ", " << newOwner1 << ", " << newOwner2 << "): ";
				std::cout << "Taka krawedz juz istnieje! Nie zmieniono wierzcholkow!" << std::endl;
			}
		}
		else {
			std::cout << "setTopsOfEdge(" << selectedEdge << ", " << newOwner1 << ", " << newOwner2 << "): ";
			std::cout << "Indeks wierzcholka jest bledny!" << std::endl;
		}
	}
	else {
		std::cout << "setTopsOfEdge(" << selectedEdge << ", " << newOwner1 << ", " << newOwner2 << "): ";
		std::cout << "Podane indeksy nie stworza krawedzi!" << std::endl;
	}
	return 1;
}
/******************************************************************/
bool IncidenceMatrix::possibleEdge(int firstTop, int secondTop) const{
	return (firstTop < top && secondTop < top && firstTop >= 0 && secondTop >= 0 && firstTop != secondTop);
}
/******************************************************************/
bool IncidenceMatrix::isThisEdgeFree(int firstTop, int secondTop) const{
	if (possibleEdge(firstTop, secondTop)) {
		bool ValueOccured = false;
		for (int e = 0; e < edge; e++) {
			if (matrix[firstTop][e] == 1 && matrix[secondTop][e] == 1) {
				ValueOccured = true;
			}
		}
		return ValueOccured;
	}
	else
		return true;
}
/******************************************************************/
bool IncidenceMatrix::edgeIndexExist(int questionedEdge) const {
	return ((questionedEdge < this->edge) && (questionedEdge >= 0));
}
/******************************************************************/
bool IncidenceMatrix::deleteEdge(int unwantedEdge) {
	if (edgeIndexExist(unwantedEdge)) {
		int** temp = allocateMatrix(top, edge - 1);
		int e;
		for (int t = 0; t < top; t++) {
			for (e = 0; e < unwantedEdge; e++) {
				temp[t][e] = matrix[t][e];
			}
			for (e = unwantedEdge; e < edge - 1; e++) {
				temp[t][e] = matrix[t][e+1];
			}
			delete[] matrix[t];
		}
		delete[] matrix;
		matrix = temp;
		edge--;
		return 0;
	}
	else return 1;
}
/******************************************************************/
bool IncidenceMatrix::addNewEdge(int newOwner1, int newOwner2) {
	if (possibleEdge(newOwner1, newOwner2)) {
		if (!isThisEdgeFree(newOwner1, newOwner2)) {
			int** temp = allocateMatrix(top, edge + 1);
			for (int t = 0; t < top; t++) {
				for (int e = 0; e < edge; e++) {
					temp[t][e] = matrix[t][e];
				}
				delete[] matrix[t];
				temp[t][edge] = 0;
			}
			delete[] matrix;
			temp[newOwner1][edge] = 1;
			temp[newOwner2][edge] = 1;
			matrix = temp;
			edge++;
			return 0;
		}
		else {
			std::cout << "addNewEdge(" << newOwner1 << ", " << newOwner2 << "):";
			std::cout << "Nie moge dodac takiej krawedzi! Taka juz istnieje!" << std::endl;
			return 1;
		}
	}
	else {
		std::cout << "addNewEdge(" << newOwner1 << ", " << newOwner2 << "):";
		std::cout << "Podane indeksy nie moga stworzyc krawedzi!" << std::endl;
		return 1;
	}
}
/******************************************************************/
bool IncidenceMatrix::setEntireMatrixByRows() {
	std::cout<<"\nWpisuj kolejne pola oddzielajac enterem \n";
	std::cout<<"Wprowadzasz wierszami (czyli 1 gdy do danego wierzcholka ma nalezec iterowana krawedz) \n";
	int temp, t, e;
	for (t = 0; t < top; t++) {
		std::cout<<"Wiersz numer "<<t<<": \n";
		for (e = 0; e < edge; e++) {
			cinSelectedInt(temp);
			if ((temp == 0) || (temp == 1))
				matrix[t][e] = temp;
			else {
				std::cout << "Mozesz wpisac tylko 0 lub 1. Wpisz liczbe ponownie: ";
				e--;
			}
		}
		std::cout<<std::endl;
	}
	bool errorOccured = eliminateAllMistakes();
	if (errorOccured)
		std::cout<<"\nMacierz byla zle wpisana. Naprawiono bledy."<<std::endl;
	return errorOccured;
}
/******************************************************************/
bool IncidenceMatrix::eliminateInvalidEdges() {
	bool errorOccured = false;
	int counter, e, t, isnot01;
	if (edge > 0) {
		for (e = edge - 1; e >= 0; e--) {
			counter = isnot01 = 0;
			for (t = 0; t < top; t++) {
				if (matrix[t][e])
					counter++;
				if (matrix[t][e] > 1)
					isnot01++;
			}
			if (counter != 2) {
				deleteEdge(e);
				std::cout << "Pozbyto sie krawedzi o indeksie " << e;
				std::cout << ": nalezala do blednej liczby wierzcholkow" << std::endl;
				errorOccured = true;
			}
			else if (isnot01) {
				deleteEdge(e);
				std::cout << "Pozbyto sie krawedzi o indeksie " << e;
				std::cout << ": posiadala w reprezentacji liczby wieksze niz 1" << std::endl;
				errorOccured = true;
			}
		}
	}
	if (errorOccured)
		std::cout << "!!!Zmieniono numeracje krawedzi z powodu usuniecia blednych krawedzi!" << std::endl;
	return errorOccured;
}
/******************************************************************/
bool IncidenceMatrix::getTopsOfEdge(int selectedEdge, int& first, int& second) const {
	first = second = -2137;
	if (!edgeIndexExist(selectedEdge)) {
		std::cout << "getTopsOfEdge(" << selectedEdge << ", ..., ...): Krawedz nie istnieje!!!" << std::endl;
		std::cout << "Pobranie wierzcholkow nie powiodlo sie!" << std::endl;
		return true;
	}
	else {
		int counter = 0;
		for (int t = 0; t < top; t++) {
			if (matrix[t][selectedEdge]) {
				if (counter == 0) {
					first = t;
					counter++;
				}
				else {
					if (counter == 1) {
						second = t;
						counter++;
					}
					else {
						std::cout << "Korzystasz z popsutej macierzy incydencji! Nie mozesz pobrac wierzcholkow!" << std::endl;
						std::abort();
					}
				}
			}
		}
		if (counter <= 1) {
			std::cout << "Korzystasz z popsutej (pustej) macierzy incydencji! Nie mozesz pobrac wierzcholkow!" << std::endl;
			std::abort();
		}
		if (second > first) { //obsula digrafu
			int temp;
			temp = first;
			first = second;
			second = temp;
		}
		return false;
	}
}
/******************************************************************/
bool IncidenceMatrix::eliminateDuplicates() {
	bool errorOccured = false;
	if (edge >= 1) {
		int e, k, index1, index2, EdgeOccured;
		for (e = edge - 1; e >= 1; e--) {
			getTopsOfEdge(e, index1, index2);
			k = e - 1;
			EdgeOccured = false;
			while (k >= 0 && !EdgeOccured) {
				if (matrix[index1][k] == 1 && matrix[index2][k] == 1)
					EdgeOccured = true;
				k--;
			}
			if (EdgeOccured) {
				deleteEdge(e);
				errorOccured = true;
				std::cout << "Usunieto zmultiplikowana krawedz o indeksie " << e << std::endl;
			}
		}
	}
	return errorOccured;
}
/******************************************************************/
bool IncidenceMatrix::eliminateAllMistakes() {
	bool x = eliminateInvalidEdges();
	bool y = eliminateDuplicates();
	return (x || y);
}
/******************************************************************/
IncidenceMatrix::~IncidenceMatrix(){
	for(int i=0;i<top;i++)
		delete [] matrix[i];
	delete [] matrix;
}
/******************************************************************/
void IncidenceMatrix::printEntireMatrix() const{
	std::cout<<"\nMacierz Incydencji: "<<std::endl;
	if (edge) {
		int edgelenght = (int)log10(edge) + 1;
		int toplenght = (int)log10(top) + 1;
		for (int j = 0; j < toplenght + 2; j++) std::cout << " ";
		for (int e = 0; e < edge; e++) std::cout << "E" << e << " "; std::cout << std::endl;
		for (int t = 0; t < top; t++) {
			
			int actualtoplenght = (int)log10(t) + 1;
			if (actualtoplenght < 0) actualtoplenght = 1;
			std::cout << t;
			for (int i = 0; i <= toplenght-actualtoplenght; i++) std::cout << " ";
			std::cout << "|";
			for (int e = 0; e < edge; e++) {
				int actualedgelenght = (int)log10(e+1) + 1;
				if (actualedgelenght < 0) actualedgelenght = 1;
				if (matrix[t][e] >= 0)
					std::cout << " " << matrix[t][e] << " ";
				else
					std::cout << "" << matrix[t][e] << " ";
				for (int i = 0; i < actualedgelenght - 1; i++) std::cout << " ";
			}
			std::cout << "|" << std::endl;
		}
	}
	else std::cout << " nie posiada wierzcholkow!" << std::endl;
}
/******************************************************************/
bool IncidenceMatrix::setEntireMatrixFromFile(const char* Filename, int numberOfTops, int numberOfEdges) {
	std::ifstream mystream;
	if (top == numberOfTops && edge == numberOfEdges) {
		mystream.close();
		mystream.open(Filename, std::ios::in); ///drugi argument == read-only mode
		if (!mystream.is_open()) {
			std::cout << "Odmowa dostepu lub nie ma pliku o tej nazwie!" << std::endl;
			mystream.clear();
			mystream.close();
		}
		else {
			int i, j, error=0;
			for (i = 0; i < top; i++) {
				for (j = 0; j < edge; j++)
					if (!(mystream >> matrix[i][j]))
						error++;
			}
			if (i == top && j == edge && error == 0) {
				std::cout << "\nPlik zostal wczytany poprawnie; sprawdzam bledy w reprezentacji..." << std::endl;
				if (!eliminateAllMistakes()) {
					std::cout << "W reprezentacji nie bylo zadnych bledow." << std::endl;
				}
				else {
					std::cout << "W reprezentacji byly bledy; plik zle wczytany; wylaczam program!" << std::endl;
					std::abort();
				}
				return 0;
			}
			else {
				std::cout << "Nie ustawiono calej macierzy!" << std::endl;
			}
		}
	}
	else {
		std::cout << "Wczytywanie z pliku nie powiodlo sie gdyz ";
		std::cout << "zaalokowana pamiec nie zgadza sie z podanymi wymiarami" << std::endl;
	}
	mystream.clear();
	mystream.close();
	return 1;
}
/******************************************************************/





/******************************************************************/
/*Funkcje spoza klasy IncidenceMatrix*/
/******************************************************************/

bool cinSelectedInt(int& destination) {
	int temp;
	std::cin >> temp;
	if (!std::cin) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		destination = -2137;
		return false;
	}
	else {
		destination = temp;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}
}
/******************************************************************/
int randomint(int A, int B) {
	return (int)((double)rand() / (RAND_MAX + 1.0)*(B - A + 1) + A);
}
/******************************************************************/
int** allocateMatrix(int top, int edge) {
	int** matrix = new int*[top];
	for (int t = 0; t < top; t++) {
		matrix[t] = new int[edge];
		for (int e = 0; e < edge; e++)
			matrix[t][e] = 0;
	}
	return matrix;
}
/******************************************************************/