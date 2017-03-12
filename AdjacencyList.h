#ifndef AdjacencyList_h
#define AdjacencyList_h
#include <vector>
#include "vertex.h"

class vertex;

class AdjacencyList{
public:
	//konstruktor
	AdjacencyList();
	/*metoda tworząca listę wierzchołków, pobierająca dane z 
	  klawiatury
	*/
	void getList();
	//metoda wypisująca całą listę grafu
	void showList();
	/*Metoda wypełniająca tablicę sąsiadów zadanego wierzchołka danymi
	  pobranymi z klawiatury
	*/
	void getGraph( int );
	//metoda inicjująca powstanie listy
	void initList();
	//metoda zwracająca listę
	std::vector< vertex* > retAdjacencyList();

private:

	std::vector< std::vector< int > > _vertTable;
};


#endif // AdjacencyList_h
