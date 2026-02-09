//#1382 Balance a Binary Search Tree - https://leetcode.com/problems/balance-a-binary-search-tree/
#include <iostream>
#include <stack>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    bool operator==(TreeNode b)
    {
        bool Left = false, mid, Right = false;
        mid = val == b.val;
        if(left == NULL && b.left == NULL)
            Left = true;
        else if(left != NULL && b.left != NULL){
            Left = *left == *b.left;
        }
        if(right == NULL && b.right == NULL)
            Right = true;
        else if(right != NULL && b.right != NULL)
            Right = *right == *b.right;
        return Left + Right + mid > 2;
     }
};

class Solution {
    TreeNode* build(int start, int end, vector<int> &inOrder)
    {
        if(start > end)
            return nullptr;
        int mid = (end - start) / 2 + start;
        TreeNode* left = build(start, mid - 1, inOrder);
        TreeNode* right = build(mid + 1, end, inOrder);
        return new TreeNode(inOrder[mid], left, right);

    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> inOrder;
        while(root || !nodes.empty())
        {
            while(root)
            {
                nodes.push(root);
                root = root->left;
            }
            inOrder.push_back(nodes.top()->val);
            root = nodes.top()->right;
            nodes.pop();
        }
        return build(0, inOrder.size() - 1, inOrder);
    }
};


int main()
{
    Solution solution;
    TreeNode* givenRoot = new TreeNode(1);
    givenRoot->right = new TreeNode(2);
    givenRoot->right->right = new TreeNode(3);
    givenRoot->right->right->right = new TreeNode(4);

    TreeNode* expectedAnswer = new TreeNode(2);
    expectedAnswer->left = new TreeNode(1);
    expectedAnswer->right = new TreeNode(3);
    expectedAnswer->right->right = new TreeNode(4);

    assert(*solution.balanceBST(givenRoot) == *expectedAnswer);

    return 0;
}
