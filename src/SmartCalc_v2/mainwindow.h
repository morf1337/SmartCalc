#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDate>
#include <QLineEdit>
#include <QMainWindow>
#include <QVector>
#include <queue>

#include "controller.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_pushButton_1_clicked();
  void on_pushButton_0_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();
  void on_pushButton_open_br_clicked();
  void on_pushButton_close_br_clicked();
  void on_pushButton_div_clicked();
  void on_pushButton_mult_clicked();
  void on_pushButton_minus_clicked();
  void on_pushButton_plus_clicked();
  void on_pushButton_X_clicked();
  void on_pushButton_sin_clicked();
  void on_pushButton_cos_clicked();
  void on_pushButton_tan_clicked();
  void on_pushButton_ln_clicked();
  void on_pushButton_asin_clicked();
  void on_pushButton_acos_clicked();
  void on_pushButton_atan_clicked();
  void on_pushButton_log_clicked();
  void on_pushButton_sqrt_clicked();
  void on_pushButton_mod_clicked();
  void on_pushButton_dot_clicked();
  void on_pushButton_clear_clicked();
  void on_pushButton_result_clicked();
  void on_pushButton_plot_graph_clicked();
  void on_pushButton_degree_clicked();
  void on_CreditCalculate_clicked();
  void on_DepositCalculate_clicked();
  void on_Box_vyplaty_activated(int index);
  void on_Box_popoln_activated(int index);
  void on_Box_snyat_activated(int index);

 private:
  Ui::MainWindow *ui;
  QVector<double> x_coord, y_coord;
  int index_vyp;
  int index_pop;
  int index_snyat;
  s21::controller myController;
};
}  // namespace s21

#endif  // MAINWINDOW_H
