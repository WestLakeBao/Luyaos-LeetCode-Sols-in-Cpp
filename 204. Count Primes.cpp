#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n<3) return 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        for (int i=2; i<sqrt(n)+1; i++) {
            if (primes[i]) {
            for (int j = i * i; j < n; j += i) {
                primes[j] = false;
            }
        }
        }
        //return count(primes.begin(), primes.end(), true);
        int count = 0;
        for (bool prime:primes){
            if (prime == true) count ++;
        }
        return count;
    }
};

int main(){
    Solution solution;
    int result=solution.countPrimes(10);
    return 0;
}