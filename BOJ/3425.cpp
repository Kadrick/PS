/**
 * @file 3425.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief implement
 * @version 0.1
 * @date 2022-01-25 07:08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                 \
  ios::sync_with_stdio(false); \
  cin.tie(0);
#define endl '\n'

bool state = false;
vector<string> program;
vector<long long> st;

int main(void)
{
  fastio;

  while (true)
  {
    if (state)
    {
      int n;
      cin >> n;
      for (int i = 0; i < n; i++)
      {
        bool error = false;
        st.clear();
        long long number;
        cin >> number;
        st.push_back(number);

        for (auto &&command : program)
        {
          string order = command.substr(0, 3);
          if (order == "NUM")
            st.push_back(stoll(command.substr(3)));
          else if (order == "POP")
          {
            if (st.empty())
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st.pop_back();
          }
          else if (order == "INV")
          {
            if (st.empty())
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st[st.size() - 1] = -st.back();
          }
          else if (order == "DUP")
          {
            if (st.empty())
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st.push_back(st.back());
          }
          else if (order == "SWP")
          {
            if (st.size() < 2)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            long long tmp = st.back();
            st.back() = st[st.size() - 2];
            st[st.size() - 2] = tmp;
          }
          else if (order == "ADD")
          {
            if (st.size() < 2)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            long long ret = 0;
            ret = st[st.size() - 2] + st[st.size() - 1];
            if (abs(ret) > 1e9)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st.pop_back();
            st.pop_back();
            st.push_back(ret);
          }
          else if (order == "SUB")
          {
            if (st.size() < 2)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            long long ret = 0;
            ret = st[st.size() - 2] - st[st.size() - 1];
            if (abs(ret) > 1e9)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st.pop_back();
            st.pop_back();
            st.push_back(ret);
          }
          else if (order == "MUL")
          {
            if (st.size() < 2)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            long long ret = 0;
            ret = st[st.size() - 2] * st[st.size() - 1];
            if (abs(ret) > 1e9)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st.pop_back();
            st.pop_back();
            st.push_back(ret);
          }
          else if (order == "DIV")
          {
            if (st.size() < 2)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            if (st.back() == 0)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }

            long long ret = 0;
            ret = st[st.size() - 2] / st[st.size() - 1];
            if (abs(ret) > 1e9)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st.pop_back();
            st.pop_back();
            st.push_back(ret);
          }
          else if (order == "MOD")
          {
            if (st.size() < 2)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            if (st.back() == 0)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            long long ret = 0;
            ret = st[st.size() - 2] % st[st.size() - 1];
            if (abs(ret) > 1e9)
            {
              cout << "ERROR" << endl;
              error = true;
              break;
            }
            st.pop_back();
            st.pop_back();
            st.push_back(ret);
          }
        }

        if (!error && st.size() != 1)
        {
          cout << "ERROR" << endl;
          error = true;
        }

        if (!error)
          cout << st.back() << endl;
      }
      state = false;

      string tmp;
      getline(cin, tmp);
    }
    else
    {
      string input;
      getline(cin, input);

      if (input == "QUIT")
        break;
      if (input == "")
      {
        st.clear();
        program.clear();
        cout << endl;
      }
      else if (input == "END")
        state = true;
      else
        program.push_back(input);
    }
  }

  return 0;
}