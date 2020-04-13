#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
int answer = 0;
int diameterOfBinaryTree(TreeNode *root);
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main()
{
}

int diameterOfBinaryTree(TreeNode *root)
{
    //if we do int something = GetDepth(); it does an extra + 1
    getDepth(root);
    return answer;
}

//returns the depth of a binary tree left and right + 1
int getDepth(TreeNode * root) {
    if (!root) {//only checks if the variable is actually a valid pointer
    // So it checks to see if the value of root which is a pointer to a TreeNode object has a valid memory address stored within this variable
        return 0;
    }
    int goLeft = getDepth(root->left);//iterate
    int goRight = getDepth(root->right);
    if (goLeft + goRight > answer) answer = goLeft + goRight;//update max depth for a sub tree/sub node, at root node
    return max(goLeft + 1, goRight + 1);//at 1, meaning include the root node of a tree / sub tree
}