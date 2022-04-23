class Solution {
public:
    int rectCover(int number) {
        // 这个就是斐波那契数列，不知道为啥
        if(number < 1) return 0;
        else if(number<=2) return number;
        else return rectCover(number-1) + rectCover(number-2);
    }
};
