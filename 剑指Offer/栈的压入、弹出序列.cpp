class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 照着解答自己没写出来，看着参考代码写的
        // 感觉早上逻辑不清楚啊，咋回事
        int n = pushV.size();
        stack<int> s;
        int j = 0;
        for(int i=0;i<n;i++)
        {
            while(j<n && (s.empty() || s.top()!=popV[i]))
            {
                s.push(pushV[j]);
                j++;
            }
            // 自己写的时候一直找不到出口，其实只要没办法
            // 按照特定顺序走完，就可以判断false了！
            if(s.top() == popV[i]) s.pop(); 
            else return false;
        }
        return true;
    }
};
