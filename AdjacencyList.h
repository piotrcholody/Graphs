#ifndef AdjacencyList_h
#define AdjacencyList_h
#include <vector>
//#include "IncidenceMatrix.h"

class IncidenceMatrix;

class AdjacencyList{
public:
	//konstruktor
	AdjacencyList();
	//kontruktor kopiujący
	AdjacencyList(const IncidenceMatrix&);
	/*metoda tworząca listę wierzchołków, pobierająca dane z 
	  klawiatury
	*/
	void getList();
	//metoda wypisująca całą listę grafu
	void showList();
	/*Metoda wypełniająca tablicę sąsiadów zadanego wierzchołka danymi
	  pobranymi z klawiatury
	*/
	void getGraph(int);
	/*Metoda wypełniająca tablicę podanych wierzchołków
	  wzajemnie sobą nawzajem, no miłość
	*/
	void addNeighbours(int, int);
	//metoda inicjująca powstanie listy
	void initList();
	//metoda inicjująca powstanie listy o określonej liczbie
	//wierzchołków
	void initList(int);
	//metoda uzupełniająca listę
	void fillList();
	//metoda sprawdzająca warunki konieczne do dodania
	//sąsiada
	bool isAddingNeighbourPossible(int, int);
	//metoda zwracająca listę
	std::vector< std::vector<int> > retAdjacencyList() const;
	//metoda zwracająca indeks jeśli dana wartość wystąpiła w 
	//tablicy
	int isThisVal(int, int);
	/*metoda zwracająca prawdę jeśli podany wierzchołek
	istnieje
	*/
	bool isThisVert(int);
	/*metoda usuwająca krawędź między wierzchołkami, o
	  ile takowa istnieje, w przeciwnym wypadku zwraca
	  False
	*/
	bool delEdge(int, int);

private:

	std::vector< std::vector<int> > _vertTable;
};


#endif // AdjacencyList_h
