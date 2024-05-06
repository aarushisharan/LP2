////============================================================================
//// Name        : N_Queens.cpp
//// Author      :
//// Version     :
//// Copyright   : Your copyright notice
//// Description : Hello World in C++, Ansi-style
////============================================================================

#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class Solution{
public:

	bool isSafe(int row, int col, vector<string> &board, int n)
	{
		int duprow=row;
		int dupcol=col;

		while(row>=0 && col>=0)
		{ //Check if queen is present in the upper left diagonal
			if(board[row][col]=='Q')
				return false;
			row--;
			col--;
		}
		row=duprow;
		col=dupcol;
		while(col>=0)
		{
			//check for left side
			if(board[row][col]=='Q')
				return false;
			col--;
		}
		row=duprow;
		col=dupcol;
		while(row<n && col>=0)
		{
			//check for lower left diagonal
			if(board[row][col]=='Q')
				return false;
			row++;
			col--;
		}
		return true;

	}
	void solve(int col, vector<vector<string>> &ans, vector<string> &board, int n)
	{
		if (col == n) {
		        ans.push_back(board);
		        return;
		      }
		      for (int row = 0; row < n; row++) {
		        if (isSafe(row, col, board, n)) {
		          board[row][col] = 'Q';
		          solve(col + 1, ans, board, n);
		          board[row][col] = '.';
		        }
		      }
	}

	vector<vector<string>> solveNQueens(int n)
		{
			vector<string> board(n);
			vector<vector<string>> ans;
			string s(n,'.');
			for (int i = 0; i < n; i++)
			{
			  board[i] = s;
			}
			solve(0,ans,board,n);
			return ans;

		}
};
int main()
{
	Solution ob;
	int n;
	cout<<"Enter the number of Queens= "<<endl;
	cin>>n;
	vector<vector<string>> res= ob.solveNQueens(n);
	for(int i=0;i<res.size();i++)
	{
		cout<<"Arrangement"<<(i+1)<<endl;
		for(int j=0;j<res[0].size();j++)
		{
			cout<<res[i][j];
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;


	}


//
//#include <bits/stdc++.h>
//
//using namespace std;
//class Solution {
//  public:
//    bool isSafe1(int row, int col, vector < string > board, int n) {
//      // check upper element
//      int duprow = row;
//      int dupcol = col;
//
//      while (row >= 0 && col >= 0) {
//        if (board[row][col] == 'Q')
//          return false;
//        row--;
//        col--;
//      }
//
//      col = dupcol;
//      row = duprow;
//      while (col >= 0) {
//        if (board[row][col] == 'Q')
//          return false;
//        col--;
//      }
//
//      row = duprow;
//      col = dupcol;
//      while (row < n && col >= 0) {
//        if (board[row][col] == 'Q')
//          return false;
//        row++;
//        col--;
//      }
//      return true;
//    }
//
//  public:
//    void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
//      if (col == n) {
//        ans.push_back(board);
//        return;
//      }
//      for (int row = 0; row < n; row++) {
//        if (isSafe1(row, col, board, n)) {
//          board[row][col] = 'Q';
//          solve(col + 1, board, ans, n);
//          board[row][col] = '.';
//        }
//      }
//    }
//
//  public:
//    vector < vector < string >> solveNQueens(int n) {
//      vector < vector < string >> ans;
//      vector < string > board(n);
//      string s(n, '.');
//      for (int i = 0; i < n; i++) {
//        board[i] = s;
//      }
//      solve(0, board, ans, n);
//      return ans;
//    }
//};
//int main() {
//  int n = 4; // we are taking 4*4 grid and 4 queens
//  Solution obj;
//  vector < vector < string >> ans = obj.solveNQueens(n);
//  for (int i = 0; i < ans.size(); i++) {
//    cout << "Arrangement " << i + 1 << "\n";
//    for (int j = 0; j < ans[0].size(); j++) {
//      cout << ans[i][j];
//      cout << endl;
//    }
//    cout << endl;
//  }
//  return 0;
//}
