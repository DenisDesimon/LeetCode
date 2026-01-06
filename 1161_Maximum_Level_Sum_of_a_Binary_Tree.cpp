//#1161 Maximum Level Sum of a Binary Tree - https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
#include <iostream>
#include <queue>
#include <cassert>
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
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> nodes;
        int result = 1, maxSum = root->val, curLevel = 1;
        nodes.push(root);
        while(!nodes.empty())
        {
            int levelSize = nodes.size();
            int curSum = 0;
            while(levelSize--)
            {
                TreeNode* cur = nodes.front();
                nodes.pop();
                curSum += cur->val;
                if(cur->left)
                    nodes.push(cur->left);
                if(cur->right)
                    nodes.push(cur->right);
            }
            if(curSum > maxSum)
            {
                result = curLevel;
                maxSum = curSum;
            }
            curLevel++;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* givenRoot = new TreeNode(2);
    givenRoot->left = new TreeNode(7);
    givenRoot->right = new TreeNode(0);
    givenRoot->left->left = new TreeNode(7);
    givenRoot->left->right = new TreeNode(-8);
    int expectedAnswer = 2;
    assert(solution.maxLevelSum(givenRoot) == expectedAnswer);

    return 0;
}
