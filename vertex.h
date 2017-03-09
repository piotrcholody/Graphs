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
	std::vector< int > getGraph( int );
	//metoda zwracająca wierzchołek
	int retVertVal();

private:
	std::vector< int > _connectedVertices;
};

#endif // vertex_h