// Convert BST to Greater Tree

void  sum_node(struct TreeNode* root, int* k){
    if(root == NULL)return;
    sum_node(root->right, k);
    root->val = (*k)+ root->val;
    *k = root->val;
    sum_node(root->left, k);
}
struct TreeNode* convertBST(struct TreeNode* root) {
    int k =0;
    struct TreeNode* temp = malloc(sizeof(struct TreeNode));
    temp = root;
    sum_node(root, &k);
    return root;
}
