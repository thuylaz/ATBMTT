#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <bits/stdc++.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QCoreApplication>
#include <QCryptographicHash>

using namespace std;
long long public_key;
long long private_key;
long long n;
long long prime1 = 11;
long long prime2 = 13;
set<long long> prime;
int lengthPrime = 3;
int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541};


string md5(string input){
        QString text = QString::fromStdString(input);
        QByteArray bytes = QCryptographicHash::hash(text.toUtf8(), QCryptographicHash::Md5);
        QString degist = QString(bytes.toHex());
        return degist.toStdString();
}


bool isPrime(int number) {
    if (number < 2) {
        return false; // Số nhỏ hơn 2 không phải số nguyên tố
    }

    int sqrtNumber = std::sqrt(number);

    for (int i = 2; i <= sqrtNumber; i++) {
        if (number % i == 0) {
            return false; // Số chia hết cho số khác không phải số nguyên tố
        }
    }

    return true; // Số còn lại là số nguyên tố
}

// sàng số nguyên tố
void primefiller()
{
   vector<bool> seive(250, true);
   seive[0] = false;
   seive[1] = false;
   for (long long i = 2; i < 250; i++) {
       for (long long j = i * 2; j < 250; j += i) {
           seive[j] = false;
       }
   }
   for (long long i = 0; i < 250; i++) {
       if (seive[i]) prime.insert(i);
   }
}

// Chọn ngẫu nhiên số nguyên tố trong vector đã sàng ở trên
long long pickrandomprime()
{
   long long k = rand() % prime.size();
   auto it = prime.begin();
   while (k--) it++;
   long long ret = *it;
   prime.erase(it);
   return ret;
}

int getLength(long long number) {
    if (number == 0) {
        return 1;
    }

    int length = 0;
    number = std::abs(number);
    while (number != 0) {
        number /= 10;
        length++;
    }

    return length;
}

// Đặt các thuộc tính cơ bản cho khóa: p, q, phi, n, d, e
void setkeys(int check){
    primefiller();
    if(check == 0){
        prime1 = arr[rand()%100];
        prime2 = arr[rand()%100];
        while (getLength(prime1) != lengthPrime) prime1 = arr[rand()%100];
        while (getLength(prime2) != lengthPrime) prime2 = arr[rand()%100];
    }
    n = prime1 * prime2;
    long long fi = (prime1 - 1) * (prime2 - 1);
    long long e = 2;
    while (1) {
        if (__gcd(e, fi) == 1)
            break;
        e++;
    }
    public_key = e;
    long long d = 2;
    while (1) {
        if ((d * e) % fi == 1)
            break;
        d++;
    }
    private_key = d;
}

// Tính giá trị của từng ký tự bằng công thức c = (m^e)%n
long long encrypt(double message)
{
    long long e = public_key;
    long long encrpyted_text = 1;
    while (e--) {
        encrpyted_text *= message;
        encrpyted_text %= n;
    }
    return encrpyted_text;
}

// Tính giá trị của từng ký tự bằng công thức m = (c^d)%n
long long decrypt(long long encrpyted_text)
{
    long long d = private_key;
    long long decrypted = 1;
    while (d--) {
        decrypted *= encrpyted_text;
        decrypted %= n;
    }
    return decrypted;
}

// Hàm mã hóa
vector<long long> encoder(string message)
{
    vector<long long> form;
    for (auto& letter : message)
        form.push_back(encrypt((long long)letter));
    return form;
}
// Hàm giải mã
string decoder(vector<long long> encoded)
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
}

// Hủy giao diện form
MainWindow::~MainWindow()
{
    delete ui;
}

// Xử lý sự kiện khi buttun có tên 'encript' được ấn
void MainWindow::on_encript_clicked()
{
    string message = ui->send_message->text().toStdString();
    message = md5(message);
    vector<long long> coded = encoder(message);
    string encoded;
    for (auto p : coded) {
        encoded += to_string(p) + ' ';
    }
    ui->hash1->setText(QString::fromStdString(message));
    ui->send_cipher->setText(QString::fromStdString(encoded));
}

