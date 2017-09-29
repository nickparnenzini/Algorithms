
template<typename T>
struct ListNode {
   ListNode(const T &v) : value(v), next(nullptr) {}
   T value;
   ListNode *next;
};


bool isListPalindrome(ListNode<int> * l) {
    if ( l == NULL || l->next == NULL )
        return true;
    
    ListNode<int> *p = l;
    ListNode<int> *q = NULL;
    int n = 0;
    int len;
    
    while ( p != NULL ) {
        n++;
        p = p->next;
    }
    
    len = n / 2;
    
    if ( n % 2 != 0 ){
        len++;        
    }
    
    p = l;
    
    while ( len > 0 ) {
        q = p;
        p = p->next;
        len--;
    }
    
    q->next = NULL;
    
    /* Reverse half of the list */
    
    ListNode<int>* prev   = NULL;
    ListNode<int>* current = p;
    ListNode<int>* next;
    
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    
    p = prev;
    
    q = l;             
    
    ListNode<int>* pp = p;
    
    while ( pp != NULL ) {
        if ( pp->value != q->value ) {
            return false;
        }
        pp = pp->next;
        q = q->next;
    }
    
    return true;
}
