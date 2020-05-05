#include <stddef.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next; //next is a pointer to a ListNode, i.e. next is pointing to a ListNode
    ListNode(int x) : val(x), next(NULL) {}
 };

void print_list(ListNode * n);

void print_list(ListNode * n) {
    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //the variable l1 is pointing to a ListNode
        int carry = 0;
        ListNode dummy(0);
        ListNode* result = &dummy;
        while (l1 or l2 or carry){
            carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            result->next = new ListNode(carry%10);
            carry /= 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            result = result->next;
        }
        return dummy.next;
    }
};

int main2(){
    ListNode *head1 = NULL;
    ListNode *second1 = NULL;
    ListNode *third1 = NULL;

    head1 = new ListNode(2);
    second1 = new ListNode(4);
    third1 = new ListNode(3);

    head1->next = second1;
    second1->next = third1;

    ListNode *head2 = NULL;
    ListNode *second2 = NULL;
    ListNode *third2 = NULL;

    head2 = new ListNode(5);
    second2 = new ListNode(6);
    third2 = new ListNode(4);

    head2->next = second2;
    second2->next = third2;

    Solution solution;
    ListNode *result;
    result = solution.addTwoNumbers(head1, head2);

    print_list(result);// 708
    return 0;
}