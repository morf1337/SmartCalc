#include "backend.h"

namespace s21 {

double model::entryPoint(const std::string& str, double xValue,
                         bool isDegrees) {
  double answer = 0;
  std::string normalized = stringNormalize(str, xValue);
  std::vector<Node> expVector = stringToRpn(normalized);
  answer = calcRpn(expVector, isDegrees);
  return answer;
}

std::string model::stringNormalize(const std::string& str, double xValue) {
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

std::vector<Node> model::stringToRpn(const std::string& inputStr) {
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
      ptrJump(operatorCode, &str);
    }
  }

  while (!operatorStack.empty()) {
    outString.push_back(operatorStack.back());
    operatorStack.pop_back();
  }
  return outString;
}

double model::calcRpn(std::vector<Node> rpnExpression, bool isDegrees) {
  double res = 0, num1 = res, num2 = num1;
  std::stack<double> values;
  for (auto it = rpnExpression.begin(); it != rpnExpression.end(); ++it) {
    if (it->isNumber) {
      values.push(it->num);
    } else {
      if (strchr("ctiqnoasb", it->ch)) {
        num1 = values.top();
        values.pop();
        res = mathOperations(it->ch, num1, isDegrees);
      } else {
        num2 = values.top();
        values.pop();
        num1 = values.top();
        values.pop();
        res = mathOperations(it->ch, num1, num2);
      }
      values.push(res);
    }
  }
  return values.top();
}

int model::priority(char ch) {
  int pr = 0;
  if (strchr("+-", ch)) pr = 1;
  if (strchr("*/m", ch)) pr = 2;
  if (strchr("^ictasbonq", ch)) pr = 3;
  return pr;
}

