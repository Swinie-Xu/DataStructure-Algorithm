class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        // 将问题分解为小问题的时候，好像有很多次都是把问题从大问题缩小，而不是从最小的问题扩大
        // 也就是说，可以定义DP(i,j)为从原点到(i,j)处最大的价值，然后推导DP(i-1,j)或者DP(i,j-1)与当前DP(i,j)的关系
        // 另外考虑一下边界条件(个人感觉这里相对困难)就可以推导出动态规划的递推关系了
        
        // 太牛逼了！！！头脑清醒的时候，写个代码一把过太爽了。
        // 当然，不是我自己想出来的思路，看了bilibili的讲解，只看了思路，立马来写的，舒服！
        // 动态规划，直接爱了！！！
        
        // 空间优化 1.原地更改啊！直接在grid上面改，毕竟也用不到原始数据了
        // 空间优化 2.定义以为数组DP[cols]来做，0 - j-1是该节点左边的最大值，j - end 是上面一行从j到end的最大值
        // 本代码用的一维数组，DP[j]表示当前计算节点上一行的节点，DP[j-1]表示左边的节点，当然最后赋值也是给的DP[j]
        vector<int> DP = grid[0];  // 一维数组
        int rows=grid.size();
        int cols=grid[0].size();
        
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if( i==0 && j==0 ) DP[j] = grid[i][j];
                if( i==0 && j>0 ) DP[j] = DP[j-1] + grid[i][j];
                if( i>0 && j==0 ) DP[j] = DP[j] + grid[i][j];
                if( i>0 && j>0 ) DP[j] = max(DP[j-1],DP[j]) + grid[i][j];
            }
        }
        
        return DP[cols-1];
    }
};
