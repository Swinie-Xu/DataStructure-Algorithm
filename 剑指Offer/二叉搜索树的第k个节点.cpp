
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    
    // 中序遍历，递归写法
    // 抄https://blog.nowcoder.net/n/28ac73092b7c4c788b1d7710b09138c2?f=comment的答案，不过自己还是学了一些啦，怎么会单纯抄
    // https://blog.nowcoder.net/n/28ac73092b7c4c788b1d7710b09138c2?f=comment
    TreeNode* res = nullptr;//记录返回的结点
    int cnt = 0;//记录中序遍历了多少个
    
    void midOrder(TreeNode* root,int k)
    {
        if(root == nullptr || cnt > k) return;//当遍历到结点为空或者超过k时，返回
        midOrder(root->left, k);
        cnt++;
        if(cnt == k) res = root;//只记录第k个
        midOrder(root->right, k);
    }
    int KthNode(TreeNode* proot, int k) {
        // write code here
        midOrder(proot, k);
        if(res) return res->val;
        else return -1;//二叉树为空，或是找不到
        
    }
};
