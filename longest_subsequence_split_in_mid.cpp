#define fr(i,n) for(int i = 0; i<=n;i++)
#define rep(i,a,n) for(int i = a; i<=n;i++)

class Solution {
public:
    
    string longestPalindrome(string s) {
      string answer = "";
       int n = s.length();
        int temp = 0;
        int count = 0;
        fr(i,n){
            temp  = 1;
            rep(j,0,n){
                int l = i-j;
                int r = i+j;
                if(l<0 || r>=n)break;
                if(s[l]==s[r]){
                    if(r-l+1>count){
                        count = r-l+1;
                        answer = s.substr(l,count);
                    }
                }
                else break;
            }
        }
        
        fr(i,n-1){
            temp = 1;
            rep(j,0,n){
                int l = i-j;
                int r = i+j+1;
                if(l<0 || r>=n)break;
                if(s[l]==s[r]){
                    if(r-l+1>count){
                        count = r-l+1;
                        answer = s.substr(l,count);
                    }
                }
                else break;
            }
        }
        
        
     return answer;
    }
};
