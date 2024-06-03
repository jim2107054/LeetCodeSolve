#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>& paths, int node) {
        path.push_back(node);
        if (node == graph.size() - 1) {
            paths.push_back(path);
        } else {
            for (int neighbor : graph[node]) {
                dfs(graph, path, paths, neighbor);
            }
        }
        path.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, path, paths, 0);
        return paths;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> graph1 = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> paths1 = sol.allPathsSourceTarget(graph1);
    for (const auto& path : paths1) {
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
