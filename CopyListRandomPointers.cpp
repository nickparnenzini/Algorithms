/* Coding challenge #138 from LeetCode */

/* A linked list is given such that each node contains an additional random pointer 
 * which could point to any node in the list or null.
 * Return a deep copy of the list.
*/

/*
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> old_new_nodes;
        RandomListNode* second_head = nullptr;
        RandomListNode* second_it_node = second_head;
        RandomListNode* p = head;
         
        while (p != nullptr) {
            RandomListNode* list_node = new RandomListNode(p->label);
            list_node->next = p->next;
            list_node->random = p->random;
            old_new_nodes.emplace(std::move(make_pair(p, list_node)));
            if (second_head == nullptr) {
                second_head = second_it_node = list_node;
            }
            else {
                second_it_node->next = list_node;
                second_it_node = second_it_node->next;
            }
            p = p->next;
        }
        
        second_it_node = second_head;
        
        while (second_it_node != nullptr) {
            auto it = old_new_nodes.find(second_it_node->random);
            if (it != old_new_nodes.end()) {
                second_it_node->random = it->second;    
            }
            else {
                second_it_node->random = nullptr;
            }
            second_it_node = second_it_node->next;
        }
              
        return second_head;
    }
};
