/**
 * @file 42576.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief sort + search
 * @version 0.1
 * @date 2022-01-21 07:18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < participant.size(); ++i)
    {
        if (i == participant.size() - 1)
            answer = participant[i];
        else
        {
            if (participant[i] != completion[i])
            {
                answer = participant[i];
                break;
            }
        }
    }

    return answer;
}