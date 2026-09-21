/**
 * @file template.cpp
 * @author kadrick (kbk2581553@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-11-18 16:29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <bits/stdc++.h>
using namespace std;
#define fastio                                                                 \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0);
#define endl '\n'

int main(void) {
    fastio;

    long long n, m, k; // dessert, drink, k-dollar
    long long x, y; // 1-dollar, k-dollar

    cin >> n >> m >> k >> x >> y;

    vector<long long> dessert_cost(n + 1, 0);
    vector<long long> drink_cost(m + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> dessert_cost[i + 1];
    }
    for (int i = 0; i < m; i++) {
        cin >> drink_cost[i + 1];
    }


    sort(dessert_cost.begin(), dessert_cost.end());
    sort(drink_cost.begin(), drink_cost.end());

    vector<long long> dessert_cost_prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dessert_cost_prefix_sum[i] = dessert_cost_prefix_sum[i - 1] + dessert_cost[i];
    }
    vector<long long> drink_cost_prefix_sum(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        drink_cost_prefix_sum[i] = drink_cost_prefix_sum[i - 1] + drink_cost[i];
    }

    vector<long long> consume_coin(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        consume_coin[i] = drink_cost[i] / k;
        if (drink_cost[i] % k > 0) {
            consume_coin[i]++;
        }
    }

    vector<long long> consume_coin_prefix_sum(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        consume_coin_prefix_sum[i] = consume_coin_prefix_sum[i - 1] + consume_coin[i];
    }

    long long ans = 0;

    for (int drink = 0; drink <= m; drink++) {

        long long cost = x + k*y - drink_cost_prefix_sum[drink];
        long long remain_coin = y - consume_coin_prefix_sum[drink];

        if (cost < 0 || remain_coin < 0) break;

        long long possible_dessert = upper_bound(dessert_cost_prefix_sum.begin(), dessert_cost_prefix_sum.end(), cost) - dessert_cost_prefix_sum.begin() - 1;

        ans = max(ans, possible_dessert + drink);

    }


    cout << ans << endl;

    return 0;
}