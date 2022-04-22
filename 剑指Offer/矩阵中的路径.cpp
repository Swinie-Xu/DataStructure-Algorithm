class Solution {
public:
    // https://blog.nowcoder.net/n/34b76241282f4907ba681c16f050576e?f=comment
    int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};//四个偏移量
    int xlen,ylen;
    bool dfs(vector<vector<char>>&g,string &str,int u,int x,int y)
    {
        if(g[x][y]!=str[u]) return false;//判断当前位置与str的字符是否对应
        if(u == str.size()-1) return true;//搜索出口:str的所有字符都完成对应
        char t = g[x][y];
        g[x][y] = '*'; //记录已经走过的格子
        for(int i=0;i<4;++i)
        {
            int X = x+dx[i],Y = y+dy[i];
            if(X>=0 && X<xlen && Y>=0 && Y<ylen)//判断转移的位置是否越出棋盘
            {
                if(dfs(g,str,u+1,X,Y)) return true;
            }
        }
        g[x][y] = t;//恢复现场
        return false;
    }
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        xlen = matrix.size(), ylen = matrix[0].size();
        for(int i=0;i<xlen;++i)
        {
            for(int j=0;j<ylen;++j)
            {
                if(dfs(matrix,word,0,i,j)) return true;
            }
        }
        return false;
 
    }
};
