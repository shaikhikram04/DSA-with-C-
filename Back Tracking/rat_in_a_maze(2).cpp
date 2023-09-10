

// T.C -> O(3^(N^2))
// S.C -> O(N^2)


#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &visited, vector<vector<int>> &arr, int n, int i, int j) {
    return (i >= 0 && j >= 0 && i < n && j < n && arr[i][j] == 1 && visited[i][j] == 0);
}

void solve(vector<vector<int>> &arr, int n, vector<string> &ans, int r, int c, vector<vector<int>> &visited, string path) {
    // base case
    if (r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    visited[r][c] = 1;

    int movement[2][4] = {{r+1 , r-1, r, r}, {c, c, c-1, c+1}};
    char direction[4] = {'D', 'U', 'L', 'R'};

    for (int i = 0; i < 4; i++) {
        if (isSafe(visited, arr, n, movement[0][i], movement[1][i]))
            solve(arr, n, ans, movement[0][i], movement[1][i], visited, path + direction[i]);
    }


    // // DOWN
    // if (isSafe(visited, arr, n, r + 1, c)) 
    //     solve(arr, n, ans, r + 1, c, visited, path + 'D');
    

    // // UP
    // if (isSafe(visited, arr, n, r - 1, c)) 
    //     solve(arr, n, ans, r - 1, c, visited, path + 'U');
    

    // // left
    // if (isSafe(visited, arr, n, r, c - 1)) 
    //     solve(arr, n, ans, r, c - 1, visited, path + 'L');
    

    // // Right
    // if (isSafe(visited, arr, n, r, c + 1))
    //     solve(arr, n, ans, r, c + 1, visited, path + 'R');
    

    visited[r][c] = 0;
}

vector<string> searchMaze(vector < vector < int >> & arr, int n) {
    
    vector<string> ans;

    if (arr[0][0] == 0 || arr[n-1][n-1] == 0)
        return ans;

    vector<vector<int>> visited = arr;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            visited[i][j] = 0;
    }

    string path = "";

    solve(arr, n, ans, 0, 0, visited, path);

    sort(ans.begin(), ans.end());

    return ans;

}