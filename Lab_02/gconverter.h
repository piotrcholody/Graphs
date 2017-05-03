#ifndef GCONVERTER_H
#define GCONVERTER_H
#include <stdexcept>
#include "Graf.h"
#include <vector>

class IncidenceMatrix: public GrafBase
{
public:
    IncidenceMatrix(): GrafBase() {}
    IncidenceMatrix(const int n, const int l): GrafBase() {init(n,l);}
    virtual ~IncidenceMatrix() {}

    void addTab(bool** tab) {_tab = tab;}

protected:
    /**
     * Funkcja dealokuje poprzednia tablice jezeli taka istaniała. Nie nalezy zmieniać _n oraz _l na nowe przed jej wykonaniem.
     * Alokuje tablice 2D o rozmiarach l x n.
     */
    void init(const int n, const int l);
};

class AdjacencyList
{
public:
    AdjacencyList(): _tab(0), _n(0), _maxL(0) {}
    AdjacencyList(const int n): _tab(0), _n(0), _maxL(0) {init(n);}
    ~AdjacencyList();

    std::vector<int>* getTab()const{return _tab;}
    int getN()const{return _n;}
    int getMaxL()const{return _maxL;}

    void addTab(std::vector<int>* tab) {_tab = tab;}
    void addMaxL(const int maxL) {_maxL = maxL;}

private:
    /**
     * Funkcja dealokuje poprzednia tablice jezeli taka istaniała. Nie nalezy zmieniać _n na nowe przed jej wykonaniem.
     * Alokuje tablice o rozmiarze n, której elementy to wektory.
     */
    void init(const int n);

    std::vector<int>* _tab;
    int _n;
    int _maxL; // Największa liczba sąsiadów dla jednego węzła
};

class GConverter
{
public:
    /**
     * Generuje macierz incydencji na podstawie macierzy sąsiedztwa
     * @param graph Graf, z którego pobierana jest macierz sąsiedztwa
     * @return Wskaźnik do macierzy incydencji
     */
    static IncidenceMatrix* adjacencyToIncidence(const GrafBase *graph);

    /**
     * Generuje macierz sąsiedztwa na podstawie macierzy incydencji
     * @param graph Graf, z którego pobierana jest macierz incydencji
     * @return Wskaźnik do grafu sąsiedztwa
     */
    static Graf* incidenceToAdjacency(const IncidenceMatrix *graph);

    /**
     * Generuje liste sąsiedztwa na podstawie macierzy sąsiedztwa
     * @param graph Graf, z którego pobierana jest macierz sąsiedztwa
     * @return Wskaźnik do listy sąsiedztwa
     */
    static AdjacencyList* matrixToList(const GrafBase *graph);

    /**
     * Generuje macierz sąsiedztwa na podstawie listy sąsiedztwa
     * @param graph Graf, z którego pobierana jest lista sąsiedztwa
     * @return Wskaźnik do grafu sąsiedztwa
     */
    static Graf* listToMatrix(const AdjacencyList *list);

    /**
     * Oblicza ilość krawędzi na podstawie macierzy sąsiedztwa
     * @param tab Macierz sąsiedcztwa
     * @return Ilość krawędzi
     */
    static int countL(bool** const tab, const int n);
};

#endif // GCONVERTER_H
