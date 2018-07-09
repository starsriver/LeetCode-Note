#include "iostream"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* sum = NULL;

            ListNode* curr = NULL;

            while(l1 != NULL || l2 != NULL){
                ListNode* temp = new ListNode(0);
                if(l1 != NULL){
                    temp->val += l1->val;
                    l1 = l1->next;
                }

                if(l2 != NULL){
                    temp->val += l2 ->val;
                    l2 = l2->next;
                }

                if(sum != NULL){
                    curr->next = temp;
                    curr = curr->next;
                }
                else{
                    sum = temp;
                    curr = sum;
                }

            }

            curr = sum;
            while(curr != NULL){
                if(curr->val >= 10){
                    if(curr->next == NULL){
                        curr->next = new ListNode(0);
                    }
                    curr->next->val += (curr->val / 10);
                    curr->val = curr->val % 10;
                }
                curr = curr->next;
            }
            return sum;
    }
};

int main(void){
    ListNode t1(2), t2(4), t3(3);
    ListNode p1(5), p2(6), p3(6);

    ListNode l1 = t1;
    l1.next = &t2;
    l1.next->next = &t3;

    ListNode l2 = p1;
    l2.next = &p2;
    l2.next->next = &p3;

    Solution s;
    ListNode* r = s.addTwoNumbers(&l1, &l2);
    while(r != NULL){
        std::cout << r->val << std::endl;
        r = r->next;
    }
    return 0;
}