class Solution {
public:
    // 输入的时候采用 插入排序，利用了lower_bound函数
    // 用了数组的insert方法，第一个参数是位置，第二个参数是 插入的值
    #define SCD static_cast<double>
    vector<int> v;
    void Insert(int num) {
        if(v.empty()) v.push_back(num);
        else 
        {
            auto it = lower_bound(v.begin(), v.end(), num);
            v.insert(it, num);
        }
    }

    double GetMedian() { 
        int sz = v.size();
        if(sz&1)  // 判断是不是奇数
        {
            return SCD(v[sz>>1]);
        }
        else 
        {
            return SCD((v[sz>>1]+v[(sz-1)>>1]))/2; // 这里要先SCD再除哦！不然就是取整了
        }
    }

};
