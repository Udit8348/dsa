class Solution {

   public:
    bool check_row(int row, vector<vector<char>>& b) {
        // status bit vector
        vector<bool> seen(9, false);

        for (int i = 0; i < 9; i++) {
            char s = b[row][i];
            if (s == '.') {
                continue;
            } else {
                int v = s - '0';
                if (!seen[v - 1]) {
                    seen[v - 1] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }

    bool check_col(int col, vector<vector<char>>& b) {
        // status bit vector
        vector<bool> seen(9, false);

        for (int i = 0; i < 9; i++) {
            char s = b[i][col];
            if (s == '.') {
                continue;
            } else {
                int v = s - '0';
                if (!seen[v - 1]) {
                    seen[v - 1] = true;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    bool check_box(int row, int col, vector<vector<char>>& b) {
        int stride = 3;

        vector<bool> seen(9, false);

        for (int i = 0; i < 3; i++) {
            
            for (int j = 0; j < 3; j++) {
                char s = b[row * stride + i][col * stride + j];
                if (s == '.') {
                    continue;
                } else {
                    int v = s - '0';
                    if (!seen[v - 1]) {
                        seen[v - 1] = true;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            if (!check_row(i, board) || !check_col(i, board)) {
                return false;
            }
        }

        

        for (int i = 0; i < 3; i++) {
            // cout << "here" << endl;
            for (int j = 0; j < 3; j++) {
                if (!check_box(i, j, board)) {
                    return false;
                }
            }
        }

        return true;
    }
};
