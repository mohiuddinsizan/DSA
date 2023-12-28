// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5;
// int dp[N];

// bool can_i(int i,int x){
//     if(i>x) return false;
//     if(i==x) return true;
//     if(dp[i]!= -1) return dp[i];
//     bool op1 = can_i(i*2,x);
//     bool op2 = can_i(i+3,x);
//     return dp[i] = op1||op2;
// }
// int main(){
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     int t ;cin>>t;
//     for(int i = 0;i<t;i++){
//         memset(dp,-1,sizeof(dp));
//         int x;cin>>x;
//         if(can_i(1,x)) cout<<"YES"<<endl;
//         else cout<<"NO"<<endl;
//     }

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int dp[1001][20001];
// bool can(int box[],int i,int sum){
//     if(sum == 0) return true;

//     if(i<0) {
//         return false;
//     }
    
//     if(dp[i][sum]!=-1) return dp[sum];

//     bool op1 = false,op2 = false;
//     if(sum>=box[i]) op1 = can(box,i-1,sum-box[i]);
//     op2 = can(box,i-1,sum);
//     return  dp[i][sum]=(op1||op2 ); 

// }

// int main(){

//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     int t ;cin>>t;
//     for(int i = 0;i<t;i++){
//         memset(dp,-1,sizeof(dp));
//         int n;cin>>n;
//         int box[n];
//         int sum = 0;
//         for(int j = 0;j<n;j++){
//             cin>>box[j];
//             sum +=box[j];
//         }
        
//         if(sum%2!=0 || n<=1) cout<<"NO"<<endl;

//         else{
//             if(can(box,n-1,sum/2)) cout<<"YES"<<endl;

//             else cout<<"NO"<<endl;
            
//         }
//     }

//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int can(int marks[],int i ,int needs,int take){

    if(needs == 0) return take;

    if(i<0) return INT_MAX;

    if(dp[i][needs]!=-1) return dp[i][needs];
    int op1 = INT_MAX,op2 = INT_MAX;
    
    if(needs>=marks[i])
        op1 = can(marks,i,needs-marks[i],take+1);
    op2 = can(marks,i-1,needs,take);

    return  dp[i][needs] = min(op1,op2);
}

int  main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;cin>>t;
    while(t--){
        
        int n,m;
        cin>>n>>m;
        int marks[n];
        for(int i = 0;i<n;i++){
            cin>>marks[i];
        }
        int needs = 1000-m;
        int x,answers=INT_MAX;

        for(int i = n-1;i>=0;i--){
            memset(dp, -1, sizeof(dp));
            answers = min(answers,can(marks,i,needs,0));
        }
       
        if(answers != INT_MAX) cout<<answers<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}