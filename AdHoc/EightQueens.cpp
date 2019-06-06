/*

 */

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void PrintBoard(vector<vector<int>>& board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    return;
}

bool CanPlace(vector<vector<int>>& board, int row, int col)
{
    int i, j;

    // Check row on left side
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < board.size(); i++, j--)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

/*
  Referenced Geek for Geeks

  Runtime: O(n * (n-1) * (n-2)...) == O(n!)
bool EightQueensV1(vector<vector<int>>& board, int col)
{
    // base case, if all queens are placed
    if (col >= board.size())
    {
        return true;
    }

    // Pick current column and place queen in all rows
    for (int i = 0; i < board.size(); i++)
    {
        if (CanPlace(board, i, col))
        {
            // Place the queen
            if (board[i][col] == 0)
            {
                board[i][col] = 1;
            }

            // Recurse to place rest of queens
            if (EightQueensV1(board, col + 1))
            {
                return true;
            }

            // If placing queen in board[i][col] doesn't lead to solution
            // then remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }

    // Queen can't be placed in any row in this col
    return false;
}

int main()
{
    vector<vector<int>> board = {{0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0, 0}};

    if (!EightQueensV1(board, 0))
    {
        cout << "Solution does NOT exist\n";
    }
    else
    {
        PrintBoard(board);
    }
    return 0;
}
