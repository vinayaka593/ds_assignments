//Delete Node in a BST

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 struct TreeNode* findMin(struct TreeNode* root)
{
    if (root == NULL) 
    {
        return NULL;
    }
    else if (root->left != NULL) 
    {
        return findMin(root->left);
    }
    return root;
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if(root == NULL)
        return NULL;

    if(key < root->val)
    {

        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val)
    {

        root->right = deleteNode(root->right, key);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if((root->left == NULL || root->right == NULL))
        {
            struct TreeNode *temp;
            if(root->left == NULL)
            {
                temp = root->right;
            }
            else
            {
                temp = root->left;
            }
            free(root);
            return temp;
        }
        else
        {
            struct TreeNode* temp = findMin(root->right);
            root->val = temp->val;
            root->right = deleteNode (root->right, temp->val);
        }
    }

    return root;
}
