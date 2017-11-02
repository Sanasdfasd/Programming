//
// Created by Sandeep on 10/30/2017.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vl;
    int l[n + 5];
    int d[n + 5];
    int cnt[100005];
    int sum[100005];
    int i, j;
    for (i = 0; i < n; i++)
        cin >> l[i];
    for (j = 0; j < n; j++)
        cin >> d[j];

    for (i = 0; i < n; i++) {
        vl.push_back(make_pair(l[i], d[i]));
    }
    for (i = 0; i < 100005; i++) {
        cnt[i] = 0;
        sum[i] = 0;
    }
    int totalSum = 0;
    int ds[205];
    int prev = 0;
    vector<int> store;
    vector<int> vlStorage[100005];
    sort(vl.begin(), vl.end());
    for (i = 0; i < n; i++) {
        if (prev != vl[i].first) {
            store.push_back(vl[i].first);
            prev = vl[i].first;
        }
        cnt[vl[i].first] += 1;
        sum[vl[i].first] += vl[i].second;
        vlStorage[vl[i].first].push_back(vl[i].second);
        totalSum += vl[i].second;
    }
    for (i = 0; i < 205; i++)
        ds[i] = 0;

    int ans = INT_MAX;
    for (i = 0; i < store.size(); i++) {
        int cur_Count = 0;
        int total = 0;
        int prev_Count = 0;
        for (j = 200; j >= 0; j--) {
            cur_Count += ds[j];
            if (cur_Count < cnt[store[i]])
                total += (j * (ds[j]));
            else {
                int temp = cnt[store[i]] - 1 - prev_Count;
                total += j * (temp);
                break;
            }
            prev_Count = cur_Count;
        }
        ans = min(ans, (totalSum - (total + sum[store[i]])));
        for (j = 0; j < cnt[store[i]]; j++) {
            ds[vlStorage[store[i]][j]] += 1;
        }
    }
    cout << ans << endl;
    return 0;
}
