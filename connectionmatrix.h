/**
* connection matrix
* @author Piotr Cholody
*
*/
#pragma once
#include <vector>
#include <iostream>
#include "AdjacencyList.h"

template <typename Type>
class ConnectionMatrix {
public:
 
    //konstruktor
    ConnectionMatrix()
    {
        std::cin >> *this;
    };

	//konstruktor przyjmujacy AdjacencyList
	ConnectionMatrix(const AdjacencyList& lista)
	{
		std::vector< std::vector<int> > tmp;
		tmp = lista.retAdjacencyList();
		size = tmp.size();
		matrix.resize(size);
		for(int i = 0; i < size; ++i) {
			matrix[i].resize(size);
			for (int j = 1; j < tmp[i].size(); ++j) {
				int tmpint = tmp[i][j];
				matrix[i][tmpint-1] = 1;
			}
		}
	};
    
    //destruktor
    ~ConnectionMatrix(){};
    
    //operator zwracajacy dane pole macierzy
    Type& operator() (int row, int col)
    {
        return matrix[row][col];
    };
    
    //operator zwracajacy dane pole macierzy - wersja const
    const Type& operator() (int row, int col) const
    {
        return matrix[row][col];
    };

	//metoda zwracajaca referencje na macierz
	const std::vector< std::vector<int> >& returnMatrix() const
	{
		return matrix;
	}

	//zwraca size
	const int returnSize() const
	{
		return size;
	}
	//zwraca edges
	const int returnEdges() const
	{
		return edges;
	}

    //extraction operator
    friend std::istream& operator>> (std::istream& is, ConnectionMatrix& obj)
    {
		int first, second;
        std::cout << "Podaj ilosc wierzcholkow ";
        is >> obj.size;
        if (obj.size < 1) {
            throw std::runtime_error("graf musi miec wierzcholki");
        }
        std::cout << "Podaj ilosc krawedzi ";
        is >> obj.edges;
        if (obj.edges < 0) {
            throw std::runtime_error("liczba krawedzi nie moze byc ujemna");
        }
        if (obj.edges > obj.size * (obj.size - 1)/2) {
            throw std::runtime_error("za duza ilosc krawedzi");
        }
        obj.matrix.resize(obj.size);
        for (int i = 0; i < obj.size; ++i) {
            obj.matrix[i].resize(obj.size);
        }
        for (int j = 0; j < obj.edges; ++j) {
            std::cout << "Podaj numery polaczonych wierzcholkow ";
            is >> first;
            if (first < 1 || first > obj.size) {
                throw std::runtime_error("nie ma takiego wierzcholka");
            }
            is >> second;
            if (second < 1 || second > obj.size) {
                throw std::runtime_error("nie ma takiego wierzcholka");
            }
            if (obj.matrix[first-1][second-1] == 1 || obj.matrix[second-1][first-1] == 1) {
                throw std::runtime_error("podales dwa razy to samo polaczenie");
            }
			if (first == second) {
				throw std::runtime_error("podales bledne polaczenie");
			}
            obj.matrix[first-1][second-1] = 1;
            obj.matrix[second-1][first-1] = 1;
        }
        return is;
    };
    
    //insertion operator
    friend std::ostream& operator<< (std::ostream& os, const ConnectionMatrix& obj)
    {
        for (int i = 0; i < obj.size; ++i) {
                os << std::endl;
                for (int j = 0; j < obj.size; ++j) {
                    os << obj.matrix[i][j] << "  ";
                }
        }
        return os;
    };
 
private:
 
    //liczba wierzcholkow - rozmiar macierzy
    int size;
	//liczba krawedzi
	int edges;
    
    //macierz
    std::vector< std::vector<Type> > matrix;
};
