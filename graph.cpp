#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept> 
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Graph {
    public:
        vector<vector<int>> G;
        int size;

        Graph(int n) {
            size = n;
            G.resize(n);
        }

        void AddEdge(int u, int v) {
            if (u >= size || v >= size || u < 0 || v < 0) {
                throw std::out_of_range ("Invalid Node Index !!!");
            }
            G[u].push_back(v);
            G[v].push_back(u);
        }

        void Print(){
            for (int i = 0; i < size; i ++) {
                cout << "Node " << i << ": ";

                for (auto n : G[i]) {
                    cout << n << " ";
                }
                cout << endl;
            }
        }

        void BFS(int u) {
            stack<int> st;

            vector<int> visited(size,false);

            st.push(u);
            visited[u] = true;
            cout << st.top() << " ";

            while(!st.empty()) {
                visited[st.top()] = true;
                for (auto n : G[st.top()]) {
                    if (!visited[n]) {
                        cout << n << " ";
                        st.push(n);
                    }
                }

                if (visited[st.top()]) st.pop();

            }

        }

        void DFSHELPER (vector<bool> &visited, int s, vector<int> &res) {
            visited[s] = true;
            res.push_back(s);

            for (auto node : G[s]) {
                if (!visited[node])
                    DFSHELPER(visited,node,res);
            }
        }

        void DFS(int u) {
            vector<bool> visited(size,false);
            vector<int> res;

            DFSHELPER(visited,u,res);

            for (auto n : res) {
                cout << n << " ";
            }
        }

      

};


#endif