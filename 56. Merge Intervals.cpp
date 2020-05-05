#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), cmp);
        int start=intervals[0][0], end=intervals[0][1];
        for (int i=0; i<intervals.size(); i++){
            if (end < intervals[i][0]){
                result.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else {
                end = max(end, intervals[i][1]);
            }
        }
        result.push_back({start, end});
        return result;
    }
};

int main56(){
    Solution solution;
    vector<vector<int>> intervals;
    intervals.push_back({1, 3});
    intervals.push_back({2, 6});
    intervals.push_back({8, 10});
    intervals.push_back({15, 18});

    vector<vector<int>> result;
    result = solution.merge(intervals);
    return 0;
}