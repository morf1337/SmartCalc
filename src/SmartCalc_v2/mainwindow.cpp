#include "mainwindow.h"

#include <string.h>

#include <QLabel>
#include <QMessageBox>
#include <QScrollArea>

#include "ui_mainwindow.h"
using namespace s21;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->DepositDate->setDate(QDate::currentDate());
  ui->Xfrom->setText("-5");
  ui->Xto->setText("5");
  ui->Yfrom->setText("-2");
  ui->Yto->setText("2");
  index_vyp = 0;
  index_pop = 0;
  index_snyat = 0;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_0_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '0');
  }
}

void MainWindow::on_pushButton_1_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '1');
  }
}

void MainWindow::on_pushButton_2_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '2');
  }
}

void MainWindow::on_pushButton_3_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '3');
  }
}

void MainWindow::on_pushButton_4_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '4');
  }
}

void MainWindow::on_pushButton_5_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '5');
  }
}

void MainWindow::on_pushButton_6_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '6');
  }
}

void MainWindow::on_pushButton_7_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '7');
  }
}

void MainWindow::on_pushButton_8_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '8');
  }
}

void MainWindow::on_pushButton_9_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'N')) {
    ui->Display->setText(ui->Display->text() + '9');
  }
}

void MainWindow::on_pushButton_open_br_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), '(')) {
    ui->Display->setText(ui->Display->text() + '(');
  }
}

void MainWindow::on_pushButton_close_br_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), ')')) {
    ui->Display->setText(ui->Display->text() + ')');
  }
}

void MainWindow::on_pushButton_div_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'O')) {
    ui->Display->setText(ui->Display->text() + '/');
  }
}

void MainWindow::on_pushButton_mult_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'O')) {
    ui->Display->setText(ui->Display->text() + '*');
  }
}

void MainWindow::on_pushButton_minus_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'U')) {
    ui->Display->setText(ui->Display->text() + '-');
  }
}

void MainWindow::on_pushButton_plus_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'U')) {
    ui->Display->setText(ui->Display->text() + '+');
  }
}

void MainWindow::on_pushButton_X_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + 'X');
  }
}

void MainWindow::on_pushButton_sin_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "sin(");
  }
}

void MainWindow::on_pushButton_cos_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "cos(");
  }
}

void MainWindow::on_pushButton_tan_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "tan(");
  }
}

void MainWindow::on_pushButton_ln_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "ln(");
  }
}

void MainWindow::on_pushButton_asin_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "asin(");
  }
}

void MainWindow::on_pushButton_acos_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "acos(");
  }
}

void MainWindow::on_pushButton_atan_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "atan(");
  }
}

void MainWindow::on_pushButton_log_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "log(");
  }
}

void MainWindow::on_pushButton_sqrt_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'F')) {
    ui->Display->setText(ui->Display->text() + "sqrt(");
  }
}

void MainWindow::on_pushButton_mod_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'O')) {
    ui->Display->setText(ui->Display->text() + "mod");
  }
}

void MainWindow::on_pushButton_dot_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), '.')) {
    ui->Display->setText(ui->Display->text() + '.');
  }
}

void MainWindow::on_pushButton_degree_clicked() {
  if (myController.allowInput(ui->Display->text().toStdString(), 'O')) {
    ui->Display->setText(ui->Display->text() + '^');
  }
}

void MainWindow::on_pushButton_clear_clicked() {
  ui->Display->setText("");
  ui->Answer->setText("");
}

void MainWindow::on_pushButton_result_clicked() {
  ui->Answer->setText(QString::fromStdString(myController.getResStr(
      ui->Display->text().toStdString(), ui->Xinput->text().toDouble(), true)));
}

void MainWindow::on_pushButton_plot_graph_clicked() {
  float step = 0.01, ycoord = 0.0, xcoord = 0.0, xfrom = 0.0, xto = 0.0,
        yfrom = 0.0, yto = 0.0;
  QString string = ui->Display->text();
  xfrom = ui->Xfrom->text().toDouble();
  xto = ui->Xto->text().toDouble();
  yfrom = ui->Yfrom->text().toDouble();
  yto = ui->Yto->text().toDouble();
  xcoord = xfrom;

  for (int i = 0; i <= (xto - xfrom) / step; i++) {
    ycoord = myController.getResValue(string.toStdString(), xcoord, false);
    if (!std::isnan(ycoord) && !std::isinf(ycoord)) {
      x_coord.push_back(xcoord);
      y_coord.push_back(ycoord);
    }
    xcoord += step;
  }

  ui->widget->addGraph();
  ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
  ui->widget->graph(0)->setScatterStyle(
      QCPScatterStyle(QCPScatterStyle::ssDisc, 1));
  ui->widget->xAxis->setRange(xfrom, xto);
  ui->widget->yAxis->setRange(yfrom, yto);
  ui->widget->xAxis->ticker()->setTickCount(12);
  ui->widget->yAxis->ticker()->setTickCount(8);
  ui->widget->graph(0)->setData(x_coord, y_coord);
  ui->widget->replot();
  x_coord.clear();
  y_coord.clear();
}

