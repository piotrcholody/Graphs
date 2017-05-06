#ifndef GRAFRYSUJ
#define GRAFRYSUJ
#include <QGraphicsScene>
#include <QFont>
#include "connectionmatrix.h"

class GrafRysuj{
	public:
	  /**
           * @param scene
           * @param r Promien wokol ktorego bedą rozrzucone wierzchołki.
           * @throws std::runtime_error dla blednych argumentow
           */
          GrafRysuj(QGraphicsScene *scene,const double r);

          /**
           * Wykonuje rysunek grafu na scenie w oparciu o zadana macierz sasiedztwa.
           * @param graf zainicjalizowany Graf
           * @throws std::runtime_error dla przypadku niezaicjalizowanego grafu.
           */
          void rysuj(ConnectionMatrix<int> *graf);
          
          void rysujEuler(std::vector<int> listN, const int n);
          
          void rysujHamilton(std::vector<int> listN);

          void rysujSkladowa(ConnectionMatrix<int> *graf, std::vector<int> listN);

		  void clear();

          QPen& getPen(){return _pen;}
          QBrush& getBrush(){return _brush;}
          double getR()const{return _r;}
          void setR(const double r){_r=r;}
	private:
	  QGraphicsScene* _scene;
	  double _r;
	  QBrush _brush;
	  QPen _pen;
};

#endif // GRAFRYSUJ

