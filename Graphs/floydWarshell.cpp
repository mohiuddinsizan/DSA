#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,e;
    cin>>n>>e;
    int distances[n+1][n+1];
    
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<n+1;j++){
            distances[i][j] = INT_MAX;
            if(i==j) distances[i][j] = 0;
        }
    }

    for(int i = 0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        distances[u][v] = w;
        distances[v][u] = w;
    }

    int threshold ;
    cin>>threshold;
    int answer[101];
    for(int i = 0;i<101;i++){
        answer[i] = 0;
    }
    
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(distances[i][k] != INT_MAX && 
                    distances[k][j] != INT_MAX && 
                    distances[i][j] > 
                    distances[i][k] + distances[k][j]){
                        distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    int mn = INT_MAX;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j) continue;
            //cout<<distances[i][j]<<" ";
            if(distances[i][j]<=threshold){
                answer[i]++;
            }

        }
        //cout<<endl;
    }

    for(int i = 0;i<101;i++){
        if(answer[i]<mn  && answer[i]>0) {
            mn = answer[i];
        }
        
    }
    for(int i = 0;i<101;i++){
        if(answer[i] == mn ) {
            cout<<i<<" ";
        }
    } 



    
    return 0;
}