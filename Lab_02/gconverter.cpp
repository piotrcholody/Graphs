#include "gconverter.h"

void IncidenceMatrix::init(const int n, const int l)
{
    for(int i=0;i<_n;i++)
        delete[] _tab[i];
    delete[] _tab;
    _tab=new bool*[n];
    for(int i=0;i<n;i++)
    {
        _tab[i]=new bool[l];
        for(int j=0;j<l;j++)
            _tab[i][j]=false;
    }
    _n=n;
    _l=l;
}

void AdjacencyList::init(const int n)
{
    //for(int i=0;i<_n;i++)
    //    delete _tab[i];
    delete[] _tab;
    _tab=new std::vector<int>[n];
    _n=n;
    _maxL = 0;
}

AdjacencyList::~AdjacencyList()
{
    delete[] _tab;
}

IncidenceMatrix* GConverter::adjacencyToIncidence(const GrafBase *graph)
{
    int n = graph->getN();
    bool** tab = graph->getTab();
    int l = GConverter::countL(tab, n);
    IncidenceMatrix *matrix = new IncidenceMatrix(n, l);
    bool** tab2 = matrix->getTab();
    int li = 0; // indeks aktualnie dodawanej krawędzi

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if (tab[i][j])
            {
                tab2[i][li] = true;
                tab2[j][li] = true;
                li++;
            }
    matrix->addTab(tab2);
    return matrix;
}

Graf* GConverter::incidenceToAdjacency(const IncidenceMatrix *graph)
{
    int n = graph->getN();
    int l = graph->getL();
    Graf *matrix = new Graf(n);
    bool** tab = graph->getTab();
    bool** tab2 = matrix->getTab();

    int x,y;
    for(int j=0; j<l; j++)
    {
        for(x=0; x<n && !(tab[x][j]); x++);
        for(y=x+1; y<n && !(tab[y][j]); y++);
        tab2[x][y] = true;
        tab2[y][x] = true;
    }
    matrix->addTab(tab2);
    return matrix;
}

AdjacencyList* GConverter::matrixToList(const GrafBase *graph)
{
    int n = graph->getN();
    int l, maxL=0;
    AdjacencyList *list = new AdjacencyList(n);
    bool** tab = graph->getTab();
    std::vector<int>* tab2 = list->getTab();

    for(int i = 0; i<n; i++)
    {
        l = 0;
        for(int j = 0; j<n; j++)
        {
            if (tab[i][j])
            {
                tab2[i].push_back(j);
                l++;
            }
        }
        if (l>maxL) maxL=l;
    }
    list->addMaxL(maxL);
    list->addTab(tab2);
    return list;
}

Graf* GConverter::listToMatrix(const AdjacencyList *list)
{
    int n = list->getN();
    int l;
    Graf *graph = new Graf(n);
    bool** tab = graph->getTab();
    std::vector<int>* tab2 = list->getTab();

    for(int i = 0; i<n; i++)
    {
        l = tab2[i].size();
        for(int j=0; j<l; j++)
            tab[i][tab2[i].at(j)] = true;
    }
    graph->addTab(tab);
    return graph;
}

int GConverter::countL(bool** const tab, const int n)
{
    int result=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if (tab[i][j]) result++;
    return result/2;
}
