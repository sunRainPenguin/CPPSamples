#ifndef SOLUTION_H
#define SOLUTION_H
#include <vector>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int h = grid.size();
        int w = grid[0].size();
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(grid[i][j]==1)
                {
                    if(i==0 || grid[i-1][j]==0)
                    {
                        result++;
                    }
                    if(j==w-1 || grid[i][j+1]==0)
                    {
                        result++;
                    }
                    if(i==h-1 || grid[i+1][j]==0)
                    {
                        result++;
                    }
                    if(j==0 || grid[i][j-1]==0)
                    {
                        result++;
                    }
                }
            }
        }
        return result;
    }
};

#endif // SOLUTION_H
