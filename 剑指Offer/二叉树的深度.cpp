/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
        /*
         函数是求二叉树的最大深度，我们不必管函数具体是怎么实现的。 
         所以最终结果为 max( 头结点左子树的最大深度, 头结点右子树的最大深度)+1
         */
        
        if(!pRoot) return 0;
        int lval = TreeDepth(pRoot->left);
        int rval = TreeDepth(pRoot->right);
        return max(lval,rval) + 1;
    }
};
