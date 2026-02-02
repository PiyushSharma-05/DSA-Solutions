/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while(count < k){
            if(curr == NULL){
                return head;
            }
            curr = curr->next;
            count++;
        }

        ListNode* prevNode = reverseKGroup(curr, k);

        curr = head, count = 0;
        while(count < k){
            ListNode* next = curr->next;
            curr->next = prevNode;

            prevNode = curr;
            curr = next;
            count++;
        }
        return prevNode;
    }
};