class Solution {
public:
    #define SCD static_cast<double>
    vector<int> v;
    void Insert(int num) {
        v.push_back(num);
    }

    double GetMedian() { 
        sort(v.begin(),v.end());
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
