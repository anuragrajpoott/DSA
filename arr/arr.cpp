#include<iostream>
using namespace std;

int max(int arr[], int size){
    int max = INT8_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int min(int arr[], int size){
    int min = INT8_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}

int main(){
    int arr[5] = {1,2,3,4,5};

    cout<<max(arr,5)<<endl;

    cout<<min(arr,5)<<endl;
}