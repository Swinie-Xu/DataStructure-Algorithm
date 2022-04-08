class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) {
        // write code here
        // 我自己写的代码，vector存，如果遇到重复，就剔除，无重复就继续push_back
        sort(array.begin(),array.end());
        vector<int> stk;
        for(int i=0;i<array.size();++i)
        {
            if(stk.empty()) stk.push_back(array[i]);  // 数组空的时候，只需要添加就行
            else if(array[i]!=stk[stk.size()-1])        // 如果下一个不等于上一个，就存进去
            {
                stk.push_back(array[i]);
            }
            else stk.resize(stk.size()-1);       // 如果相等，就让size-1，相当于删了
        }
        return stk;
    }
};
