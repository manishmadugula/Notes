// //bfs
#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> graph;
// vector<bool> visited;

int main(int argc, char const *argv[])
{
    // vector<vector<int>> v;
    // v.assign(3, 10);
    // return 0;
    stack<int> s;
    s.push(19);
    return 0;
}

// void bfs(int node)
// {
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while (!q.empty())
//     {
//         int n = q.front();
//         cout << n << endl;
//         q.pop();
//         for (size_t i = 0; i < graph[n].size(); i++)
//             if (!visited[graph[n][i]])
//             {
//                 q.push(graph[n][i]);
//                 visited[graph[n][i]] = 1;
//             }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     int n, e;
//     cin >> n >> e;
//     visited.assign(n, false);
//     graph.assign(n, vector<int>());
//     int a, b;
//     for (size_t i = 0; i < e; i++)
//     {
//         cin >> a >> b;
//         graph[a].push_back(b);
//     }
//     bfs(0);
//     return 0;
// }
