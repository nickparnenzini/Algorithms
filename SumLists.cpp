struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* p = l1;
	ListNode* q = l2;
	ListNode* head = new ListNode(0);
	ListNode* current = head;
	int carry = 0;

	while ( (p != NULL) || ( q != NULL ) ) {
		int x = (p!=NULL) ? p->val : 0;
		int y = (q !=NULL) ? q->val : 0;
		int sum = x + y + carry;
		carry = sum / 10;
		ListNode* r = new ListNode(sum%10);
		current->next = r;
		current = current->next;
		if (p!=NULL) p = p->next;
		if ( q!=NULL) q = q->next;
		
	}
	
	if ( carry == 1 ) {
		current->next = new ListNode(1);
	}
	
	return head->next; 
}
