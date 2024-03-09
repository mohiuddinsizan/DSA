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
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

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