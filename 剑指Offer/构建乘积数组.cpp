class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        // 注意还是要多多体会一下感觉，目前我脑子里不是很清楚明了
        // 确实不可以用 累乘/A[i] 来计算，因为很可能A[i]=0;
        // 这个用的是前缀乘积 乘以 后缀乘积的方式来实现
        // 需要注意体会空间复杂度的降低，直接用B来代替left[i]以及用temp来替代right[i]
        vector<int> B(A.size(),1);
        for(int i=1;i<A.size();++i)
        {
            B[i] = B[i-1] * A[i-1];   // left[i]这里用B[i]替代，减少空间复杂度
        }
        int temp = 1;
        for(int j=A.size()-2;j>=0;--j)
        {
            temp = temp*A[j+1];        // right[i]用temp代替
            B[j] = B[j] * temp;        // 就是一次一次累乘，节约空间
        }
        return B;
    }
};
