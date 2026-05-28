#include<iostream>
#include<vector>
using namespace std;

void dfs(int row,int col,vector<vector<bool>>&visited,vector<vector<char>>&grid)
{
    visited[row][col] = true;
    int rowSize = grid.size();
    int colSize = grid[0].size();

    for(int delRow = -1;delRow<2;++delRow)
    {
        for(int delCol = -1;delCol<2;++delCol)
        {
            int nearRow = row + delRow;
            int nearCol = col + delCol;
            if(nearRow>=0 && nearRow <rowSize && nearCol>=0 && nearCol<colSize && grid[nearRow][nearCol] == 'L' &&  visited[nearRow][nearCol] == 0)
            {
                dfs(nearRow,nearCol,visited,grid);
            }
            
        }

    }

}

int countIslands(vector<vector<char>>&grid)
{
    int rowSize = grid.size();
    int colSize = grid[0].size();

    vector<vector<bool>>visited(rowSize,vector<bool>(colSize,false));
    int islandCount = 0;

    for(int row=0;row<rowSize;++row)
    {
        for(int col=0;col<colSize;++col)
        {
            if(!visited[row][col] && grid[row][col]=='L')
            {
                dfs(row,col,visited,grid);
                islandCount++;
            }
            
        }
    }

    return islandCount;

}

int main()
{
    vector<vector<char>> grid = {
        {'L', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'L'},
        {'L', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'W'}};

    // printing the number of islands
    cout << countIslands(grid) << endl;

    return 0;
}