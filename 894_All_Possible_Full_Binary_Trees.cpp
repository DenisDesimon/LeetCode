//#894 All Possible Full Binary Trees - https://leetcode.com/problems/all-possible-full-binary-trees/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
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
    unordered_map<int, vector<TreeNode*>> hash;
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(hash.count(N))
            return hash[N];
        vector<TreeNode*> result;
        if(N < 1)
            return result;
        else if(N == 1)
        {
            result.push_back(new TreeNode(0));
            return result;
        }
        for(int i = 1; i < N; i += 2)
        {
            vector<TreeNode*> left_subtrees = allPossibleFBT(i);
            vector<TreeNode*> right_subtrees = allPossibleFBT(N - i - 1);
            for(auto left_tree : left_subtrees)
            {
                for(auto right_tree : right_subtrees)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left = left_tree;
                    root->right = right_tree;
                    result.push_back(root);
                }
            }
        }
        hash[N] = result;
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode* root = new TreeNode(0);
    root->right = new TreeNode(0);
    root->left = new TreeNode(0);

    vector<TreeNode*> expected_answer = {root};
    auto generated_tree = solution.allPossibleFBT(3);
    assert(*expected_answer[0] == *generated_tree[0]);

    return 0;
}
