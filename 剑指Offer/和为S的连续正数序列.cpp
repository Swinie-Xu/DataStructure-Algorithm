class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        // 用的是公式，不过时间复杂度不低，而且有点笨
        // 就是换不同的a1利用等差数列求和，来确定是不是可以有个合适的
        // 遍历所有。。。所以时间复杂度不低
        vector<int> part;
        vector<vector<int> > ret;
        for(int a1 = 1;a1<sum;++a1)
        {
            int length = 2;
            while(a1*length + length*length/2 -length/2 < sum) ++length;
            if(a1*length + length*length/2 -length/2 == sum) 
            {
                for(int i=a1;i<a1+length;++i) part.push_back(i);
                ret.push_back(part);
                part.clear();
            }
        }
        return ret;
    }
};
