//#449 Serialize and Deserialize BST - https://leetcode.com/problems/serialize-and-deserialize-bst/
#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
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

class Codec {
    char delim = ',';
    TreeNode* BST_from_array(vector<int> nodes)
    {
        int size_nodes = (int)nodes.size();
        if(size_nodes == 0)
            return NULL;
        TreeNode* root = new TreeNode(nodes[0]);
        if(size_nodes > 1)
        {
            auto upper = upper_bound(nodes.begin(), nodes.end(), root->val);
            vector<int> left(nodes.begin() + 1, upper);
            vector<int> right(upper, nodes.end());
            root->left = BST_from_array(left);
            root->right = BST_from_array(right);
        }
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<TreeNode*> nodes;
        string result;
        while(root != NULL || !nodes.empty())
        {
            while(root != NULL)
            {
                result += to_string(root->val) + delim;
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            root = root->right;
        }
        if(result.size() > 0)
        result.erase(result.end() - 1);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        vector<int> nodes;
        while(getline(ss, token, delim))
            nodes.push_back(stoi(token));
        TreeNode* root = BST_from_array(nodes);
        return root;
    }
};

int main()
{
    Codec solution;
    TreeNode *given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(4);
    given_tree->left->left = new TreeNode(3);
    given_tree->right= new TreeNode(7);
    given_tree->right->left = new TreeNode(6);
    assert(*solution.deserialize(solution.serialize(given_tree)) == *given_tree);

    return 0;
}
