#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void filler(vector<vector<int>> &ans, vector<string> &board, int n)
    {
        vector<int> temp; 
        for(int i =0; i<n; i++)
        {
            for(int j =0; j<n; j++)
            {
                
                if(board[j][i] == 'Q')
                {
                    temp.push_back(j+1);
                }
            }
        }
        ans.push_back(temp);
    }
    void solve(int col, int n, vector<string> &board, vector<int> &leftRow, vector<int> &upperD, vector<int> &lowerD, vector<vector<int>> &ans)
    {
        if(col == n)
        {
            filler(ans, board, n);
        }
        for(int row = 0; row<n; row++)
        {
            if(leftRow[row] == 0 && upperD[row + col] == 0 && lowerD[n-1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftRow[row] = 1;
                upperD[row+col] = 1;
                lowerD[n-1 + col - row] = 1;
                solve(col+1, n, board, leftRow, upperD, lowerD, ans);
                
                board[row][col] = '.';
                leftRow[row] = 0;
                upperD[row+col] = 0;
                lowerD[n-1 + col - row] = 0;
            }
        }
        
    }
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        string s(n,'.');
        vector<string> board(n);
        for(int i =0; i<n; ++i)
        {
            board[i] = s;
        }
        vector<int> leftRow(n, 0), upperD(2* n - 1, 0), lowerD(2* n - 1, 0);
        solve(0, n, board, leftRow, upperD, lowerD, ans);
        return ans;
    }
};
