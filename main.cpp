#include "graph.cpp"

int main() {
    Graph G(5,true,true);

    G.AddEdge(0, 1, 1);
    G.AddEdge(1, 2, 3);
    G.AddEdge(3, 2, 5);
    G.AddEdge(4, 1, 6);
    // G.AddEdge(5,1);

    G.Print();

    G.BFS(0);

    cout << endl;

    G.DFS(0);

    return 0;
}