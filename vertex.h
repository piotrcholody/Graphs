#ifndef vertex_h
#define vertex_h
#include <vector>

class vertex{
public:
	vertex();
	vertex( int );
	vertex( std::vector< int > );

	std::vector< int > getGraph( int );
	int retVertVal();

private:
	std::vector< int > _connectedVertices;
};

#endif // vertex_h