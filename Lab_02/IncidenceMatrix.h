#pragma once
#include "connectionmatrix.h"
#include "vld.h"


struct node1
{
	int val;
	int num;
};

	//podstawia wpisana wartosc pod int tylko wtedy gdy strumien jest dobry
	//jesli wpiszesz tekst ustawi -2137
	//jesli wpiszesz "123xxx..." to ustawi integer z poczatku strumienia
	//zwraca 1 gdy sie udalo, 0 gdy sie nie udalo (ustawiono -2137)
bool cinSelectedInt(int& selectedInt);
	//alokuje pamiec na macierz incydencji o 'top' wierzcholkach i 'edge' krawedziach
	//zwraca wskaznik na stworzona macierz
static int** allocateMatrix(int top, int edge);
	//zwraca losowy int z przedzialu <A,B>
int randomint(int A, int B);
	//zwraca losowy float z przedzalu <A,B>
float randomfloat(int A, int B);
	//porownanie dla sortowania struktur "node1" rosnaco
bool compareToSortNodes(node1& a, node1& b);
	//sprawdza czy sekwencja liczb jest ciagiem graficznym
	//zwraca 1 gdy jest ciagiem graficznym
	//zwraca 0 gdy nie jest ciagiem graficznym
bool checkIfSequenceIsGraphic(std::vector<int> sequence);


	//Macierz Indcydencji
