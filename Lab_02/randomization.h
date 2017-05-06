#pragma once
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "IncidenceMatrix.h"


	//randomizacja dwoch krawedzi grafu
	//zwraca 1 gdy tego grafu nie da sie randomizowac (po 100.000 losowan krawedzi nadal nie dalo sie niczego przepiac)
	//zwraca 0 gdy sie udalo
IncidenceMatrix graphRandomization(IncidenceMatrix graph) {
	if (graph.getEdge() >= 2) {
		std::cout << "\nRandomizacja..." << std::endl;
		int a, b, c, d, rand1, rand2, count = 0;
		a = b = c = d = 0;
		bool error1, error2, error3, error4;
		while ((graph.isThisEdgeFree(a, d) || graph.isThisEdgeFree(b, c)) || (graph.isThisEdgeFree(a, c) || graph.isThisEdgeFree(b, d))) {
			if (count < 100000) {
				count++;
				rand1 = randomint(0, graph.getEdge()- 1);
				rand2 = randomint(0, graph.getEdge()- 1);
				while (rand1 == rand2) {
					rand2 = randomint(0, graph.getEdge()- 1);
				}
				error1 = graph.getTopsOfEdge(rand1, a, b);
				error2 = graph.getTopsOfEdge(rand2, c, d);
				if (error1 || error2)
					 throw std::runtime_error("Randomizacja nie powiodla sie!");
			}
			else {
				std::cout << "Nie da sie randomizowac tego grafu!" << std::endl;
				throw std::runtime_error("Randomizacja nie powiodla sie!");
			}
		}
		error3 = graph.setTopsOfEdge(rand1, a, d);
		error4 = graph.setTopsOfEdge(rand2, b, c);
		if (error3 || error4) {
			graph.setTopsOfEdge(rand2, c, d);
			graph.setTopsOfEdge(rand1, a, b);
		}
		else {
			std::cout << "Randomizacja powiodla sie (przepieto krawedzie o indeksach " << rand1 << " i " << rand2 << ")\n" << std::endl;
			return graph;
		}
		error3 = graph.setTopsOfEdge(rand1, a, c);
		error4 = graph.setTopsOfEdge(rand2, b, d);
		if (error3 || error4) {
			graph.setTopsOfEdge(rand2, c, d);
			graph.setTopsOfEdge(rand1, a, b);
		}
		else {
			std::cout << "Randomizacja powiodla sie (przepieto krawedzie o indeksach " << rand1 << " i " << rand2 << ")\n" << std::endl;
			return graph;
		}
		std::cout << "Wylosowana para krawedzi nie mogla zostac zamieniona" << std::endl;
	}
	else {
		std::cout << "Nie da sie randomizowac grafu z mniej niz 2 krawedziami" << std::endl;
		throw std::runtime_error("Randomizacja nie powiodla sie!");
	}
	throw std::runtime_error("Randomizacja nie powiodla sie!");
}
/******************************************************************/