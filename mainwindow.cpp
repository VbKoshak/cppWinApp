#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int colcount = ui->table->columnCount();
    int rowcount = ui->table->rowCount();
    double ** data = new double*[colcount];
    double sum = 0;
    int count = 0;
    float temp;
    for (int i = 0; i < rowcount; i++) {
        data[i] = new double[colcount];
        for (int j = 0; j < colcount; j++) {
            temp = ui->table->itemAt(i,j)->text().toFloat();
            data[i][j] = temp;
            if (data[i][j]) count++;
            sum+=data[i][j];
        }
    };
    double avg =sum/count;
    QString Savg = QString::number(avg);
    QString Ssum = QString::number(sum);
    ui->text->setText("Average: " + Savg + "\nSum: " + Ssum + "\nCount: " + QString::number(count));
    for (int i = 0; i < rowcount; i++){
        for (int j = 0; j < colcount; j++){
            ui->text->append("\n" + QString::number(i) + " " + QString::number(j) + " : " + QString::number(data[i][j]));
        }
    }


   // ui->text->setText(ui->table->itemAt(0,0)->text());
}
