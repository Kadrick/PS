/**
 * @file 67256.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-01-28 09:28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int get_distance(int target, int cur) {
    int vertical = abs(target - cur) / 3;
    int horizontal = abs(target - cur) % 3;
    return vertical + horizontal;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int left = 10, right = 12;
    
    for (auto&& target : numbers) {
        if(target == 0) 
            target = 11;
            
        if(target % 3 == 1) {
            left = target;
            answer += 'L';
        } else if (target % 3 == 0) {
            right = target;
            answer += 'R';
        } else {
            int left_distance = get_distance(target, left);
            int right_distance = get_distance(target, right);

            if(left_distance == right_distance) {
                if(hand == "left") {
                    left = target;
                    answer += 'L';
                } else {
                    right = target;
                    answer += 'R';
                }
            } else {
                if(left_distance < right_distance) {
                    left = target;
                    answer += 'L';  
                } else {
                    right = target;
                    answer += 'R';
                }
            }
        }
        
    }
    
    return answer;
}