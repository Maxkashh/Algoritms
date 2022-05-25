
#include<vector>
#include"IGraph.h"
#include<iostream>
#include"SetGraph.h"
#include<cassert>
 
SetGraph ::SetGraph(int vertices_count) {
		vertices.resize(vertices_count);
	}

SetGraph::SetGraph(const IGraph* graph)  
	:vertices(graph->VerticesCount())
{
	 
	 
		for (size_t from = 0; from < vertices.size(); ++from)
		{
			for (const auto& to : graph->GetNextVertices(from))
			{
				vertices[from].insert(to);
			}
		}
	 
}

	void SetGraph:: AddEdge(int from, int to)   {
		assert(from < vertices.size());
		assert(to < vertices.size());
			vertices[from].insert(to);
		 
	}

	int SetGraph:: VerticesCount() const   {
		return vertices.size();
	}

	std::vector<int> SetGraph:: GetNextVertices(int vertex) const   {
		assert(vertex < vertices.size());
		std::vector<int> tmp;
		for (const auto& to : vertices[vertex]) {
			tmp.push_back(to);

		}
		   
		return tmp ;
	}

	std::vector<int> SetGraph:: GetPrevVertices(int vertex) const   {
		assert(vertex < vertices.size());
		std::vector<int> result;
		for (size_t from = 0; from < vertices.size(); ++from) 
		{
			if (vertices[from].find(vertex) != vertices[from].end()) {
				result.push_back(from);
				//break;
			}
		}
		return result;
	}

	SetGraph ::~SetGraph() {}
 

 