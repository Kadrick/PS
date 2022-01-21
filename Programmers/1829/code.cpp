#include <vector>
#include <algorithm>
#include <queue>

#define y first
#define x second

using namespace std;

int bfs(int& m, int& n, vector<vector<int>>& picture, pair<int, int> start, int& color, vector<vector<bool>>& visited) {
    int ret = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.y][start.x] = true;
    
    while(!q.empty()) {
        auto here = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int movex = here.x + dx[i];
            int movey = here.y + dy[i];
            
            if(0 <= movex && movex < n && 0 <= movey && movey < m) {
                if(!visited[movey][movex] && color == picture[movey][movex]) {
                    ret++;
                    visited[movey][movex] = true;
                    q.push({movey, movex});
                }
            }
        }
    }
    
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> visited;
    visited.resize(m, vector<bool> (n, false));
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!visited[i][j] && picture[i][j]) {
                number_of_area++;
                max_size_of_one_area = 
                    max(max_size_of_one_area, bfs(m, n, picture, {i, j}, picture[i][j], visited));
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}