class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0); // Dummy node to simplify handling the head
        ListNode* curr = &dummyHead;
        int carry = 0;
        
        // Loop until both lists are exhausted and no carry remains
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get values from current nodes, default to 0 if list is exhausted
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            // Calculate total sum for this position
            int totalSum = val1 + val2 + carry;
            
            // Update carry and create the new digit node
            carry = totalSum / 10;
            curr->next = new ListNode(totalSum % 10);
            
            // Advance pointers
            curr = curr->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
        return dummyHead.next;
    }
};