#include<bits/stdc++.h>
using namespace std;

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

void IMergeSort(int arr[], int n){

    int p, l, h, mid, i;

    for(int p = 2; p <= n; p*=2){
        for(i = 0; i+p-1 < n; i++){
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            merge(arr, l, mid, h);
        }
    }
    if(p/2 < n){
        merge(arr, 0, p/2, n-1);
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    IMergeSort(arr, n);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}