#include <bits/stdc++.h>
using namespace std;

int priority(char C) {
    if (C == '-' || C == '+') return 1;
    else if (C == '*' || C == '/') return 2;
    else if (C == '^') return 3;
    return 0;
}

// ✅ Custom reverse with bracket swapping
string reverseString(const string &s) {
    string res = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') res += ')';
        else if (s[i] == ')') res += '(';
        else res += s[i];
    }
    return res;
}

// ✅ Infix to Prefix
string infixtoprefix(string s) {
    s = reverseString(s); // Step 1: Reverse + swap brackets
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (isalnum(ch)) {
            ans += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); // Pop the '('
        }
        else { // Operator
            while (!st.empty() &&
                   ((ch == '^' && priority(ch) <= priority(st.top())) ||
                    (ch != '^' && priority(ch) < priority(st.top())))) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    return reverseString(ans); // Step 3: Reverse again for prefix
}

int main() {
    string s = "(A+B)*C-D+F";
    string p = infixtoprefix(s);
    cout << p << endl;
    return 0;
}
