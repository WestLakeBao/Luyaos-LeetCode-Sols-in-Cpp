#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // solution 1: 44% & 31%
    int fourSumCount1(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        int result=0;
        for (int a:A){
            for (int b:B){
                map1[a+b]++;
            }
        }
        for (int c:C) {
            for (int d:D) {
                map2[c + d]++;
            }
        }
        for (auto sum1: map1){
            if (map2.find(-sum1.first)!=map2.end()) result += sum1.second * map2[-sum1.first];
        }
        return result;
    }

    //solution 2: 83% & 86%
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;
        int result=0;
        for (int i=0; i<A.size(); i++){ //using for (int=0; i<A.size(); i++) is a lot faster than for (int a:A)
            for (int j=0; j<B.size(); j++){
                map[A[i]+B[j]]++;
            }
        }
        for (int i=0; i<C.size(); i++){
            for (int j=0; j<D.size(); j++){
                if (map.find(-C[i]-D[j])!=map.end()) result += map[-C[i]-D[j]];
            }
        }
        return result;
    }
};

int main454(){
    Solution solution;
    vector<int> A={1, 2}, B={-2,-1}, C={-1, 2}, D={0, 2};
    int result;
    result = solution.fourSumCount(A, B, C, D);
    return 0;
}