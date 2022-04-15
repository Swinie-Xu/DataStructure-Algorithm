class Solution {
public:
    string LeftRotateString(string str, int n) {
        // 我自己查了字符串的一些函数后想到的。
        // 性能很差劲。
        if(str.empty()) return "";
        int nn = n%str.size();
        string head = str.substr(0, nn);
        string tail = str.substr(nn, str.size()-nn);
        return tail+head;
    }
};
