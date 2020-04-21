/**
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of 
node.left has a value < node.val, and any descendant of node.right has a value > node.val.  
Also recall that a preorder traversal displays the value of the node first, then traverses node.left, 
then traverses node.right.)

**/


#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
class Solution {
    TreeNode* head;

    TreeNode* bstInsert(TreeNode** node, int val){
        if (*node == NULL){
            *node = new TreeNode(val);
            if (head == NULL){
                head = *node;
            }
            return head;
        }

        if ((*node)->val < val){
            return bstInsert(&((*node)->right), val);
        } else {
            return bstInsert(&((*node)->left), val);
        }
    }

public:
    Solution()
    {
        head = NULL;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        for(auto ii: preorder){
            bstInsert(&head, ii);
        }

        return head;
    }

    void bstPreorder(TreeNode* node){
        if (node != NULL){
            cout<<node->val<<" ";
            bstPreorder(node->left);
            bstPreorder(node->right);
        }
    }
};

int main()
{
    TreeNode* head = NULL;
    vector<int> preorder{8,5,1,7,10,12};
    Solution s;
	
    head = s.bstFromPreorder(preorder);
    s.bstPreorder(head);

	return 0;
}
