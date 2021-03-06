/**
* connection matrix
* @author Piotr Cholody
*
*/
#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include "AdjacencyList.h"
#include<fstream>

template <typename Type>
class ConnectionMatrix {
public:

    //konstruktor
    ConnectionMatrix()
    {
       // std::cin >> *this;
    };

    //metoda do grafu losowego z krawedziami
    void edgeGraph(const int n, const int l)
    {
        if (n < 1) {
            throw std::runtime_error("graf musi miec wierzcholki");
        }
        if (l < 0) {
            throw std::runtime_error("liczba krawedzi nie moze byc ujemna");
        }
        if (l > n * (n - 1) / 2) {
            throw std::runtime_error("za duza ilosc krawedzi");
        }
        size = n;
        edges = l;
        matrix.resize(n);
        for (int i = 0; i < n; ++i) {
            matrix[i].resize(n);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
        for (int j = 0; j < l; ++j) {
            int first = 0;
            int second = 0;
            while (first == second || matrix[first][second] == 1) {
                first = std::rand() % n;
                second = std::rand() % n;
            }
            matrix[first][second] = 1;
            matrix[second][first] = 1;
        }
    };

    //metoda do grafu losowego z prawdopodobienstwem
    void probGraph(const int n, const double p)
    {
        if (n < 1) {
            throw std::runtime_error("graf musi miec wierzcholki");
        }
        if (p < 0) {
            throw std::runtime_error("prawdopodobienstwo musi byc dodatnie");
        }
        if (p > 1) {
            throw std::runtime_error("prawdopodbienstwo musi byc mniejsze od 1");
        }
        size = n;
        edges = 0;
        matrix.resize(n);
        for (int i = 0; i < n; ++i) {
            matrix[i].resize(n);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (((double)(std::rand() % 1000)) / 1000 < p) {
                    matrix[j][i] = 1;
                    matrix[i][j] = 1;
                    edges++;
                }
            }
        }
    };

    //konstruktor przyjmujacy AdjacencyList
    ConnectionMatrix(const AdjacencyList& lista)
    {
        std::vector< std::vector<int> > tmp;
        tmp = lista.retAdjacencyList();
        size = static_cast<int>(tmp.size());
        matrix.resize(size);
        for(int i = 0; i < size; ++i) {
            matrix[i].resize(size);
            for (int j = 1; j < static_cast<int>(tmp[i].size()); ++j) {
                int tmpint = tmp[i][j];
                matrix[i][tmpint] = 1;
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
    const std::vector< std::vector<int> >& getMatrix() const
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
   /* friend std::istream& operator>> (std::istream& is, ConnectionMatrix& obj)
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
    };*/

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
    void save(const std::string str){
      std::fstream plik;
      plik.open(str.c_str(),std::ios::out);
      if(matrix.empty()||size<=0||edges<0)
          throw  std::runtime_error("Bład argumentu");
      if( plik.good() == false)
          throw std::runtime_error("Bład pliku");
      plik<<size<<" "<<edges<<std::endl;
      for(int i=0;i<size;i++){
          for(int j=i+1;j<size;j++){
              if(matrix[i][j]==true){
                  plik<<i<<" "<<j<<std::endl;
                }
            }
        }
      plik.close();
    }
    void open(const std::string str){
      if(str.find(".graf")==std::string::npos)
        throw std::runtime_error("Błedny format pliku");
      std::fstream plik;
      plik.open(str.c_str(),std::ios::in);
      if( plik.good() == false)
          throw std::runtime_error("Bład odczytu pliku");
      int n1,n2;
      plik>>size>>edges;
      matrix.resize(size);
      for(int i = 0; i < size; ++i) {
          matrix[i].resize(size);
          for(int j = 0; j < size; ++j) {
              matrix[i][j] = 0;
          }
      }
      if(size<=0||edges<0)
                    throw std::runtime_error("Bład pliku");

      for(int i=0;i<edges;i++){
          plik>>n1>>n2;
          matrix[n1][n2]=true;
          matrix[n2][n1]=true;
        }
      plik.close();
    }
private:

    //liczba wierzcholkow - rozmiar macierzy
    int size;
    //liczba krawedzi
    int edges;

    //macierz
    std::vector< std::vector<Type> > matrix;
};
