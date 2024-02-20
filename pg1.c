//Linked List Cycle
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head->next == NULL)return false;
    struct ListNode *fast = head , *slow = head;
    while(fast != NULL && fast->next != NULL){
        if(slow == NULL)return false;
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)return true;
    }
    return false;
}