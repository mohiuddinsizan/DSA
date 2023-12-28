// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     int t;cin>>t;
//     while(t--){
//         long long  n;cin>>n;
//         vector<long long> axis;
//         for(long long  i = 0;i<n;i++){
//             long long x;cin>>x;
//             axis.push_back(x);
            
//         }

//         long long max1=INT_MIN,max2=INT_MIN;
//         int index1 , index2 ; 

//         for(long long  i = 0;i<n;i++){
//             if(axis[i]>=max1){
//                 max1 = axis[i];
//                 index1 = i;
//             }
//         }

//         for(long long  i = 0;i<n;i++){
//             if(axis[i] >= max2 && axis[i] < max1){
//                 max2 = axis[i];
//                 index2 = i;
//             }
//         }
//         if(index1>index2) cout<<index2<<" "<<index1<<endl;
//         else cout<<index1<<" "<<index2<<endl;
        
        

//     }

//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// int lcs(string word1,int n,string word2,int m){

//     if(n<=0 || m<=0 ) return 0;

//     if(word1[n-1] == word2[m-1]){
//         return lcs(word1,n-1,word2,m-1)+1;
//     }
//     else{
//         return max(lcs(word1,n-1,word2,m),lcs(word1,n,word2,m-1));
//     }

// }

// int main(){
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);
//     string word1,word2;
//     while(cin>>word1>>word2){
        
//         int n = word1.size();
//         int m = word2.size();

//         if(lcs(word1,n,word2,m) == m) cout<<"Possible"<<endl;
//         else cout<<"Impossible"<<endl;
//     }
    

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     int t;cin>>t;
//     while(t--){
//         string s;cin>>s;
//         int siz_e = s.size();
//         int zaza=0,kaza=0;
//         int counts = 0;
//         int tracker = 1;
//         vector <int> counters;
//         for(int i = 0;i<siz_e;i++){

//             if(s[i] == '0'){
//                 if(counts==0) continue;
//                 counters.push_back(counts); 
//                 counts=0;
//             }

//             else if(i == siz_e-1 && s[i] == '1'){
//                 counters.push_back(counts+1);
//                 counts=0;
//             }

//             else counts++;
//         }
//         sort(counters.begin(),counters.end());
//         reverse(counters.begin(),counters.end());
//         // for(int i = 0;i<counters.size();i++){
//         //     cout<<counters[i]<<endl;
//         // }
//         // cout<<endl;
//         for(int i = 0;i<counters.size();i++){
//             if(i%2 == 0)
//                 zaza+=counters[i];
//         }
//         cout<<zaza<<endl;
//         //cout<<endl;
       
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     int n;
//     cin>>n;

//     for(int i = 1;i<=n;i++){

//         for(int j = 0;j<n;j++){

//             if(i == 1) cout<<i+j;
//             else if(j==0 || i == n) cout<<i;
//             else if(j == n-1) cout<<j+1;
//             else cout<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const long long N = 1e5+5;
// vector<pair<long long,long long>> adjacent[N];
// vector<long long> adjacent2 [N];
// bool visited[N];
// bool visited2[N];

// class edges{
//     public :
//     long long u,v,w;
//     edges(long long u,long long v,long long w){
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

// pair<long long,long long> prims(long long source){
//     priority_queue<edges,vector<edges>,compare> pq;
//     pq.push(edges(source,source,0));
//     vector<edges> edge_list;
//     while(!pq.empty()){
//         edges parent = pq.top();
//         pq.pop();
//         long long u = parent.u;
//         long long v = parent.v;
//         long long w = parent.w;
//         if(visited[v]) continue;
//         visited[v] = true;
//         edge_list.push_back(parent);
//         for(pair<long long,long long> x : adjacent[v]){
//             long long xv = x.first;
//             long long xw = x.second;
//             if(!visited[xv]) pq.push(edges(v,xv,xw));
//         }
//     }
//     edge_list.erase(edge_list.begin());
//     long long sum = 0;
//     for(edges x : edge_list){
//         //cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
//         sum+=x.w;
//     }
//     pair<long long, long long> answer = make_pair(edge_list.size(), sum);
//     return answer;
// }

// void dfs(long long i){
//     visited2[i] = true;
//     for(long long x : adjacent2[i]){
//         if(!visited2[x]){
//             dfs(x);
//         }
//     }
// }

// int main(){

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     long long n,e;
    
//     cin>>n>>e;
//     long long b = e;
//     while(e--){
//         long long u,v,w;
//         cin>>u>>v>>w;
//         adjacent[u].push_back({v,w});
//         adjacent[v].push_back({u,w});
//         adjacent2[u].push_back(v);
//         adjacent2[v].push_back(u);
//     }
//     long long comp = 0;
//     for(long long i = 1;i<=n;i++){
//         if(!visited2[i]){
//             comp++;
//             dfs(i);
//         }
//     }

//     if(comp>1) cout<<"Not Possible"<<endl;
//     else{
//         pair<long long,long long> ans = prims(1);

//         cout<<b-ans.first<<" "<<ans.second<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// const long long N = 1e5+5;
// vector<long long> adjacent2 [N];
// bool visited2[N];

