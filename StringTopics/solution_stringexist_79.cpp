#include "solution_stringexist_79.h"

using namespace std;




bool SolutionStringExist::dfs(vector<vector<char>>& board,string &word,int idx,int x,int y,vector<vector<bool>> &visit)
{
    if(idx >= (int)word.size() || idx < 0) return true;
    
    if(x < 0 || x >= (int)board.size() || y < 0 || y >=  (int)board[0].size()) return false;
    
    if(visit[x][y] == true) return false;
    
    if(board[x][y] != word.at(idx) ) return false;

    visit[x][y] = true;

    //向下
    bool res = dfs(board,word,idx + 1,x + 1,y,visit);
    //向上
    if(!res) res = dfs(board,word,idx + 1,x - 1,y,visit);
    //向右
    if(!res) res = dfs(board,word,idx + 1,x ,y + 1,visit);
    //向左
    if(!res) res = dfs(board,word,idx + 1,x ,y - 1,visit);
    //搜索一次后还原记录，等待下一次搜索
    visit[x][y] = false;
    return res;
}

bool SolutionStringExist::exist(vector<vector<char>>& board, string word) {
    
    if(word.empty()) return true;
    if(board.empty() || board[0].empty()) return false;
    
    int y_len  = board.size();
    int x_len = board[0].size();
    vector<vector<bool>> visit(y_len,vector<bool> (x_len,false));
    bool res = false;
    for(int i = 0; i < y_len; ++i)
    {
        for(int j = 0; j < x_len; ++j)
        {
            if(board[i][j] != word.at(0)) continue;
            
            res = dfs(board,word,0,i,j,visit);
            if(res)
            {
                break;
            }
        }
        if(res)
        {
            break;
        }
    }
    return res;
}

void SolutionStringExist::answer()
{
    
    vector< vector<char > > test_case = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector< vector<char > > test_case2 = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    vector< vector<char > > * arr[] = {&test_case,&test_case2};

    string str_case = "ABCESEEEFS";

    for (u32 i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        /* code */
    
        bool flag = exist(*arr[i],str_case);

        cout << "flag " << flag  << endl;            
    }   
}

