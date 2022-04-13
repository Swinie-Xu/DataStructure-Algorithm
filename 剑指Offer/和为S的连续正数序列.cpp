class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        // 滑动窗口的想法
        // 代码是直接复制的，感觉不是很难，没有自己写
        vector<vector<int>> result;
        int dis=1,p1=1,i;     //dis记录窗口的间隔，p1记录窗口左侧元素
        while(dis*(dis+1)/2 < sum){      //满足第一个条件
            if((sum - dis*(dis+1)/2) % (dis+1) == 0){      //满足第二个条件
                p1 = (sum - dis*(dis+1)/2) / (dis+1);      //求窗口的左侧元素
                vector<int> v;
                for(i=p1;i<=p1+dis;i++)     //保存符合条件的序列
                    v.push_back(i);
                result.push_back(v);
            }
            dis++; // 间隔从小到大
        }
        reverse(result.begin(), result.end());     //序列间逆置处理
        return result;
    }
};
