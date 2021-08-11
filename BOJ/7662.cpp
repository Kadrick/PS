#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(0);
#define endl '\n'

multimap<int, int> m;

int main(void) {
  fastio;

  int t;
  cin >> t;
  while (t--) {
    int nOrder;
    cin >> nOrder;

    for (int i = 0; i < nOrder; ++i) {
      char order;
      cin >> order;

      if (order == 'I') {
        int input;
        cin >> input;
        m.insert(make_pair(input, input));
      } else {
        int flag;
        cin >> flag;
        if (!m.empty()) {
          if (flag == 1)
            m.erase(--(m.end()));
          else
            m.erase(m.begin());
        }
      }
    }

    if (m.empty())
      cout << "EMPTY" << endl;
    else
      cout << m.rbegin()->first << ' ' << m.begin()->first << endl;
    m.clear();
  }

  return 0;
}