#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&a,int l,int m,int r){
    int left_size = m-l+1;
    int right_size = r-m;
    int L[left_size],R[right_size];
    int k = 0;
    for(int i=l;i<=m;i++){
        L[k] = a[i];
        k++;
    }
    k=0;
    for(int i=m+1;i<=r;i++){
        R[k] = a[i];
        k++;
    }
    int left = 0,right = 0;
    k=l;
    while(left<left_size && right<right_size){
        if(L[left]<=R[right]){
            a[k++] = L[left++];
        }
        else a[k++] = R[right++]; 
    }
    while(left<left_size){
            a[k++] = L[left++];
    }
    while(right<right_size){
        a[k++] = R[right++]; 
    }
}
void divide(vector<int>&a,int l,int r){
    if(l>=r) return ;
    int mid = (l+r)/2;
    divide(a,l,mid);
    divide(a,mid+1,r);
    merge(a,l,mid,r);
}
int main(){
    int n;cin>>n;
    vector<int>a;
    for(int i = 0;i<n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    divide(a,0,n-1);
    for(int i = 0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}