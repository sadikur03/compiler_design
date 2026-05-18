#include <iostream>
#include <string>
using namespace std;

bool match_RE(string s) {
    int n = s.length();
    int i = 0;

    // a(a*+b*)ba*
    // Must start with 'a'
    if (i >= n || s[i] != 'a') return false;
    i++;

    // (a*+b*) => zero or more a's OR zero or more b's
    // Try matching a* first
    int save = i;
    bool matched = false;

    // Try a*
    int j = i;
    while (j < n && s[j] == 'a') j++;
    // then must have 'b'
    if (j < n && s[j] == 'b') {
        int k = j + 1;
        // then a*
        while (k < n && s[k] == 'a') k++;
        if (k == n) matched = true;
    }

    if (matched) return true;

    // Try b*
    j = i;
    while (j < n && s[j] == 'b') j++;
    // then must have 'b'
    if (j < n && s[j] == 'b') {
        int k = j + 1;
        // then a*
        while (k < n && s[k] == 'a') k++;
        if (k == n) return true;
    }

    return false;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Checking string..." << endl;
    if (match_RE(s))
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;
    return 0;
}