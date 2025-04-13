#include<bits/stdc++.h>
using namespace std;

bool checkArray(int arr[],int n){
    if(n==0 || n==1){//Because the lowest size of an array is 0 or 1, it is already sorted.
        return true;
    }

    return arr[n-1] >= arr[n-2] && checkArray(arr,n-1);
}

int main(){
    int arr1[] = {1,5,3,4,2};
    int arr2[] = {1,2,3,4,5};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout<<checkArray(arr1, n1)<<endl;
    cout<<checkArray(arr2, n2)<<endl;
    return 0;
}