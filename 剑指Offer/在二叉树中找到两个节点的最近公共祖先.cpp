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
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    
    // 这里是我照着答案敲得，不然没法理解他的意思
    // 不过还好，能大概看懂
    
    bool found = false;    //标记是否找到了
    
    void dfs(vector<int>& road,TreeNode* root,int o)
    {
        if(found || root==nullptr) return;    //已经找到或者到达空节点
        road.push_back(root->val);    //加入数组
        if(root->val == o)
        {
            found = true;
            return;
        }
        dfs(road,root->left,o);
        dfs(road,root->right,o);
        if(found) return;    //防止将节点去除
        road.pop_back();    //不在这条路径，去除节点
    }
    
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
        vector<int>road1,road2;
        dfs(road1,root,o1);    //找到 root到o1路径
        found = false; //重置标记
        dfs(road2,root,o2);    //找到 root到o2路径
        int leng = min(road1.size(), road2.size());
        //寻找最后一个相等节点
        for(int i=0;i<leng;++i)
        {
            if(road1[i] != road2[i] )
            {
                return road1[i-1];
            }
        } 
        return road2[leng-1];// 这里就是两个路径在截断处都是相等，所以最后一个就是了
    }
};
