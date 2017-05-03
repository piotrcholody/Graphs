#ifndef GRAFRANDOMIZE_H
#define GRAFRANDOMIZE_H
#include "Graf.h"
#include "gconverter.h"

class Grafrandomize{
  struct Data{
    Data(bool **tab,const int n);
    ~Data();
    void rek(const int m, const int s);
    /**
     * @brief tab Macierz sasiedztwa.
     * @brief tabB Tablica zawierajaca wartosc log. czy dany wierz może zostać użyty.
     * @brief find Wart. log. czy znaleziona zostala scieżka.
     */
    bool **tab,*tabB,find;
    std::list<int> tabN;
    int n;
  };
public:
  /**
   * Funkcja generuje sciezke Hamiltona
   * @param tab Tablica sasiedztwa.
   * @param n Ilosc wierch
   * @return Funkcja zwraca liste z kolejnymi wiercholkami listy Hamiltona. Zwraca pusta liste jezeli nie znaleziono!!!.
   * @throws std::runtime_error W przypadku zlych argumentow.
   */
  static GrafBase* randomize(const GrafBase *graph);
};

#endif // GRAFRANDOMIZE_H
