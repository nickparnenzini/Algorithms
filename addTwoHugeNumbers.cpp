/* addTwoHugeNumbers from CodeFights */

// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int>* addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    std::stack<int> num1;
    std::stack<int> num2;
    ListNode<int> *p = a;
    while (p != nullptr) {
        num1.push(p->value);
        p = p->next;
    }

    p = b;
    while (p != nullptr) {
        num2.push(p->value);
        p = p->next;
    }

    int x = 0;
    int carry = 0;
    ListNode<int> *head = nullptr;
    
    while (!num1.empty() && !num2.empty()) {
        x = num1.top() + num2.top() + carry;   
        num1.pop();
        num2.pop();
        carry = x / 10000;
        x = x % 10000;
        p = new ListNode(x);
        p->next = head;
        head = p;
    }
    
    while (!num1.empty()) {
        x = num1.top() + carry;
        num1.pop();
        carry = x / 10000;
        x = x % 10000;
        p = new ListNode(x);
        p->next = head;
        head = p;
    }
    
   while(!num2.empty()) {
        x = num2.top() + carry;
        num2.pop();
        carry = x / 10000;
        x = x % 10000;
        p = new ListNode(x);
        p->next = head;
        head = p;
    }
    
    if (carry > 0) {
        p = new ListNode(carry);
        p->next = head;
        head = p;
    }
    
    return head;
}
