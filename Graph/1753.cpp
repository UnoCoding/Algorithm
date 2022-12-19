#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAXSIZE 20000
#define INFINTE 999999
vector<vector<pair<int,int>>> edges(MAXSIZE);  
/**
 * push_back indirection edges
 * @param {int} v_id1
 * @param {int} v_id2
 * @param {int} weight
*/
void insertEdge(int u,int v,int w){
    edges[u].push_back({v,w});
}
/**
 * dijkstar algorithm
 * @param {int} start vertex id
 * @param {int} number of vertexs
*/
void dijkstar(int start_vid,int n_vertexs){
    int *dist = new int[n_vertexs+1];
    for(int i=1;i<=n_vertexs;i++)
        dist[i] = INFINTE;
    priority_queue<pair<int,int>>pq;
    pq.push({0,start_vid});
    dist[start_vid]=0;
    while(!pq.empty()){
        int cur_cost = -pq.top().first;
        int cur_vid = pq.top().second;
        pq.pop();
        for(int i=0;i<edges[cur_vid].size();i++){
            int next_cost = cur_cost + edges[cur_vid][i].second;
            int next_vid = edges[cur_vid][i].first;
            if(dist[next_vid]>next_cost){
                dist[next_vid] = next_cost;
                pq.push({-next_cost,next_vid});
            }
        }
    }
    for(int i=1;i<=n_vertexs;i++){
        if(dist[i]==INFINTE)
            cout<<"INF"<<"\n";
        else cout<<dist[i]<<"\n";
    }
}
int main(){
    int V,E;
    cin>>V>>E;
    int K;cin>>K;
    for(int i=0;i<E;i++){
        int u,v,w;
        cin>>u>>v>>w;
        insertEdge(u,v,w);
    }
    dijkstar(K,V);
    return 0;
}
