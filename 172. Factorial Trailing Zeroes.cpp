class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
        int i=5;
        while (i<=n){
            result += n/i;
            if (i>429496729) break;  //429496729=2147483647/5;
            i*=5;
        }
        return result;
    }
};

int main172(){
    Solution solution;
    int result=solution.trailingZeroes(1808548329);
    return 0;
}