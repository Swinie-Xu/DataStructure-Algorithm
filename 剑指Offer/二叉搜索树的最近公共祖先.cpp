/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param root TreeNode类 
     * @param p int整型 
     * @param q int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        // write code here
        
        /*
        思路：非递归，利用二叉搜索树的特点。左子树<根节点<右子树
        
        若p,q都比当前结点的值小，说明最近公共祖先结点在当前结点的左子树上，继续检查左子树；
        若p,q都比当前结点的值大，说明最近公共祖先结点在当前结点的右子树上，继续检查右子树；
        若p,q中一个比当前结点的值大，另一个比当前结点的值小，则当前结点为最近公共祖先结点
        */
        
        TreeNode * curnode = root;  // 当前遍历节点
        while(true)
        {
            if(p<curnode->val && q<curnode->val) curnode = curnode->left;  // 在左子树找
            else if(p>curnode->val && q>curnode->val) curnode = curnode->right;  // 在右子树找
            else return curnode->val;
        }

    }
};
