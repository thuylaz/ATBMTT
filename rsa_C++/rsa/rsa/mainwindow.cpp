#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>
#include <QFileDialog>
#include <QMessageBox>
using namespace std;
int public_key;
int private_key;
int n;
int prime1;
int prime2;
set<int> prime;


// sàng số nguyên tố
void primefiller()
{
   vector<bool> seive(250, true);
   seive[0] = false;
   seive[1] = false;
   for (int i = 2; i < 250; i++) {
       for (int j = i * 2; j < 250; j += i) {
           seive[j] = false;
       }
   }
   for (int i = 0; i < 250; i++) {
       if (seive[i]) prime.insert(i);
   }
}

// Chọn ngẫu nhiên số nguyên tố trong vector đã sàng ở trên
int pickrandomprime()
{
   int k = rand() % prime.size();
   auto it = prime.begin();
   while (k--) it++;
   int ret = *it;
   prime.erase(it);
   return ret;
}

// Đặt các thuộc tính cơ bản cho khóa: p, q, phi, n, d, e
void setkeys()
{
    primefiller();
    prime1 = pickrandomprime();
    prime2 = pickrandomprime();
    // int prime1 = 11;
    // int prime2 = 13;
    n = prime1 * prime2;
    int fi = (prime1 - 1) * (prime2 - 1);
    int e = 2;
    while (1) {
        if (__gcd(e, fi) == 1)
            break;
        e++;
    }
    public_key = e;
    int d = 2;
    while (1) {
        if ((d * e) % fi == 1)
            break;
        d++;
    }
    private_key = d;
}

// Tính giá trị của từng ký tự bằng công thức c = (m^e)%n
long long int encrypt(double message)
{
    int e = public_key;
    long long int encrpyted_text = 1;
    while (e--) {
        encrpyted_text *= message;
        encrpyted_text %= n;
    }
    return encrpyted_text;
}

// Tính giá trị của từng ký tự bằng công thức m = (c^d)%n
long long int decrypt(int encrpyted_text)
{
    int d = private_key;
    long long int decrypted = 1;
    while (d--) {
        decrypted *= encrpyted_text;
        decrypted %= n;
    }
    return decrypted;
}

// Hàm mã hóa
vector<int> encoder(string message)
{
    vector<int> form;
    for (auto& letter : message)
        form.push_back(encrypt((int)letter));
    return form;
}
// Hàm giải mã
string decoder(vector<int> encoded)
{
    string s;
    for (auto& num : encoded)
        s += decrypt(num);

    return s;
}

// Khởi tạo giao diện form
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setkeys();
    ui->p->setText(QString::fromStdString(to_string(prime1)));
    ui->q->setText(QString::fromStdString(to_string(prime2)));
    ui->e->setText(QString::fromStdString(to_string(public_key)));
    ui->n->setText(QString::fromStdString(to_string(n)));
    ui->d->setText(QString::fromStdString(to_string(private_key)));
    ui->n_2->setText(QString::fromStdString(to_string(n)));
}

// Hủy giao diện form
MainWindow::~MainWindow()
{
    delete ui;
}

// Xử lý sự kiện khi buttun có tên 'encript' được ấn
void MainWindow::on_encript_clicked()
{
    setkeys();
    string message = ui->send_message->text().toStdString();
    vector<int> coded = encoder(message);
    string encoded;
    for (auto p : coded) {
        encoded += to_string(p) + ' ';
    }
    ui->send_cipher->setText(QString::fromStdString(encoded));
}

// Xử lý sự kiện khi buttun có tên 'decript' được ấn
void MainWindow::on_decript_clicked()
{
    try {
        string encript = ui->receive_cypher->text().toStdString();
        vector<int> coded;
        stringstream ss(encript);
        string temp;
        while (ss >> temp)
        {
            int encryptedChar = stoi(temp);
            coded.push_back(encryptedChar);
        }
        ui->receive_message->setText(QString::fromStdString(decoder(coded)));
    } catch (exception& e) {
        ui->receive_message->setText(QString::fromStdString("Invalid encription!"));
    }
}

// Xử lý sự kiện khi buttun có tên 'send_choose_file' được ấn (Đọc nội dung khi chọn file)
void MainWindow::on_send_choose_file_clicked()
{
    // mặc định là mở ổ D, chỉ chọn file txt
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "D://",
        "Text File (*.txt)"
        );

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        file.close();
        string message = fileContent.toStdString();
        ui->send_message->setText(QString::fromStdString(message));

    }
    else {
        QMessageBox::warning(this, tr("Error"), tr("Failed to open the file."));
    }
}

// Xử lý sự kiện khi buttun có tên 'receive_choose_file' được ấn (Đọc nội dung khi chọn file)
void MainWindow::on_receive_choose_file_clicked()
{
    // mặc định là mở ổ D, chỉ chọn file txt
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        "D://",
        "Text File (*.txt)"
        );

    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString fileContent = in.readAll();
        file.close();
        string message = fileContent.toStdString();
        ui->receive_cypher->setText(QString::fromStdString(message));

    }
    else {
        QMessageBox::warning(this, tr("Error"), tr("Failed to open the file."));
    }
}

// Hủy giao diện
void MainWindow::on_pushButton_clicked()
{
    delete ui;
}

// clear nội dung của các input
void MainWindow::on_pushButton_2_clicked()
{
    ui->receive_message->clear();
    ui->receive_cypher->clear();
    ui->send_cipher->clear();
    ui->send_message->clear();
}