// Xử lý sự kiện khi buttun có tên 'decript' được ấn
void MainWindow::on_decript_clicked()
{
    try {
        string encript = ui->receive_cypher->text().toStdString();
        vector<long long> coded;
        stringstream ss(encript);
        string temp;
        while (ss >> temp)
        {
            long long encryptedChar = stoi(temp);
            coded.push_back(encryptedChar);
        }
        string old_hash = decoder(coded);
        string new_hash = md5(ui->message2->text().toStdString());
        if(new_hash == old_hash){
            QMessageBox::warning(this, tr("Success"), tr("Chữ ký hợp lệ."));
        }else{
            QMessageBox::warning(this, tr("Error"), tr("Chữ ký không hợp lệ."));
        }

    } catch (exception& e) {
        QMessageBox::warning(this, tr("Error"), tr("Bản mã không hợp lệ."));
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
    ui->receive_cypher->clear();
    ui->send_cipher->clear();
    ui->send_message->clear();
    ui->p->clear();
    ui->q->clear();
    ui->n->clear();
    ui->d->clear();
    ui->e->clear();
    ui->n_2->clear();
    ui->hash1->clear();
    ui->message2->clear();
}


void MainWindow::on_genkey_clicked()
{
    try{
        prime1 = ui->p->text().toLongLong();
        prime2 = ui->q->text().toLongLong();
        if(isPrime(prime1) && isPrime(prime2)){
            lengthPrime = ui->lengthPrime->currentText().toInt();
            setkeys(1);
            ui->p->setText(QString::fromStdString(to_string(prime1)));
            ui->q->setText(QString::fromStdString(to_string(prime2)));
            ui->e->setText(QString::fromStdString(to_string(public_key)));
            ui->n->setText(QString::fromStdString(to_string(n)));
            ui->d->setText(QString::fromStdString(to_string(private_key)));
            ui->n_2->setText(QString::fromStdString(to_string(n)));
        }else{
            QMessageBox::warning(this, tr("Error"), tr("p và q phải là số nguyên tố."));
        }

    }catch(exception){
        QMessageBox::warning(this, tr("Error"), tr("Không được để trống p và q."));

    }

}


void MainWindow::on_random_key_clicked()
{
    lengthPrime = ui->lengthPrime->currentText().toInt();
    setkeys(0);
    ui->p->setText(QString::fromStdString(to_string(prime1)));
    ui->q->setText(QString::fromStdString(to_string(prime2)));
    ui->e->setText(QString::fromStdString(to_string(public_key)));
    ui->n->setText(QString::fromStdString(to_string(n)));
    ui->d->setText(QString::fromStdString(to_string(private_key)));
    ui->n_2->setText(QString::fromStdString(to_string(n)));
}


void MainWindow::on_file3_clicked()
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
        ui->message2->setText(QString::fromStdString(message));

    }
    else {
        QMessageBox::warning(this, tr("Error"), tr("Failed to open the file."));
    }
}


void MainWindow::on_save1_clicked()
{   
    QString cript = ui->hash1->text();
    QString filePath = QFileDialog::getSaveFileName(this, tr("Chọn vị trí và tên file"), "", tr("Tệp tin văn bản (*.txt)"));

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << cript;
            file.close();
            QMessageBox::warning(this, tr("Thành công"), tr("Đã lưu file vào %1.").arg(filePath));
        } else {
            QMessageBox::warning(this, tr("Lỗi"), tr("Không thể lưu file."));
        }
    }
}


void MainWindow::on_save2_clicked()
{
    QString cript = ui->send_cipher->text();
    QString filePath = QFileDialog::getSaveFileName(this, tr("Chọn vị trí và tên file"), "", tr("Tệp tin văn bản (*.txt)"));

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << cript;
            file.close();
            QMessageBox::warning(this, tr("Thành công"), tr("Đã lưu file vào %1.").arg(filePath));
        } else {
            QMessageBox::warning(this, tr("Lỗi"), tr("Không thể lưu file."));
        }
    }
}

