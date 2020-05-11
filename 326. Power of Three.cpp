class Solution {
public:
    // solution 1: 71% & 100%
    bool isPowerOfThree1(int n) {
        while (n>1){
            if (n%3 != 0) return false;
            n /= 3;
        }
        return n==1;
    }

    // solution 2: 5% & 100%
    bool isPowerOfThree(int n) {
        while (n%3 == 0 and n!=0){
            n /= 3;
        }
        if (n==1) {
            return true;
        }
        else return false;
    }
};

int main326(){
    Solution solution;
    bool result=solution.isPowerOfThree(45);
    return 0;
}