// #include<bits/stdc++.h>
// using namespace std;

// bool visited[100005];
// vector<int> adjacent[100005];
// int counts = 0;
// int parent[100005];

// void dfs(int source){
//     visited[source] = true;

//     for(int x : adjacent[source]){
//         if(!visited[x]){
//             parent[x] = source;
//             dfs(x);
//         }

//         else if(visited[x] && parent[source]!=x){
//             //cout<<source<<" "<<x<<" "<<parent[source]<<endl;
//             counts++;
//         }

//     }
// }

// int main(){

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int n,e;
//     cin>>n>>e;

//     while(e--){
        
//         int u,v;
//         cin>>u>>v;
//         adjacent[u].push_back(v);
//         adjacent[v].push_back(u);
//     }

//     parent[1] = -1;

//     for(int i = 1;i<=n;i++){
//         if(!visited[i]){
//             dfs(i);
//         }
//     }

//     cout<<counts/2;
//     return 0;
// }




// #include<bits/stdc++.h>
// using namespace std;
// int  main(){
//     //freopen("input.txt", "r", stdin);
//     //freopen("output.txt", "w", stdout);
//     long long n,e;
//     cin>>n>>e;
//     long long distances[n+1][n+1];
    
//     for(long long i = 1;i<n+1;i++){
//         for(long long j = 1;j<n+1;j++){
//             distances[i][j] = 9223372036854775807;
//             if(i==j) distances[i][j] = 0;
//         }
//     }

//     for(long long i = 0;i<e;i++){
//         long long u,v,w;
//         cin>>u>>v>>w;
//         if(distances[u][v] == 9223372036854775807)
//             distances[u][v] = w;
//         else if(distances[u][v] != 9223372036854775807 && distances[u][v]>w)
//             distances[u][v] = w;
//     }

//     for(long long k = 1;k<=n;k++){
//         for(long long i = 1;i<=n;i++){
//             for(long long j = 1;j<=n;j++){
//                 if(distances[i][k] != 9223372036854775807 && 
//                     distances[k][j] != 9223372036854775807 && 
//                     distances[i][j] > 
//                     distances[i][k] + distances[k][j]){
//                         distances[i][j] = distances[i][k] + distances[k][j];
//                 }
//             }
//         }
//     }
//     long long t;cin>>t;
//     while(t--){
//         long long s,d;
//         cin>>s>>d;
//         if(distances[s][d] == 9223372036854775807) cout<<-1<<endl;
//         else cout<<distances[s][d]<<endl;
//     }
    
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int parent[100000];
// int parent_size[100000];

// const int N = 1e5+5;
// vector<int> adjacent[N];
// bool visited[N];
// void dfs(int source){
//     visited[source] = true;
//     for(int x : adjacent[source]){
//         if(!visited[x]){
//             dfs(x);
//         }
//     }
// }

// class edges{
//     public :
//     int u,v,w;
//     edges(int u,int v,int w){
//         this->u = u;
//         this->v = v;
//         this->w = w;
//     }
// };
// void dsu_set(int n){
//     for(int i =1;i<=n;i++){
//         parent[i] = -1;
//         parent_size[i] = 1;
//     }
// }
// int dsu_find(int a){
//     while(parent[a] != -1){
//         a = parent[a];
//     }
//     return a;
// }
// void dsu_union(int u,int v){
//     int leader_u = dsu_find(u);
//     int leader_v = dsu_find(v);
//     if(leader_u != leader_v){
//         if(parent_size[leader_u]>parent_size[leader_v]){
//             parent[leader_v] = leader_u;
//             parent_size[leader_u] += parent_size[leader_v];
//         }
//         else{
//             parent[leader_u] = leader_v;
//             parent_size[leader_v]+=parent_size[leader_u];
//         }
//     }
// }

// bool compare(edges a,edges b){
//     return a.w<b.w;
// }

// int main(){
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     int n,e;
//     cin>>n>>e;
//     vector<edges> ed;
//     dsu_set(n);
//     while(e--){
//         int u,v,w;
//         cin>>u>>v>>w;
//         ed.push_back(edges(u,v,w));
//         adjacent[u].push_back(v);
//         adjacent[v].push_back(u);
//     }

