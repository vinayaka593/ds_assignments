//Delete Node in a Linked List

void deleteNode(struct ListNode* node) {
    struct ListNode *prev = node , *curr = node->next;
    while(curr != NULL)
    {
        int temp = prev->val;
        prev->val = curr->val;
        curr->val = temp;
        if(prev->next->next == NULL)
        {
            prev->next = NULL;
            curr = curr->next;
        }
        else
        {
            prev = prev->next;
            curr = curr->next;
        }
    }
    
}
