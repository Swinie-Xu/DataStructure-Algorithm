
class Solution {
public:
        /*
        递归情况：
        1.当到达空节点（既叶子节点的子节点）时，直接返回空
        2.当root等于 o1 或 o2 时，返回root
        3.若不为1， 2中情况，说明需要继续处理：
        对左子树进行递归，返回值记为 t1
        对右子树进行递归，返回值记位 t2
        t1 ，t2 存在以下几种情况：
        ①. 当t1, t2都为空时，说明root的左右子树中都不存在o1, o2， 返回空
        ②. 当t1为空且t2不为空时，说明左子树找不到 o1, o2,所以返回 t2
        ③. 当t2为空且t1不为空时，说明右子树找不到 o1, o2,所以返回 t1
        ④. 当t1, t2都不为空时,说明o1, o2分别位于root的左右子树中，既root为答案，返回root
        */
    TreeNode* dfs(TreeNode* root,int o1,int o2)
    {
        if(root == nullptr) return nullptr;//超过叶节点，返回空
        if(root->val == o1 || root->val == o2) return root;//节点为其中一个
        TreeNode* t1 = dfs(root->left,o1,o2);
        TreeNode* t2 = dfs(root->right,o1,o2);
        if(t1 == nullptr) return t2;//此时两个节点都在右侧
        if(t2 == nullptr) return t1;//此时两个节点都在左侧
        return root;//此时两个节点分别位于左右两侧
    }
    
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        // 其实我不是很明白。。。写完了去好好看看dfs和bfs的C++实现
        return dfs(root,o1,o2)->val;  
    }
};
