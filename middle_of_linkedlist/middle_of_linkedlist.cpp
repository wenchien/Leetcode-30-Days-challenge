#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#define MAX_NODE 5

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode();
    //ListNode(int x) : val(x), next(NULL) {} //constructor
};
ListNode *middleNode(ListNode *head);
void printList(ListNode *head);
void add_node(int i);
ListNode *head;
ListNode *current;
int main()
{
   
    for (int i = 0; i < MAX_NODE; i++) {
        add_node(i);
    }
    printList(head);
    return 0;
}

void add_node(int i) {
     ListNode *tmp = new ListNode;
        tmp->val = i;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            current = tmp;
        }
        else
        {
            current->next = tmp;
            current = current->next;
        }
}

void printList(ListNode *head)
{
    
    if (head == NULL) {
        cout << "NULL" << endl;
    }
    else {
        cout << head->val << endl;
        printList(head->next);
    }
    return;
}