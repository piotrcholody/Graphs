#include <iostream>
#include "main.h"

int main( void ){


	//Testy przedstawienia grafu za pomocą macierzy połączeń:
	ConnectionMatrix<int> *testCM = nullptr;
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

	delete testCM;
	delete testAL_CM;
	delete test;
	return 0;
}
