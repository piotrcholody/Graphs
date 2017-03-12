/**
* connection matrix
* @author piotr cholody
*
*/
 
#include <vector>
#include <iostream>
 
template <typename Type>
class ConnectionMatrix {
public:
 
    //konstruktor
    ConnectionMatrix()
    {
        std::cin >> *this;
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
    //extraction operator
    friend std::istream& operator>> (std::istream& is, ConnectionMatrix& obj)
    {
        int first, second, n;
        std::cout << "Podaj ilosc wierzcholkow ";
        is >> obj.size;
        if (obj.size < 1) {
            throw std::runtime_error("graf musi miec wierzcholki");
        }
        std::cout << "Podaj ilosc krawedzi ";
        is >> n;
        if (n < 0) {
            throw std::runtime_error("liczba krawedzi nie moze byc ujemna");
        }
        if (n > obj.size * (obj.size - 1)/2) {
            throw std::runtime_error("za duza ilosc krawedzi");
        }
        obj.matrix.resize(obj.size);
        for (int i = 0; i < obj.size; ++i) {
            obj.matrix[i].resize(obj.size);
        }
        for (int j = 0; j < n; ++j) {
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
    //macierz
    std::vector< std::vector<Type> > matrix;
};
