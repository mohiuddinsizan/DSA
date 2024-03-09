#include<bits/stdc++.h>
using namespace std;
int adjacent[101][101];
bool visited[101];
int parent[101];
int out_flows[101];
int in_flows[101];
int source,sink;

bool BFS(){
    queue<int> myQueue;
    myQueue.push(source);
    visited[source] = true;
    while(!myQueue.empty()){
        parent[source] = -1;
        int vertex = myQueue.front();
        myQueue.pop();

        for(int i = 0;i<101;i++){
            if(adjacent[vertex][i]!=INT_MAX && adjacent[vertex][i] > 0 && (!visited[i])){
                myQueue.push(i);
                parent[i] = vertex;
                visited[i] = true;
                if(i == sink) return true;
            }
        }

    }

    return false;
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    for(int i = 0;i<101;i++){
        for(int j = 0;j<101;j++){
            adjacent[i][j] = 0;
        }
    }

    int n,e;
    cin>>n>>e;

    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adjacent[u][v] = w;
    }

    cin>>source>>sink;


    int max_flow = 0;


    while(BFS()){

        int min_capacity = INT_MAX;
        int x = sink;

        while(parent[x]!=-1){
            if(adjacent[parent[x]][x] < min_capacity){
                min_capacity = adjacent[parent[x]][x];
            }
            x = parent[x];
        }

        max_flow += min_capacity;
        x = sink;

        while(parent[x]!=-1){
            adjacent[parent[x]][x] -= min_capacity;
            adjacent[x][parent[x]] += min_capacity;
            out_flows[parent[x]]+=min_capacity;
            in_flows[x]+=min_capacity;
            x = parent[x];
        }

        for(int i = 0;i<101;i++){
            visited[i] = false;
        }

        for(int i = 0;i<101;i++){
            parent[i] = 0;
        }

        for(int i = 0;i<101;i++){
            visited[i] = false;
        }
    }
    int answer = INT_MIN;
    int answer_node ;
    for(int i = 1;i<=n;i++){
        if(i == sink || i == source) continue;
        if(out_flows[i]>answer){
            answer = out_flows[i];
            answer_node = i;
        }
        if(in_flows[i]>answer){
            answer = in_flows[i];
            answer_node = i;
        }
    }

    cout<<answer_node<<" "<<answer<<endl;

    return 0;
}
