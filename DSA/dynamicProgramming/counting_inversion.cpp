#include<bits/stdc++.h>
using namespace std;

int merge(int arr[],int left,int right,int mid){
    int inversion = 0;
    int left_size = mid - left + 1;
    int right_size = right - mid;
    int left_array[left_size];
    int right_array[right_size];
    int k = 0;
    for(int i = 0;i<left_size;i++){
        left_array[i] = arr[i+left];
    }
    k = 0;
    for(int i = 0;i<right_size;i++){
        right_array[i] = arr[i+mid+1];
    }
    k = left;
    int i = 0;
    int j = 0;
    while(i<left_size && j<right_size){
        if(left_array[i]>right_array[j]){
            inversion += (left_size - i);
            arr[k] = right_array[j];
            j++;
        }
        else{
            arr[k] = left_array[i];
            i++;
        }
        k++;
    }
    while(i<left_size){
        arr[k] = left_array[i];
        i++;
        k++;
    }
    while(j<right_size){
        arr[k] = right_array[j];
        j++;
        k++;
    }
    return inversion;

}

int mergeSort(int arr[],int left,int right){
    if(left>=right) return 0;

    int inversion = 0;
    int mid = (left+right)/2;
    inversion += mergeSort(arr,left,mid);
    inversion += mergeSort(arr,mid+1,right);
    inversion += merge(arr,left,right,mid);
    return inversion;
}

int main(){

    int n;cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergeSort(arr,0,n-1)<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}