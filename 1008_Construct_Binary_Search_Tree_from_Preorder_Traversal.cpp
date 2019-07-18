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
  };

class Solution {
    TreeNode* buildtree(vector<int>& preorder, int start, int end){
        if(start > end)
            return NULL;
        if(start == end)
            return new TreeNode(preorder[start]);
        TreeNode* root = new TreeNode(preorder[start]);
        int index = end + 1;
        for(int i = 0; i <= end; i++)
        {
            if(preorder[start] < preorder[i])
               {
                    index = i;
                    break;
                }
        }
        root->left = buildtree(preorder, start + 1, index - 1);
        root->right = buildtree(preorder, index, end);
        return root;

    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildtree(preorder, 0, (int)preorder.size() - 1);
    }
};

int main()
{
    Solution solution;
    vector<int> given_preorder = {8, 5, 1, 7, 10, 12};
    auto result = solution.bstFromPreorder(given_preorder);
    cout<<result->val;
    return 0;
}
