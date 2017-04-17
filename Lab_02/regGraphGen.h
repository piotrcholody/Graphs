#ifndef regGraphGen_h
#define regGraphGen_h
#include "IncidenceMatrix.h"
#include "MyExceptions.h"

// funkcja tworz¹ca graf regularny zwraca go jeœli siê uda³o
IncidenceMatrix& regGraphGen(int vertex_counter, int degree);
// funkcja tworz¹ca tablicê punktów
std::vector< int > getMatrixOfPoints(int, int);
// funkcja tworz¹ca tablicê par punktów
std::vector< std::vector< int > > getMatrixOfPairs(int, int);
// funkcja sprawdzaj¹ca czy stworzenie grafu jest mo¿liwe
bool isCreatingGraphPossible(int, int);
// funkcja sprawdzaj¹ca czy istnieje ju¿ taka para wierzcho³ków, zwraca 0 gdy nie
bool isThisPairExist(int, int, std::vector< std::vector< int > >, int);
// funkcja sprawdzaj¹ca czy nie zosta³ tylko jeden wierzcho³ek
bool isOnlyOneVertex(std::vector< int >);

#endif // regGraphGen_h

