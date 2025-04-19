#include "graph.cpp"

int main() {
    Graph G(5);

    G.AddEdge(0, 1);
    G.AddEdge(1, 2);
    G.AddEdge(3, 2);
    G.AddEdge(4, 1);
    // G.AddEdge(5,1);

    G.Print();

    G.BFS(0);

    cout << endl;

    G.DFS(0);

    return 0;
}