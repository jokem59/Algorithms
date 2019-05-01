/*

 */

#include <iostream>
#include <vector>

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

/*
  Runtime: 

  Brute force implementation.

  For each position in n x n board, place the first queen
 */
void EightQueensV1(vector<vector<int>>& board)
{

}

int main()
{

    return 0;
}
