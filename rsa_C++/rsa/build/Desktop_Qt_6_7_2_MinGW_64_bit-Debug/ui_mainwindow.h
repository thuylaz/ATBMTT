/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *send_choose_file;
    QLabel *label;
    QLabel *label_2;
    QPushButton *encript;
    QPushButton *receive_choose_file;
    QPushButton *decript;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *send_message;
    QLineEdit *send_cipher;
    QLineEdit *receive_cypher;
    QLineEdit *message2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QTextEdit *e;
    QTextEdit *n;
    QTextEdit *d;
    QTextEdit *n_2;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *genkey;
    QPushButton *random_key;
    QLabel *label_17;
    QLineEdit *hash1;
    QLineEdit *p;
    QLineEdit *q;
    QPushButton *file3;
    QLabel *label_18;
    QComboBox *lengthPrime;
    QPushButton *save1;
    QPushButton *save2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1138, 590);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        send_choose_file = new QPushButton(centralwidget);
        send_choose_file->setObjectName("send_choose_file");
        send_choose_file->setGeometry(QRect(320, 40, 80, 31));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(170, 20, 37, 12));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(600, 10, 37, 12));
        encript = new QPushButton(centralwidget);
        encript->setObjectName("encript");
        encript->setGeometry(QRect(220, 230, 80, 31));
        receive_choose_file = new QPushButton(centralwidget);
        receive_choose_file->setObjectName("receive_choose_file");
        receive_choose_file->setGeometry(QRect(740, 40, 80, 31));
        decript = new QPushButton(centralwidget);
        decript->setObjectName("decript");
        decript->setGeometry(QRect(650, 320, 80, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 40, 37, 12));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(430, 40, 41, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 400, 51, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(420, 220, 51, 16));
        send_message = new QLineEdit(centralwidget);
        send_message->setObjectName("send_message");
        send_message->setGeometry(QRect(60, 40, 241, 131));
        send_cipher = new QLineEdit(centralwidget);
        send_cipher->setObjectName("send_cipher");
        send_cipher->setGeometry(QRect(80, 400, 231, 61));
        send_cipher->setReadOnly(true);
        receive_cypher = new QLineEdit(centralwidget);
        receive_cypher->setObjectName("receive_cypher");
        receive_cypher->setGeometry(QRect(480, 40, 251, 131));
        message2 = new QLineEdit(centralwidget);
        message2->setObjectName("message2");
        message2->setGeometry(QRect(480, 220, 251, 61));
        message2->setReadOnly(false);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(870, 30, 71, 16));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(870, 60, 71, 16));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(870, 110, 111, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(870, 190, 111, 16));
        e = new QTextEdit(centralwidget);
        e->setObjectName("e");
        e->setGeometry(QRect(1040, 110, 71, 21));
        e->setReadOnly(true);
        n = new QTextEdit(centralwidget);
        n->setObjectName("n");
        n->setGeometry(QRect(1040, 140, 71, 21));
        n->setReadOnly(true);
        d = new QTextEdit(centralwidget);
        d->setObjectName("d");
        d->setGeometry(QRect(1040, 190, 71, 21));
        d->setReadOnly(true);
        n_2 = new QTextEdit(centralwidget);
        n_2->setObjectName("n_2");
        n_2->setGeometry(QRect(1040, 220, 71, 21));
        n_2->setReadOnly(true);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(1020, 110, 21, 16));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(1020, 140, 21, 16));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(1020, 190, 21, 16));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(1020, 220, 21, 16));
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(1020, 30, 21, 16));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(1020, 60, 21, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(650, 500, 80, 31));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(550, 500, 80, 31));
        genkey = new QPushButton(centralwidget);
        genkey->setObjectName("genkey");
        genkey->setGeometry(QRect(930, 330, 80, 31));
        random_key = new QPushButton(centralwidget);
        random_key->setObjectName("random_key");
        random_key->setGeometry(QRect(1030, 330, 80, 31));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(30, 300, 61, 16));
        hash1 = new QLineEdit(centralwidget);
        hash1->setObjectName("hash1");
        hash1->setGeometry(QRect(80, 300, 231, 61));
        hash1->setReadOnly(true);
        p = new QLineEdit(centralwidget);
        p->setObjectName("p");
        p->setGeometry(QRect(1040, 30, 71, 20));
        q = new QLineEdit(centralwidget);
        q->setObjectName("q");
        q->setGeometry(QRect(1040, 60, 71, 20));
        file3 = new QPushButton(centralwidget);
        file3->setObjectName("file3");
        file3->setGeometry(QRect(740, 220, 80, 31));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(870, 290, 131, 16));
        lengthPrime = new QComboBox(centralwidget);
        lengthPrime->addItem(QString());
        lengthPrime->addItem(QString());
        lengthPrime->addItem(QString());
        lengthPrime->addItem(QString());
        lengthPrime->setObjectName("lengthPrime");
        lengthPrime->setGeometry(QRect(1044, 290, 61, 22));
        save1 = new QPushButton(centralwidget);
        save1->setObjectName("save1");
        save1->setGeometry(QRect(330, 300, 80, 31));
        save2 = new QPushButton(centralwidget);
        save2->setObjectName("save2");
        save2->setGeometry(QRect(330, 400, 80, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1138, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        send_choose_file->setText(QCoreApplication::translate("MainWindow", "ch\341\273\215n file", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "G\341\273\255i", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Nh\341\272\255n", nullptr));
        encript->setText(QCoreApplication::translate("MainWindow", "K\303\275", nullptr));
        receive_choose_file->setText(QCoreApplication::translate("MainWindow", "ch\341\273\215n file", nullptr));
        decript->setText(QCoreApplication::translate("MainWindow", "X\303\241c th\341\273\261c", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "b\341\272\243n r\303\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "b\341\272\243n m\303\243", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Ch\341\273\257 k\303\275 s\341\273\221", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "B\341\272\243n r\303\265", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "s\341\273\221 nguy\303\252n t\341\273\221 p", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "s\341\273\221 nguy\303\252n t\341\273\221 q", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Kh\303\263a c\303\264ng khai (e, n)", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Kh\303\263a b\303\255 m\341\272\255t (d, n)", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "e =", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "n =", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "d =", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "n =", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "p =", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "q =", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Tho\303\241t", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        genkey->setText(QCoreApplication::translate("MainWindow", "sinh kh\303\263a", nullptr));
        random_key->setText(QCoreApplication::translate("MainWindow", "random key", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "hash value", nullptr));
        hash1->setText(QString());
        file3->setText(QCoreApplication::translate("MainWindow", "ch\341\273\215n file", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\304\220\341\273\231 d\303\240i s\341\273\221 nguy\303\252n t\341\273\221", nullptr));
        lengthPrime->setItemText(0, QCoreApplication::translate("MainWindow", "3", nullptr));
        lengthPrime->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        lengthPrime->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        lengthPrime->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));

        save1->setText(QCoreApplication::translate("MainWindow", "L\306\260u", nullptr));
        save2->setText(QCoreApplication::translate("MainWindow", "L\306\260u", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