//     sort(ed.begin(),ed.end(),compare);
//     vector<edges> answer;
//     for(edges x : ed){
//         int u = x.u;
//         int v = x.v;
//         int w = x.w;
//         if(dsu_find(u)!=dsu_find(v)){
//             answer.push_back(x);
//             dsu_union(u,v);
//         }
//     }


//     // for(edges x : answer){
//     //     cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
//     // }

//     //road reparation

    
//     int com = 0;
//     for(int i = 1;i<=n;i++){
//         if(!visited[i]){
//             com++;
//             dfs(i);
//         }
//     }


//     int sum = 0;
//     for(edges x : answer){
//         sum+=x.w;
//     }
//     if(com==1)
//         cout<<sum;
//     else cout<<-1;


//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int  main(){
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     long long n,e;
//     cin>>n>>e;
//     long long distances[1001][1001];
//     vector<int> nodes;
//     for(long long i = 0;i<1001;i++){
//         for(long long j = 0;j<1001;j++){
//             distances[i][j] = 9223372036854775807;
//             if(i==j) distances[i][j] = 0;
//         }
//     }
    

//     for(long long i = 0;i<e;i++){
//         long long u,v,w;
//         cin>>u>>v>>w;
//         nodes.push_back(u);
//         nodes.push_back(v);
//         distances[u][v] = w;
//     }
//     sort(nodes.begin(), nodes.end());
//     auto it =unique(nodes.begin(), nodes.end());
//     nodes.erase(it, nodes.end());
//     // for(int n : nodes){
//     //     cout<<n<<endl;
//     // }
//     for(int k : nodes){
//         for(int i : nodes){
//             for(int j : nodes){
//                 if(distances[i][k] != 9223372036854775807 && 
//                     distances[k][j] != 9223372036854775807 && 
//                     distances[i][j] > 
//                     distances[i][k] + distances[k][j]){
//                         distances[i][j] = distances[i][k] + distances[k][j];
//                 }
//             }
//         }
//     }

//     long long source ; cin>>source;
//     long long t;cin>>t;

//     if(distances[source][source]==0){
//         while(t--){
//             long long d;
//             cin>>d;
//             if(distances[source][d] == 9223372036854775807) cout<<"Not Possible"<<endl;

//             else cout<<distances[source][d]<<endl;
//        }
    
//     }
//     else cout<<"Negative Cycle Detected"<<endl;
    
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

class edges{
    public:

    long long u;
    long long v;
    long long w;

    edges(long long u,long long v,long long w){
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,e;
    cin>>n>>e;
    vector<edges> edge;

    while(e--){
        long long u,v,w;
        cin>>u>>v>>w;
        edges ed(u,v,w);
        edge.push_back(ed);
    }

    long long distances[n+1];
    for(int i = 0;i<=n+1;i++){
        distances[i] = INT_MAX;
    }


    int source;cin>>source;
    

    bool cycle = false;

    distances[source] = 0;

    for(int i = 1;i<=n;i++){
        for(int j = 0;j<edge.size();j++){
            edges ed = edge[j];
            if((distances[ed.u] != INT_MAX ) && distances[ed.u]+ed.w<distances[ed.v] ){
                distances[ed.v] = distances[ed.u]+ed.w;
            }
        }
    }

    for(int j = 0;j<edge.size();j++){
        edges ed = edge[j];
        if( (distances[ed.u] != INT_MAX && distances[ed.v] != INT_MAX ) && distances[ed.u]+ed.w<distances[ed.v]){
            distances[ed.v] = distances[ed.u]+ed.w;
            cycle = true;
        }
    }
    
    if(!cycle){
        int t;cin>>t;
        for(int j = 0;j<t;j++){
            int d;cin>>d;
            if(distances[d]!=INT_MAX) cout<<distances[d]<<endl;
            else cout<<"NOT POSSIBLE"<<endl;
        }

    }

    else cout<<"Negative Cycle Detected"<<endl;

    return 0;
}