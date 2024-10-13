#include <iostream>

using namespace std;

bool isInMengerSponge(int L, long long xn, long long xd, long long yn, long long yd, long long zn, long long zd) {
    long long x = xn, y = yn, z = zn;
    while (L > 0) {
        x = (x * 3) % xd;
        y = (y * 3) % yd;
        z = (z * 3) % zd;

        if (x < xd && y < yd && z < zd && (x % 3 == 1) && (y % 3 == 1) && (z % 3 == 1)) {
            return false;
        }
        L--;
    }
    return true;
}

int main() {
    int L;
    long long xn, xd, yn, yd, zn, zd;
    cin >> L >> xn >> xd >> yn >> yd >> zn >> zd;

    cout << isInMengerSponge(L, xn, xd, yn, yd, zn, zd) << endl;

    return 0;
}