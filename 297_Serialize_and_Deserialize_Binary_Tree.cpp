//#297 Serialize and Deserialize Binary Tree - https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
#include <iostream>
#include <queue>
#include <sstream>
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

class Codec {
    string null_ptr = "NULL";
    char delim = ',';
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())
        {
            int size_nodes = (int)nodes.size();
            while(size_nodes--)
            {
                auto cur_node = nodes.front();
                nodes.pop();
                if(cur_node == NULL)
                {
                    result += null_ptr + delim;
                    continue;
                }
                result += to_string(cur_node->val) + delim;
                nodes.push(cur_node->left);
                nodes.push(cur_node->right);
            }

        }
        result.erase(result.end() - 1);
        return result;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string token;
        while(getline(ss, token, delim))
        {
            nodes.push_back(token);
        }
        queue<TreeNode*> q;
        int index = 0;
        if(nodes[index] == null_ptr)
            return NULL;
        TreeNode* root = new TreeNode(stoi(nodes[index++]));
        q.push(root);
        while(!q.empty())
        {
            int size_q = (int)q.size();
            while(size_q--)
            {
                auto cur_node = q.front();
                q.pop();
                if(nodes[index] == null_ptr)
                    cur_node->left = NULL;
                else
                {
                    cur_node->left = new TreeNode(stoi(nodes[index]));
                    q.push(cur_node->left);
                }
                index++;
                if(nodes[index] == null_ptr)
                    cur_node->right = NULL;
                else
                {
                    cur_node->right = new TreeNode(stoi(nodes[index]));
                    q.push(cur_node->right);
                }
                index++;

            }
        }
        return root;


    }
};

int main()
{
    Codec solution;
    TreeNode *given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(3);
    given_tree->right = new TreeNode(6);
    given_tree->left->left = new TreeNode(2);
    given_tree->left->right = new TreeNode(4);
    given_tree->right->right = new TreeNode(7);
    assert(*solution.deserialize(solution.serialize(given_tree)) == *given_tree);

    return 0;
}
