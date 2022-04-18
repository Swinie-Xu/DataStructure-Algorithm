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
     * @param sum int整型 
     * @return int整型
     */
    // 这个代码是手把手抄的，因为想不出来
    // 感觉dfs的思想比较粗暴，接受起来比较需要时间吧
    // 但是我大概看懂了代码的意思，毕竟递归这东西，是需要模糊理解的，不然不可能理解
    
    int res = 0;
    void dfs(TreeNode* root,int sum)  //dfs查询以某结点为根的路径数
    {
        if(root==nullptr)
        {
            return;
        }
        if(sum == root->val) res++;    //符合目标值
        
        dfs(root->left,sum-root->val);    //进入子节点继续找
        dfs(root->right,sum-root->val);
    }
    
    int FindPath(TreeNode* root, int sum) {//dfs 以每个结点作为根查询路径
        // write code here
        if(root == nullptr) return res;//为空则返回
        dfs(root,sum);//查询以某结点为根的路径数
        
        FindPath(root->left, sum);//以其子结点为新根
        FindPath(root->right, sum);
        
        return res;

        }
};
