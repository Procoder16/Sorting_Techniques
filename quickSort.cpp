#include<iostream>
using namespace std;

int partition(int arr[], int l, int h){

    int pivot = arr[l];
    int i = l;
    int j = h;

    do{
        do{
            i++;
        }while(arr[i] <= pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        if(i<j){
            swap(arr[i], arr[j]);
        }

    }while(i<j);

    swap(arr[l], arr[j]);

    return j;
}

void quickSort(int arr[], int l, int h){

    if(l < h){
        int j = partition(arr, l, h);
        quickSort(arr, 0, j);
        quickSort(arr, j+1, h);
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int h = n;

    quickSort(arr, 0, h);

    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}