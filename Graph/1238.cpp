#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
// N = number of students  , X = town num ,  m = edges num
//
#define MAXSIZE 10001
#define INF 999999
vector<vector<pair<int,int>>> edges(MAXSIZE);
vector<int>Time(MAXSIZE);
/**
 * 
 * push_back indirection edges to vector
 * @param {int} src 
 * @param {int} dst
 * @param {int} weight
 * */
void insertEdge(int src,int dst,int time){ 
    edges[src].push_back({dst,time});
}
/**
 * solve shortest path using edges
 * @param {int} src : start vertex
 * @param {int} dst : destination vertex
*/
void dijkstra(int src,int dst){
    int dist[MAXSIZE];
    for(int i=0;i<MAXSIZE;i++)
        dist[i] = INF;
    priority_queue<pair<int,int>>pq;
    dist[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int cur_cost = -pq.top().first;
        int cur_vid = pq.top().second;
        pq.pop();
        for(int i=0;i<edges[cur_vid].size();i++){
            int next_vid = edges[cur_vid][i].first;
            int next_cost = cur_cost+ edges[cur_vid][i].second;
            if(dist[next_vid]>next_cost){
                dist[next_vid] = next_cost;
                pq.push({-next_cost,next_vid});
            }
        }
    }
    int src_to_dst = dist[dst]; 
    for(int i=0;i<MAXSIZE;i++)
        dist[i] = INF;
    dist[dst]=0;
    pq.push({0,dst});
    while(!pq.empty()){
        int cur_cost = -pq.top().first;
        int cur_vid = pq.top().second;
        pq.pop();
        for(int i=0;i<edges[cur_vid].size();i++){
            int next_vid = edges[cur_vid][i].first;
            int next_cost = cur_cost+ edges[cur_vid][i].second;
            if(dist[next_vid]>next_cost){
                dist[next_vid] = next_cost;
                pq.push({-next_cost,next_vid});
            }
        }
    }
    int dst_to_src = dist[src];
    Time[src] = src_to_dst+ dst_to_src;
}
int main(){
  int N, M , X; // X goes dst
  cin>>N>>M>>X;
  for(int i=0;i<M;i++){
    int src,dst,time;
    cin>>src>>dst>>time;
    insertEdge(src,dst,time);
  } 
    for(int i=1;i<=N;i++){
        dijkstra(i,X);
    }
    sort(Time.begin(),Time.end(),greater<int>());
    cout<<Time[0]<<"\n";



}
