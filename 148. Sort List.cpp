struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* divide(ListNode* head){
        if (!head || !head->next) return head;
        ListNode* slow=head, *fast=head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2=slow->next;
        slow->next= nullptr;
        return head2;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* head2 = divide(head);

        head = sortList(head);
        head2 = sortList(head2);

        if (!head) return head2;
        if (!head2) return head;

        ListNode *dummy= new ListNode(0);
        ListNode *result=dummy;

        while (head && head2){
            if (head->val < head2->val){
                result->next = head;
                head = head->next;
            }
            else{
                result->next = head2;
                head2 = head2->next;
            }
            result = result->next;
        }
        if (head) result->next = head;
        else if (head2) result->next = head2;
        return dummy->next;
    }
};

int main(){
    Solution solution;
    ListNode node1(4);
    ListNode node2(2);
    ListNode node3(1);
    ListNode node4(3);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    ListNode * result;
    result = solution.sortList(&node1);
    return 0;
}