class Solution {
public:
    int reverse(int x) {
        int result=0;
        while (x){
            int outflow=x%10;
            if (result>214748364 || result<-214748364) return 0;
            result *=10;
            if (result+outflow>2147483647 || result+outflow<-2147483648) return 0;
            result+=x%10;
            x/=10;
        }
        return result;
    }
};