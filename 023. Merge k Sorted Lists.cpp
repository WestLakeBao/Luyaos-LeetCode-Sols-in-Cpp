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
        return a->val >= b->val;} //the front of the queue contains the "last" element
};

class Solution {
public:
    // solution 1: using heap 86% & 14%
    ListNode* mergeKLists1(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comparator> min_heap;
        //for (int i=0; i<lists.size(); i++){
        for (auto i: lists){
            if (i) min_heap.push(i);
        }
        ListNode dummy(0);
        ListNode* result=&dummy;
        while (!min_heap.empty()){
            result->next=min_heap.top();
            min_heap.pop();
            result=result->next;
            if (result->next) min_heap.push(result->next);
        }
        return dummy.next;
    }

    // solution 2: reuse mergeTwoLists (divide and conquer) 99% & 5%
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1||!l2) return l1?l1:l2;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

    ListNode* merge(vector<ListNode*>& Lists, int start, int end){
        if (start==end) return Lists[start];
        if (start+1==end) return mergeTwoLists(Lists[start], Lists[end]);
        return mergeTwoLists(merge(Lists, start, (start+end)/2), merge(Lists, (start+end)/2+1, end));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n==0) return nullptr;
        if (n==1) return lists[0];
        ListNode *result = merge(lists, 0, n-1);
        return result;
    }
};

int main23(){
    Solution solution;
    ListNode node1(1);
    ListNode node2(4);
    ListNode node3(5);
    ListNode node4(1);
    ListNode node5(3);
    ListNode node6(4);
    ListNode node7(2);
    ListNode node8(6);

    node1.next=&node2;
    node2.next=&node3;

    node4.next=&node5;
    node5.next=&node6;

    node7.next=&node8;

    vector<ListNode*> lists;
    lists.push_back(&node1);
    lists.push_back(&node4);
    lists.push_back(&node7);

    ListNode* result;

    result = solution.mergeKLists(lists);
    return 0;
}