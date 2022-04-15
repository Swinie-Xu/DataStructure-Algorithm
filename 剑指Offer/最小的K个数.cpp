class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        // 这个是真的垃圾，为啥性能这么垃圾
        // 我自己写的
        // 而且我不知道这题考察的啥东西。。。
        vector<int> ret;
        if( input.empty() || k==0 ) return ret;
        sort(input.begin(),input.end());
        ret.assign(input.begin(),input.begin()+k);
        return ret;
    }
};
