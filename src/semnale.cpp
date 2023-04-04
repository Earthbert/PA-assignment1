#include <iostream>

using namespace std;

const int mod = 1000000007;

int type1(int x, int y) {
    //TODO Compute the number of type 1 signals.
    return 0;
}

int type2(int x, int y) {
    //TODO Compute the number of type 2 signals.
    return 0;
}

int main()
{
    freopen("semnale.in", "r", stdin);
	freopen("semnale.out", "w", stdout);

	int sig_type, x, y;

	cin >> sig_type >> x >> y;

    switch(sig_type) {
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
