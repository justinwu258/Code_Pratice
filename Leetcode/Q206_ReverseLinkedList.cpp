/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
    ref: https://leetcode.com/problems/reverse-linked-list/
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* originNext; 
        ListNode* originHead; 
        ListNode* lastNode = NULL;
        originHead = head;
        while(head != NULL){
            originNext = head->next;
            head->next = lastNode;
            lastNode = head;
            head = originNext;
        }
        return lastNode; // lastNode is a new "begin node" 
    }
};
