#ifndef BACKEND_H
#define BACKEND_H

#include <QDate>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

namespace s21 {

struct Node {
  bool isNumber;  // true = number, false = operator
  char ch;
  double num;
};

class model {
 public:
  double entryPoint(const std::string& str, double xValue, bool isDegrees);
  std::string rmZeros(std::string& str);
  bool allowInput(const std::string& str, char ch);
  int bracketBalance(const std::string& str);
  void creditCalculate(double sum, double months, double percents,
                       std::queue<double>& payments, bool isAnnuitet,
                       double& totalSum, double& overPayment);
  void depositCalculate(double& summa, int time, double stavka, double tax_rate,
                        double summa_popoln, double summa_snyat, QDate depDate,
                        bool isKapital, double& summa_proc, double& NDFL,
                        int index_vyp, int index_pop, int index_snyat);

 private:
  std::string stringNormalize(const std::string& str, double xValue);
  std::vector<Node> stringToRpn(const std::string& str);
  int priority(char ch);
  void ptrJump(char ch, const char** arr);
  char singleCharCode(const char** arr);
  double calcRpn(std::vector<Node> rpnExpression, bool isDegrees);
  double mathOperations(char code, double num1, double num2);
  double mathOperations(char code, double num1, bool isDegrees);
  QDate date_now_add(QDate date_now, int index);
  QDate date_vyplat_index(QDate date_now, int index);
};

}  // namespace s21

#endif  // BACKEND_H
