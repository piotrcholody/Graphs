#define _USE_MATH_DEFINES
#include <math.h>
#include "grafrysuj.h"
#include <QGraphicsTextItem>
#include <sstream>
#include <stdexcept>

GrafRysuj::GrafRysuj(QGraphicsScene *scene,const double r)
  	:_scene(scene),_r(r),_brush(Qt::black),_pen(Qt::black){
  	if(scene==0||scene==NULL)
   		throw std::runtime_error("GrafRysuj::GrafRysuj : Blad scene");
        if(r<=0)
    	throw std::runtime_error("GrafRysuj::GrafRysuj : Blad promienia");
}
//----------------------------------------------------
void GrafRysuj::rysuj(ConnectionMatrix<int> *graf){
int n=graf->getN(),w=8;
std::vector< std::vector<int> > tab = graf->getMatrix();
double d=(2*M_PI)/n,temp=M_PI/2;
_scene->clear();
for(int i=0;i<n;i++){
    _scene->addEllipse(std::sin(i*d+temp)*_r,std::cos(i*d+temp)*_r,w,w,_pen,_brush);
    std::stringstream str;str<<i;
    QGraphicsTextItem *text=_scene->addText(str.str().c_str(),QFont());
    text->setDefaultTextColor(Qt::black);
    text->setPos(std::sin(i*d+temp)*(_r+15)-w,std::cos(i*d+temp)*(_r+15)-w);
    for(int j=i+1;j<n;j++){
            if(tab[i][j] == 1)
                _scene->addLine(std::sin(i*d+temp)*_r+w/2,std::cos(i*d+temp)*_r+w/2,std::sin(j*d+temp)*_r+w/2,std::cos(j*d+temp)*_r+w/2,_pen);
    }
}
}
void GrafRysuj::rysujEuler(std::vector<int> listN,const int n){
  if(listN.empty())
    throw std::runtime_error("GrafRysuj::rysujEuler : Niezainicjalizowana sciezka");
  std::vector<int>::iterator i=listN.begin();
  int ntemp=(*i),w=8,ind=1;
  double x1,x2,y1,y2;
  i++;
  QFont qf;
  qf.setBold(true);
  double d=(2*M_PI)/n,temp=M_PI/2;
  for(;i!=listN.end();i++,ind++){
      x1=std::sin(ntemp*d+temp)*_r+w/2;
      y1=std::cos(ntemp*d+temp)*_r+w/2;
      x2=std::sin((*i)*d+temp)*_r+w/2;
      y2=std::cos((*i)*d+temp)*_r+w/2;
      std::stringstream str;str<<ind;
      QGraphicsTextItem *text=_scene->addText(str.str().c_str(),qf);
      text->setDefaultTextColor(Qt::black);
      text->setPos((x1+x2)/2-w,(y1+y2)/2-w);
      ntemp=(*i);
  }
}

void GrafRysuj::rysujHamilton(std::vector<int> listN){
    std::vector<int>::iterator i=listN.begin();
    int ntemp=(*i),w=8;
    double x1,x2,y1,y2;
    i++;
    QPen qp;
    qp.setWidth(2);
    double d=(2*M_PI)/(listN.size() - 1),temp=M_PI/2;
    for(;i!=listN.end();i++){
        x1=std::sin(ntemp*d+temp)*_r+w/2;
        y1=std::cos(ntemp*d+temp)*_r+w/2;
        x2=std::sin((*i)*d+temp)*_r+w/2;
        y2=std::cos((*i)*d+temp)*_r+w/2;
        _scene->addLine(x1,y1,x2,y2,qp);
        ntemp=(*i);
      }
}

void GrafRysuj::rysujSkladowa(ConnectionMatrix<int> *graf, std::vector<int> listN){
  if(listN.empty())
    throw std::runtime_error("GrafRysuj::rysujSkladowa : Niezainicjalizowana sciezka");
  int n = graf->getN(), w=8;
  std::vector< std::vector<int> > tab = graf->getMatrix();
  double d = (2*M_PI)/n, temp = M_PI/2;
  _scene->clear();
  for(int i = 0; i < n; ++i){
      std::stringstream str;
      str << i;
      QGraphicsTextItem *text = _scene->addText(str.str().c_str(), QFont());
      for (auto it = listN.begin(); it != listN.end(); ++it) {
          if (listN[*it] == i) {
              text->setDefaultTextColor(Qt::red);
              _brush.setColor(Qt::red);
              break;
          }
          else
              text->setDefaultTextColor(Qt::black);
              _brush.setColor(Qt::black);
      }
      _scene->addEllipse(std::sin(i*d+temp)*_r,std::cos(i*d+temp)*_r,w,w,_pen,_brush);
      text->setPos(std::sin(i*d+temp)*(_r+15)-w,std::cos(i*d+temp)*(_r+15)-w);
      for(int j=i+1;j<n;j++){
              if(tab[i][j] == 1)
                  _scene->addLine(std::sin(i*d+temp)*_r+w/2,std::cos(i*d+temp)*_r+w/2,std::sin(j*d+temp)*_r+w/2,std::cos(j*d+temp)*_r+w/2,_pen);
      }
      text->setDefaultTextColor(Qt::black);
      _brush.setColor(Qt::black);
  }
}
