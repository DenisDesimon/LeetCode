//#508 Most Frequent Subtree Sum - https://leetcode.com/problems/most-frequent-subtree-sum/
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
  };

class Solution {
    int post_order(TreeNode* root, unordered_map<int, int>& num_path){
        if(root == NULL)
            return 0;
        int left = post_order(root->left, num_path);
        int right = post_order(root->right, num_path);
        int path_sum = left + right + root->val;
        num_path[path_sum]++;
        return path_sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> num_path;
        vector<int> result;
        post_order(root, num_path);
        int max_freq = 0;
        for(auto path : num_path)
        {
            if(path.second > max_freq)
            {
                result.clear();
                result.push_back(path.first);
                max_freq = path.second;
            }
            else if(path.second == max_freq)
            {
                result.push_back(path.first);
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    TreeNode *given_tree = new TreeNode(5);
    given_tree->left = new TreeNode(2);
    given_tree->right = new TreeNode(-3);
    vector<int> expected_answer = {4, 2, -3};
    assert(solution.findFrequentTreeSum(given_tree) == expected_answer);

    return 0;
}
