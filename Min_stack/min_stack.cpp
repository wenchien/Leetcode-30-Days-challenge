#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
class MinStack
{
struct Node {
        int data = NULL;
        Node *next = nullptr;
    };
    Node* Stack = nullptr;
    int Min = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack(){}
    
    void push(int x) {
        if(x < Min) Min = x;
        if(Stack == nullptr) {
            Stack = new Node;
            Stack->data = x;
            return;
        }
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = Stack;
        Stack = newNode;
    }
    
    void pop() {
        if(Min == Stack->data) {
            if(Stack->next != nullptr) {
                Node* temp = Stack->next;
                Min = temp->data;
                while(temp->next != nullptr) {
                    temp = temp->next;
                    Min = min(Min,temp->data);
                }
            }
            else {
                Min = INT_MAX;
            }
        }
        Stack = Stack->next;
    }
    
    int top() {
        return Stack->data;
    }
    
    int getMin() {
        return Min;
    }
};
int main()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin();
    //-- > Returns - 3. 
    minStack.pop();
    minStack.top();
    //-- > Returns 0. 
    minStack.getMin();
    //-- > Returns - 2. return 0;
}