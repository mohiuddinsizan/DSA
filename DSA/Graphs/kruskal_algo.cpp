// #include<bits/stdc++.h>
// using namespace std;
// int parent[100000];
// int parent_size[100000];
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
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     int n,e;
//     cin>>n>>e;
//     vector<edges> ed;
//     dsu_set(n);
//     while(e--){
//         int u,v,w;
//         cin>>u>>v>>w;
//         ed.push_back(edges(u,v,w));
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

    

//     int sum = 0;
//     for(edges x : answer){
//         sum+=x.w;
//     }
//     cout<<sum;


//     return 0;
// }