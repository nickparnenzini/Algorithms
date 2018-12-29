/* Coding challenge "Reverse nodes in K groups" from Code Signal*/

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };

ListNode<int>* reverseNodesInKGroups(ListNode<int>* l, int k) {
    ListNode<int>* current = l;
    ListNode<int>* prev = nullptr;
    ListNode<int>* next = nullptr;
    int count = 0;
    
    ListNode<int>* p = l;
    int n = 0;
    while (p != nullptr) {
        p = p->next;
        n++;
    }
    
    if (n < k)
        return l;
    
    while (current != nullptr && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    if (next != nullptr)
        l->next = reverseNodesInKGroups(next, k);
    
    return prev;
}
