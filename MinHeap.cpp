#include <bits/stdc++.h>
using namespace std;

class MinHeap{
  public:
  int * arr;
  int ind;
  int cap;
  
  MinHeap(){
      arr = new int[10];
      cap = 10;
      ind =0;
  }
  
  int parent(int ii){
      if(ii==0)return 0;
      return (ii-1)/2;
  }
  
  int leftChild(int ii){
      return 2*ii+1;
  }
  int rightChild(int ii){
      return 2*ii+2;
  }
  
  void insert(int val){
      if(ind==cap){
          cout<<"MinHeap capacity reached remove first!";
          return ;
      }
      if(ind==0){
          arr[ind] = val;
          ind++;
          return;
      }
      arr[ind]  = val;
      int ii = ind;
      ind++;
      while(ii>0 && arr[parent(ii)]>arr[ii]){
          swap(arr[ii],arr[parent(ii)]);
          ii = parent(ii);
      }
  }
  void heapify(int ii){
      int small = ii;
      if(leftChild(ii)<ind && arr[leftChild(ii)]<arr[ii])small = leftChild(ii);
      if(rightChild(ii)<ind && arr[rightChild(ii)]<arr[small])small = rightChild(ii);
      if(small!=ii){
          swap(arr[small],arr[ii]);
          heapify(small);
      }
  }
  
  int deletee(){
      if(ind == 0)return -1;
      if(ind==1){
          ind--;
          return arr[0];
      }
      int to_return = arr[0];
      arr[0] = arr[ind-1];
      heapify(0);
      ind--;
      return to_return;
  }
};
int main()
{
    MinHeap mn;
    mn.insert(10);
    mn.insert(5);
    mn.insert(50);
    mn.insert(1);
    cout<<mn.deletee()<<endl;
    cout<<mn.deletee()<<endl;
    cout<<mn.deletee()<<endl;
    cout<<mn.deletee()<<endl;
    return 0;
}
