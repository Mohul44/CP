/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void computePrefix(vector<int>&prefix,string p){
    int len = 0;
    int i = 1;
    prefix[0] = 0;
    while(i<p.length()){
        if(p[i]==p[len]){
            len++;
            prefix[i] = len;
            i++;
        }
        else{
            if(len==0){
                prefix[i] = 0;
                i++;
            }
            else{
                len = prefix[len-1];
            }
        }
    }
}

void KMPsearch(string p,string s,vector<int> &prefix){
    int n = p.length();
    int m = s.length();
    int i = 0;
    int j = 0;
    vector<int> ind;
    while(j<m){
        if(p[i]==s[j]){
            i++;
            j++;
        }
        else{
            if(i==0){
                j++;
                continue;
            }
            else{
                i  = prefix[i-1];
            }
        }
          if(i==n){
            ind.push_back(j-i);
            i = prefix[i-1];
        }
    }
    for(auto x : ind)cout<<x<<" ";
    cout<<endl;
}
int main()
{
    string s = "aabaccdfabcssabacaabacaababaacabac";
    string p = "abac";
    int n  = s.length();
    int m = p.length();
    vector<int> prefix(m,0);
    computePrefix(prefix,p);
    KMPsearch(p,s,prefix);
    return 0;
}
