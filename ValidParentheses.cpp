#include <stack>
#include <iostream>
#include <string>
#include "./Stack/ArrayStack.h"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;

        for(char c : s) {
            if(c == '(' || c == '[' || c =='{') {
                stack.push(c);
            } else {
                if(stack.empty())
                    return false;
                
                if(c == ')' && stack.top() != '(')
                    return false;
                
                if(c == '}' && stack.top() != '{')
                    return false;

                if(c == ']' && stack.top() != '[')
                    return false;
                    
                stack.pop();
            }
        }

        return stack.empty();
    }

    bool isValid2(string s) {
        ArrayStack<char> stack;

        for(char c : s) {
            if(c == '(' || c == '[' || c =='{') {
                stack.push(c);
            } else {
                if(stack.isEmpty())
                    return false;
                
                if(c == ')' && stack.pop() != '(')
                    return false;
                
                if(c == '}' && stack.pop() != '{')
                    return false;

                if(c == ']' && stack.pop() != '[')
                    return false;
            }
        }

        return stack.isEmpty();
    }    
};


int main() {
    Solution s = Solution();
    cout << s.isValid2("((([])))") << endl;

    return 0;
}