// void dfs(long long i){
//     visited2[i] = true;
//     for(long long x : adjacent2[i]){
//         if(!visited2[x]){
//             dfs(x);
//         }
//     }
// }

// int main(){

//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     long long n,e;
    
//     cin>>n>>e;
//     long long b = e;
//     while(e--){
//         long long u,v;
//         cin>>u>>v;
//         // adjacent[u].push_back({v,w});
//         // adjacent[v].push_back({u,w});
//         adjacent2[u].push_back(v);
//         adjacent2[v].push_back(u);
//     }
//     long long comp = 0;
//     for(long long i = 1;i<=n;i++){
//         if(!visited2[i]){
//             comp++;
//             dfs(i);
//         }
//     }

//     if(comp>1) cout<<"NO"<<endl;
//     else{
//         cout<<"YES";
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5;
// vector<int> adjacent[N];
// bool visited[N];
// int distances[N];

// void bfs(int source){
//     visited[source] = true;
//     queue<int> q;
//     q.push(source);
//     distances[source] = 0;

//     while(!q.empty()){
//         int parent = q.front();
//         q.pop();
//         for(int x : adjacent[parent]){
//             if(!visited[x]){
//                 distances[x] = distances[parent] + 1;
//                 visited[x] = true;
//                 q.push(x);
//             }
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

//     int x,y,k;
//     cin>>x>>y>>k;

//     bfs(x);
//     //cout<<distances[y]<<endl;
//     if(distances[y] > 0 && distances[y]<=k*2) cout<<"YES"<<endl;
//     else cout<<"NO"<<endl;


//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// const long long N = 1e9+7;
// long long dp[201][1001];
// long long counts = 0;
// long long subset_sum(long long ar[],long long sum,long long i){

//     if(i < 0) {
//         if(sum == 0) 
//         {   
//             return 1;
//         }
//        else return 0;;
//     }
//     if(dp[sum][i] != -1) return dp[sum][i];

//     long long op1=0,op2=0;

//     if(sum>=ar[i]){
//         op1 = subset_sum(ar,sum-ar[i],i-1);
//     }
//     op2 = subset_sum(ar,sum,i-1);

//     return  dp[sum][i] = (op1 + op2);
// }

// int main(){

//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     long long t;cin>>t;
//     while(t--){
//         long long n,d;
//         cin>>n>>d;
//         long long ar[n];
//         long long sum = 0;
//         memset(dp,-1,sizeof(dp));
//         for(long long i = 0;i<n;i++){
//             cin>>ar[i];
//             sum+=ar[i];
//         }
//         long long answer = subset_sum(ar,2*d,n-1);
//         cout<<answer%N<<endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int counts = 0;
// int dp[1001][1001];
// bool can(int coins[],int i,int target){

//     if(target == 0) {
//         return true;
//     }

//     if(i<0) return false;

//     bool op1 = 0,op2 =  0;

//     //if(dp[i][target]!=-1) return dp[i][target];

//     if(target>=coins[i])
//         op1 = can(coins,i-1,target-coins[i]);
//     op2 = can(coins,i-1,target);

//     return (op1||op2);
// }
// int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     memset(dp,-1,sizeof(dp));
//     int n;cin>>n;
//     int coins[n];
//     int sum = 0;
//     for(int i = 0;i<n;i++){
//         cin>>coins[i]; 
//         sum+=coins[i];
//     }

//     int target=sum/2;

//     if(can(coins,n-1,target)) cout<<"yes"<<endl;

//     else cout<<"Not Possible";

//     return 0;
// }

/*5
10 20 30 40 50
4
1 2 3 10*/
/*
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int answer(int weights[],int values[],int i,int bag_weight){

    if(i < 0){
        return 0;
    }
    
    int op1 = INT_MIN,op2=INT_MIN;
    if(dp[i][bag_weight]!=-1) return dp[i][bag_weight];
    if(bag_weight>=weights[i])
        op1 = answer(weights,values,i-1,bag_weight-weights[i]) + values[i];
    op2 = answer(weights,values,i-1,bag_weight) + 0;

    return dp[i][bag_weight]=max(op1,op2);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;cin>>t;

    for(int i = 0;i<t;i++){
        memset(dp,-1,sizeof(dp));
        int n;cin>>n;
        int bag_weight;cin>>bag_weight;
        int weights[n];
        int values[n];
        for(int i = 0;i<n;i++){
            cin>>weights[i];
        }
        for(int i = 0;i<n;i++){
            cin>>values[i];
        }
        
        cout<<answer(weights,values,n-1,bag_weight)<<endl;
    }

    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int answer(int values[],int i,int bag_weight){

    if(i < 0){
        return 0;
    }
    if(bag_weight<0) return 0;
    int op1 = INT_MIN,op2=INT_MIN;

    if(dp[i][bag_weight]!=-1) return dp[i][bag_weight];

    op1 = answer(values,i-1,bag_weight-values[i]) + values[i];
    op2 = answer(values,i-1,bag_weight) + 0;

    return dp[i][bag_weight]=max(op1,op2);
}
int main(){
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    int sum = 0;
    int values[n];
    for(int i = 0;i<n;i++){
        cin>>values[i];
        sum += values[i];
    }
    int bag_weight=sum/2;
        
    cout<<answer(values,n-1,bag_weight)<<endl;

    return 0;
}