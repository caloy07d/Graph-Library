#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stdexcept> 
#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;

class Graph {
    public:
        vector<vector<int>> G;
        int size;
        bool directed = false;
        bool weighted = false;
        vector<vector<vector<int>>> edgeWeight;

        struct CompareSecond {
            bool operator () (const pair<int,int>& a, const pair<int,int>& b) {
                return a.second > b.second;
            }
        };
        

        Graph(int n) {
            size = n;
            G.resize(n);
        }

        Graph(int n,bool type) {
            size = n;
            G.resize(n);
            directed = type;
        }

        Graph(int n,bool type,bool w) {
            size = n;
            G.resize(n);
            weighted = w;
            directed = type;
            if (weighted) {
                edgeWeight.resize(n);
                for (int i = 0; i < n; ++i) {
                    edgeWeight[i].resize(n); 
                }
            }
            
        }
// Directed W/O Weight
        void AddEdge(int u, int v) {
            if (u >= size || v >= size || u < 0 || v < 0) {
                throw std::out_of_range ("Invalid Node Index !!!");
            }
            if (directed == true) {
                G[u].push_back(v);
            } else {
                G[u].push_back(v);
                G[v].push_back(u);
            }
         
        }
// Directed with Weight
        void AddEdge(int u, int v,int w) {
            if (u >= size || v >= size || u < 0 || v < 0) {
                throw std::out_of_range ("Invalid Node Index !!!");
            }
            if (directed == true) {
                G[u].push_back(v);
                if (weighted)
                    edgeWeight[u][v].push_back(w);
            } else {
                G[u].push_back(v);
                G[v].push_back(u);
                if (weighted) {
                    edgeWeight[u][v].push_back(w);
                    edgeWeight[v][u].push_back(w);
                }
          
            }
         
        }

        void Print(){
            cout << "Graph Information" << endl;
            
            if (directed)
                cout << "Type of Graph : Directed ";
            else 
                cout << "Type of Graph : Undirected ";
                
            if (weighted) {
                cout << "Weigted Graph" << endl;

                for (int i = 0; i < size; i ++) {
                    cout << "Node " << i << ": ";
    
                    for (auto n : G[i]) {
                        cout << "( " << n << " weight : " << edgeWeight[i][n][0] << ") ";
                    }
                    cout << endl;
                }
            }
            else {
                cout << "Unweigted Graph" << endl;

                for (int i = 0; i < size; i ++) {
                cout << "Node " << i << ": ";

                for (auto n : G[i]) {
                    cout << n << " ";
                }
                cout << endl;
                }
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

        vector<int> Djikstra(int src) {
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
            vector<bool> visited(size, false);
            vector<int> dist(size, INT_MAX);
        
            pq.push({0, src});
            dist[src] = 0;
        
            while (!pq.empty()) {
                int currDist = pq.top()[0];
                int currentNode = pq.top()[1];
                pq.pop();
        
                if (!visited[currentNode]) {
                    visited[currentNode] = true;
            
                    for (int neighbor : G[currentNode]) {
                        int weight = edgeWeight[currentNode][neighbor][0];
                        
                        if (!visited[neighbor] && dist[neighbor] > dist[currentNode] + weight) {
                            dist[neighbor] = dist[currentNode] + weight;
                            pq.push({dist[neighbor], neighbor});
                        }
                    }
                }
            
            }
        
            return dist;
        }

      

};


#endif