//#3997 Count Dominant Nodes in a Binary Tree - https://leetcode.com/problems/count-dominant-nodes-in-a-binary-tree/
#include <iostream>
#include <cassert>
#include  <algorithm>
using namespace std;




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int getMaxInSubtree(TreeNode* root, int &result){
        int left = 0, right = 0;
        if(root->left)
            left = getMaxInSubtree(root->left, result);
        if(root->right)
            right = getMaxInSubtree(root->right, result);
        if(left <= root->val && root->val >= right)
            result++;
        return max({left, right, root->val});
    }
public:
    int countDominantNodes(TreeNode* root) {
        int result = 0;
        getMaxInSubtree(root, result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* givenRoot = new TreeNode(5);
    givenRoot->left = new TreeNode(3);
    givenRoot->right = new TreeNode(8);
    givenRoot->left->left = new TreeNode(2);
    givenRoot->left->right = new TreeNode(4);
    givenRoot->right->left = new TreeNode(7);
    givenRoot->right->right = new TreeNode(1);
    int expectedAnswer = 5;
    assert(solution.countDominantNodes(givenRoot) == expectedAnswer);

    givenRoot = new TreeNode(1);
    givenRoot->left = new TreeNode(2);
    givenRoot->right = new TreeNode(3);
    givenRoot->left->left = new TreeNode(1);
    givenRoot->left->right = new TreeNode(2);
    expectedAnswer = 4;
    assert(solution.countDominantNodes(givenRoot) == expectedAnswer);

    return 0;
}
