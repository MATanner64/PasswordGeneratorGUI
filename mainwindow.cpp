// Created by Matt Tanner

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QRandomGenerator>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set a 50-character limit for the password length entry
    ui->PasswordLengthEntry->setMaxLength(2); // Limit input to 2 digits (max: 50)

    // Connect the Generate button to the slot
    connect(ui->generateButton, &QPushButton::clicked, this, &MainWindow::onGenerateButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGenerateButtonClicked()
{
    // Retrieve password length
    bool ok;
    int length = ui->PasswordLengthEntry->text().toInt(&ok);
    if (!ok || length <= 0 || length > 50) {
        QMessageBox::warning(this, "Input Error", "Please enter a valid password length (1-50).");
        return;
    }

    // Gather character sets
    QString characterSet;
    if (ui->UppercaseLetterCheckbox->isChecked()) {
        characterSet += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    }
    if (ui->LowercaseLetterCheckbox->isChecked()) {
        characterSet += "abcdefghijklmnopqrstuvwxyz";
    }
    if (ui->SpeicalCharactersLetterbox->isChecked()) {
        characterSet += "!@#$%^&*()_+-=[]{}|;:',.<>?/";
    }
    if (ui->NumbersCheckbox->isChecked()) {
        characterSet += "0123456789";
    }

    if (characterSet.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please select at least one character type.");
        return;
    }

    // Generate password
    QString password;
    for (int i = 0; i < length; ++i) {
        int index = QRandomGenerator::global()->bounded(characterSet.length());
        password += characterSet.at(index);
    }

    // Display the generated password
    ui->GeneratedPasswordDisplay->setText(password);
}
