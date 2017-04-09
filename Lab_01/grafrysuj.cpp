#include<grafrysuj.h>
#define M_PI 3.14

GrafRysuj::GrafRysuj(QGraphicsScene *scene,const double r)
:_scene(scene),_r(r),_brush(Qt::black),_pen(Qt::black){
if(scene==0||scene==NULL)
    throw std::runtime_error("GrafRysuj::GrafRysuj : Blad scene");
    if(r<=0)
    throw std::runtime_error("GrafRysuj::GrafRysuj : Blad promienia");
}
//----------------------------------------------------
void GrafRysuj::rysuj(ConnectionMatrix<int> *graf){
   // if(graf->init()==false)
  //  throw std::runtime_error(" GrafRysuj::rysuj : Niezainicjalizowany graf");
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
            if(tab[i][j]==true)
                _scene->addLine(std::sin(i*d+temp)*_r+w/2,std::cos(i*d+temp)*_r+w/2,std::sin(j*d+temp)*_r+w/2,std::cos(j*d+temp)*_r+w/2,_pen);
    }
}
}
