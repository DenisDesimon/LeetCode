//#95 Unique Binary Search Trees II - https://leetcode.com/problems/unique-binary-search-trees-ii/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;


 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<TreeNode*> generate(int start, int end){
        vector<TreeNode*> result;
        if(start > end)
        {
            result.push_back(NULL);
            return result;
        }
        else if(start == end)
        {
            result.push_back(new TreeNode(start));
            return result;
        }
        for(int root_val = start; root_val <= end; root_val++)
        {
            auto left_sub_trees = generate(start, root_val - 1);
            auto right_sub_trees = generate(root_val + 1, end);

            for(auto left_sub_tree : left_sub_trees)
            {
                for(auto right_sub_tree : right_sub_trees)
                {
                    auto root = new TreeNode(root_val);
                    root->left = left_sub_tree;
                    root->right = right_sub_tree;
                    result.push_back(root);
                }
            }

        }
        return result;

    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        return generate(1, n);
    }
};

int main()
{
    Solution solution;
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    vector<TreeNode*> expected_answer = {root1, root2};
    auto generated_tree = solution.generateTrees(2);
    assert(*expected_answer[0] == *generated_tree[0] && *expected_answer[1] == *generated_tree[1]);

    return 0;
}
