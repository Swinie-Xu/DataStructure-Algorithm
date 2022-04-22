/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return bool布尔型
     */
    
    // 抄的代码，完全没有可能自己写出来
    // 基本记不住，虽然自己好像遇到好几次了
    // 寄希望于多次的重复吧
    
    bool preorder(TreeNode* root,int sum,int ans)
    {
        if(!root) return false;//先序遍历终止条件；
        ans+=root->val;//累和
        if(!root->left && !root->right && ans==sum) return true;//当前节点为子节点，并且和为sum，存在节点和为指定值的路径；
        return preorder(root->left,sum,ans) || preorder(root->right,sum,ans);//分支分别从左右节点判断是否存在；
    }
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(!root) return false;//特判根节点为空的情况；
        return preorder(root,sum,0);
 
    }
};
