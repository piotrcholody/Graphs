#include <vector>
#include <iostream>
 
template <typename Type>
class ConnectionMatrix{
public:
    ConnectionMatrix(){
        std::cin >> *this;
    };
 
    ~ConnectionMatrix(){
    };
 
    Type& operator() (int row, int col){
        return matrix[row][col];
    };
 
    const Type& operator() (int row, int col) const{
        return matrix[row][col];
    };
 
    friend std::istream& operator>> (std::istream& is, ConnectionMatrix& obj){
        int help;
        std::cout << "Podaj rozmiar ";
        is >> obj.size;
        for(int i = 0; i < obj.size; ++i){
                std::vector<Type> row;
            for(int j = 0; j < obj.size; ++j){
                std::cout << "Podaj pole " << i << " " << j << "\n";
                is >> help;
                row.push_back(help);
            }
            obj.matrix.push_back(row);
        }
        return is;
    };
 
    friend std::ostream& operator<< (std::ostream& os, const ConnectionMatrix& obj){
        for(int i = 0; i < obj.size; ++i){
                os << std::endl;
                for(int j = 0; j < obj.size; ++j){
                    os << obj.matrix[i][j] << "  ";
                }
        }
        return os;
    };
private:
    int size;
    std::vector< std::vector<Type> > matrix;
};
