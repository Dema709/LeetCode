#include "test_runner.h"
#include "profile.h"
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullptr, nullptr);
    }
private:
    /*
    //16-24ms
    bool isValidBST2(TreeNode* root, int* left, int* right) {
        if (root == nullptr) return true;
        if (left  != nullptr && root->val <= *left ) return false;
        if (right != nullptr && root->val >= *right) return false;
        
        return isValidBST2(root->left, left, &root->val) &&
                    isValidBST2(root->right, &root->val, right);
    }*/
    
    //12-32ms random =_=
    bool isValidBST(TreeNode* root, int* left, int* right) {
        if (left  != nullptr && root->val <= *left ) return false;
        if (right != nullptr && root->val >= *right) return false;
        
        if (root->left != nullptr){
            if (root->right != nullptr){
                return isValidBST(root->left, left, &root->val) &&
                    isValidBST(root->right, &root->val, right);
            } else {
                return isValidBST(root->left, left, &root->val);
            }
        } else {
            if (root->right != nullptr){
                return isValidBST(root->right, &root->val, right);
            } else {
                return true;
            }
        }
    }
    
};

/*
Validate Binary Search Tree

Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

Example 1:
Input: root = [2,1,3]
Output: true
    2
  /   \
 1     3

Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.

Constraints:
    The number of nodes in the tree is in the range [1, 10^4].
    -2^31 <= Node.val <= 23^1 - 1
*/