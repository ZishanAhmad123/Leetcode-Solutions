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
    int pseudoPalindromicPaths (struct TreeNode* root) {
	int result = 0;
	std::vector<int> map_(10); // node values contain only 1~9 and NULL
	helper(root, result, map_);
	return result;
}
void helper(struct TreeNode* root, int& result, std::vector<int>& map_) { // find every path
	if (root == nullptr) return;
	map_[root->val]++;
	if (root->left == nullptr && root->right == nullptr && isPalindrome(map_)) result++;
	helper(root->left, result, map_);
	helper(root->right, result, map_);
	map_[root->val]--;
}
bool isPalindrome(std::vector<int>& map_) { // check pseudo-palindrome
	int single = 0;
	for (int i = 0; i < map_.size(); i++) {
		if (map_[i] % 2 == 1) single++;
	}
	return single > 1 ? false : true;
}
};