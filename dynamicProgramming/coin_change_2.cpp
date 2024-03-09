#include<bits/stdc++.h>
using namespace std;

// dp is not working correctly here !!! recurrsion is finely working !! 

int dp[1000][1000];

int coin_required(int coins[],int target,int i,int coin){

    if(target == 0) return coin;
    if(i<0) return INT_MAX;

    int op1 = INT_MAX,op2 = INT_MAX;
    if(dp[i][target]!= -1) return dp[i][target];
    if(target>=coins[i])
        op1 = coin_required(coins,target-coins[i],i,1+coin);
    op2 = coin_required(coins,target,i-1,coin);

    return dp[i][target] = min(op1,op2);
}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    int coins[n];

    for(int i = 0;i<n;i++){
        cin>>coins[i];
    }

    int target;cin>>target;
    cout<<coin_required(coins,target,n-1,0);

    return 0;
}