class IncidenceMatrix
{
public:
		//zwraca liste polaczen dla danego wierzcholka (z ktorymi wierzcholkami laczy sie seletedTop)
	std::vector<int> adjForTop(int selectedTop);
		//tworzy macierz pytajac o ilosc wierzcholkow i krawedzi, wypelnia zerami
		//CHCESZ JEJ UZYC TO JA WYPELNIJ!!!!!!!!
	IncidenceMatrix(int taWartoscNicNieRobi);
		//tworzy macierz o podanym rozmiarze, wypelnia zerami
		//CHCESZ JEJ UZYC TO JA WYPELNIJ!!!!!!!!
	IncidenceMatrix(int numberOfTops, int numberOfEdges); 
		//konstruktor kopiujacy z klasy ConnectionMatrix
	IncidenceMatrix(const ConnectionMatrix<int>& conn);
		//kontruktor kopiujacy
	IncidenceMatrix(const IncidenceMatrix& org);
		//kontruktor macierzy z podanej sekwencji graficznej
		//jesli to nie bedzie sekwencja graficzna i tworzenie sie nie powiedzie: std::abort()
		//najlepiej sprawdzic przedtem checkIfSequenceIsGraphic()
	IncidenceMatrix(std::vector<int> sequence);
		//ustawia w kolumnie (w krawedzi) same zera; krawedz przestaje miec wlascicieli
		//zwraca 0 gdy sie uda
		//zwraca 1 gdy nie ma takiej krawedzi
	bool resetTopsOfEdge(int selectedEdge);
		//ustawia elementy calej macierzy wpisanymi wartosciami
		//wpisujesz po kolei pola do ca³ej macierzy, wiersz po wierszu
		//zwraca 0 gdy jest poprawnie, 1 gdy jest niepoprawnie wpisana
		//bledy w reprezentacji sa eliminowane; wypisywane jest co zostalo usuniete
	bool setEntireMatrixByRows();
		//ustawia elementy calej macierzy wartosciami wczytanymi z pliku 'Filename'
		//zwraca 0 gdy wczyta poprawnie, 1 gdy wystapil jakis blad i wypisuje komunikat bledu
		//bledy w reprezentacji sa eliminowane; wypisywane jest co zostalo usuniete
	bool setEntireMatrixFromFile(const char* Filename, int numberOfTops, int numberOfEdges);
		//usuwa bledy w reprezentacji macierzy incydencji, takie jak
		//krawedzie z bledna liczba wierzcholkow lub zmultiplikowane krawedzie
		//zwraca 1 gdy wystapily jakiekolwiek bledy (na pewno je naprawiono)
		//zwraca 0 gdy w nie bylo bledow w reprezentacji
		//gdy bledow nie uda sie naprawic (jakims cudem) to wczesniej wysypie sie program
	bool eliminateAllMistakes();
					//usuwa krawedzie ktore sie powtarzaja
					//zwraca 0 gdy nie bylo zmultiplikowanych krawedzi
					//nie wywoluj gdy moga istniec bledne krawedzie, nie usunie wtedy wszystkich
				bool eliminateDuplicates();
					//usuwa krawedzie z bledna liczba wierzcholkow lub liczbami wiekszymi niz 1
					//zwraca 0 gdy nie bylo blednych krawedzi; zwraca 1 gdy usunieto bledne i wypisuje komunikat
				bool eliminateInvalidEdges();
		//inforumuje o istnieniu indeksu krawedzi (gdy istnieje zwraca 1)
	bool edgeIndexExist(int questionedEdge) const;
		//zwraca numer krawedzi ktora jest tworzona przez podane przez nas wierzcholki
		//zwraca -1 gdy nie ma takiej krawedzi
	int whichEdge(int firstTop, int secondTop);
		//informuje o mozliwosci istnienia/stworzenia krawedzi (poprawnosc indeksow wierzcholkow)
		//zwraca 0 gdy nie moze istniec taka krawedz
		//zwraca 1 gdy taka krawedz moze istniec
	bool possibleEdge(int firstTop, int secondTop) const;
		//informuje o mozliwosci dodania krawedzi o zadanych indeksach wierzcholkow
		//zwraca 0 gdy nie ma takiej krawedzi (mozna taka dodac)
		//zwraca 1 gdy taka krawedz istnieje lub podano zle indeksy etc. (NIE mozna takiej dodac)
	bool isThisEdgeFree(int firstTop, int secondTop) const;
		//wypisuje na ekran cala macierz
	void printEntireMatrix() const;
		//ustala(badz zmienia) wierzcho³ki do których nale¿y zadana krawêdŸ
		//gdy ktorekolwiek indeksy sa bledne zwraca 1 i wypisuje komunikat bledu 
		//gdy taka krawedz juz istnieje zwraca 1 i wypisuje komunikat bledu
		//gdy operacja sie udaje zwraca 0
	bool setTopsOfEdge(int selectedEdge, int newOwner1, int newOwner2);
		//funckja zwraca indeksy wybranej krawedzi poprzez zmiane waratosci referowanych integerow
		//jesli graf prosty, to pierwszy indeks bedzie wiekszy od drugiego
		//jesli digraf, to pierwszy indeks jest poczatkiem, a drugi koncem krawedzi
		//gdy indeksy wierzcholkow zostana poprawnie pobrane i wpisane pod referowane zmienne: zwraca 0
		//gdy indeks krawedzi jest bledny zwraca 1, a pod referowane zmienne podstawia -2137
		//gdy macierz ma bledna lub pusta reprezentacje zwraca 1 i postawia -2137
		//cokolwiek niespodziewanego sie zdazy : podstawi -2137
	bool getTopsOfEdge(int selectedEdge, int& storageInt1, int& storageInt2) const;
		//dodaje nowa krawedz nalezaca do zadanych wierzcholkow (realokacja pamieci)
		//gdy uzyjesz zlych nieporawnych indeksow lub taka krawedz juz istnieje: zwraca 1 i wypisuje blad
		//gdy pomyslnie doda krawedz zwraca 0
	bool addNewEdge(int newOwner1, int newOwner2);
		//gdy krawedz nie istnieje zwraca 1
		//gdy usunie pomyslnie zwraca 0
	bool deleteEdge(int selectedEdge);
		//gdy wierzcholek nie istnieje zwraca 1
		//gdy usunie pomyslnie zwraca 0
	bool deleteTop(int unwantedTop);
		//powoduje destrukcje wszechswiata oraz usuniecie macierzy
	~IncidenceMatrix();
		//zwraca liczbe wierzcholkow
	const int getTop() const { return top; }
		//zwraca liczbe krawedzi
	const int getEdge() const { return edge; }
		//te¿ zwraca liczbe wierzcholkow
	const int getN() const { return top; }
		//te¿ zwraca liczbe krawedzi
	const int getL() const { return edge; }
		//zwraca graf dla QT
	int** getMatrix() const { return matrix; }
private:
		//wierzcholki
	int top;  
		//krawedzie
	int	edge;	
		//macierz incydencji
	int** matrix;
};

