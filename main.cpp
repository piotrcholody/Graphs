#include <cstdlib>
#include <iostream>
#include <ctime>
#include "main.h"

int main( void ){
	
	IncidenceMatrix dohamiltona(6, 9);
	dohamiltona.setEntireMatrixFromFile("Plik1.txt", 6, 9);
	dohamiltona.printEntireMatrix();
	std::cout << "____ma byc hamiltonowski" << std::endl;
	int* rpath = dohamiltona.findHamiltionianGraph();
	delete[] rpath;
	
	
	IncidenceMatrix dohamiltona2(6, 8);
	dohamiltona2.setEntireMatrixFromFile("Plik2.txt", 6, 8);
	dohamiltona2.printEntireMatrix();
	std::cout << "____ma byc POLhamiltonowski" << std::endl;
	int* rpath2 = dohamiltona2.findHamiltionianGraph();
	delete[] rpath2;
	
	IncidenceMatrix dohamiltona3(6, 6);
	dohamiltona3.setEntireMatrixFromFile("Plik3.txt", 6, 6);
	dohamiltona3.printEntireMatrix();
	std::cout << "____ma byc hamiltonowski" << std::endl;
	int* rpath3 = dohamiltona3.findHamiltionianGraph();
	delete[] rpath3;
	
	IncidenceMatrix dohamiltona4(6, 5);
	dohamiltona4.setEntireMatrixFromFile("Plik4.txt", 6, 5);
	dohamiltona4.printEntireMatrix();
	std::cout << "____ma byc POLhamiltonowski" << std::endl;
	int* rpath4 = dohamiltona4.findHamiltionianGraph();
	delete[] rpath4;
	
	IncidenceMatrix dohamiltona5(2, 1);
	dohamiltona5.setTopsOfEdge(0, 0, 1);
	dohamiltona5.printEntireMatrix();
	int* rpath5 = dohamiltona5.findHamiltionianGraph();
	delete[] rpath5;

	IncidenceMatrix dohamiltona6(6, 7);
	dohamiltona6.setEntireMatrixFromFile("Plik6.txt", 6, 7);
	dohamiltona6.printEntireMatrix();
	std::cout << "_____ma byc POLhamiltonowski" << std::endl;
	int* rpath6 = dohamiltona6.findHamiltionianGraph();
	delete[] rpath6;

	IncidenceMatrix dohamiltona7(3, 1);
	dohamiltona7.setTopsOfEdge(0, 0, 1);
	dohamiltona7.printEntireMatrix();
	int* rpath7 = dohamiltona7.findHamiltionianGraph();
	delete[] rpath7;
	
	IncidenceMatrix dohamiltona8(6, 5);
	dohamiltona8.setEntireMatrixFromFile("Plik7.txt", 6, 5);
	dohamiltona8.printEntireMatrix();
	std::cout << "_____ma byc POLhamiltonowski" << std::endl;
	int* rpath8 = dohamiltona8.findHamiltionianGraph();
	delete[] rpath8;

	/*
	std::cout << "Tworzenie macierzy konstruktorem pytajacym o wymiary macierzy" << std::endl;
	IncidenceMatrix imatrix(1432432);
	imatrix.setGraphType(0);
	std::cout << "setEntireMatrix...() zwraca: " << imatrix.setEntireMatrixByColumns() << std::endl;
	imatrix.printEntireMatrix();
	std::cout << "edgeIndexExist(0) zwraca: " << imatrix.edgeIndexExist(0) << std::endl;
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

	
	/* juz nieaktualne
	//Testy przedstawienia grafu za pomocą macierzy połączeń:
	ConnectionMatrix<int> *testCM = NULL;
	try {
		testCM = new ConnectionMatrix<int>();
		std::cout << *testCM << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	*/

	/*
	//Testy przedstawienia grafu losowego podajac liczbe krawedzi:
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

	std::cout << test -> maxL() << std::endl;
	
	//Testy przedstawienia listy za pomocą macierzy połączeń:
	ConnectionMatrix<int> *testAL_CM = NULL;
	testAL_CM = new ConnectionMatrix<int>(*test);
	std::cout << *testAL_CM << std::endl;
	


	delete testKG;
	delete testPG;
	//delete testCM;
	delete testAL_CM;
	delete test;
	
	
	//Przejscie z Macierzy Polaczen na Macierz Incydencji
	ConnectionMatrix<int> testconn;
	std::cout << testconn << std::endl;
	IncidenceMatrix testinci(testconn);
	testinci.printEntireMatrix();
	
	*/
	
	getchar();
	return 0;
}
