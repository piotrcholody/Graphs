#include <cstdlib>
#include <iostream>
#include <ctime>
#include "main.h"

int main( void ){
	
	IncidenceMatrix dohamiltona(6, 9);
	dohamiltona.setEntireMatrixFromFile("hamiltonTest/Plik1.txt", 6, 9);
	dohamiltona.printEntireMatrix();
	std::cout << "____ma byc hamiltonowski" << std::endl;
	int* rpath = dohamiltona.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona.getTop() + 1; i++) {
		std::cout << rpath[i];
		if (i < dohamiltona.getTop())
			std::cout << ",";
	}
	std::cout << std::endl;
	delete[] rpath;
	
	
	IncidenceMatrix dohamiltona2(6, 8);
	dohamiltona2.setEntireMatrixFromFile("hamiltonTest/Plik2.txt", 6, 8);
	dohamiltona2.printEntireMatrix();
	std::cout << "____ma byc POLhamiltonowski" << std::endl;
	int* rpath2 = dohamiltona2.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona2.getTop() + 1; i++) {
		std::cout << rpath2[i];
		if (i < dohamiltona2.getTop())
			std::cout << ",";
	}
	std::cout << std::endl;
	delete[] rpath2;
	
	IncidenceMatrix dohamiltona3(6, 6);
	dohamiltona3.setEntireMatrixFromFile("hamiltonTest/Plik3.txt", 6, 6);
	dohamiltona3.printEntireMatrix();
	std::cout << "____ma byc hamiltonowski" << std::endl;
	int* rpath3 = dohamiltona3.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona3.getTop() + 1; i++) {
		std::cout << rpath3[i];
		if (i < dohamiltona3.getTop())
			std::cout << ",";
	}
	std::cout << std::endl; 
	delete[] rpath3;
	
	IncidenceMatrix dohamiltona4(6, 5);
	dohamiltona4.setEntireMatrixFromFile("hamiltonTest/Plik4.txt", 6, 5);
	dohamiltona4.printEntireMatrix();
	std::cout << "____ma byc POLhamiltonowski" << std::endl;
	int* rpath4 = dohamiltona4.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona4.getTop() + 1; i++) {
		std::cout << rpath4[i];
		if (i < dohamiltona4.getTop())
			std::cout << ",";
	}
	std::cout << std::endl; 
	delete[] rpath4;
	
	IncidenceMatrix dohamiltona5(2, 1);
	dohamiltona5.setTopsOfEdge(0, 0, 1);
	dohamiltona5.printEntireMatrix();
	std::cout << "_____musi byc polhamiltonowski bo jest tylko jedna krawedz" << std::endl;
	int* rpath5 = dohamiltona5.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona5.getTop() + 1; i++) {
		std::cout << rpath5[i];
		if (i < dohamiltona5.getTop())
			std::cout << ",";
	}
	std::cout << std::endl; 
	delete[] rpath5;

	IncidenceMatrix dohamiltona6(6, 7);
	dohamiltona6.setEntireMatrixFromFile("hamiltonTest/Plik6.txt", 6, 7);
	dohamiltona6.printEntireMatrix();
	std::cout << "_____ma byc POLhamiltonowski" << std::endl;
	int* rpath6 = dohamiltona6.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona6.getTop() + 1; i++) {
		std::cout << rpath6[i];
		if (i < dohamiltona6.getTop())
			std::cout << ",";
	}
	std::cout << std::endl; 
	delete[] rpath6;

	IncidenceMatrix dohamiltona7(3, 1);
	dohamiltona7.setTopsOfEdge(0, 0, 1);
	dohamiltona7.printEntireMatrix();
	std::cout << "_____nie moze byc czymkolwiek z powodu ilosci wierzcholkow i krawedzi" << std::endl;
	int* rpath7 = dohamiltona7.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona7.getTop() + 1; i++) {
		std::cout << rpath7[i];
		if (i < dohamiltona7.getTop())
			std::cout << ",";
	}
	std::cout << std::endl;
	delete[] rpath7;
	
	IncidenceMatrix dohamiltona8(6, 5);
	dohamiltona8.setEntireMatrixFromFile("hamiltonTest/Plik7.txt", 6, 5);
	dohamiltona8.printEntireMatrix();
	std::cout << "_____ma byc POLhamiltonowski" << std::endl;
	int* rpath8 = dohamiltona8.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona8.getTop() + 1; i++) {
		std::cout << rpath8[i];
		if (i < dohamiltona8.getTop())
			std::cout << ",";
	}
	std::cout << std::endl; 
	delete[] rpath8;

	IncidenceMatrix dohamiltona9(6, 5);
	dohamiltona9.setEntireMatrixFromFile("hamiltonTest/Plik8.txt", 6, 5);
	dohamiltona9.printEntireMatrix();
	std::cout << "_____ma NIE BYC NICZYM" << std::endl;
	int* rpath9 = dohamiltona9.findHamiltionianGraph();
	for (int i = 0; i < dohamiltona9.getTop() + 1; i++) {
		std::cout << rpath9[i];
		if (i < dohamiltona9.getTop())
			std::cout << ",";
	}
	std::cout << std::endl; 
	delete[] rpath9;
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
