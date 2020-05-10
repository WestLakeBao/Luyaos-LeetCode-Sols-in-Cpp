struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node->next;
        node->next = temp->next;
        node->val = temp->val;
    }
};

int main237(){
    ListNode* head  = new ListNode(4);
    ListNode* head2 = new ListNode(5);
    ListNode* head3 = new ListNode(1);
    ListNode* head4 = new ListNode(9);
    head->next=head2;
    head2->next=head3;
    head3->next=head4;
    Solution solution;

}