void model::ptrJump(char ch, const char** p) {
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
char model::singleCharCode(const char** arr) {
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

double model::mathOperations(char code, double num1, double num2) {
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

double model::mathOperations(char code, double num1, bool isDegrees) {
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

std::string model::rmZeros(std::string& str) {
  if (str.find('.') != std::string::npos ||
      str.find(',') != std::string::npos) {
    str.erase(str.find_last_not_of('0') + 1);
    if (str.back() == '.' || str.back() == ',') {
      str.pop_back();
    }
  }
  return str;
}

int model::bracketBalance(const std::string& str) {
  int sum = 0;
  for (size_t i = 0; i < str.length(); ++i) {
    if (str[i] == '(') {
      sum++;
    } else if (str[i] == ')') {
      sum--;
    }
  }
  return sum;
}

bool model::allowInput(const std::string& str, char ch) {
  bool res = true;
  char last = '~';
  if (!str.empty()) {
    last = str.back();
    switch (ch) {
      case 'N':  // number
        if (strchr("X)", last)) res = false;
        break;
      case 'F':  // function
        if (strchr("X)1234567890.d", last)) res = false;
        break;
      case 'O':  // operator
        if (strchr(".+-*/^(d", last)) res = false;
        break;
      case 'U':  // unarn operator
        if (strchr(".+-*/^d", last)) res = false;
        break;
      case '(':
        if (strchr("X.)1234567890", last)) res = false;
        break;
      case ')':
        if (strchr("(.+-*/^)", last) && !(bracketBalance(str) > 0)) res = false;
        break;
      case '.':
        if (!strchr("1234567890", last)) res = false;
        break;
      default:
        break;
    }
  } else if (ch == ')' || ch == 'O') {
    res = false;
  }
  return res;
}

void model::creditCalculate(double sum, double months, double percents,
                            std::queue<double>& payments, bool isAnnuitet,
                            double& totalSum, double& overPayment) {
  double result = 0, monthBasepayment = 0, localSum = sum;
  char resString[50] = "";
  if (isAnnuitet) {
    result = sum * percents / (100 * 12) /
             (1 - pow((1 + percents / (100 * 12)), (months * -1)));
    sprintf(resString, "%0.2f руб.", result);
    payments.push(result);
    totalSum = result * months;
    overPayment = result * months - sum;
  } else {
    monthBasepayment = sum / months;
    totalSum = sum;
    for (int i = 1; i <= months; i++) {
      result = localSum * percents / 100 * 30 / 365;
      payments.push(result + monthBasepayment);
      totalSum += result;
      localSum -= monthBasepayment;
    }
    overPayment = totalSum - sum;
  }
}

void model::depositCalculate(double& summa, int time, double stavka,
                             double tax_rate, double summa_popoln,
                             double summa_snyat, QDate depDate, bool isKapital,
                             double& summa_proc, double& NDFL, int index_vyp,
                             int index_pop, int index_snyat) {
  double limit_nalog = tax_rate * 10000, NDFL_year = 0;
  QDate date_now = depDate;
  QDate date_end = date_now.addMonths(time);
  QDate date_popoln = date_now_add(date_now, index_pop);
  QDate date_snyat = date_now_add(date_now, index_snyat);
  QDate date_nalog;
  QDate date_vyplat = date_vyplat_index(date_now, index_vyp);
  int year_now = date_now.year();
  date_nalog = date_vyplat;
  if (index_vyp == 0) {
    date_nalog.setDate(date_now.year(), 12, 31);
  } else if (index_vyp == 6) {
    date_nalog = date_now;
  } else {
    while ((int)date_nalog.year() == year_now) {
      QDate date_nalog_temp = date_vyplat_index(date_nalog, index_vyp);
      if ((int)date_nalog_temp.year() == year_now)
        date_nalog = date_nalog_temp;
      else
        break;
    }
  }
  if (isKapital && index_vyp != 6) {
    double summa_kapital = 0.0;
    while (date_now != date_end) {
      date_now = date_now.addDays(1);
      double days_year = date_now.daysInYear();
      double summa_kapital_temp =
          summa * (1 + (stavka / (100.0 * days_year))) - summa;
      summa_kapital = summa_kapital + summa_kapital_temp;
      NDFL_year += summa_kapital_temp;
      if (index_snyat != 0 && date_now == date_snyat) {
        summa -= summa_snyat;
        if (summa < 0) {
          summa += summa_snyat;
        }
        date_snyat = date_now_add(date_now, index_snyat);
      }
      if (date_now == date_vyplat) {
        summa_proc += summa_kapital;
        summa += summa_kapital;
        summa_kapital = 0;
        date_vyplat = date_vyplat_index(date_now, index_vyp);
      }
      if (date_now == date_nalog) {
        if (NDFL_year > limit_nalog && date_nalog.year() != 2022)
          NDFL = NDFL + ((NDFL_year - limit_nalog) * 0.13);
        NDFL_year = 0;
        if (index_vyp == 1) {
          date_nalog = date_nalog.addDays(364);
          QDate temp_date = date_nalog.addDays(7);
          if (temp_date.year() == date_nalog.year()) {
            date_nalog.setDate(temp_date.year(), temp_date.month(),
                               temp_date.day());
          }
        } else
          date_nalog = date_nalog.addYears(1);
      }
      if (index_pop != 0 && date_now == date_popoln) {
        summa += summa_popoln;
        date_popoln = date_now_add(date_now, index_pop);
      }
      if (date_now == date_end) {
        summa_proc += summa_kapital;
        summa += summa_kapital;
        if (NDFL_year > limit_nalog)
          NDFL = NDFL + ((NDFL_year - limit_nalog) * 0.13);
      }
    }
  } else {
    while (date_now != date_end) {
      date_now = date_now.addDays(1);
      double days_year = date_now.daysInYear();
      double profit = (summa * stavka) / (days_year * 100.0);
      summa_proc += profit;
      NDFL_year += profit;
      if (date_now == date_nalog) {
        if (NDFL_year > limit_nalog && date_nalog.year() != 2022)
          NDFL = NDFL + ((NDFL_year - limit_nalog) * 0.13);
        NDFL_year = 0;
        if (index_vyp == 1) {
          date_nalog = date_nalog.addDays(364);
          QDate temp_date = date_nalog.addDays(7);
          if (temp_date.year() == date_nalog.year()) {
            date_nalog.setDate(temp_date.year(), temp_date.month(),
                               temp_date.day());
          }
        } else
          date_nalog = date_nalog.addYears(1);
      }
      if (date_now == date_end && NDFL_year > limit_nalog)
        NDFL = NDFL + ((NDFL_year - limit_nalog) * 0.13);
      if (index_pop != 0 && date_now == date_popoln) {
        summa += summa_popoln;
        date_popoln = date_now_add(date_now, index_pop);
      }
      if (index_snyat != 0 && date_now == date_snyat) {
        summa -= summa_snyat;
        if (summa < 0) {
          summa = 0;
          break;
        }
        date_snyat = date_now_add(date_now, index_snyat);
      }
    }
    if (index_vyp == 6 && isKapital) summa = summa + summa_proc;
  }
}

QDate model::date_now_add(QDate date_now, int index) {
  QDate result;
  if (index == 1) {
    result = date_now.addMonths(1);
  } else if (index == 2) {
    result = date_now.addMonths(2);
  } else if (index == 3) {
    result = date_now.addMonths(3);
  } else if (index == 4) {
    result = date_now.addMonths(6);
  } else if (index == 5) {
    result = date_now.addYears(1);
  }
  return result;
}

QDate model::date_vyplat_index(QDate date_now, int index) {
  QDate result;
  if (index == 0) {
    result = date_now.addDays(1);
  } else if (index == 1) {
    result = date_now.addDays(7);
  } else if (index == 2) {
    result = date_now.addMonths(1);
  } else if (index == 3) {
    result = date_now.addMonths(3);
  } else if (index == 4) {
    result = date_now.addMonths(6);
  } else if (index == 5) {
    result = date_now.addYears(1);
  } else if (index == 6) {
    result = date_now.addMonths(1);
  }
  return result;
}

}  // namespace s21