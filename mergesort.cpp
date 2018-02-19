/* A possible implementation of mergesort in C++ */
#include <iostream>

using namespace std;

struct Elem {
  int data;
  Elem* next;
};

void split(Elem*& list1, Elem*& list2) {
    /* A possible implementation of split function is assigning the elements in odd position to list2 */  
    if (list1 == nullptr || list1->next == nullptr)
        return;
        
    Elem* l = list1->next;
    list1->next = l->next;
    l->next = list2;
    list2 = l;
    split(list1->next, list2);
}

void merge(Elem*& list1, Elem* list2) {
    if (list1 == nullptr) {list1 = list2; return;}
    if (list2 == nullptr) {return;}
    if (list1->data <= list2->data) {
        merge(list1->next, list2);
    }
    else {
        merge(list2->next, list1);
        list1 = list2;
    }
}

void mergesort(Elem*& list1) {
    if (list1 == nullptr || list1->next == nullptr)
        return;
        
    Elem* list2 = nullptr;
    /* split list1 into two lists and assign the second half to list2 */
    split(list1, list2);
    /* order the first list */
    mergesort(list1);
    /* order the second list */
    mergesort(list2);
    /* merge the two lists */
    merge(list1, list2);
}

void insertElem(Elem*& list1, int x) {
    Elem* p = new Elem;
    p->data = x;
    p->next = list1;
    list1 = p;
} 

int main() {
    
    Elem* head = nullptr;
    insertElem(head, 4);
    insertElem(head, 6);
    insertElem(head, 1);
    insertElem(head, 2);
    
    mergesort(head);
    
    for (Elem* p = head; p != nullptr; p = p->next) {
        cout << p->data << " ";
    }   

    return 0;
}
