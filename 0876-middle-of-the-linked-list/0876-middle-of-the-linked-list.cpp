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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         vector<int> v1;
//         ListNode *curr = head, *temp = head;
//         while(curr!=nullptr){
//             v1.push_back(curr->val);
//             curr = curr->next;
//         }
//         int n = v1.size()/2;
//         while(n--)  temp = temp->next;
//         return temp;
//     }
// };