// int * and int arr[] are same
#include<bits/stdc++.h>
using namespace std;

int partition(int * arr,int l,int h){
    int pivot = arr[h];
    int i = l-1;
    for(int j=l;j<=h-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[h]);
    return i+1;
}
void quicksort(int * arr,int l,int h){
    if(l<h){
        int mid = partition(arr,l,h);
        quicksort(arr,l,mid-1);
        quicksort(arr,mid+1,h);
        
    }
}
int main(){
    int arr[] = {10,9,87,90,2,67};
    for(auto x : arr)cout<<x<<" ";
    cout<<endl;
    quicksort(arr,0,5);
    for(auto x : arr)cout<<x<<" ";
    return 0;
}
