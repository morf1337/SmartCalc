#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

struct Node {
  bool isNumber;  // true = number, false = operator
  char ch;
  double num;
};

std::string stringNormalize(const std::string& str, double xValue);
std::vector<Node> stringToRpn(const std::string& str);
int priority(char ch);
void ptr_jump(char ch, const char** arr);
char singleCharCode(const char** arr);
double calcRpn(std::vector<Node> rpnExpression, bool isDegrees);
double math_operations(char code, double num1, double num2);
double math_operations(char code, double num1, bool isDegrees);
double entryPoint(const std::string& str, double xValue, bool isDegrees);

double entryPoint(const std::string& str, double xValue, bool isDegrees) {
  double answer = 0;
  std::string normalized = stringNormalize(str, xValue);
  std::vector<Node> expVector = stringToRpn(normalized);
  answer = calcRpn(expVector, isDegrees);
  return answer;
}

std::string stringNormalize(const std::string& str, double xValue) {
  std::string result, xValueStr = std::to_string(xValue);

  if (xValue < 0) {
    xValueStr = "(0-1)*" + xValueStr.substr(1);
  }

  for (char ch : str) {
    if (ch == 'X') {
      result += xValueStr;
    } else if (ch == '+' && (result.empty() || result.back() == '(')) {
      continue;
    } else if (ch == '-' && (result.empty() || result.back() == '(')) {
      result += "(0-1)*";
    } else {
      result += ch;
    }
  }
  return result;
}

std::vector<Node> stringToRpn(const std::string& inputStr) {
  const char* str = inputStr.data();
  std::vector<Node> operatorStack, outString;
  char* strEnd;
  char operatorCode = ' ';
  while (*str) {
    if (isdigit(*str)) {
      outString.push_back({true, 'N', strtod(str, &strEnd)});
      str = strEnd;
    } else {
      operatorCode = singleCharCode(&str);
      if (operatorCode == '(') {
        operatorStack.push_back({false, operatorCode, 0});
      } else if (strchr("ctiqnoasb", operatorCode)) {
        operatorStack.push_back({false, operatorCode, 0});
      } else if (operatorCode == ')') {
        while (operatorStack.back().ch != '(') {
          outString.push_back(operatorStack.back());
          operatorStack.pop_back();
        }
        operatorStack.pop_back();
      } else {
        while (!operatorStack.empty() &&
               priority(operatorCode) <= priority(operatorStack.back().ch)) {
          outString.push_back(operatorStack.back());
          operatorStack.pop_back();
        }
        operatorStack.push_back({false, operatorCode, 0});
      }
      ptr_jump(operatorCode, &str);
    }
  }

  while (!operatorStack.empty()) {
    outString.push_back(operatorStack.back());
    operatorStack.pop_back();
  }
  return outString;
}

double calcRpn(std::vector<Node> rpnExpression, bool isDegrees) {
  double res = 0, num1 = res, num2 = num1;
  std::stack<double> values;
  for (auto it = rpnExpression.begin(); it != rpnExpression.end(); ++it) {
    if (it->isNumber) {
      values.push(it->num);
    } else {
      if (strchr("ctiqnoasb", it->ch)) {
        num1 = values.top();
        values.pop();
        res = math_operations(it->ch, num1, isDegrees);
      } else {
        num2 = values.top();
        values.pop();
        num1 = values.top();
        values.pop();
        res = math_operations(it->ch, num1, num2);
      }
      values.push(res);
    }
  }
  return values.top();
}

int priority(char ch) {
  int pr = 0;
  if (strchr("+-", ch)) pr = 1;
  if (strchr("*/m", ch)) pr = 2;
  if (strchr("^ictasbonq", ch)) pr = 3;
  return pr;
}

void ptr_jump(char ch, const char** p) {
  if (strchr("asbq", ch)) {
    *p = *p + 4;
  } else if (strchr("mctio", ch)) {
    *p = *p + 3;
  } else if (ch == 'n') {
    *p = *p + 2;
  } else if (strchr("+/*^-()", ch)) {
    (*p)++;
  }
}

// m - mod code
// c - cos code
// t - tan code
// q - sqrt code
// i - sin code
// n - ln code
// o - log code
// a - atan code
// s - asin code
// b - acos code
// +-*/ operations returns value as it is
char singleCharCode(const char** arr) {
  const char* p = *arr;
  char ch = *p;
  switch (ch) {
    case 's':
      if (*(p + 1) == 'i') {
        ch = 'i';
      } else {
        ch = 'q';
      }
      break;
    case 'l':
      if (*(p + 1) == 'n') {
        ch = 'n';
      } else {
        ch = 'o';
      }
      break;
    case 'a':
      if (*(p + 1) == 't') {
        ch = 'a';
      } else if (*(p + 1) == 's') {
        ch = 's';
      } else {
        ch = 'b';
      }
      break;
  }
  return ch;
}

double math_operations(char code, double num1, double num2) {
  double res = 0.0;
  switch (code) {
    case '*':
      res = num1 * num2;
      break;
    case '/':
      res = num1 / num2;
      break;
    case 'm':
      res = fmod(num1, num2);
      break;
    case '+':
      res = num1 + num2;
      break;
    case '-':
      res = num1 - num2;
      break;
    case '^':
      res = pow(num1, num2);
      break;
  }
  return res;
}

double math_operations(char code, double num1, bool isDegrees) {
  double res = 0.0;
  switch (code) {
    case 'i':
      if (isDegrees) {
        res = sin(num1 * M_PI / 180);
      } else {
        res = sin(num1);
      }
      break;
    case 'c':
      if (isDegrees) {
        res = cos(num1 * M_PI / 180);
      } else {
        res = cos(num1);
      }
      break;
    case 't':
      if (isDegrees) {
        res = tan(num1 * M_PI / 180);
      } else {
        res = tan(num1);
      }
      break;
    case 'a':
      res = atan(num1);
      break;
    case 's':
      res = asin(num1);
      break;
    case 'b':
      res = acos(num1);
      break;
    case 'n':
      res = log(num1);
      break;
    case 'o':
      res = log10(num1);
      break;
    case 'q':
      res = sqrt(num1);
      break;
  }
  return res;
}
