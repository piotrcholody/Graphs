#include <iostream>
#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(){}
/******************************************************************/
void AdjacencyList::initList(){
	int number;

	std::cout << "Podaj liczbę wierchołków: ";
	std::cin >> number;
	for( int vert = 1; vert <= number; ++vert ){
		vertex *temp = new vertex( vert );
		_vertTable.push_back( temp );
		std::cout << "Stworzyłem kolejną listę dla wierzchołka: " << _vertTable[ vert - 1 ] -> retVertVal() << std::endl;
	}
	getList();
}
/******************************************************************/
void AdjacencyList::getList(){

	for( int i = 0; i < ( int )_vertTable.size(); ++i ){
		_vertTable[i] -> getGraph( _vertTable.size() );
	}
	int temp;
	for( int j = 0; j < ( int )_vertTable.size(); ++j ){
		temp = ( int )_vertTable[j] -> retSize();
		for( int k = 1; k < temp; ++k ){
				_vertTable[ _vertTable[j] -> retVertex( k ) - 1 ] -> addVert( j + 1 );
		}
	}
}
/******************************************************************/
void AdjacencyList::showList(){
	for( int i = 0; i < ( int )_vertTable.size(); ++i ){
		std::cout << "Wierzchołek nr: " << _vertTable[i] -> retVertex( 0 ) << std::endl;
		std::cout << "Sąsiedzi: ";
		_vertTable[i] -> printNeig();
		std::cout << std::endl;
	}
}
/******************************************************************/
std::vector< vertex* > AdjacencyList::retAdjacencyList(){
	if( _vertTable.size() )
		return _vertTable;
	else
		std::cout << "Aby zwrócić listę należy najpierw ją utworzyć" << std::endl;
	return _vertTable;
}	
/******************************************************************/
