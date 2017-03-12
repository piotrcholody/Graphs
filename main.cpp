#include <iostream>
#include "main.h"

int main( void ){


	//Testy przedstawienia grafu za pomocą macierzy połączeń:
	ConnectionMatrix<int> *testCM;
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

	std::vector< vertex* > temp;
	temp = test -> retAdjacencyList();

	std::cout << std::endl;	

	for( int i = 0; i < ( int )temp.size(); ++i ){
		for( int j = 0; j < ( int )temp[i] -> retSize(); ++j )
			std::cout << temp[i] -> retVertex(j) << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;

	test -> showList();
	
	delete[] testCM;
	delete[] test;
	return 0;
}
