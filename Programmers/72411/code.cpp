/**
 * @file 72411.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief Brute Force
 * @version 0.1
 * @date 2022-01-28 18:58
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int mx[30]; // A ~ Z = 26
map<string, int> combi;
vector<string> db[30][30];

void combination(string& origin, int idx, string& make) {
    if(make.size() > 1) {
        combi[make]++;
        mx[make.size()] = max(mx[make.size()], combi[make]);
        db[make.size()][combi[make]].push_back(make);
    }
    
    for (int i = idx; i < origin.size(); ++i) {
        make.push_back(origin[i]);
        combination(origin, i + 1, make);
        make.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for (auto&& order : orders) {
        string tmp = "";
        sort(order.begin(), order.end());
        combination(order, 0, tmp);
    }
    
    for(auto&& length : course) {
        if (mx[length] > 1) {
            for (auto&& str : db[length][mx[length]])
                answer.push_back(str);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}