#pragma once
#include"IGraph.h"
#include<unordered_set>
 
class SetGraph : public IGraph
{
public:
	SetGraph(const IGraph& graph);
	SetGraph(int vertices_count);

	SetGraph(const IGraph* graph);
	 
	void AddEdge(int from, int to) override;
	int VerticesCount() const override;
	std::vector<int> GetNextVertices(int vertex) const override;
	std::vector<int> GetPrevVertices(int vertex) const override;
	~SetGraph();
private:
	std::vector<std::unordered_set<int>> vertices;

};