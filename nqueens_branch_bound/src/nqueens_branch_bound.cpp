//============================================================================
// Name        : nqueens_branch_bound.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n)
	{
		if(col==n)
		{
			ans.push_back(board);//add the solution to the answer
		return;
		}

		for(int row=0;row<n;row++)
		{
			if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1 +col-row]==0)
			{
				board[row][col]='Q';
				leftRow[row]=1;
				lowerDiagonal[row+col]=1;
				upperDiagonal[n-1 +col-row]=1;
				solve(col+1,board,ans,leftRow,lowerDiagonal,upperDiagonal,n);
				//backtracking steps
				board[row][col]='.';
				leftRow[row]=0;
				lowerDiagonal[row+col]=0;
				upperDiagonal[n-1 +col-row]=0;


			}
		}

	}

	vector<vector<string>> solveNqueens(int n)
	{
		vector<vector<string>> ans;
		vector<string> board(n);
		string s(n,'.');
		for(int i=0;i<n;i++)
		{
			board[i]=s;
		}
		vector<int> leftRow(n,0), lowerDiagonal((2*n-1),0), upperDiagonal((2*n-1),0);
		solve(0,board,ans,leftRow, lowerDiagonal, upperDiagonal,n);
		return ans;
	}
};

int main() {
	int n;
	cout<<"Enter the number of Queens= "<<endl;
	cin>>n;
	Solution ob;
	vector<vector<string>> res= ob.solveNqueens(n);
	for(int i=0;i<res.size();i++)
	{
		cout<<"Arrangement= "<<(i+1)<<endl;
		for(int j=0;j<res[0].size();j++)
		{
			cout<<res[i][j];
			cout<<endl;
		}
		cout<<endl;
	}

	return 0;
}
