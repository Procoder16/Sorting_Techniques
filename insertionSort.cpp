#include<iostream>
using namespace std;

int main(){

    int arr[] = {8,5,7,3,2};
    int n = 5;

    for(int i = 1; i < n; i++){  // we are starting from 1 because we assume the first element to be already inserted
        int x = arr[i];         // and sorted.   
        int j = i-1;
        while(j>-1 && arr[j] > x){   // cheching j to be greater than -1 so that while coming back, j doesn't go beyond 0
            arr[j+1] = arr[j];
            j--;                     // we will be shifting the elements to the right until the jth element becomes less than x
        }
        arr[j+1] = x;
    }

    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}