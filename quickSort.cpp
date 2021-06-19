#include<iostream>
using namespace std;

/*
    The quick sort works on the principle that an element is sorted if all the element to its right are greater than that element
    and all the elements on the left are smaller than itself.
    Steps:
        1. Firstly we will assign the pivot element to the first element of the array and then find the appropriate position for it.
        2. Then we will call the recursive quick sort function for the two halves after partition.
*/

int partition(int arr[], int l, int h){

    int pivot = arr[l];  // the partition element
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
            swap(arr[i], arr[j]);  // swapping the greater and the smaller elements on both side
        }

    }while(i<j);

    swap(arr[l], arr[j]);  // swapping the pivot element with the found position

    return j;
}

void quickSort(int arr[], int l, int h){

    if(l < h){ // checking if there is at least 2 elements
        int j = partition(arr, l, h);  // getting the partition elements
        quickSort(arr, 0, j);  // calling the recursive function for the two halves
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