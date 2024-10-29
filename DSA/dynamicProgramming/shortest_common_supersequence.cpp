#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int lcs(string a,int ia,string b,int ib){
    if(ia < 0 || ib < 0 ) return 0;
    if(dp[ia][ib]!=-1) return dp[ia][ib];
    if(a[ia] == b[ib]){
        return dp[ia][ib] = lcs(a,ia-1,b,ib-1)+1;
    }
    else{
        int op1 = lcs(a,ia,b,ib-1);
        int op2 = lcs(a,ia-1,b,ib);
        return dp[ia][ib] = max(op1,op2);
    }
}

int main(){

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        string a,b;
        cin>>a>>b;
        int n = a.size();
        int m = b.size();
        //lcs(a,a.size()-1,b,b.size()-1);
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i==0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }

        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                    if(a[i-1] == b[j-1]){
                        dp[i][j] = dp[i-1][j-1]+1;
                    }
                    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        int i = n,j=m;
        vector<char> answer;

        while(i != 0 && j != 0){
            if(a[i-1] == b[j-1]) {
                answer.push_back(a[i-1]);
                i--,j--;
            }
            else if(dp[i][j-1]<dp[i-1][j]){
                    answer.push_back(a[i-1]);
                    i--;
            }
            else {
                answer.push_back(b[j-1]);
                j--;
            }
        }

        if (i>0){
            while(i--){
                answer.push_back(a[i]);
            }
        }
        if(j>0){
            while(j--){
                answer.push_back(b[j]);
            }
        }

        cout<<answer.size()<<endl;

    }
    return 0;
}