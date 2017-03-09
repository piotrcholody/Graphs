#include <iostream>
#include "AdjacencyList.h"

int main( void ){

	AdjacencyList *test = new AdjacencyList();

	test -> initList();
	test -> showList();

	return 0;
}