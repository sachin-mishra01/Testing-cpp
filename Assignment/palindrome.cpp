#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "a b cd sdc baa"; 
    vector<char> v;
    bool ans = true; 
    for (int i = 0; i < str.size(); i++) {
        v.emplace_back(str[i]);
    }
    v.erase(remove(v.begin(), v.end(), ' '), v.end());
     int left = 0;
    int right = v.size() - 1;

    while (left < right) {
        if (v[left] != v[right]) { 
            ans = false;
            break;
        }
        left++;
        right--;
    }
    if (!ans) {
        cout << "String is not a palindrome" << endl;
    } else {
        cout << "String is a palindrome" << endl;
    }

    return 0;
}
