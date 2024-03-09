#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main(){

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;cin>>t;
    while(t--){

        string a,b;
        cin>>a;
        b = a;
        reverse(b.begin(),b.end());
        int n = a.size();
        int m = b.size();

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

        // for(int i = 0;i<=n;i++){
        //     for(int j = 0;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //cout<<dp[n][m]<<endl;

        int i = n,j=m;
        vector<char> answer;

        while(i != 0 && j != 0){
            if(a[i-1] == b[j-1]) {
                answer.push_back(a[i-1]);
                i--,j--;
            }
            else{
                if(dp[i][j-1]>dp[i-1][j]){
                    j--;
                }
                else i--;
            }

        }

        reverse(answer.begin(),answer.end());
        for(char x : answer){
            cout<<x;
        }
        cout<<endl;
        
        // deletion / insertion to make a palindrom

        cout<<a.size()-answer.size()<<endl; // answer for both
    }

    return 0;
}