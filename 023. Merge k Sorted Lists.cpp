#include <vector>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Comparator{
public:
    bool operator() (ListNode* a, ListNode* b) {
        return a->val <= b->val;}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode, vector<ListNode*>, Comparator> next_heap;
        //for (int i=0; i<lists.size(); i++){
        for (auto i: lists){
            if (i) next_heap.push(i);
        }

    }
};