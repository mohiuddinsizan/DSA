#include<bits/stdc++.h>
using namespace std;
int findmin(int arr[],int l,int r){
    if(l == r) return arr[l];
    int mid = (l + r) / 2;
    int left = findmin(arr,l,mid);
    int right = findmin(arr,mid+1,r);
    return min(left,right);   
}
int findmax(int arr[],int l,int r){
    if(l == r) return arr[l];
    int mid = (l + r) / 2;
    int left = findmax(arr,l,mid);
    int right = findmax(arr,mid+1,r);
    return max(left,right);

}
int main(){

    int n;cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<findmin(arr,0,n-1)<<endl;
    cout<<findmax(arr,0,n-1)<<endl;

    return 0;
}