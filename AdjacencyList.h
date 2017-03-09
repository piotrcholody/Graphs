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
	//metoda inicjująca powstanie listy
	void initList();

private:

	std::vector < vertex* > _vertTable;
};


#endif // AdjacencyList_h
