#include <bits/stdc++.h>
#define ll long long int
#define prime 119
using namespace std;

ll createhash(string str, int n) {
    ll result = 0;
    for (int i = 0; i < n; i++) {
        result += (ll)(str[i] * (ll)pow(prime, i));
    }
    return result;
}
ll recalculate_hash(string str, int oldindex, int newindex, ll oldhash, int pathlength) {
    ll newhash = oldhash - str[oldindex];
    newhash = newhash / prime;
    newhash += (ll)(str[newindex] * (ll)(pow(prime, pathlength - 1)));
    return newhash;
}
bool checkequal(string str1, string str2, int start1, int end1, int start2, int end2) {
    if (end1 - start1 != end2 - start2) return false;
    while (start1 <= end1 and start2 <= end2) {
        if (str1[start1] != str2[start2]) return false;
        start1++;
        start2++;
    }
    return true;
}
int main() {
    string str = "ababcabdab";
    string pat = "abd";
    // this will give the initial hash value of the string and the pattern
    ll pathash = createhash(pat, pat.length());
    ll strhash = createhash(str, pat.length());
    for (int i = 0; i <= str.length() - pat.length() - 1; i++) {
        if (pathash == strhash and
            checkequal(str, pat, i, i + pat.length() - 1, 0, pat.length() - 1)) {
            cout << i << endl;
        }
        if (i < str.length() - pat.length()) {
            strhash = recalculate_hash(str, i, i + pat.length(), strhash, pat.length());
        }
    }
    return 0;
}
