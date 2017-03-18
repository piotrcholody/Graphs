#ifndef IncidenceMatrix_h
#define IncidenceMatrix_h

//podstawia wpisana wartosc pod int tylko wtedy gdy strumien jest dobry
//zaleta1: nie stanie siê nic czego sie nie bedziemy spodziewac
//zaleta2: bez dodatkowych bibliotek (tylko <iostream> potrzebny)
//zaleta3: procesor nie robi za grzejnik na prad
//jesli wpiszesz tekst ustawi -2137
//jesli wpiszesz "123xxx..." to ustawi integer z poczatku strumienia
//zwraca 1 gdy sie udalo, 0 gdy sie nie udalo
bool cinSelectedInt(int& selectedInt);



//Macierz Indcydencji
class IncidenceMatrix
{
public:
	//tworzy macierz pytajac o ilosc wierzcholkow i krawedzi, wypelnia zerami
	IncidenceMatrix();
	//tworzy macierz o podanym rozmiarze, wypelnia zerami
	IncidenceMatrix(int numberOfTops, int numberOfEdges); 
	//wpisujesz po kolei pola do ca³ej macierzy, wiersz po wierszu
	//zwraca 1 gdy jest poprawnie, 0 gdy jest niepoprawnie wpisana
	bool setEntireMatrix();
	//wypisuje na ekran cala macierz
	void printEntireMatrix() const;
	//zmienia wierzcho³ki do których nale¿y zadana krawêdŸ
	//oczywiscie podajesz indeks tablicy (czyli dla pierwszej krawedzi/wierzcholka jest 0)
	//gdy nowy wlasciciel lub wybrana krawedz nie istnieje funkcja zwraca 0 i nic nie robi
	//gdy istnieja te wierzcholki i krawedzie, to zmienia i zwraca 1
	bool changeTopsOfEdge(int selectedEdge, int newOwner1, int newOwner2);
	//dodaje nowa krawedz nalezaca do zadanych wierzcholkow (realokacja pamieci)
	//protip: oczywiscie podajesz indeks tablicy (czyli dla pierwszego wierzcholka jest 0)
	//gdy nowy wlasciciel nie istnieje funkcja zwraca 0 i nic nie robi
	//gdy doda zwraca 1
	bool addNewEdge(int newOwner1, int newOwner2);
	//powoduje destrukcje wszechswiata oraz usuniecie macierzy
	~IncidenceMatrix();

private:
	int top;  //wierzcholki
	int	edge;	//krawedzie
	int** matrix;	//macierz
};




#endif // IncidenceMatrix_h