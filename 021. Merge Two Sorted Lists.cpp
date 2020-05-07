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


class Solution {
public:
    // Solution 1: iteration 89% & 5%
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode * result = new ListNode(0), *result2 = result;
        while (l1 && l2){
            if (l1->val <= l2->val) {
                result->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            else {
                result->next = new ListNode(l2->val);
                l2 = l2->next;
            }
            result = result->next;
        }
        if (l1) result->next = l1;
        if (l2) result->next = l2;
        return result2->next;
    }

    // solution 2: recursion 89% & 5%
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1||!l2) return l1?l1:l2;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};