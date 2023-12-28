// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5;
// vector<pair<int,int>> adjacent[N];
// bool visited[N];

// class edges{
//     public :
//     int u,v,w;
//     edges(int u,int v,int w){
//         this->u = u;
//         this->v = v;
//         this->w = w;
//     }
// };

// class compare{
//     public:
//     bool operator()(edges a,edges b){
//         return a.w>b.w;
//     }
// };

// void prims(int source){
//     priority_queue<edges,vector<edges>,compare> pq;
//     pq.push(edges(source,source,0));
//     vector<edges> edge_list;
//     while(!pq.empty()){
//         edges parent = pq.top();
//         pq.pop();
//         int u = parent.u;
//         int v = parent.v;
//         int w = parent.w;
//         if(visited[v]) continue;
//         visited[v] = true;
//         edge_list.push_back(parent);
//         for(pair<int,int> x : adjacent[v]){
//             int xv = x.first;
//             int xw = x.second;
//             if(!visited[xv]) pq.push(edges(v,xv,xw));
//         }
//     }
//     edge_list.erase(edge_list.begin());
//     for(edges x : edge_list){
//         cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
//     }
// }
// int main(){
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int n,e;
//     cin>>n>>e;
//     while(e--){
//         int u,v,w;
//         cin>>u>>v>>w;
//         adjacent[u].push_back({v,w});
//         adjacent[v].push_back({u,w});
//     }
//     prims(1);
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adjacent[1000];
bool visited[1000];
class edges{
    public:
    int u,v,w;
    edges(int u,int v,int w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
class compare{
    public:
    bool operator()(edges a, edges b){
        return a.w>b.w;
    }
};
void prims(int source){
    priority_queue<edges,vector<edges>,compare> myQueue;
    vector<edges> Ed;
    myQueue.push(edges(source,source,0));
    while(!myQueue.empty()){
        edges mainEdge = myQueue.top();
        myQueue.pop();
        if(!visited[mainEdge.v]){
            Ed.push_back(mainEdge);
            visited[mainEdge.v] = true;
            for(pair<int,int> x : adjacent[mainEdge.v]){
                myQueue.push(edges(mainEdge.v,x.first,x.second));
            }
        }
    }
    Ed.erase(Ed.begin());
    for(edges x: Ed){
        cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
    }
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,e;
    cin>>n>>e;
    while(e--){
        int x,y,w;
        cin>>x>>y>>w;
        adjacent[x].push_back({y,w});
        adjacent[y].push_back({x,w});
    }
    prims(1);
}

























