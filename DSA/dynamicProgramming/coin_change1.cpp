#include<bits/stdc++.h>
using namespace std;
int counts = 0;
int dp[1001][1001];
int can(int coins[],int i,int target){
    if(target == 0) {
        return 1;
    }
    if(i<0) return 0;

    int op1 = 0,op2 =  0;

    if(dp[i][target]!=-1) return dp[i][target];

    if(target>=coins[i])
        op1 = can(coins,i,target-coins[i]);
    op2 = can(coins,i-1,target);

    return dp[i][target]=(op1+op2);
}
int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof(dp));
    int n;cin>>n;
    int coins[n];
    for(int i = 0;i<n;i++){
        cin>>coins[i]; 
    }

    int target;cin>>target;
    if(can(coins,n-1,target))cout<<can(coins,n-1,target)<<endl;
    else cout<<"Not Possible";

    return 0;
}

/*
5
5 
1 2 3 4 5
1000
5 
2 3 4 5 6
999
2 
30 40
900
3 
2 6 5
904
2 
2 5
904
*/