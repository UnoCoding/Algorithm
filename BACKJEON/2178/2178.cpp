#include<iostream>
#include<queue>
using namespace std;
char matrix[101][101];
bool visited[101][101];
int check[101][101];
int dx[4]={1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M;
void init(void){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            matrix[i][j]=-1;
            visited[i][j]=false;
        }
    }
}
void bfs(int x,int y){
    visited[x][y]= true;
    check[x][y]=1;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(matrix[next_x][next_y]=='1'&& visited[next_x][next_y]==false){
                visited[next_x][next_y] =true;
                check[next_x][next_y] = check[cur_x][cur_y]+1;
                q.push({next_x,next_y});
            }
        }
    }
        cout<<check[N][M]<<"\n";
}
int main(){
    cin>>N>>M;
    init();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>matrix[i][j];
        }
    }
    bfs(1,1);
}
