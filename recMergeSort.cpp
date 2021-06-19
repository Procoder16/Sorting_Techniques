#include<bits/stdc++.h>
using namespace std;

/*
    
*/

void merge(int arr[], int l, int mid, int h){

    int i = l, j = mid + 1, k = l;
    int len = h-l + 1;
    int b[len];

    while(i<=mid && j<=h){
        if(arr[i] < arr[j]){
            b[k++] = arr[i++];
        }
        else{
            b[k++] = arr[j++];
        }
    }
    for(; i<=mid; i++){
        b[k++] = arr[i];
    }
    for(; j<=h; j++){
        b[k++] = arr[j];
    }

    for(int i = l; i<=h; i++){
        arr[i] = b[i];
    }
}

void recMergeSort(int arr[], int l, int h){

    int mid;
    if(l < h){
        mid = (l + h)/2;
        recMergeSort(arr, l, mid);
        recMergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    recMergeSort(arr, 0, n-1);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}