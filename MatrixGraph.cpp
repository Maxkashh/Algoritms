#include<iostream>
#include<cassert>
#include"MatrixGraph.h"
#include<queue>
#include <fstream>
#include <sstream> 
	MatrixGraph ::MatrixGraph(int vertices_count)
	{
		matrix.resize(vertices_count);
		for (int i = 0; i < vertices_count; ++i) 
		{
			matrix[i].resize(vertices_count, 0);
		}
	}

	MatrixGraph:: MatrixGraph(const IGraph& graph)
	{
		size_t size = graph.VerticesCount();
		if (size == 0)
		{
			MatrixGraph(0);
			return;
		}
		matrix.resize(size);
		for (int i = 0; i < size; ++i) 
		{
			matrix[i].resize(size, 0);
		}

		std::vector<bool> visited(size, false);
		for (int i = 0; i < size; ++i)
		{
			if (!visited[i]) 
			{
				visited[i] = true;
				for (auto& vertex : graph.GetNextVertices(i)) 
				{
					this->AddEdge(i, vertex);
				}
			}
		}
	}

	void MatrixGraph:: AddEdge(int from, int to)  
	{
		matrix[from][to] = 1;
	}

	int MatrixGraph:: VerticesCount() const
	{
		return matrix[0].size();
	}

	std::vector<int> MatrixGraph::GetNextVertices(int vertex) const
	{
		std::vector<int> result;
		for (int i = matrix[0].size()-1; i >0; --i)
		{
			if (matrix[vertex][i] != 0) 
			{
				result.push_back(i);
			}
		}
		return result;
	}

	std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const
	{
		std::vector<int> result;
		for (int i = 0; i < matrix[0].size(); ++i)
		{
			if (matrix[i][vertex] != 0) 
			{
				result.push_back(i);
			}
		}
		return result;
	}

	MatrixGraph ::~MatrixGraph() {}
	void dfs_aux(const IGraph& graph, int vertex, std::vector<bool>& visited, void(*callback)(int v)) {
		visited[vertex] = true;
		callback(vertex);

		std::vector<int> children = graph.GetNextVertices(vertex);
		for (auto& child : children) {
			if (!visited[child]) {
				dfs_aux(graph, child, visited, callback);
			}
		}
	}

	 
 