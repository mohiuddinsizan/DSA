#include<bits/stdc++.h>
using namespace std;
int dp[10005][10005];
int counts = 0;
bool subset_sum(int ar[],int sum,int i){

    if(i < 0) {
        if(sum == 0) 
        {   
            counts++;
            return true;
        }
       else return false;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    
    bool op,op2;

    if(sum>=ar[i]){
        op2 = subset_sum(ar,sum-ar[i],i-1);
    }

    op = subset_sum(ar,sum,i-1);

    return dp[i][sum] = op || op2;
}

int main(){

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int n,d;
    cin>>n>>d;
    int ar[n];
    int sum = 0;
    memset(dp,-1,sizeof(dp));
    for(int i = 0;i<n;i++){
        cin>>ar[i];
        sum+=ar[i];
    }

    if(subset_sum(ar,sum-2*d,n-1)) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<counts<<endl;
    return 0;
}