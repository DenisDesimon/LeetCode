//#109 Convert Sorted List to Binary Search Tree - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
#include <iostream>
#include <cassert>
using namespace std;


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


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
    TreeNode* buildTree(int left, int right, ListNode*& head)
    {
        if(left > right)
            return NULL;
        int mid = (left + right) / 2;
        TreeNode* left_node = buildTree(left, mid - 1, head);
        TreeNode* root = new TreeNode(head->val);
        root->left = left_node;
        head = head->next;
        root->right = buildTree(mid + 1, right, head);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = 0;
        ListNode* cur = head;
        while(cur != NULL)
        {
            cur = cur->next;
            size++;
        }
        return buildTree(0, size - 1, head);
    }
};

int main()
{
    Solution solution;
    ListNode* given_list = new ListNode(-10);
    given_list->next = new ListNode(-3);
    given_list->next->next = new ListNode(0);
    given_list->next->next->next = new ListNode(5);
    given_list->next->next->next->next = new ListNode(9);

    TreeNode* expected_answer = new TreeNode(0);
    expected_answer->left = new TreeNode(-10);
    expected_answer->left->right = new TreeNode(-3);
    expected_answer->right = new TreeNode(5);
    expected_answer->right->right = new TreeNode(9);

    assert(*solution.sortedListToBST(given_list) == *expected_answer);

    return 0;
}
