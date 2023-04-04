#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int type1(int x, int y) {
	vector<vector<int>> end_in_one(x + 1, vector<int>(y + 1, 0));
	vector<vector<int>> end_in_zero(x + 1, vector<int>(y + 1, 0));

	for (int i = 1; i <= x; i++) {
		end_in_zero[i][0] = 1;
	}

	end_in_one[0][1] = 1;

	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			end_in_zero[i][j] = (end_in_zero[i - 1][j] + end_in_one[i - 1][j]) % mod;
			end_in_one[i][j] = (end_in_zero[i][j - 1]) % mod;
		}
	}

	return (end_in_one[x][y] + end_in_zero[x][y]) % mod;
}

int type2(int x, int y) {
	//TODO Compute the number of type 2 signals.
	return 0;
}

int main() {
	freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

	switch (sig_type) {
	case 1:
		cout << type1(x, y);;
		break;
	case 2:
		cout << type2(x, y);
		break;
	default:
		cout << "wrong task number" << endl;
	}

	return 0;
}
