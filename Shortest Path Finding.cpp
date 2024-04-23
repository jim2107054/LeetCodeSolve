#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int>>&adjList, int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u);
}

//the shortest path.
vector<int> shortestPath(vector<vector<int>>&adjList,vector<bool>&visited,int start, int end){
   vector<int>parent;
   queue<int>q;
   visited[start]=true;
   q.push(start);
   parent[start]=-1;

   while(!q.empty()){
    int frontNode = q.front();
    q.pop();

    for(auto neighbor:adjList[frontNode]){
        if(!visited[neighbor]){
            visited[neighbor]=true;
            parent[neighbor]=frontNode;
            q.push(neighbor);
        }
     }
   }

   //prepare shortest path.
   vector<int>ans;
   int currentNode = end;
   ans.push_back(currentNode);
   while(currentNode != start){
    currentNode = parent[currentNode];
    ans.push_back(currentNode);
   }

   reverse(ans.begin(),ans.end());
   return ans;
}

int main()
{
    int v=5;
    int e=6;
    vector<vector<int>>adjList;
    int a,b;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        addEdge(adjList,a,b);
    }


}
