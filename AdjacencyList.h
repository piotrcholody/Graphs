#ifndef AdjacencyList_h
#define AdjacencyList_h
#include <vector>
#include "vertex.h"

class vertex;

class AdjacencyList{
public:

	AdjacencyList();
	void getList();

private:

	std::vector < vertex* > _vertTable;
};


#endif // AdjacencyList_h
