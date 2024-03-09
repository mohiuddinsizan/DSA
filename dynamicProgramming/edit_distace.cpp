#include<bits/stdc++.h>
using namespace std;
int counter = 0;
int dp[1000][1000];
int minDistance(string s1,string s2,int l1,int l2){

    if(dp[l1][l2]!=-1) return dp[l1][l2];
    if(l1 == 0) return dp[l1][l2] = l2;
    if(l2 == 0) return dp[l1][l2] = l1;
    
    if(s1[l1-1] == s2[l2-1]){
        return dp[l1][l2] = minDistance(s1,s2,l1-1,l2-1);
    }
    int insert = minDistance(s1,s2,l1,l2-1) + 1;
    int modify = minDistance(s1,s2,l1-1,l2-1) + 1;
    int Delete = minDistance(s1,s2,l1-1,l2) + 1;

    return dp[l1][l2] = min(insert,min(modify,Delete));
}
int main(){
    memset(dp,-1,sizeof(dp));
    string s1,s2;
    cin>>s1>>s2;
    cout<<minDistance(s1,s2,s1.length(),s2.length())<<endl;

    return 0;
}