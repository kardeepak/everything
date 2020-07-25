#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main() {
	int t; cin >> t;
	for(int c = 1; c <= t; c++) {
		cout << "Case #" << c << ": ";
		int n; cin >> n;
		vector<pair<int, int>> trees(n);
		for(int i = 0; i < n; i++) {
			cin >> trees[i].first;
			cin >> trees[i].second;
		}
		// sort by position
		sort(trees.begin(), trees.end());

		// forward[i] is the length of the longest timber ending at i when all trees fell forward
		// same for backward
		map<int, int> forward, backward;

		// calculate forward
		for(int i = 0; i < n; i++) {
			int start = trees[i].first;
			int end = trees[i].first + trees[i].second;
			forward[end] = max(forward[end], forward[start] + trees[i].second);
		}

		// calculate backward
		for(int i = n-1; i >= 0; i--) {
			int start = trees[i].first;
			int end = trees[i].first - trees[i].second;
			backward[end] = max(backward[end], backward[start] + trees[i].second);
		}

		int maxLength = 0;

		for(auto it : forward) {
			int position = it.first;
			maxLength = max(maxLength, forward[position] + backward[position]);
		}
		for(auto it : backward) {
			int position = it.first;
			maxLength = max(maxLength, forward[position] + backward[position]);
		}

		cout << maxLength << endl;
	}
}
