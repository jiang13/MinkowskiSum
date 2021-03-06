#ifndef MINKOWSKI_H
#define MINKOWSKI_H

#include <SFML\Graphics.hpp>
#include <vector>
#include <set>
#include "Math.h"

class Minkowski
{
public:
	//Returns vertices of the sum. If either one of the shapes are not concave, pass in an empty vector
	std::vector<sf::Vector2f> MinkoswkiSum( const std::vector<sf::Vector2f>& verticesA, const std::vector<int>& aReflexIndices, 
											const std::vector<sf::Vector2f>& verticesB, const std::vector<int>& bReflexIndices);

private:
	struct Loop
	{
		std::vector<sf::Vector2f> edges;
	};

	//Constructs the convolution
	//My implementaiton, still working out some bugs.
	void ReducedConvolution(const std::vector<int>& aReflexIndices, const std::vector<int>& bReflexIndices);
	void CalculateCycle(int i0, int j0, const std::vector<int>& aReflexIndices, const std::vector<int>& bReflexIndices);

	//CGAL implementation I use for refrence
	void ReducedConvolution_CGAL(const std::vector<int>& aReflexIndices, const std::vector<int>& bReflexIndices);
	//Constructs adjacency matrix;
	void ConstructAdjacencyMatrix();
	//Cleans up the adjacency matrix and vertices, merging points that are close to each other
	//void MergePoints();
	//Removes duplicate edges. Again not an optimized function
	//void RemoveDuplicateEdges();
	//Mark dangling edges
	void MarkRemainingDanglingEdges();
	//Splits edges at intersection points. At this point, I want to move on to other projects, so I'm just going to brute force it
	void SplitIntersectingEdges();
	//Used for recursively splitting edges returns ALL segements of the original edge
	std::vector<sf::Vector2f> SplitEdgeAtIntersections(sf::Vector2f& a, sf::Vector2f& b, std::vector<sf::Vector2f>& encounteredVertices);

	//Returns the loops of the reduced convolution
	std::vector<Loop> ExtractOrientableLoops();

	//Places edge with largest CW turn from e in out variables.
	bool BestDirection(const sf::Vector2f& start, const sf::Vector2f& end, const std::vector<int> edgeIDs, const int targetID, sf::Vector2f& outStart, sf::Vector2f& outEnd, int& outID);

	//Traces loop starting from e
	Loop RecordLoop(int startIndex, const int targetID);

	//Used during convolution construction
	typedef std::pair<int, int> VisitedEdge;

	std::set<VisitedEdge> m_visited;
	std::vector<sf::Vector2f> m_aVertices;
	std::vector<sf::Vector2f> m_bVertices;
	std::vector<sf::Vector2f> m_aDirections;
	std::vector<sf::Vector2f> m_bDirections;

	std::vector<sf::Vector2f> m_convolution;
	std::vector<sf::Vector2f> m_convolution2;
	std::vector<sf::Vector2f> m_convolutionVertices;
	std::map<sf::Vector2f, int, sfmath::Vector2fComperator> m_vertexToIndex;
	std::vector<std::vector<int>> m_adjacencyMatrix;
	std::set<int> m_danglingEdgeIndices;
	//Returns true if e is between e1 and e2 in the CCW direction
	bool IsBetweenCCW(sf::Vector2f eVec, sf::Vector2f e1Vec, sf::Vector2f e2Vec);

	//Returns the index of the point closest to the origin
	int MinIndex(const std::vector<sf::Vector2f>& vertices);

};


#endif
