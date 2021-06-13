// set any k any N
class Solution {
public:
    int twoEggDrop(int n) {
       int K = 2;
        int N = n;
            vector<int> floors(K,1);

        int counter = 2;
        if(N==1)return counter-1;
        while (N>1) {
            for (int j = K - 1; j > 0; --j) floors[j] += floors[j-1] + 1; 
            floors[0] = counter;

            if (floors[K-1] >= N) return counter;
            ++counter;
        }

        return 0;
        
    }
};
