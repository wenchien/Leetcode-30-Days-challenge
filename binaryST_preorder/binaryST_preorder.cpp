#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *bstFromPreorder(vector<int> &preorder);
TreeNode * helperCreation(TreeNode* node, int val);
void printTree(TreeNode *current);
TreeNode * current;
int main()
{
    vector<int> tester {
        8,5,1,7,10,12
    };
    current = bstFromPreorder(tester);
    
    printTree(current);
}

TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *driver = NULL;
    
    for (int i = 0; i < preorder.size(); i++) {
        driver = helperCreation(driver, preorder[i]);
    }
    
    return driver;
}

TreeNode * helperCreation(TreeNode* node, int val) {
    if (node == NULL) {
        cout << "created new node" << endl;
        node = new TreeNode(val);
    }
    else {
        if (val <= node->val) {
            //go left
            cout << "going left" << endl;
            node->left = helperCreation(node->left, val);
        }
        else {
            cout << "going right" << endl;
            node->right = helperCreation(node->right, val);
            //go irght
        }
    }
    //returns untouched pointer
    return (node);
}

//preorder traversal
void printTree(TreeNode *curr) {
    //if current != null
    if (curr == NULL) {
        
    }
    if (curr) {
        cout << curr->val << " ";
        printTree(curr->left);
        printTree(curr->right);
    }
}