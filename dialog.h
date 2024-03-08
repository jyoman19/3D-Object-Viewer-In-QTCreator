#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    //void on_doubleSpinBox_textChanged(const QString &arg1);
    //void keyPressEvent(QKeyEvent *event);
    void on_doubleSpinBox_valueChanged(double arg1);

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_18_clicked();


    void on_pushButton_20_clicked();

    void on_doubleSpinBox_2_valueChanged(double arg1);

    void on_pushButton_22_clicked();

    void on_doubleSpinBox_3_valueChanged(double arg1);

    void on_pushButton_26_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_31_clicked();

    void on_doubleSpinBox_4_valueChanged(double arg1);

    void on_pushButton_30_clicked();

    void on_doubleSpinBox_5_valueChanged(double arg1);

    void on_pushButton_32_clicked();

    void on_doubleSpinBox_6_valueChanged(double arg1);

    void on_doubleSpinBox_7_valueChanged(double arg1);

    void on_doubleSpinBox_8_valueChanged(double arg1);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
