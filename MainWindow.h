#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onConvertClicked();

private:
    bool validateInput() const;

    QLineEdit *latDegEdit;
    QLineEdit *latMinEdit;
    QLineEdit *latSecEdit;

    QLineEdit *lonDegEdit;
    QLineEdit *lonMinEdit;
    QLineEdit *lonSecEdit;

    QLabel *latResultLabel;
    QLabel *lonResultLabel;

    QPushButton *convertButton;
};
#endif // MAINWINDOW_H
