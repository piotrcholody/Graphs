#include <cstdlib>
#include <iostream>
#include <ctime>
#include "main.h"

int main( void ){

	/*
	std::cout << "Tworzenie macierzy konstruktorem domyslnym" << std::endl;
	IncidenceMatrix imatrix;
	imatrix.setGraphType(1);
	std::cout << "setEntireMatrix...() zwraca: " << imatrix.setEntireMatrixByColumns() << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.setTopsOfEdge(1, 0, 1) zwraca: " << imatrix.setTopsOfEdge(1, 0, 1) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.setTopsOfEdge(1, 100, 99) zwraca: " << imatrix.setTopsOfEdge(1, 100, 99) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.setTopsOfEdge(1, 1, 1) zwraca: " << imatrix.setTopsOfEdge(1, 1, 1) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.addNewEdge(0, 1) zwraca: " << imatrix.addNewEdge(0, 1) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.addNewEdge(1, 2) zwraca: " << imatrix.addNewEdge(1, 2) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.addNewEdge(10, 1) zwraca: " << imatrix.addNewEdge(10, 1) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.addNewEdge(0, 0) zwraca: " << imatrix.addNewEdge(0, 0) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.deleteEdge(0) zwraca: " << imatrix.deleteEdge(0) << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "imatrix.deleteEdge(100) zwraca: " << imatrix.deleteEdge(100) << std::endl;
	imatrix.printEntireMatrix();
	int x, y;
	std::cout << "imatrix.getTopsOfEdge(10, x, y) zwraca: " << imatrix.getTopsOfEdge(10, x, y) << std::endl;
	std::cout << "getTopsOfEdge(10, x, y): x: " << x << " y: " << y << std::endl;
	std::cout << "imatrix.getTopsOfEdge(0, x, y) zwraca: " << imatrix.getTopsOfEdge(0, x, y) << std::endl;
	std::cout << "getTopsOfEdge(0, x, y) x: " << x << " y: " << y << std::endl;
	std::cout << "imatrix.isThisEdgeFree(0, 1) zwraca: " << imatrix.isThisEdgeFree(0, 1) << std::endl;
	std::cout << "imatrix.isThisEdgeFree(2, 1) zwraca: " << imatrix.isThisEdgeFree(2, 1) << std::endl;
	std::cout << "imatrix.isThisEdgeFree(2, 3) zwraca: " << imatrix.isThisEdgeFree(2, 3) << std::endl;
	std::cout << "imatrix.isThisEdgeFree(0, 0) zwraca: " << imatrix.isThisEdgeFree(0, 0) << std::endl;
	std::cout << "imatrix.isThisEdgeFree(100, 100) zwraca: " << imatrix.isThisEdgeFree(100, 100) << std::endl;
	std::cout << "imatrix.isThisEdgeFree(0, 100) zwraca: " << imatrix.isThisEdgeFree(0, 100) << std::endl;
		
	

	IncidenceMatrix lmat(4, 4);
	lmat.setEntireMatrixFromFile("Plik1.txt", 4, 4);
	lmat.printEntireMatrix();
	
	*/
	srand(time(NULL));

	edgeGraph<int> *testKG = NULL;
	try {
		testKG = new edgeGraph<int>();
		std::cout << *testKG << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	//Testy przedstawienia grafu losowego podajac prawdopodobienstwo:
	probGraph<int> *testPG = NULL;
	try {
		testPG = new probGraph<int>();
		std::cout << *testPG << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	//Testy przedstawienia grafu za pomocą macierzy połączeń:
	ConnectionMatrix<int> *testCM = NULL;
	try {
		testCM = new ConnectionMatrix<int>();
		std::cout << *testCM << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	//Testy przedstawienia grafu za pomocą listy:
	AdjacencyList *test = new AdjacencyList();
	test -> initList();

	std::vector< std::vector < int > > temp;
	temp = test -> retAdjacencyList();

	std::cout << std::endl;	

	for( int i = 0; i < ( int )temp.size(); ++i ){
		for( int j = 0; j < ( int )temp[i].size(); ++j )
			std::cout << temp[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	test -> showList();
	
	//Testy przedstawienia listy za pomocą macierzy połączeń:
	ConnectionMatrix<int> *testAL_CM;
	testAL_CM = new ConnectionMatrix<int>(*test);
	std::cout << *testAL_CM << std::endl;

	delete testKG;
	delete testPG;
	delete testCM;
	delete testAL_CM;
	delete test;

	
	getchar();
	return 0;
}
