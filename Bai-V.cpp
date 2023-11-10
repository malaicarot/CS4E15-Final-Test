#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int orangesRotting(vector<vector<int>> &grid);
int main()
{
    vector<vector<int>> v = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int r = orangesRotting(v);
    cout << r;

    return 0;
}

/*Dinh Nghia*/
int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> rotten;
    int m = grid.size();
    int n = grid[0].size();
    int freshCount = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                freshCount++;
            }
            else if (grid[i][j] == 2)
            {
                rotten.push({i, j});
            }
        }
    }

    int minutes = 0;
    vector<pair<int, int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!rotten.empty() && freshCount > 0)
    {
        int size = rotten.size();
        for (int i = 0; i < size; i++)
        {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();

            for (auto dir : direction)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    freshCount--;
                    rotten.push({newX, newY});
                }
            }
        }
        minutes++;
    }

    return (freshCount == 0) ? minutes : -1;
}