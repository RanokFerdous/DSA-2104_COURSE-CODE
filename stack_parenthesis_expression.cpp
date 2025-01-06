#include <bits/stdc++.h>
using namespace std;

int checkParentheses(string exp) {
    stack<char> ST;
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        // Push opening parenthesis into stack
        if (ch == '(') {
            ST.push(ch);
        }
        // Check for closing parenthesis
        else if (ch == ')') {
            if (!ST.empty()) {
                ST.pop(); // Pop matching opening parenthesis
            } else {
                return -1; // Invalid, unmatched closing parenthesis
            }
        }
    }
    // If stack is empty, parentheses are balanced
    return ST.empty() ? 1 : -1;
}

int main() {
    string exp;
    cout << "Enter expression: ";
    cin >> exp;

    int result = checkParentheses(exp);
    if (result == -1) {
        cout << "Invalid" << endl;
    } else {
        cout << "Valid" << endl;
    }

    return 0;
}
