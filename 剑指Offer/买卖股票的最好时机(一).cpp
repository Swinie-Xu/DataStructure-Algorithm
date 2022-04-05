class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        // 就是贪心算法：超级牛逼的思路啊！！！
        /*
            对于某一个天的股票的价格，假设我们在这天卖出，
            那么假如我们需要最大的收益的话，我们就需要在这一天前选择价格最低的一天买入，
            得到的差值就是我们的最大收益，然后维护一个最大值就行了。
        */
        int min = prices[0];  // 维护前面已知的最小值
        int max = 0;          // 维护最大收益
        for(auto k:prices)    // 别的不知道，循环的时候 auto 真好用
        {
            if(k<min) min = k;
            if(max<=k-min) max = k-min;
        }
        return max;
        
    }
};
