// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> cs;
        char ec;
        for(auto &c : s) {
            switch(c) {
            case '(':
            case '[':
            case '{':
                cs.push(c);
                break;
            default:
                if(cs.empty()) {
                    return false;
                }
                if(c == ')') {
                    ec = '(';
                } else if(c == '}') {
                    ec = '{';
                } else if(c == ']') {
                    ec = '[';
                } else {
                    return false;
                }
                if(cs.top() == ec) {
                    cs.pop();
                } else {
                    return false;
                }
                break;
            }
        }
        if(cs.empty())
            return true;
        else
            return false;
    }
};
