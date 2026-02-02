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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        int count = 0;
        while(count < 2){
            if(curr == NULL){
                return head;
            } else if(curr->next == NULL && count == 0){
                return curr;
            }
            curr = curr->next;
            count++;
        }
        ListNode* prevNode = swapPairs(curr);

        curr = head, count = 0;
        while(count < 2){
            ListNode* next = curr->next;
            curr->next = prevNode;

            prevNode = curr;
            curr = next;
            count++;
        }
        return prevNode;
    }
};