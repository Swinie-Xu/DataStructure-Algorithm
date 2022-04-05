class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        // 用的最傻瓜的方式
        // 主要就是用了 j %= A.size(); 来循环索引A的值
        // 结果只超过了1%的人
        vector<int> B;
        for(int i = 0;i<A.size();i++)
        {
            int temp = 1;
            for(int j = (i+1)%A.size(),cnt = 0;cnt<A.size()-1;++j,++cnt) 
            {
                j %= A.size();
                temp *= A[j];
            }
            B.push_back(temp);
        }
        return B;
    }
};
