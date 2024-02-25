#include "controller.h"

namespace s21 {

int controller::bracketBalance(const std::string& str) {
  return backEnd.bracketBalance(str);
}

bool controller::allowInput(const std::string& str, char ch) {
  return backEnd.allowInput(str, ch);
}

std::string controller::getResStr(const std::string& str, double xValue,
                                  bool isDegrees) {
  std::string resString = "Error";
  if (backEnd.bracketBalance(str) == 0) {
    double resValue = backEnd.entryPoint(str, xValue, isDegrees);
    if (!std::isnan(resValue) && !std::isinf(resValue)) {
      resString = std::to_string(resValue);
      resString = backEnd.rmZeros(resString);
    }
  }
  return resString;
}

double controller::getResValue(const std::string& str, double xValue,
                               bool isDegrees) {
  return backEnd.entryPoint(str, xValue, isDegrees);
}

void controller::creditCalculate(double sum, double months, double percents,
                                 std::queue<double>& payments, bool isAnnuitet,
                                 double& totalSum, double& overPayment) {
  backEnd.creditCalculate(sum, months, percents, payments, isAnnuitet, totalSum,
                          overPayment);
}

void controller::depositCalculate(double& summa, int time, double stavka,
                                  double tax_rate, double summa_popoln,
                                  double summa_snyat, QDate depDate,
                                  bool isKapital, double& summa_proc,
                                  double& NDFL, int index_vyp, int index_pop,
                                  int index_snyat) {
  backEnd.depositCalculate(summa, time, stavka, tax_rate, summa_popoln,
                           summa_snyat, depDate, isKapital, summa_proc, NDFL,
                           index_vyp, index_pop, index_snyat);
}

}  // namespace s21