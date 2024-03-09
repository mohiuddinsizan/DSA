#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int knapscak(int weight[],int val[],int i,int bag){
    if(i<0) return 0;
    if(dp[i][bag]!=-1) return dp[i][bag];
    int op1 = INT_MIN,op2=INT_MIN;
    if(bag>=weight[i])
        op1 = knapscak(weight,val,i,bag-weight[i]) + val[i];
    op2 = knapscak(weight,val,i-1,bag);
    return dp[i][bag]=max(op1,op2);
}
int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    int bag;cin>>bag;
    int val[n];
    int weight[n];
    for(int i = 0;i<n;i++){
        cin>>val[i];
    }
    for(int i = 0;i<n;i++){
        cin>>weight[i];
    }
   
    cout<<knapscak(weight,val,n-1,bag);


    return 0;
}