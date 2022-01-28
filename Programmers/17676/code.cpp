/**
 * @file 17676.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief sweep line
 * @version 0.1
 * @date 2022-01-28 19:06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;
    vector<string> result;
    
    while (getline(iss, buffer, Delimiter))
        result.push_back(buffer);
    return result;
}

int get_endtime(string time) { 
    vector<string> v = split(time, ':');
    v[2].erase(v[2].begin() + 2, v[2].begin() + 3); 
    int hour = stoi(v[0]) * 60 * 60 * 1000; 
    int minute = stoi(v[1]) * 60 * 1000; 
    int second = stoi(v[2]); 
    return hour + minute + second; 
}

int get_duration(string processTime) {
    string subStr = processTime.substr(0, processTime.length() - 1);
    double num = stod(subStr);
    int res = num * 1000;
    return res;
}

int solution(vector<string> lines) {
    int answer = 1;
    vector<pair<int, int>> points;
    
    for(auto&& line : lines) {
        vector<string> v = split(line, ' ');
        int endtime = get_endtime(v[1]);
        int duration = get_duration(v[2]);
        points.push_back({endtime + 999, -1});
        points.push_back({endtime - duration + 1, 1});
    }
    
    sort(points.begin(), points.end(), 
         [&](pair<int, int>& left, pair<int, int>& right) {
             if(left.first == right.first)
                 return left.second > right.second;
             return left.first < right.first;
         });
    
    int cnt = 0;
    for (int i = 0; i < points.size(); ++i) {
        cnt += points[i].second;
        answer = max(answer, cnt);
    }
    
    return answer;
}