class Solution {
public:
    int mySqrt(int x) {
        long left=0, right=x;
        while (left<=right){
            long mid=(left+right)/2;
            long square = mid*mid;
            if (square>x) {
                right=mid-1;
            }
            else if (square==x) return mid;
            else {
                left=mid+1;
            }
        }
        return left>1?left-1:left;
    }
};

int main69(){
    Solution solution;
    int result=solution.mySqrt(2147395599);
    return 0;
}