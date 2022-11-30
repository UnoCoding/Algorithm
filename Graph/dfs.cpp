#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<pair<int,int>>v;
vector<bool>visited(1000);
vector<vector<int>>edges(1000);
void dfs(int v1){
    if(visited[v1]==true)
        return;
    visited[v1]=true;
    cout<<v1<<"\n";
    for(int i=0;i<edges[1].size();i++){
        dfs(edges[v1][i]);
    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;cin>>N>>M;
        for(int i=0;i<N;i++){
            int height;cin>>height;
            v.push_back({height,i});
        }
        for(int i=0;i<M;i++){
            int u,v;cin>>u>>v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<N;i++){
            sort(edges[i].begin(),edges[i].end());
        }
        for(int i=0;i<N;i++)
            dfs(v[i].second);
        v.clear(); v.resize(1000);
        edges.clear();edges.resize(1000);
        visited.clear();visited.resize(1000);


    }
}
/*
 Floyd_Warshall;
*/
