/**
 * @file 20328.cpp
 * @author Kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2025-04-10 17:26
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

class Filter {
  public:
    int level;
    Filter *child;
    tuple<int, int, int, int> order;
    Filter(int level) {
        if (level > 0) {
            this->level = level;
            this->child = new Filter(level - 1);
            this->order = make_tuple(0, 1, 2, 3);
        }
    }
    ~Filter() {};

    void vFlip(int level) {
        if (this->level >= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {bl, br, tr, tl};
        }
        if (this->level > 1) {
            child->vFlip(level);
        }
    }

    void hFlip(int level) {
        if (this->level >= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {tr, tl, bl, br};
        }

        if (this->level > 1) {
            child->hFlip(level);
        }
    }

    void rRotate(int level) {
        if (this->level >= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {bl, tl, tr, br};
        }
        if (this->level > 1) {
            child->rRotate(level);
        }
    }

    void lRotate(int level) {
        if (this->level >= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {tr, br, bl, tl};
        }

        if (this->level > 1) {
            child->lRotate(level);
        }
    }

    void vertical(int level) {
        if (this->level <= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {bl, br, tr, tl};
        }
        if (this->level > 1) {
            child->vertical(level);
        }
    }

    void horizontal(int level) {
        if (this->level <= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {tr, tl, bl, br};
        }
        if (this->level > 1) {
            child->horizontal(level);
        }
    }

    void right(int level) {
        if (this->level <= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {bl, tl, tr, br};
        }
        if (this->level > 1) {
            child->right(level);
        }
    }

    void left(int level) {
        if (this->level <= level) {
            auto [tl, tr, br, bl] = this->order;
            this->order = {tr, br, bl, tl};
        }
        if (this->level > 1) {
            child->left(level);
        }
    }

    tuple<int, int, int, int> get(int level) {
        if (this->level == level) {
            return order;
        }
        return this->child->get(level);
    }
};

class Node {
  public:
    int level;
    Node *child[4];
    pair<int, int> target;
    Node(int top, int left, int level) {
        this->level = level;
        int size = 1 << level;
        if (level > 0) {
            child[0] = new Node(top + 0, left + 0, level - 1);
            child[1] = new Node(top + 0, left + size / 2, level - 1);
            child[2] = new Node(top + size / 2, left + size / 2, level - 1);
            child[3] = new Node(top + size / 2, left + 0, level - 1);
        } else {
            target = {top, left};
        }
    };
    ~Node() {};

    void print(const vector<vector<int>> &org, vector<vector<int>> &canvas,
               Filter *filter, pair<int, int> pivot) {
        auto [y, x] = pivot;
        if (level == 0) {
            canvas[y][x] = org[target.first][target.second];
        } else {
            int size = 1 << level;
            auto [tl, tr, br, bl] = filter->get(this->level);
            child[tl]->print(org, canvas, filter, {y + 0, x + 0});
            child[tr]->print(org, canvas, filter, {y + 0, x + size / 2});
            child[br]->print(org, canvas, filter, {y + size / 2, x + size / 2});
            child[bl]->print(org, canvas, filter, {y + size / 2, x + 0});
        }
    }
};

int32_t main(int argc, char **argv) {
    fastio;

    int n, r;
    cin >> n >> r;

    vector<vector<int>> arr((1 << n), vector<int>((1 << n), 0)),
        ans((1 << n), vector<int>((1 << n), 0));
    for (int i = 0; i < 1 << n; i++) {
        for (int j = 0; j < 1 << n; j++) {
            cin >> arr[i][j];
        }
    }

    Node *root = new Node(0, 0, n);
    Filter *filter = new Filter(n);

    for (int i = 0; i < r; i++) {
        int k, l;
        cin >> k >> l;
        switch (k) {
        case 1:
            filter->vertical(l);
            break;
        case 2:
            filter->horizontal(l);
            break;
        case 3:
            filter->right(l);
            break;
        case 4:
            filter->left(l);
            break;
        case 5:
            filter->vFlip(l + 1);
            break;
        case 6:
            filter->hFlip(l + 1);
            break;
        case 7:
            filter->rRotate(l + 1);
            break;
        case 8:
            filter->lRotate(l + 1);
            break;
        }
    }

    root->print(arr, ans, filter, {0, 0});

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}