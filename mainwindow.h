#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGenerateButtonClicked();

private:
    Ui::MainWindow *ui;
    QCheckBox *uppercaseCheckbox;
    QCheckBox *lowercaseCheckbox;
    QCheckBox *specialCharactersCheckbox;
    QCheckBox *numbersCheckbox;
    QLineEdit *passwordLengthEntry;
    QLineEdit *generatedPasswordDisplay;
    QPushButton *generateButton;
};

#endif // MAINWINDOW_H
