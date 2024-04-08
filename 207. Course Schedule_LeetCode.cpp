#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool TopoLogicalSort(int node, vector<int>& visited, stack<int>& s, vector<vector<int>>& adjlist) {
        // Mark the node as being visited or in visiting state
        if (visited[node] == 1)
            return false; // Cycle detected
        if (visited[node] == 2)
            return true; // Already visited, no need to visit again
        visited[node] = 1; // Mark as visiting

        // Explore neighbors
        for (int neighbor : adjlist[node]) {
            if (!TopoLogicalSort(neighbor, visited, s, adjlist))
                return false; // Cycle detected
        }

        // Mark the node as visited and push it to the stack
        visited[node] = 2;
        s.push(node);
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for (auto& prerequisite : prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adjlist[v].push_back(u);
        }

        vector<int> visited(numCourses, 0); // 0: not visited, 1: visiting, 2: visited
        stack<int> s;
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && !TopoLogicalSort(i, visited, s, adjlist)) {
                return false; // Cycle detected, cannot finish all courses
            }
        }

        return true; // No cycle detected, can finish all courses
    }
};

int main() {
    // Example usage of the Solution class
    Solution solution;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}/*,{0, 1}*/};
    if (solution.canFinish(numCourses, prerequisites)) {
        cout << "It is possible to finish all courses." << endl;
    } else {
        cout << "It is not possible to finish all courses due to cyclic dependencies." << endl;
    }
    return 0;
}
