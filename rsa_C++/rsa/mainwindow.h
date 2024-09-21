#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_encript_clicked();

    void on_decript_clicked();

    void on_send_choose_file_clicked();

    void on_receive_choose_file_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_genkey_clicked();

    void on_random_key_clicked();

    void on_file3_clicked();

    void on_save1_clicked();

    void on_save2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
