#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

template<typename T>
class DLLNode{
    public:
        DLLNode<T> * prev;
        T data;
        DLLNode<T> *next;
    DLLNode(T val){
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

template<typename T>
class Stack
{
    public:
        DLLNode<T> * top;
        DLLNode<T> * mid;
        int count;
    Stack(){
        count = 0;
        top = nullptr;
        mid = nullptr;
    }
};

template<typename T> void push(T val, Stack<T> * stk){
    DLLNode<T> * node = new DLLNode<T>(val);
    stk->count++;
    if(stk->top==NULL)stk->top = node;
    else{
        node->next = stk->top;
        stk->top = node;
    }
}

template<typename T> T top(Stack<T> * stk){
    if(stk->count==0)return 0;
    else{
        return stk->top->data;
    }
}

template<typename T> void pop(Stack<T> * stk){
    if(stk->count==0)return;
    stk->count--;
    if(stk->count==0)free(stk->top);
    else{
        DLLNode<T> * toFree = stk->top;
        stk->top = stk->top->next;
        free(toFree);
    }
    return ;
}

int main(){
    Stack<int> * stk = new Stack<int>;
    push(10,stk);
    push(20,stk);
    pop(stk);
    cout<<top(stk);
    return 0;   
}
