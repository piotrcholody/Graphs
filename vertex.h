#ifndef vertex_h
#define vertex_h
#include <vector>

class vertex{
public:
	vertex();
	//konstruktor wpisujący zadany wierzchołek
	vertex( int );
	//konstruktor kopiujący listę wierzchołków ( to-test )
	vertex( std::vector< int > );

	/*Metoda wypełniająca tablicę sąsiadów zadanego wierzchołka danymi
	  pobranymi z klawiatury
	*/
	void getGraph( int );
	//metoda zwracająca wierzchołek
	int retVertVal();
	//metoda zwracająca rozmiar
	int retSize(){ return _connectedVertices.size(); }
	//metoda zwracająca element o podanym indeksie
	int retVertex( int );
	//metoda dodająca wierzchołek do sąsiadów
	void addVert( int );
	//metoda wypisująca sąsiadów
	void printNeig();

private:
	std::vector< int > _connectedVertices;
};

#endif // vertex_h