/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* list1 = headA;
        ListNode* list2 = headB;
        
        if(list1==NULL || list2==NULL)  return NULL;
        
        while(list1 and list2 and list1!=list2){
            list1 = list1->next;
            list2 = list2->next;
            
            if(list1==list2)    return list1;
            
            if(list1==NULL) list1 = headA;
            if(list2==NULL) list2 = headB;
        }
        
        return list1;
    }
};