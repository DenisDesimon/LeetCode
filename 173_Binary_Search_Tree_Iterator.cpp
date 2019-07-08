//#173 Binary Search Tree Iterator - https://leetcode.com/problems/binary-search-tree-iterator/
#include <iostream>
#include <vector>
#include <cassert>
#include <stack>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class BSTIterator {
    vector<int> in_order;
    int index = 0;
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> nodes;
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            in_order.push_back(root->val);
            root = root->right;
        }
    }

    /** @return the next smallest number */
    int next() {
        return in_order[index++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < (int)in_order.size();
    }
};

int main()
{
    TreeNode *given_tree = new TreeNode(7);
    given_tree->left = new TreeNode(3);
    given_tree->right = new TreeNode(15);
    given_tree->right->left = new TreeNode(9);
    given_tree->right->right = new TreeNode(20);
    BSTIterator solution(given_tree);
    assert(solution.next() == 3 && solution.next() == 7);

    return 0;
}
