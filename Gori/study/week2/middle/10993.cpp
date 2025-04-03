/**
 * @file 10993.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief 별 찍기 - 18
 * @version 0.1
 * @date 2025-04-03 13:41
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

void tri(vector<string> &canvas, int w, int h, bool f, int l, int t) {

    if (w == 1) {
        canvas[t][l] = '*';
        return;
    }

    if (f) {

        for (int i = 0; i < h; i++) {
            canvas[t + i][l + w / 2 - i] = '*';
            canvas[t + i][l + w / 2 + i] = '*';
        }
        for (int i = 0; i < w; i++) {
            canvas[t + h - 1][l + i] = '*';
        }

        tri(canvas, (w - 3) / 2, (h - 1) / 2, !f, l + w / 4 + 1, t + h / 2);

    } else {

        for (int i = 0; i < h; i++) {
            canvas[t + h - 1 - i][l + w / 2 - i] = '*';
            canvas[t + h - 1 - i][l + w / 2 + i] = '*';
        }
        for (int i = 0; i < w; i++) {
            canvas[t][l + i] = '*';
        }

        tri(canvas, (w - 3) / 2, (h - 1) / 2, !f, l + w / 4 + 1, t + 1);
    }
}

void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(),
                    [](unsigned char ch) { return !isspace(ch); })
                .base(),
            s.end());
}

int32_t main(int argc, char **argv) {
    fastio;

    int n;
    cin >> n;

    int w = (1 << (n + 1)) - 3;
    int h = (1 << n) - 1;

    vector<string> canvas(h, string(w, ' '));

    tri(canvas, w, h, n % 2, 0, 0);

    for (int i = 0; i < h; i++) {
        rtrim(canvas[i]);
        cout << canvas[i] << endl;
    }

    return 0;
}