#include<iostream>
#include"SetGraph"
#include"ListGraph"
#include"MatrixGraph"
#include"ArcGraph"
void Test(IGraph* graph, std::string namegraph)
{
	std::cout << "Testing :" << namegraph << std::endl;
	int countVer = 9;
	if (countVer == graph->VerticesCount())
	{
		std::cout << "function VerticesCount() OK";

	}
	else std::cout << "function VerticesCount() FAIL";
	std::vector<int> checkGetNextVertices = graph->GetNextVertices(1);
	std::vector<int>tmp = { 5,2 };
	std::vector < bool >check(2);
	for (size_t i = 0; i < checkGetNextVertices.size(); i++)
	{
		if (checkGetNextVertices[i] == tmp[i])
		{
			check[i] = true;

		}
		else check[i] = false;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 2; i++)
	{
		if (check[i] == true && i == 1) {
			std::cout << "function GetNextVertices(int vertex) OK" << std::endl;
		}
		else if (check[i] == false) { std::cout << "function GetNextVertices(int vertex) FAIL" << std::endl; break; }
	}

	std::vector<int> checkGetPrevVertices = graph->GetPrevVertices(2);
	std::vector<int>tmp2 = { 1,4 };
	std::vector < bool >check2(2);
	for (size_t i = 0; i < checkGetPrevVertices.size(); i++)
	{
		if (checkGetPrevVertices[i] == tmp2[i])
		{
			check2[i] = true;

		}
		else check2[i] = false;
	}

	for (size_t i = 0; i < 2; i++)
	{
		if (check2[i] == true && i == 1) {
			std::cout << "function GetPrevVertices(int vertex) OK" << '\n';
		}
		else if (check2[i] == false) { std::cout << "function GetPrevVertices(int vertex) FAIL" << std::endl; break; }
	}
	IGraph* graph2(graph);
	if (graph2 == graph) {
		std::cout << "OK copy" << std::endl;
	}
	else  std::cout << "fail copy" << std::endl;
	std::cout << "OBJ1 and OBJ2:" << std::endl;
	for (size_t i = 0; i < checkGetNextVertices.size(); i++)
	{
		std::cout << checkGetNextVertices[i] << " ";
	}
	std::cout << std::endl;
	checkGetNextVertices = graph2->GetNextVertices(1);

	for (size_t i = 0; i < checkGetNextVertices.size(); i++)
	{
		std::cout << checkGetNextVertices[i] << " ";
	}

}
int main()
{
	IGraph* graph = new ListGraph(9);
	graph->AddEdge(0, 1);
	graph->AddEdge(1, 5);
	graph->AddEdge(6, 0);
	graph->AddEdge(1, 2);
	graph->AddEdge(2, 3);
	graph->AddEdge(3, 4);
	graph->AddEdge(4, 2);
	graph->AddEdge(0, 7);
	graph->AddEdge(0, 8);

	Test(graph, "ListGraph");
	IGraph* graph = new MatrixGraph(9);
	graph->AddEdge(0, 1);
	graph->AddEdge(1, 5);
	graph->AddEdge(6, 0);
	graph->AddEdge(1, 2);
	graph->AddEdge(2, 3);
	graph->AddEdge(3, 4);
	graph->AddEdge(4, 2);
	graph->AddEdge(0, 7);
	graph->AddEdge(0, 8);

	Test(graph, "MatrixGraph");
	IGraph* graph = new ArcGraph(9);
	graph->AddEdge(0, 1);
	graph->AddEdge(1, 5);
	graph->AddEdge(6, 0);
	graph->AddEdge(1, 2);
	graph->AddEdge(2, 3);
	graph->AddEdge(3, 4);
	graph->AddEdge(4, 2);
	graph->AddEdge(0, 7);
	graph->AddEdge(0, 8);

	Test(graph, "ArcGraph");
	IGraph* Sgraph = new SetGraph(9);
	Sgraph->AddEdge(0, 1);
	Sgraph->AddEdge(1, 5);
	Sgraph->AddEdge(6, 0);
	Sgraph->AddEdge(1, 2);
	Sgraph->AddEdge(2, 3);
	Sgraph->AddEdge(3, 4);
	Sgraph->AddEdge(4, 2);
	Sgraph->AddEdge(0, 7);
	Sgraph->AddEdge(0, 8);

	Test(Sgraph, "SetGraph");
}