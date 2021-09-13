#include<bits/stdc++.h>
using namespace std;
template< typename T>
class myVector{
  public:
  T * arr;
  int ind;
  int c;
  
  myVector<T>(T size){
      c = size;
      arr = new T[c];
      ind = 0;
  }
  
  void push(T val){
      if(ind<c){
      arr[ind] = val;
      ind++;
      }else{
          T * temp = arr;
          arr = new T[2*c];
          for(int i=0;i<ind;i++){
              arr[i] = temp[i];
          }
          free(temp);
          c*=2;
          arr[ind] = val;
          ind++;
      }
  }

  void pop(){
      if(ind==0)return;
      arr[ind] = 0;
      ind--;
  }
    
    int size(){
       return ind; 
    }
    T operator[](int i){
        return arr[i];
    }
};

int main(){
    myVector<char> vec(10);
    vec.push('l');
    vec.push('m');
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<endl;
    }
}
