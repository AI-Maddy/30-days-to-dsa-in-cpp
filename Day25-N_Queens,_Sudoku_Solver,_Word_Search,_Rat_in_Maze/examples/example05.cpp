/*
 * Example 5: Rat in a Maze
 */
#include <bits/stdc++.h>
using namespace std;
// Example 5: Rat in a Maze (find all paths)
int N;
vector<string> maze;
vector<string> paths;
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1,  0};
char dc[] = {'D', 'R', 'L', 'U'};
void solve(int x, int y, string path, vector<vector<bool>>& visited) {
    if (x == N-1 && y == N-1) { paths.push_back(path); return; }
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && maze[nx][ny] == '1') {
            visited[nx][ny] = true;
            solve(nx, ny, path + dc[d], visited);
            visited[nx][ny] = false;
        }
    }
}
int main() {
    N = 4;
    maze = {"1100","1110","0110","0011"};
    if (maze[0][0] == '0' || maze[N-1][N-1] == '0') { cout << "No path\n"; return 0; }
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[0][0] = true;
    solve(0, 0, "", visited);
    if (paths.empty()) cout << "No path\n";
    else for (auto& p : paths) cout << p << "\n";
}
