#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool isParenthesisBalanced(string& s) {
        unordered_map<char, char> m = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;

        for (char ch : s) {
            if (m.count(ch)) { // If closing bracket
                if (st.empty() || st.top() != m[ch]) return false;
                st.pop();
            } else if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = "{[()]}";
    cout << (sol.isParenthesisBalanced(s) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
