#include <iostream>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(){
	int number;

	std::cout << "Podaj liczbę wierchołków: ";
	std::cin >> number;
	for( int vert = 1; vert <= number; ++vert ){
		vertex *temp = new vertex( vert );
		_vertTable.push_back( temp );
		std::cout << "Stworzyłem kolejną listę dla wierchołka: " << _vertTable[ vert - 1 ] -> retVertVal() << std::endl;
	}
	std::cout << _vertTable.size() << std::endl;
	getList();
}
/******************************************************************/
void AdjacencyList::getList(){
	for( int i = 0; i < ( int )_vertTable.size(); ++i ){
		_vertTable[i] -> getGraph( _vertTable.size() );
	}
}
/******************************************************************/
