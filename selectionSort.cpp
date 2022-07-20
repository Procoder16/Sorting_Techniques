#include<iostream>
using namespace std;

int main(){

    int arr[] = {8,6,3,2,5,4};
    int n = 6;
    for(int i = 0; i<n-1; i++){  
        // number of passes is (n-1)
        int j,k;
        for(j = k = i; j<n; j++){  
            // both j and k start from i and j traverses to find the minimum for that index
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        swap(arr[k], arr[i]);
    }
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}