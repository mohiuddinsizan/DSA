#include<bits/stdc++.h>
using namespace std;

int row,column;
const int N = 1e3+5;
int distances[N][N];
bool visited[N][N];
char matrix[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool isValid(int y,int x){
    return x>=0 && x<column && y>=0 && y<row;
}

void bfs(int iy,int ix){
    distances[iy][ix] = 0;
    visited[iy][ix] = true;
    queue<pair<int,int>> q;
    q.push({iy,ix});

    while(!q.empty()){
        pair<int,int> parent_pair = q.front();
        q.pop();
        int x = parent_pair.second;
        int y = parent_pair.first;

        for(int i = 0;i<4;i++){
            int child_x = x + dx[i];
            int child_y = y + dy[i];
            if(isValid(child_y,child_x) && !visited[child_y][child_x]){
                visited[child_y][child_x] = true;
                q.push({child_y,child_x});
                distances[child_y][child_x] = distances[y][x] + 1 ;
            }
        }
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    cin>>row>>column;

    for(int i = 0;i<row;i++){

        for(int j = 0;j<column;j++){
            cin>>matrix[i][j];
        }
    }

    int source_x,source_y;
    cin>>source_x>>source_y;
    bfs(source_x,source_y);
    int destination_x,destination_y;
    cin>>destination_x>>destination_y;
    cout<<distances[destination_x][destination_y];
    
    return 0;
}