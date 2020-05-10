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
        ListNode *slow=head, *fast=head;
        while (fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = nullptr;
        return head2;
    }

    ListNode* reverse(ListNode* head2){
        ListNode* previous=nullptr; // dont forget this =nullptr which makes a difference. if you dont write this, you are creating a listnode with val=0, next=null
        while (head2){
            ListNode* next = head2->next;
            head2->next = previous;
            previous = head2;
            head2 = next;
        }
        return previous;
    }

    // solution 1: divide -> reverse -> isPalindrome 18% & 8%
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* head2 = divide(head);
        head2 = reverse(head2);
        while (head && head2){
            if (head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};

int main234ee(){
    Solution solution;
    ListNode* node1=new ListNode(1);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;

    bool result;
    result = solution.isPalindrome(node1);
    return 0;
}