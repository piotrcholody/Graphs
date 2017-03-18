#include <iostream>
#include "IncidenceMatrix.h"
#include "vld.h"

IncidenceMatrix::IncidenceMatrix(int numberOfTops, int numberOfEdges)
	:top(numberOfTops),
	edge(numberOfEdges) {
	matrix = new int*[top];
	for (int t = 0; t < top; t++) {
		matrix[t] = new int[edge];
		for (int e = 0; e < edge; e++)
			matrix[t][e] = 0;
	}
}


IncidenceMatrix::IncidenceMatrix()
	:top(1),
	edge(0) {
	while (top <= 1) {
		std::cout << "Podaj ilosc wierzcholkow (liczbe >= 2): ";
		cinSelectedInt(top);
	};
	while (edge <= 0) {
		std::cout << "Podaj ilosc wszystkich krawedzi (liczbe >=1): ";
		cinSelectedInt(edge);
	};
	matrix = new int*[top];
	for (int t = 0; t < top; t++) {
		matrix[t] = new int[edge];
		for (int e = 0; e < edge; e++)
			matrix[t][e] = 0;
	}
}

bool IncidenceMatrix::changeTopsOfEdge(int selectedEdge, int newOwner1, int newOwner2) {
	if (newOwner1 < top && newOwner2 < top && newOwner1 >= 0 && newOwner2 >= 0) {
		if (selectedEdge < edge && selectedEdge >= 0) {
			for (int t = 0; t < top; t++)
				matrix[t][selectedEdge] = 0;
			matrix[newOwner1][selectedEdge] = 1;
			matrix[newOwner2][selectedEdge] = 1;
			return 1;
		}
		else return 0;
	}
	else return 0;
}

bool IncidenceMatrix::addNewEdge(int newOwner1, int newOwner2) {
	if (newOwner1 < top && newOwner2 < top && newOwner1 >=0 && newOwner2 >= 0 ) {
		int** temp = new int*[top];
		for (int t = 0; t < top; t++) {
			temp[t] = new int[edge + 1];
			for (int e = 0; e < edge; e++) {
				temp[t][e] = matrix[t][e];
			}
			delete[] matrix[t];
			temp[t][edge] = 0;
			matrix[t] = temp[t];
		}
		delete[] matrix;
		temp[newOwner1][edge] = 1;
		temp[newOwner2][edge] = 1;
		matrix = temp;
		edge++;
		return 1;
	}
	else return 0;
}

bool IncidenceMatrix::setEntireMatrix(){
	std::cout<<"\nWpisuj kolejne pola oddzielając enterem \n";
	std::cout<<"Wprowadzasz wierszami, w ktorych sa punkty \n";
	int temp;
	for(int t=0;t<top;t++){
		std::cout<<"Wiersz numer "<<t+1<<": \n";
		for(int e=0;e<edge;e++){
				cinSelectedInt(temp);
			if ((temp==0) ^ (temp==1))
				matrix[t][e]=temp;
			else{
				std::cout<<"Mozesz wpisac tylko 0 lub 1. Wpisz liczbe ponownie: ";
				e--;
			}
		}
		std::cout<<std::endl;
	}
	int counter;
	bool initializedCorrectly = true;
	for(int e=0;e<edge;e++){
		counter=0;
		for(int t=0;t<top;t++){
			if (matrix[t][e]==1)
				counter++;
		}
		if (counter!=2){
			std::cout<<"Przy wierzcholku E"<<e+1<<" znaleziono blad (suma kolumny musi byc 2)\n";
			initializedCorrectly = false;
		}
	}
	if (!initializedCorrectly)
		std::cout<<"\nMacierz zostala zle wpisana!"<<std::endl;
	return initializedCorrectly;
}



IncidenceMatrix::~IncidenceMatrix(){
	for(int i=0;i<top;i++)
		delete [] matrix[i];
		delete [] matrix;
}

void IncidenceMatrix::printEntireMatrix() const{
	std::cout<<"Macierz Indcydencji: "<<std::endl;
	std::cout<<"    ";
	for(int e=0;e<edge;e++) std::cout<<"E"<<e+1<<" "; std::cout<<std::endl;
	for(int t=0;t<top;t++){
		std::cout<<t+1<<" |";
		for(int e=0;e<edge;e++){
			std::cout<<" "<<matrix[t][e]<<" ";
		}
		std::cout<<"|"<<std::endl;
	}
}





bool cinSelectedInt(int& destination) {
	int temp;
	std::cin >> temp;
	if (!std::cin) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		destination = -2137;	//ustawia gdy wpiszesz napis
		return false;
	}
	else {
		destination = temp;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return true;
	}
}
