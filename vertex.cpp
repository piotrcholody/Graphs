#include <iostream>
#include "vertex.h" 

vertex::vertex(){}
/********************************************************************/
vertex::vertex( int oneVert ){
	_connectedVertices.push_back( oneVert );
}
/********************************************************************/
vertex::vertex( std::vector< int > fewVertices ){
	_connectedVertices = fewVertices;
}
/********************************************************************/
void vertex::getGraph( int vertCounter ){
	int temp;
	std::cin.clear();
	std::cin.ignore();

	std::cout << "Wpisz sąsiadów wierzchołka: " << _connectedVertices[0] << std::endl;

	std::cout << "Wypisz jego sąsiadów: ";
	while( std::cin >> temp ){
		if( temp != _connectedVertices.front() && temp <= vertCounter && temp > 0 )
			_connectedVertices.push_back( temp );
	}
		
	std::cout << "Dodano następujących sąsiadów do wierzchołka nr " << _connectedVertices[0] << ": " << std::endl;
	for( int i = 1; i < ( int )_connectedVertices.size(); ++i ){
		std::cout << _connectedVertices[i] << "  " << std::endl;
	}
}
/*******************************************************************/
int vertex::retVertVal()
{
	return _connectedVertices.front();
}
/*******************************************************************/
int vertex::retVertex( int index ){
	if( index > ( int )_connectedVertices.size() )
		return 0;
	return _connectedVertices[ index ];
}
/*******************************************************************/
void vertex::addVert( int index ){
	for( int i = 0; i < ( int )_connectedVertices.size(); ++i ){
		if( _connectedVertices[i] == index )
			return;
	}
	_connectedVertices.push_back( index );
}
/*******************************************************************/
void vertex::printNeig(){
	for( int i = 1; i < ( int )_connectedVertices.size(); ++i )
		std::cout << _connectedVertices[i] << " ";
}
/*******************************************************************/
