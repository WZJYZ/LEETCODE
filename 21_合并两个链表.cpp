//
// Created by lwj on 2020/4/26.
//
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }else if (l2 == nullptr){
            return l1;
        }

        ListNode* head = new ListNode{-1};
        ListNode* cur = head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        cur->next = (l1 == nullptr) ? l2:l1;
        return head->next;
    }
};