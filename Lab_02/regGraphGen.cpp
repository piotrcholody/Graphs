#include "regGraphGen.h"

std::vector< int > getMatrixOfPoints(int vertex_counter, int degree) {
	std::vector< int > buckets;
	for (int i = 0; i < vertex_counter; ++i) {
		buckets.push_back(degree);
	}

	return buckets;
}
/*****************************************************************************************/
bool isOnlyOneVertex(std::vector< int > buckets) {
	int flag = 0;
	for (int i = 0; i < buckets.size(); ++i) {
		if (buckets[i])
			++flag;
		if (flag > 1)
			return 0;
	}
	
	if (flag == 1)
		return 1;
	else
		return 0;
}
/*****************************************************************************************/
std::vector< std::vector< int > > getMatrixOfPairs(int edges_counter, int degree) {
	std::vector< std::vector< int > > pairs;
	for (int i = 0; i < edges_counter; ++i)
		pairs.push_back(std::vector< int >(2));

	return pairs;
}
/*****************************************************************************************/
bool isCreatingGraphPossible(int vertex_counter, int degree) {
	return !((vertex_counter * degree) % 2) && vertex_counter >= degree + 1;
}
/*****************************************************************************************/
bool isThisPairExist(int vertex_one, int vertex_two, std::vector< std::vector< int > > pairs, int index) {
	for (int i = 0; i < index; ++i) {
		if (pairs[i][0] == vertex_one || pairs[i][1] == vertex_one) {
			if (pairs[i][0] == vertex_two || pairs[i][1] == vertex_two)
				return 1;
		}
	}
	return 0;
}
/*****************************************************************************************/
IncidenceMatrix& regGraphGen(int vertex_counter, int degree) {
	if (!isCreatingGraphPossible(vertex_counter, degree))
		throw CreatingRegularGraphFailed();
	int edges_counter = vertex_counter * degree / 2;
	int point_one, point_two;
	int i = 0;
	std::vector< int > buckets = getMatrixOfPoints(vertex_counter, degree);
	std::vector< std::vector< int > > pairs = getMatrixOfPairs(edges_counter, degree);
	IncidenceMatrix* incidence_matrix = new IncidenceMatrix(vertex_counter, edges_counter);
	
	while (i < edges_counter) {
		// sprawdza czy oba punkty nie nale¿¹ do jednego wierzcho³ka
		// przejdzie dalej dopiero kiedy oba punkty bêda ró¿ne
		do {
			point_one = randomint(0, static_cast<int>(buckets.size()) - 1);
			point_two = randomint(0, static_cast<int>(buckets.size()) - 1);
			std::cout << "Jestem w while: " << point_one << " i " << point_two << std::endl;
		} while (point_one == point_two);
		std::cout << "Za while" << std::endl;
		std::cout << "buckets[point_one] = " << buckets[point_one] << " buckets[point_two] = " << buckets[point_two] << std::endl;
		// sprawdza czy obie podtablice przechowuja jakis element
		if (buckets[point_one] && buckets[point_two]) {
			std::cout << "Sprawdzamy parê: " << point_one << " i " << point_two << std::endl;
			if (!isThisPairExist(point_one, point_two, pairs, i)) {
				std::cout << "Wszystkie warunki spe³nione" << std::endl;
				pairs[i][0] = point_one;
				--buckets[point_one];
				pairs[i][1] = point_two;
				--buckets[point_two];
				++i;
			}
		}

		if (isOnlyOneVertex(buckets)) {
			std::cout << "Powtarzamy operacje, ta próba zakoñczy³a siê niepowodzeniem" << std::endl;
			i = 0;
			pairs = getMatrixOfPairs(edges_counter, degree);
			buckets = getMatrixOfPoints(vertex_counter, degree);
		}
			
	}

	for (int i = 0; i < pairs.size(); ++i) {
		std::cout << "Para: " << pairs[i][0] << " i " << pairs[i][1] << std::endl;
		incidence_matrix->setTopsOfEdge(i, pairs[i][0], pairs[i][1]);
	}

	return *incidence_matrix;
}