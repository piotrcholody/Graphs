/**
* random graph v1
* @author Piotr Cholody
*
*/
#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>

template <typename Type>
class probGraph {
public:

	//konstruktor
	probGraph()
	{
		std::cin >> *this;
	};

	//destruktor
	~probGraph() {};

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

	//extraction operator
	friend std::istream& operator>> (std::istream& is, probGraph& obj)
	{
		std::cout << "Podaj ilosc wierzcholkow ";
		is >> obj.size;
		if (obj.size < 1) {
			throw std::runtime_error("graf musi miec wierzcholki");
		}
		std::cout << "Podaj prawdopodobienstwo ";
		is >> obj.prob;
		if (obj.prob < 0) {
			throw std::runtime_error("prawdopodobienstwo musi byc dodatnie");
		}
		if (obj.prob > 1) {
			throw std::runtime_error("prawdopodbienstwo musi byc mniejsze od 1");
		}
		obj.matrix.resize(obj.size);
		for (int i = 0; i < obj.size; ++i) {
			obj.matrix[i].resize(obj.size);
		}
		for (int i = 0; i < obj.size - 1; ++i) {
			for (int j = i + 1; j < obj.size; ++j) {
				if (((double)(std::rand() % 1000)) / 1000 < obj.prob) {
					obj.matrix[j][i] = 1;
					obj.matrix[i][j] = 1;
				}
			}
		}
		return is;
	};

	//insertion operator
	friend std::ostream& operator<< (std::ostream& os, const probGraph& obj)
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
	//prawdopodobienstwo
	double prob;

	//macierz
	std::vector< std::vector<Type> > matrix;
};
