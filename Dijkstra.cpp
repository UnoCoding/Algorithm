#include<iostream>
#include<vector>
#include<queue>
#define MAX 251
#define INF 999999999
using namespace std;
typedef vector<vector<pair<int,int>>>adjlist;
void insertEdge(int src,int dst, int weight);
void dijkstra(int src,int dst);
adjlist adj(MAX);
int main(){
    int T;
    cin>>T; //test case
    while(T--){
        
        int N,M,Q; // n = number of vertexs, m = number of edges, Q = num of pair we want to know (src,dst)
        cin>>N>>M>>Q;
        for(int i=0;i<M;i++){
            int u,v,w; // u = src, v = dst, w = weight
            cin>>u>>v>>w;
            insertEdge(u,v,w);
        }
        for(int i=0;i<Q;i++){
            int src,dst;
            cin>>src>>dst;
            dijkstra(src,dst);
        }
        adj.clear();
        adj.resize(MAX);
    }
}
void insertEdge(int src,int dst,int weight){
    // guranteed that src!=dst
    adj[src].push_back({dst,weight});
    adj[dst].push_back({src,weight});

}
void dijkstra( int src,int dst){
    vector<int> dist(MAX,INF); //initalize dist
    dist[src]= 0;  // src's distance =0
    priority_queue<pair<int,int>>pq;
    pq.push({0,src}); //push first vertex
    while(!pq.empty()){
        int Cost = -pq.top().first;
        int Cur = pq.top().second;
        pq.pop();
        for(int i=0;i<adj[Cur].size();i++){
            int nextCost = Cost + adj[Cur][i].second;
            int next= adj[Cur][i].first;
            if(nextCost<dist[next]){ //change value
                dist[next] =nextCost;
                pq.push({-nextCost,next});
            }
        }
    }
        cout<<dist[dst]<<"\n"; //print distance
}
