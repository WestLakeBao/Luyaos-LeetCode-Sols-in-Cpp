struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd=head;
        ListNode *even=head->next;
        ListNode *temp=even;
        while (odd->next && even->next){
            odd->next=even->next;
            odd = odd->next;
            even->next=odd->next;
            even=even->next;
        }
        odd->next = temp;
        return head;
    }
};

int main328(){
    Solution solution;
    ListNode* node1=new ListNode(1);
    ListNode* node2=new ListNode(2);
    ListNode* node3=new ListNode(3);
    ListNode* node4=new ListNode(4);
    ListNode* node5=new ListNode(5);

    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next=node5;

    ListNode* result;
    result = solution.oddEvenList(node1);
    return 0;
}