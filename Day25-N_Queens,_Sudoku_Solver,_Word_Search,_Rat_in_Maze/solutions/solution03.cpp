/*
 * Solution 3: Sudoku Solver
 */
#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<char>>&b,int r,int c,char ch){
    for(int i=0;i<9;i++){
        if(b[r][i]==ch||b[i][c]==ch||b[3*(r/3)+i/3][3*(c/3)+i%3]==ch)return false;
    }return true;
}
bool solveSudoku(vector<vector<char>>&b){
    for(int r=0;r<9;r++)for(int c=0;c<9;c++)if(b[r][c]=='.'){
        for(char ch='1';ch<='9';ch++){
            if(isValid(b,r,c,ch)){b[r][c]=ch;if(solveSudoku(b))return true;b[r][c]='.';}
        }return false;
    }return true;
}
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);
    vector<vector<char>>board={
        {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},{'.','.','.','.','.','.','.','.','.'},
        {'8','.','.','.','6','.','.','.','3'},{'.','.','.','.','2','.','.','.','.'},
        {'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board);
    for(auto&row:board){for(char c:row)cout<<c<<" ";cout<<"\n";}
}
