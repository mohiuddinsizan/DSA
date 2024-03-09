#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int lcs(string a , int ia,string b,int ib){

    if(ia < 0 || ib < 0) return 0;

    if(dp[ia][ib]!= -1) return dp[ia][ib];

    if(a[ia] == b[ib])
        return dp[ia][ib]=lcs(a,ia-1,b,ib-1)+1;

    else{
        int op1 = lcs(a,ia-1,b,ib);
        int op2 = lcs(a,ia,b,ib-1);

        return dp[ia][ib]=max(op1,op2);
    }

}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;cin>>t;

    while(t--){
    
        memset(dp,-1,sizeof(dp));

       
        string a,b;
        cin>>a>>b;

        // to form b from a or b to a !!

        int a1 = lcs(a,a.size()-1,b,b.size()-1);

        int deletion = a.size() - a1;
        int insertion = b.size() - a1;

        cout<<deletion+insertion<<endl;   

    }
    return 0;
}