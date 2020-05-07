#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    // Solution 1: use of hash map (iteration) 96% & 100%
    Node* copyRandomList1(Node* head) {
        if (!head) return NULL;
        copies[head] = new Node(head->val);
        Node* node = head;
        while (node){
            Node* next = node->next;
            Node* random = node->random;
            if (next && copies.find(next)==copies.end()) copies[next] = new Node(next->val);
            if (random && copies.find(random)==copies.end()) copies[random] = new Node(random->val);
            copies[node] -> next = next ? copies[next] : NULL;
            copies[node] -> random = random? copies[random] : NULL;
            node=next;
        }
        return copies[head];
    }
    //Solution 2: use of hash map (recursion) 96% & 100%
    Node* copyRandomList2(Node* head) {
        if (!head) return NULL;
        if (copies.find(head)==copies.end()){
            copies[head] = new Node(head->val);
            copies[head]->next = copyRandomList2(head->next);
            copies[head]->random = copyRandomList2(head->random);
        }
        return copies[head];
    }

    //Solution 3: 42% & 100%
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        Node *temp=head, *newNode;
        while (temp){
            newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp=head;
        while (temp){
            if (temp->random) temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        Node *newHead = head->next, *pold = head, *pnew = newHead;
//        while (pnew->next){
//            pold->next = pnew->next;
//            pold = pold->next;
//            pnew->next = pold;
//            pnew = pnew->next;
//        }
        while (pold){
            pold->next = pold->next->next;
            pnew -> next = pnew->next ? pnew->next->next:NULL;
            pold = pold->next;
            pnew = pnew->next;
        }
        return newHead;
    }

private:
    unordered_map<Node*, Node*> copies;
};

int main138(){
    Solution solution;
    Node* head1;
    Node* head2;
    Node* head3;
    Node* head4;
    Node* head5;
    Node* result;
//    head1 = new Node(7, head2, head5);
    head1 = new Node(7);
    head2 = new Node(13);
    head3 = new Node(11);
    head4 = new Node(10);
    head5 = new Node(1);

    head1->next = head2;
    head1->random = head5;
    head2->next = head3;
    head2->random = head1;
    head3->next = head4;
    head3->random = head5;
    head4->next = head5;
    head4->random = head3;
    result = solution.copyRandomList(head1);
    return 0;
}