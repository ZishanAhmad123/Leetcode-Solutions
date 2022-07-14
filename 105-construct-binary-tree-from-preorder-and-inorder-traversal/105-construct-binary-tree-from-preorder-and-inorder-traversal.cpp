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
 unordered_map<int,int> hashMap; // to store inorder values 
	int idx; // current idx value for processing 
    
	TreeNode* build(vector<int>& preorder, vector<int>& inorder,int start, int end)
	{
		   if(start > end) 
			return NULL;
		int curr=preorder[idx]; // curr node value
		idx++;
		TreeNode *root = new TreeNode(curr);
		// if (start == end)
		// 	return root;
		int mid = hashMap[curr];// search in inorder list
		root->left = build(preorder, inorder, start, mid-1); // spliting two halves
		root->right = build(preorder, inorder, mid+1, end);

		return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
		for(int i = 0;i < n; i++){
			hashMap[inorder[i]] = i;
		}
		idx = 0;
		return build(preorder, inorder, 0, n-1);
    }
};