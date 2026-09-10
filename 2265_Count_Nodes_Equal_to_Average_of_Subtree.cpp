//#2265 Count Nodes Equal to Average of Subtree - https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
#include <iostream>
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
    pair<int, int> dfs(TreeNode* root, int &result){
        int sum = root->val;
        int count = 1;
        if(root->left)
        {
            auto [leftSum, leftCount] = dfs(root->left, result);
            sum += leftSum;
            count += leftCount;
        }
        if(root->right)
        {
            auto [rightSum, rigthCount] = dfs(root->right, result);
            sum += rightSum;
            count += rigthCount;

        }
        int avg = sum / count;
        if(avg == root->val)
            result++;
        return {sum, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *givenTree = new TreeNode(4);
    givenTree->left = new TreeNode(8);
    givenTree->left->left = new TreeNode(0);
    givenTree->left->right = new TreeNode(1);
    givenTree->right = new TreeNode(5);
    givenTree->right->right = new TreeNode(6);
    int expectedAnswer = 5;
    assert(solution.averageOfSubtree(givenTree) == expectedAnswer);

    givenTree = new TreeNode(1);
    expectedAnswer = 1;
    assert(solution.averageOfSubtree(givenTree) == expectedAnswer);


    return 0;
}