void MainWindow::on_CreditCalculate_clicked() {
  double sum = ui->CreditSum->text().toDouble();
  double months = ui->CreditPeriod->text().toDouble();
  double percent = ui->CreditPercentage->text().toDouble();
  std::queue<double> payments;

  double totalSum = 0, overPayment = 0;

  ui->Tablica->setShowGrid(false);
  ui->Tablica->clear();
  ui->Tablica->setColumnCount(2);
  ui->Tablica->setRowCount(1);
  ui->Tablica->setRowHeight(0, 1);
  ui->Tablica->setColumnWidth(0, 1);

  if (ui->Annuitet->isChecked()) {
    myController.creditCalculate(sum, months, percent, payments, true, totalSum,
                                 overPayment);
    ui->Tablica->setItem(
        0, 1,
        new QTableWidgetItem(QString::number(payments.front(), 'f', 2) +
                             " руб."));
    payments.pop();
  } else if (ui->Differenc->isChecked()) {
    myController.creditCalculate(sum, months, percent, payments, false,
                                 totalSum, overPayment);
    for (int i = 1; i <= months; i++) {
      if (i < months) ui->Tablica->insertRow(i);
      ui->Tablica->setItem(
          i - 1, 1,
          new QTableWidgetItem(QString::number(payments.front(), 'f', 2) +
                               " руб."));
      ui->Tablica->setItem(i - 1, 0, new QTableWidgetItem(QString::number(i)));
      payments.pop();
    }
  }
  ui->TotalCreditPayment->setText(QString::number(totalSum, 'f', 2) + " руб.");
  ui->CreditOverpay->setText(QString::number(overPayment, 'f', 2) + " руб.");
}

void MainWindow::on_DepositCalculate_clicked() {
  double summa = ui->Summa_vklad->text().toDouble();
  int time = ui->Time_vklad->text().toInt();
  double stavka = ui->Proc_stavka->text().toDouble();
  double tax_rate = ui->Nalog_stavka->text().toDouble();
  double summa_popoln = ui->Summa_popoln->text().toDouble();
  double summa_snyat = ui->Summa_snyat->text().toDouble();

  double summa_proc = 0.0, NDFL = 0.0;
  if (time <= 600 && stavka < 100 && time > 0 && stavka >= 0 && summa >= 0 &&
      summa_popoln >= 0 && summa_snyat >= 0 && tax_rate >= 0 &&
      tax_rate < 100) {
    myController.depositCalculate(summa, time, stavka, tax_rate, summa_popoln,
                                  summa_snyat, ui->DepositDate->date(),
                                  ui->Kapital->isChecked(), summa_proc, NDFL,
                                  index_vyp, index_pop, index_snyat);

    ui->result_proc->setText(QString::number(summa_proc, 'f', 2));
    ui->result_nalog->setText(QString::number(NDFL, 'f', 2));
    ui->result_summa_vklad->setText(QString::number(summa, 'f', 2));
  } else {
    ui->result_proc->setText("");
    ui->result_nalog->setText("");
    ui->result_summa_vklad->setText("");
  }
}

void MainWindow::on_Box_vyplaty_activated(int index) { index_vyp = index; }

void MainWindow::on_Box_popoln_activated(int index) {
  index_pop = index;
  if (index == 0) {
    ui->Summa_popoln->setEnabled(false);
    ui->Summa_popoln->setStyleSheet(
        "QLineEdit { background: rgb(200, 211, 201); border: 1px solid black; "
        "border-radius: 5px;}");
  } else {
    ui->Summa_popoln->setEnabled(true);
    ui->Summa_popoln->setStyleSheet(
        "QLineEdit { background: rgb(255, 255, 255); border: 1px solid black; "
        "border-radius: 5px;}");
  }
}

void MainWindow::on_Box_snyat_activated(int index) {
  index_snyat = index;
  if (index == 0) {
    ui->Summa_snyat->setEnabled(false);
    ui->Summa_snyat->setStyleSheet(
        "QLineEdit { background: rgb(200, 211, 201); border: 1px solid black; "
        "border-radius: 5px;}");
  } else {
    ui->Summa_snyat->setEnabled(true);
    ui->Summa_snyat->setStyleSheet(
        "QLineEdit { background: rgb(255, 255, 255); border: 1px solid black; "
        "border-radius: 5px;}");
  }
}
