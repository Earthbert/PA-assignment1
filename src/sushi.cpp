#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int task1(int n, int m, int x, vector <int> &p, vector <vector<int>> &g) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0)
				g[i][j] += g[i - 1][j];
		}
	}

	vector<vector<int>> dp(m + 1, vector<int>(x * n + 1, 0));

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= x * n; j++) {
			dp[i][j] = dp[i - 1][j];

			if (j - p[i - 1] >= 0) {
				int aux = dp[i - 1][j - p[i - 1]] + g[n - 1][i - 1];
				dp[i][j] = max(dp[i][j], aux);
			}
		}
	}

	return dp[m][x * n];
}

int task2(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0)
				g[i][j] += g[i - 1][j];
		}
	}

	vector<vector<int>> dp(m + 1, vector<int>(x * n + 1, 0));

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= x * n; j++) {
			dp[i][j] = dp[i - 1][j];

			if (j - 2 * p[i - 1] >= 0) {
				int two_plates_aux = dp[i - 1][j - 2 * p[i - 1]] + 2 * g[n - 1][i - 1];
				int one_plate_aux = dp[i - 1][j - p[i - 1]] + g[n - 1][i - 1];
				dp[i][j] = max(dp[i][j], two_plates_aux);
				dp[i][j] = max(dp[i][j], one_plate_aux);
			} else if (j - p[i - 1] >= 0) {
				int aux = dp[i - 1][j - p[i - 1]] + g[n - 1][i - 1];
				dp[i][j] = max(dp[i][j], aux);
			}
		}
	}

	return dp[m][x * n];
}

int task3(int n, int m, int x, vector <int> &p, vector <vector <int> > &g) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i > 0)
				g[i][j] += g[i - 1][j];
		}
	}

	int w = n * x;

	for (int i = 0; i < m; i++) {
		p[i] += w + 1;
	}

	w += n * (w + 1);

	vector<vector<int>> dp(vector(m + 1, vector<int>(w + 1, 0)));

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j] = dp[i - 1][j];

			if (j - 2 * p[i - 1] >= 0) {
				int two_plates_aux = dp[i - 1][j - 2 * p[i - 1]] + 2 * g[n - 1][i - 1];
				int one_plate_aux = dp[i - 1][j - p[i - 1]] + g[n - 1][i - 1];
				dp[i][j] = max(dp[i][j], two_plates_aux);
				dp[i][j] = max(dp[i][j], one_plate_aux);
			} else if (j - p[i - 1] >= 0) {
				int aux = dp[i - 1][j - p[i - 1]] + g[n - 1][i - 1];
				dp[i][j] = max(dp[i][j], aux);
			}
		}
	}

	return dp[m][w];
}

int main() {
	freopen("sushi.in", "r", stdin);
	freopen("sushi.out", "w", stdout);

	int task;  // task number

	int n;  // number of friends
	int m;  // number of sushi types
	int x;  // how much each of you is willing to spend

	vector <int> prices;  // prices of each sushi type
	// the grades you and your friends gave to each sushi type
	vector <vector <int> > grades;

	cin >> task;
	cin >> n >> m >> x;

	prices.assign(m, 0);
	grades.assign(n, vector <int>(m, 0));

	// price of each sushi
	for (int i = 0; i < m; i++) {
		cin >> prices[i];
	}

	// each friends rankings of sushi types
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grades[i][j];
		}
	}

	int ans = -1;

	switch (task) {
	case 1:
		ans = task1(n, m, x, prices, grades);
		break;
	case 2:
		ans = task2(n, m, x, prices, grades);
		break;
	case 3:
		ans = task3(n, m, x, prices, grades);
		break;
	default:
		cout << "wrong task number" << endl;
	}

	cout << ans << endl;

	return 0;
}
