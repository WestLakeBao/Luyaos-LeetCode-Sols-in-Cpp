class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if (N<0) return 1/myPow_recursive(x, -N);
        return myPow_recursive(x, N);
    }

    double myPow_recursive(double x, int n){
        if (n==0) return 1;
        if (n%2==0) return myPow_recursive(x*x, n/2);
        else return x*myPow_recursive(x*x, n/2);
    }
};

int main50(){
    Solution solution;
    double result=solution.myPow(1.00000,-2147483648);
    return 0;
}