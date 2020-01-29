#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

int myrandom(int i) { return rand() % i; }

int main() {
	srand(unsigned(time(0)));

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int w, n;
	cin >> w >> n;

	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	int maxc = 0;
	vector <int> maxans;
	for (int h = 0; h < 1e9; h += n) {
		random_shuffle(a.begin(), a.end(), myrandom);
		int c = 0, i = 0;
		while (true) {
			if (c + a[i].first > w)
				break;
			c += a[i].first;
			i++;
		}

		if (c > maxc) {
			maxc = c;
			maxans.clear();
			for (int j = 0; j < i; j++)
				maxans.push_back(a[j].second);
		}
	}

	sort(maxans.begin(), maxans.end());
	cout << /*maxc << ' ' <<*/ maxans.size() << '\n';
	for (auto cur : maxans)
		cout << cur << ' ';
	cout << '\n';

	return 0;
}
