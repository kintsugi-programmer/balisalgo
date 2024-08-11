#include <iostream>
#include <vector>

using namespace std;

void floodFill(vector<vector<char>>& board, int i, int j) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'N')
        return;

    board[i][j] = 'F';

    floodFill(board, i+1, j);
    floodFill(board, i-1, j);
    floodFill(board, i, j+1);
    floodFill(board, i, j-1);
}

void updateFloodedAreas(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    // Find the regions of 'N' and mark them as 'F'
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'N') {
                floodFill(board, i, j);
                return; // We only need to flood one region
            }
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'F', 'F', 'F', 'F'},
        {'F', 'N', 'N', 'F'},
        {'F', 'F', 'N', 'F'},
        {'F', 'N', 'F', 'F'}
    };

    updateFloodedAreas(board);

    // Output the updated grid
    for (auto row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}

