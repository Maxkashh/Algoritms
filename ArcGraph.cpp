#include"ArcGraph.h"
#include<iostream>
	ArcGraph ::ArcGraph(int vertices_count) : vertices_count(vertices_count) {}

	ArcGraph:: ArcGraph(const IGraph& graph) {
		size_t size = graph.VerticesCount();
		if (size == 0) {
			ArcGraph(0);
			return;
		}
		vertices_count = size;

		std::vector<bool> visited(size, false);
		for (int i = 0; i < size; ++i) {
			if (!visited[i]) {
				visited[i] = true;
				for (auto& vertex : graph.GetNextVertices(i)) {
					this->AddEdge(i, vertex);
				}
			}
		}
	}

	void ArcGraph:: AddEdge(int from, int to)   {
		vertices.push_back(std::make_pair(from, to));
	}

	int ArcGraph::VerticesCount() const   {
		return vertices_count;
	}

	std::vector<int> ArcGraph:: GetNextVertices(int vertex) const   {
		std::vector<int> result;
		for (auto& pair : vertices) {
			if (std::get<0>(pair) == vertex) {
				result.push_back(std::get<1>(pair));
			}
		}
		return result;
	}

	std::vector<int> ArcGraph::GetPrevVertices(int vertex) const   {
		std::vector<int> result;
		for (auto& pair : vertices) {
			if (std::get<1>(pair) == vertex) {
				result.push_back(std::get<0>(pair));
			}
		}
		return result;
	}

	ArcGraph ::	~ArcGraph() {}
	 
