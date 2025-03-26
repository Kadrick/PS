/**
 * @file 4882.cpp
 * @author BoGwon Kang (kbk2581553@gmail.com)
 * @brief stack
 * @version 0.1
 * @date 2025-03-24 13:54
 * @copyright Copyright (c) 2025
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

class Node {
  public:
    int lv;
    vector<bool> states;
    vector<Node *> child;

    Node(int lv) : lv(lv) {}

    ~Node() {
        for (int i = 0; i < child.size(); i++) {
            delete child[i];
        }
    }

    void addChild(Node *child) { this->child.push_back(child); }

    void addState(bool state) { this->states.push_back(state); }

    // logical: true => and, false => or
    bool calc(bool logical) {
        bool result = logical;

        for (int i = 0; i < states.size(); i++) {
            if (logical) {
                result = result && states[i];
            } else {
                result = result || states[i];
            }
        }

        if (!logical && result == true) {
            return true;
        } else if (logical && result == false) {
            return false;
        }

        // opposite logical calc for child
        for (int i = 0; i < child.size(); i++) {
            if (logical) {
                result = result && child[i]->calc(!logical);
            } else {
                result = result || child[i]->calc(!logical);
            }
        }

        return result;
    }
};

int32_t main(int argc, char **argv) {
    fastio;

    int tcNum = 1;
    string input;

    while (true) {

        cin >> input;
        if (input == "()")
            break;

        // logical: true => and, false => or
        bool result = true, logical = true;

        int currentLV = 0, maxLV = 0;
        Node *root = new Node(0);
        vector<Node *> st;
        st.push_back(root);

        for (int i = 0; i < input.length(); ++i) {

            if (input[i] == '(') {

                currentLV++;
                Node *node = new Node(currentLV);
                st.back()->addChild(node);
                st.push_back(node);
                maxLV = max(maxLV, currentLV);

            } else if (input[i] == ')') {

                currentLV--;
                st.pop_back();

            } else {
                st.back()->addState(input[i] == 'T' ? true : false);
            }
        }

        cout << tcNum++ << ". "
             << (root->calc(maxLV % 2 == 0) ? "true" : "false") << endl;

        delete root;
    }

    return 0;
}