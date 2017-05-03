#include "grafrandomize.h";

GrafBase* Grafrandomize::randomize(const GrafBase *graph)
{
    int n = graph->getN();
    bool** tab = graph->getTab();
    int l = GConverter::countL(tab, n);
    IncidenceMatrix *matrix = new IncidenceMatrix(n, l);
    bool** tab2 = matrix->getTab();
}
