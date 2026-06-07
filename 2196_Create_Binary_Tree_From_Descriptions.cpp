//#2196 Create Binary Tree From Descriptions - https://leetcode.com/problems/create-binary-tree-from-descriptions/
#include <iostream>
#include <cassert>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> valTree;
        unordered_set<int> children;
        for(auto &descript : descriptions)
        {
            int val = descript[0];
            if(!valTree.count(val))
                valTree[val] = new TreeNode(val);
            int child = descript[1];
            children.insert(child);
            if(!valTree.count(child))
            {
                valTree[child] = new TreeNode(child);
            }
            if(descript[2])
                valTree[val]->left = valTree[child];
            else
                valTree[val]->right = valTree[child];
        }
        for(auto &descript : descriptions)
        {
            if(!children.count(descript[0]))
                return valTree[descript[0]];
        }
        return nullptr;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> givenDescriptions  = {{20, 15, 1}, {20, 17, 0}, {50, 20, 1}, {50, 80, 0}, {80, 19, 1}};
    TreeNode* expectedAnswer = new TreeNode(50);
    expectedAnswer->left = new TreeNode(20);
    expectedAnswer->left->left = new TreeNode(15);
    expectedAnswer->left->right = new TreeNode(17);
    expectedAnswer->right = new TreeNode(80);
    expectedAnswer->right->left = new TreeNode(19);
    assert(*solution.createBinaryTree(givenDescriptions) == *expectedAnswer);

    givenDescriptions  = {{1, 2, 1}, {2, 3, 0}, {3 ,4, 1}};
    expectedAnswer = new TreeNode(1);
    expectedAnswer->left = new TreeNode(2);
    expectedAnswer->left->right = new TreeNode(3);
    expectedAnswer->left->right->left = new TreeNode(4);
    assert(*solution.createBinaryTree(givenDescriptions) == *expectedAnswer);

    return 0;
}
