/**
* random graph v2
* @author Piotr Cholody
*
*/
#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename Type>
class edgeGraph {
public:

	//konstruktor
	edgeGraph()
	{
		std::cin >> *this;
	};


	//destruktor
	~edgeGraph() {};

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
	};

	//zwraca size
	const int getN() const
	{
		return size;
	};

	//zwraca edges
	const int getL() const
	{
		return edges;
	};

	//extraction operator
	friend std::istream& operator>> (std::istream& is, edgeGraph& obj)
	{
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
		if (obj.edges > obj.size * (obj.size - 1) / 2) {
			throw std::runtime_error("za duza ilosc krawedzi");
		}
		obj.matrix.resize(obj.size);
		for (int i = 0; i < obj.size; ++i) {
			obj.matrix[i].resize(obj.size);
		}

		for (int j = 0; j < obj.edges; ++j) {
			int first = 0;
			int second = 0;
			while (first == second || obj.matrix[first][second] == 1) {
				first = std::rand() % obj.size;
				second = std::rand() % obj.size;
			}
			obj.matrix[first][second] = 1;
			obj.matrix[second][first] = 1;
		}
		return is;
	};

	//insertion operator
	friend std::ostream& operator<< (std::ostream& os, const edgeGraph& obj)
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
