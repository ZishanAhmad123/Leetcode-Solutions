class Solution {
public:
void inorder(TreeNode *p,int &sum)
{

	if(!p)return;   
    inorder(p->right,sum);
    sum+=p->val;
    p->val=sum;
    inorder(p->left,sum);
    return ;   
}

TreeNode* bstToGst(TreeNode* root) {
    
    int sum=0;
    inorder(root,sum);
    return root;
}
};