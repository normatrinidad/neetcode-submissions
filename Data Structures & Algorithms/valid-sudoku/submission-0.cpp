class Solution {
public:

    bool rowsValid(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            vector<bool> seen(10, false);
            for ( int j = 0; j < board[i].size();j++) {
                int cell = board[i][j];
                if (isdigit(cell)) {
                    if (seen[cell - '0']) {
                        return false;
                    }
                    seen[cell - '0'] = true;
                }
            }
        }

        return true;
    }
    
    bool colsValid(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            vector<bool> seen(10, false);
            for ( int j = 0; j < board[i].size();j++) {
                int cell = board[j][i];
                if (isdigit(cell)) {
                    if (seen[cell - '0']) {
                        return false;
                    }
                    seen[cell - '0'] = true;
                }
            }
        }

        return true;
    }

    bool squaresValid(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i+=3) {
            for (int j = 0; j < board[i].size();j+=3) {
                bool result = validateSquare(board, i, j);
                if (!result) {
                    return false;
                }
            }
        }

        return true;
    }

    bool validateSquare(vector<vector<char>>& board, int rini, int cini) {
        vector<bool> seen(10, false);

        for (int i = 0; i < 3; i++) {
            for ( int j = 0; j < 3; j++) {
                int cell = board[rini + i][cini + j];
                if (isdigit(cell)) {
                    if (seen[cell - '0']) {
                        return false;
                    }
                    seen[cell - '0'] = true;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return rowsValid(board) && colsValid(board) && squaresValid(board);
    }
};
