#pragma once
#include"IGraph.h"
#include<vector>
class ArcGraph : public IGraph
{
public:
	ArcGraph(int vertices_count);
	ArcGraph(const IGraph& graph);
	void AddEdge(int from, int to) override;
	int VerticesCount() const override;
	std::vector<int> GetNextVertices(int vertex) const override;
	std::vector<int> GetPrevVertices(int vertex) const override;
	~ArcGraph();
private:
	std::vector<std::pair<int, int>> vertices;
	int vertices_count;
};