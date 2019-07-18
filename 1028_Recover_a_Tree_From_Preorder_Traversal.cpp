//#1028 Recover a Tree From Preorder Traversal - https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
#include <iostream>
#include <vector>
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
    TreeNode* buildtree(vector<string>& nodes, int start, int end, int level){
        if(start > end)
            return NULL;
        if(start == end)
            return new TreeNode(stoi(nodes[start]));
        TreeNode* root = new TreeNode(stoi(nodes[start]));
        int index = end + 2;
        string delim(level, '-');
        for(int i = start + 2; i <= end; i++)
        {
            if(nodes[i] == delim)
                index = i + 1;
        }
        root->left = buildtree(nodes, start + 2, index - 2, level + 1);
        root->right = buildtree(nodes, index, end, level + 1);
        return root;
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        vector<string> nodes;
        int i = 0;
        string temp;
        while(i < (int)S.size())
        {
            while(i < (int)S.size() && S[i] != '-')
            {
                temp.push_back(S[i]);
                i++;
            }
            nodes.push_back(temp);
            temp.clear();
            while(i < (int)S.size() && S[i] == '-')
            {
                temp.push_back('-');
                i++;
            }
            nodes.push_back(temp);
            temp.clear();
        }
        return buildtree(nodes, 0, (int)nodes.size() - 1, 1);
    }
};

int main()
{
    Solution solution;
    string given_S = "1-2--3--4-5--6--7";
    TreeNode* expected_answer = new TreeNode(1);
    expected_answer->left = new TreeNode(2);
    expected_answer->left->left =new TreeNode(3);
    expected_answer->left->right = new TreeNode(4);
    expected_answer->right = new TreeNode(5);
    expected_answer->right->left = new TreeNode(6);
    expected_answer->right->right = new TreeNode(7);

    assert(*solution.recoverFromPreorder(given_S) == *expected_answer);
    return 0;
}
