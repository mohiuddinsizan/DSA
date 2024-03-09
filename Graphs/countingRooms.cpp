#include<bits/stdc++.h>
using namespace std;
char matrix[1000][1000];
bool visited[1000][1000];
int n,m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool is_valid(int x,int y){
    return y>=0 && y<m && x>=0 && x<n;
}
void dfs(int i,int j){
    visited[i][j] = true;
    for(int k = 0;k<4;k++){
        if(is_valid(i+dx[k],j+dy[k]) && !visited[i+dx[k]][j+dy[k]] && matrix[i+dx[k]][j+dy[k]] =='.'){
            dfs(i+dx[k],j+dy[k]);
        }
    }
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin>>n>>m;
    for(int i= 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int room = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(matrix[i][j] == '.' && !visited[i][j]){
                room++;
                dfs(i,j);
            }
        }
    }
    cout<<room;
    return 0;
}