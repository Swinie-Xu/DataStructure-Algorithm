class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型vector
     */
    vector<int> reOrderArray(vector<int>& array) {
        // write code here
        // 最简单的方法，我一开始没用这个，一开始用的新建一个数组，但是偶数的顺序不变好像需要stack
        vector<int> odd,even;
        for(auto k:array)
        {
            if(k&1) odd.push_back(k);
            else even.push_back(k);
        }
        odd.insert(odd.end(),even.begin(),even.end());
        return odd;
    }
};
