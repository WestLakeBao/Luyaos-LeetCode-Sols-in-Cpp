#include <vector>
#include <unordered_map>
#include <map> // to use multimap
#include <queue>

using namespace std;

class ComparePair
{
public:
    bool operator()(pair<int, int> n1, pair<int, int> n2) {
        return n1.second > n2.second;
    }
};

class Solution {
public:
    // Solution 1: using hashmap 27% & 6%
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num: nums) map[num]++;
        multimap<int, int> k_most_map;
        for (auto begin=map.begin(); begin!=map.end(); begin++){
            if (k_most_map.size()<k) k_most_map.insert({begin->second, begin->first});
            else if (k_most_map.begin()->first < begin->second){
                k_most_map.erase(k_most_map.begin()); // multimap containers keep all their elements sorted by key (ascending)
                k_most_map.insert({begin->second, begin->first});
            }
        }
        vector<int> result;
        for (auto begin=k_most_map.begin(); begin!=k_most_map.end(); begin++){
            result.push_back(begin->second);
        }
        return result;
    }

    // Solution 2: using max heap 51% & 6%
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num: nums) map[num]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePair> k_most_heap;
        for (auto element:map){
            if (k_most_heap.size()<k) k_most_heap.push(element);
            else {
                pair<int, int> heap_min=k_most_heap.top();
                if (element.second > heap_min.second) {
                    k_most_heap.pop();
                    k_most_heap.push(element);
                }
            }
        }
        vector<int> result;
        while (!k_most_heap.empty()){
            pair<int, int> heap_min = k_most_heap.top();
            result.push_back(heap_min.first);
            k_most_heap.pop();
        }
        return result;
    }
};