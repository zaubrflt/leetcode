#include <string>
#include <vector>
#include <stack>

class Solution {
public:
  int evalRPN(std::vector<std::string>& tokens)
  {
    std::stack<int> tokenStack;
    for (int i = 0; i < tokens.size(); i++) {
      if (isOpera(tokens[i])) {
        int second = tokenStack.top();
        tokenStack.pop();
        int first = tokenStack.top();
        tokenStack.pop();
        if (tokens[i] == "+") {
          tokenStack.push(first + second);
        }
        if (tokens[i] == "-") {
          tokenStack.push(first - second);
        }
        if (tokens[i] == "*") {
          tokenStack.push(first * second);
        }
        if (tokens[i] == "/") {
          tokenStack.push(first / second);
        }
      } else {
        tokenStack.push(std::stoi(tokens[i]));
      }
    }
    return tokenStack.top();
  }
private:
  bool isOpera(const std::string& token)
  {
    return token == "+" || token == "-" || token == "*" || token == "/";
  }
};