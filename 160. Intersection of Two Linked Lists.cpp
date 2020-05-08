struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode *head1 = headA, *head2 = headB;
        while (head1 != head2) {
            head1 = head1?head1->next:headB;
            head2 = head2?head2->next:headA;
        }
        return head1?head1:nullptr;
    }
};

