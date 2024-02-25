#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <cstring>
#include <queue>
#include <string>

#include "backend.h"

namespace s21 {
class controller {
 public:
  bool allowInput(const std::string& str, char ch);
  int bracketBalance(const std::string& str);
  std::string getResStr(const std::string& str, double xValue, bool isDegrees);
  double getResValue(const std::string& str, double xValue, bool isDegrees);
  void creditCalculate(double sum, double months, double percents,
                       std::queue<double>& payments, bool isAnnuitet,
                       double& totalSum, double& overPayment);
  void depositCalculate(double& summa, int time, double stavka, double tax_rate,
                        double summa_popoln, double summa_snyat, QDate depDate,
                        bool isKapital, double& summa_proc, double& NDFL,
                        int index_vyp, int index_pop, int index_snyat);

 private:
  model backEnd;
};
}  // namespace s21

#endif  // CONTROLLER_H
