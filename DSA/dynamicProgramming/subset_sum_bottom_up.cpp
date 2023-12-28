// #include<bits/stdc++.h>
// using namespace std;
// int main(){

//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     int n;cin>>n;
//     int sum =0;
//     int ar[n];
//     for(int i = 0;i<n;i++){
//         cin>>ar[i];
//         sum+=ar[i];
//     }
//     bool dp[n+1][sum+1];
//     for(int i = 1;i<=n;i++){
//         for(int j = 1;j<=sum;j++){
//             if(ar[i-1]<=j){
//                 dp[i][j] = dp[i-1][j-1];
//             }
//         }
//     }
//     return 0;
// } 