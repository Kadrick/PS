#include <string>
#include <vector>

using namespace std;

int turn(vector<vector<int>>& board, int left, int top, int right, int bottom) {
    int ret = 2e9;
    vector<int> newL, newT, newR, newB;
    
    newT.push_back(board[top + 1][left]);
    for (int i = 0; i < right - left; ++i) {
        newT.push_back(board[top][left + i]);
        ret = min(ret, board[top][left + i]);
    }
    
    for (int i = 0; i < bottom - top; ++i) {
        newL.push_back(board[bottom - i][left]);
        ret = min(ret, board[bottom - i][left]);
    }    
    
    newB.push_back(board[bottom - 1][right]);
    for (int i = 0; i < right - left; ++i) {
        newB.push_back(board[bottom][right - i]);
        ret = min(ret, board[bottom][right - i]);
    }
    
    for (int i = 0; i < bottom - top; ++i) {
        newR.push_back(board[top + i][right]);
        ret = min(ret, board[top + i][right]);
    }    
    
    for (int i = 0; i < newT.size(); ++i)
        board[top][left + i] = newT[i];
    
    for (int i = 0; i < newR.size(); ++i)
        board[top + i + 1][right] = newR[i];
    
    for (int i = 0; i < newB.size(); ++i)
        board[bottom][right - i] = newB[i];
    
    for (int i = 0; i < newL.size(); ++i)
        board[bottom - i - 1][left] = newL[i];
    
    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int number = 0;
    vector<vector<int>> board;
    board.resize(rows, vector<int> (columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j)
            board[i][j] = ++number;
    }
    
    for (auto&& query : queries)
        answer.push_back(turn(board, query[1] - 1, query[0] - 1, query[3] - 1, query[2] - 1));    
    
    return answer;
}