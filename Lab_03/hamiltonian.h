#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "IncidenceMatrix.h"
#include <cmath>
#include <cstdlib>
#include <vector>



	//sprawdza czy nie bylo juz wartosci 'v' w tablicy 'path' ponizej indeksu 'pos'
bool isSafe(IncidenceMatrix& graph, int candidat, std::vector<int> path, int pos)
{
	//std::cout << "przed if:" << std::endl; //fdssdf
	int debug = path[pos - 1];
	//std::cout << "debug:" << debug << std::endl; //fdssdf
	if (graph.isThisEdgeFree(debug, candidat) == 0)
		return false;
	//std::cout << "po if:" << std::endl; //fdssdf

	for (int i = 0; i <= pos; i++) {
		//std::cout << "w ifsafe for nr:" << i << std::endl; //fdssdf
		if (path[i] == candidat)
			return false;
	}
	return true;
}
/******************************************************************/


	//do rekurencji dla cyklu
bool hamCycleUtil(IncidenceMatrix& graph, std::vector<int>& path, int pos)
{
	path[0] = 0;
	if (pos == graph.getTop()) {
		//std::cout << "if" << std::endl;//fdssdf
		if ((graph.isThisEdgeFree(path[pos - 1], path[0]) == 1) && graph.possibleEdge(path[pos - 1], path[0])) {
			path[graph.getTop()] = 0;
			return true;
		}
		else
			return false;
	}

	for (int v = 1; v < graph.getTop(); v++) {
		//std::cout << "for nr:"<<v << std::endl; //fdssdf
		if (isSafe(graph, v, path, pos)) {
			//std::cout << "is safe" << v << std::endl; //fdssdf
			path[pos] = v;
			if (hamCycleUtil(graph, path, pos + 1) == true) {
				return true;
				path[pos] = -1;
			}
		}
	}
	return false;
}
/******************************************************************/


	//do rekurencji dla sciezki
bool hamPathUtil(IncidenceMatrix& graph, std::vector<int>& path, int pos, int first)
{
	path[0] = first;
	if (pos == graph.getTop())
		return true;

	for (int v = 0; v < graph.getTop(); v++) {
		if (isSafe(graph, v, path, pos)) {
			path[pos] = v;
			if (hamPathUtil(graph, path, pos + 1, first) == true) {
				return true;
				path[pos] = -1;
			}
		}
	}
	return false;
}
/******************************************************************/


	//sprawdza rekurencyjna metoda Brute Force czy graf jest Hamiltonowski
	//zwraca tablice o dlugosci (getTop()+1)z numerami kolejnych indeksow wierzcholkow,
	//     ktore tworza cykl Hamiltona lub polHamiltona
	//gdy jest polhamiltonowski, ostatenie pole tablicy wynikowej == -1
	//zwraca pusty vector, gdy nie jest to ani graf hamiltonowski ani polhamiltonowski
std::vector<int> findHamiltionianGraph(IncidenceMatrix& graph)
{
	std::cout << std::endl;
	std::vector<int> path;
	for (int i = 0; i < graph.getTop() + 1; i++)
		path.push_back(-1);
	if (graph.getTop() < 3) {
		std::cout << "Graf polhamiltonowski, sciezka 0,1." << std::endl;
		path[0] = 0;
		path[1] = 1;
		return path;
	}
	if (graph.getEdge() < graph.getTop() - 1) {
		std::cout << "Nie mozna utworzyc z tego grafu ani sciezki, ani cyklu (edge < top - 1)" << std::endl;
		path.erase(path.begin(), path.end());
		return path;
	}

	int c = 0;
	bool canBeHamilton = true;
	bool isHamilton = true;
	bool isHalf = false;
	for (int i = 0; i < graph.getTop(); i++) {
		std::vector<int> t = graph.adjForTop(i);
		c = static_cast<int>(t.size());
		if (c < 2) {
			canBeHamilton = false;
			std::cout << "Graf NIE moze byc hamiltonowski (liczba krawedzi przy choc 1 wierzcholku <2)" << std::endl;
			i = graph.getTop();
			break;
		}
	}

	if (canBeHamilton) {
		std::cout << "Graf moze byc hamiltonowski!" << std::endl;
		if (hamCycleUtil(graph, path, 1) == false) {
			std::cout << "Graf NIE jest hamiltonowski (nie posiada cyklu Hamiltona)!" << std::endl;
			isHamilton = false;
		}
	}
	else
		isHamilton = false;

	if (!canBeHamilton || !isHamilton) { //polhamiltonowski
		int first = 0;
		std::cout << "Graf moze byc polhamiltonowski!" << std::endl;
		isHalf = false;
		while ((first < graph.getTop()) && (!isHalf)) {
			//std::cout << "while dla first="<<first<< std::endl;
			if (hamPathUtil(graph, path, 1, first) == false) {
				isHalf = false;
			}
			else {
				isHalf = true;
				break;
			}
			first++;
		}
	}


	if (isHamilton && canBeHamilton) {
		std::cout << "Graf jest hamiltonowski." << std::endl;
		std::cout << "Cykl Hamiltona:  ";
		for (int i = 0; i < graph.getTop() + 1; i++) {
			std::cout << path[i];
			if (i < graph.getTop())
				std::cout << ",";
		}
		std::cout << std::endl;
	}

	if (isHalf) {
		std::cout << "Graf jest POLhamiltonowski." << std::endl;
		std::cout << "Sciezka Hamiltona:  ";
		for (int i = 0; i < graph.getTop() + 1; i++) {
			std::cout << path[i];
			if (path[i + 1] < 0)
				break;
			if (i < graph.getTop())
				std::cout << ",";
		}
		std::cout << std::endl;
	}

	if (!isHalf && !isHamilton) {
		std::cout << "Nie jest tez jednak polhamiltonowski" << std::endl;
		path.erase(path.begin(), path.end());
	}
	return path;
}
/******************************************************************/