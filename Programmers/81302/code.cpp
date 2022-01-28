/**
 * @file 81302.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief BFS
 * @version 0.1
 * @date 2022-01-28 09:36
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <utility> // pair
#include <queue>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int dy[] = {1, 0, -1, 0};
    int dx[] = {0, 1, 0, -1};
    
    for (auto&& room : places) {
        bool ret = false;
        
        for (int y = 0; y < room.size(); ++y) {
            for (int x = 0; x < room[y].size(); ++x) {
                if(room[y][x] == 'P') {
                    vector<vector<bool>> visited(5, vector<bool> (5, false));
                    queue<pair<int, pair<int, int>>> q;
                    q.push({0, {y, x}});
                    visited[y][x] = true;
                    
                    while(q.size()) {
                        auto here = q.front();
                        q.pop();
                        
                        if(here.first >= 2) continue;
                        
                        for (int i = 0; i < 4; ++i) {
                            int ny = here.second.first + dy[i];
                            int nx = here.second.second + dx[i];
                            
                            if(ny < 0 || ny >= 5 || nx < 0 || nx >= 5) 
                                continue;
                            
                            if(visited[ny][nx]) continue;
                            
                            if(room[ny][nx] == 'P') {
                                ret = true;
                                break;
                            }
                            
                            if(room[ny][nx] == 'O') {
                                q.push({here.first + 1, {ny, nx}});
                                visited[ny][nx] = true;
                            }
                        }
                    }
                }
                if (ret) break;
            }
            if (ret) break;
        }
        
        
        answer.push_back(!ret);
    }
    
    return answer;
}