class Solution {
public:
    string ReverseSentence(string str) {
        // 真的服了，果然是对功能运用出了问题，卡了我他妈一大堆时间
        // string.append(str,index,length) 不是范围索引，是从索引开始往后面几个字符
        // 真的他妈服了！！！！
        
        // 用的双指针，从右边往左边指
        // 右指针表示结尾的index
        // 左指针表示开始的前一个位置，即空格位置
        // 遇到空格之后，需要整体将左右指针全部左移
        // 注意结尾的地方，还需要append剩下的一个单词
        
        int left=str.size()-1;
        int right = left;
        string tmp;
        string test;
        while(left != -1)
        {
            if(str[left] == ' ')
            {
                test=str.substr(left+1,right-left);
                tmp.append(str,left+1,right-left);
                tmp += ' ';
                while(str[left]==' ') left--;
                right = left;
            }
            left--;
        }
        tmp.append(str,left+1,right-left);
        return tmp;
    }
};
