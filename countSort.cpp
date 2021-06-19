#include<bits/stdc++.h>
using namespace std;

/*  
    This is the fastest sorting algorithm but also very space consuming as it needs an extra array whose size can be very large depending upon the input elements
    The main idea is:
        1. create n array with the total size as the greatest number available in the given array
        2. traverse through the given array and mark the digits or increment at the new array
        3. make the given array empty
        4. traverse through the new array and fill the given array according to the frequency
*/

int findMax(int arr[], int n){   //function to find the max element in the given array 
    int maxN = INT_MIN;
    for(int i = 0; i<n; i++){
        maxN = max(maxN, arr[i]);
    }
    return maxN;
}

int main(){

    int arr[] = {8,2,3,8,5,5,6,2,4,2,9,10,9};
    int n = 13;

    int max = findMax(arr, n);  

    int temp[max + 1] = {0}; // creating a temp array to store the frequencies

    for(int i = 0; i<n; i++){ // storing the frequencies
        temp[arr[i]]++;
    }

    for(int i = 0; i<n; i++){   // making the given array all zero
        arr[i] = 0;
    }

    int k = 0;

    for(int i = 0; i<max+1; i++){     // filling the given array with the elements in a sorted order
        if(temp[i] != 0){
            while(temp[i]){
                arr[k++] = i;
                temp[i]--;
            }
        }
    }  

    for(int i = 0; i< n; i++){ // displaying the array
        cout<<arr[i]<<" ";
    }

    return 0;
}