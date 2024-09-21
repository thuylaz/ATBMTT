using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using Microsoft.Win32;
using System.Security.Cryptography;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Collections;
//using Microsoft.Office.Interop.Word;

namespace chukyRSA
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {

            InitializeComponent();
            rb_tdRSA.IsChecked = true;   //Mặc định radioButton tự động true
            rb_tcRSA.IsChecked = false;
        }

        //Phần 1 tạo khoá 
        //Tạo khoá 
        int RSA_soP, RSA_soQ, RSA_soN, RSA_soE, RSA_soD, RSA_soPhi_n;   // 
        int F_rsa_d_dau = 0     /*Đánh dấu kiểm tra đã tạo khóa và ký chưa ?*/, check = 0;//0 : Tai file | 1. Nhap tay
        string fileNameCanKi = "";
        string fileNameKiemTra = "";
        private void btn_TaoKhoa_Click(object sender, RoutedEventArgs e)
        {
            // Tạo khoá tự động - Điều kiện
            if (rb_tdRSA.IsChecked == true && rb_tcRSA.IsChecked == false)
            {
                reset_rsa();
                RSA_soP = RSA_soQ = 0;
                do
                {
                    RSA_soP = RSA_ChonSoNgauNhien();
                    RSA_soQ = RSA_ChonSoNgauNhien();
                }
                while (RSA_soP == RSA_soQ || !RSA_kiemTraNguyenTo(RSA_soP) || !RSA_kiemTraNguyenTo(RSA_soQ));
                So_P.Text = RSA_soP.ToString();
                So_Q.Text = RSA_soQ.ToString();
                RSA_taoKhoa();
                F_rsa_d_dau = 1;
                btn_TaoKhoa.IsEnabled = false;
                rb_tcRSA.IsEnabled = false;
                rb_tdRSA.IsEnabled = false;
            }
            else
            {
                if (rb_tdRSA.IsChecked == false && rb_tcRSA.IsChecked == true)
                {
                    if (So_P.Text == "" || So_Q.Text == "")
                        MessageBox.Show("Phải nhập đủ 2 số ", "Thông Báo ", MessageBoxButton.OK, MessageBoxImage.Error);
                    else
                    {
                        try
                        {
                            RSA_soP = int.Parse(So_P.Text);
                            RSA_soQ = int.Parse(So_Q.Text);
                            if (RSA_soP == RSA_soQ)
                            {
                                MessageBox.Show("Nhập 2 số nguyên tố khác nhau ", " Thông Báo", MessageBoxButton.OK, MessageBoxImage.Error);
                                So_Q.Focus();
                            }
                            else
                            {
                                if (!RSA_kiemTraNguyenTo(RSA_soP) || RSA_soP <= 1)
                                {
                                    MessageBox.Show("Phải nhập số nguyên  tố [p] lớn hơn 1 ", "Thông Báo", MessageBoxButton.OK, MessageBoxImage.Error);
                                    So_P.Focus();
                                }
                                else
                                {
                                    if (!RSA_kiemTraNguyenTo(RSA_soQ) || RSA_soQ <= 1)
                                    {
                                        MessageBox.Show("Phải nhập số nguyên  tố [q] lớn hơn 1 ", "Thông Báo", MessageBoxButton.OK, MessageBoxImage.Error);
                                        So_Q.Focus();
                                    }
                                    else
                                    {

                                        RSA_taoKhoa();
                                        So_P.Text = RSA_soP.ToString();
                                        So_Q.Text = RSA_soQ.ToString();
                                        F_rsa_d_dau = 1;
                                        //bt_taokhoaTuychonMoi.Visible = true;
                                        //btn_TaoKhoa.IsEnabled = false;
                                        So_P.IsEnabled = So_Q.IsEnabled = false;
                                    }
                                }

                            }
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show(ex.Message, "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                        }
                    }

                }
            }


        }
        // Hàm xoá text 
        private void reset_rsa()
        {
            So_P.Text = So_Q.Text = So_E.Text = So_D.Text = So_N.Text = So_N_copy.Text = string.Empty;

        }

        private void rb_tcRSA_Checked(object sender, RoutedEventArgs e)
        {
            So_P.Text = So_Q.Text = So_E.Text = So_D.Text = So_N.Text = So_N_copy.Text = string.Empty;
            So_P.IsEnabled = So_Q.IsEnabled = true;
            So_E.IsEnabled = So_D.IsEnabled = So_N.IsEnabled = So_N_copy.IsEnabled = So_O_le.IsEnabled = false;
        }

        private void rb_tdRSA_Checked(object sender, RoutedEventArgs e)
        {
            So_P.Text = So_Q.Text = So_E.Text = So_D.Text = So_N.Text = So_N_copy.Text = string.Empty;
            So_P.IsEnabled = So_Q.IsEnabled = So_E.IsEnabled = So_D.IsEnabled = So_N.IsEnabled = So_N_copy.IsEnabled = So_O_le.IsEnabled = false;
        }
        private void RSA_taoKhoa()
        {
            //Tinh n=p*q
            RSA_soN = RSA_soP * RSA_soQ;
            So_N.Text = RSA_soN.ToString();
            So_N_copy.Text = RSA_soN.ToString();
            //Tính Phi(n)=(p-1)*(q-1)
            RSA_soPhi_n = (RSA_soP - 1) * (RSA_soQ - 1);
            So_O_le.Text = RSA_soPhi_n.ToString();
            //Tính e là một số ngẫu nhiên có giá trị 0< e <phi(n) và là số nguyên tố cùng nhau với Phi(n)
            do
            {
                Random RSA_rd = new Random();
                RSA_soE = RSA_rd.Next(2, RSA_soPhi_n);
            }
            while (!nguyenToCungNhau(RSA_soE, RSA_soPhi_n));
            So_E.Text = RSA_soE.ToString();

            //Tính d là nghịch đảo modular của e
            RSA_soD = EuclideMoRong(RSA_soE, RSA_soPhi_n);
            So_D.Text = RSA_soD.ToString();
        }



        //----------------------------------------------Hàm tính toán--------------------------------------------------------------
        // "Hàm kiểm tra hai số nguyên tố cùng nhau"
        public bool nguyenToCungNhau(int ai, int bi)
        {
            bool ktx_; //Kiểm tra
            // giải thuật Euclid;
            int temp;
            while (bi != 0)
            {
                temp = ai % bi;
                ai = bi;
                bi = temp;
            }
            if (ai == 1) { ktx_ = true; }
            else ktx_ = false;
            return ktx_;
        }
        //"Hàm kiểm tra nguyên tố"
        private bool RSA_kiemTraNguyenTo(int xi)
        {
            bool kiemtra = true;
            if (xi == 2 || xi == 3)
            {
                // kiemtra = true;
                return kiemtra;
            }
            else
            {
                if (xi == 1 || xi % 2 == 0 || xi % 3 == 0)
                {
                    kiemtra = false;
                }
                else
                {
                    for (int i = 5; i <= Math.Sqrt(xi); i = i + 6)
                        if (xi % i == 0 || xi % (i + 2) == 0)
                        {
                            kiemtra = false;
                            break;
                        }
                }
            }
            return kiemtra;
        }

        // Thuật toán bình phương và nhân
        public int RSA_mod(int mx, int ex, int nx)
        {

            //Chuyển e sang hệ nhị phân
            int[] a = new int[100];
            int k = 0;
            do
            {
                a[k] = ex % 2;
                k++;
                ex = ex / 2;
            }
            while (ex != 0);
            //Quá trình lấy dư
            int kq = 1;
            for (int i = k - 1; i >= 0; i--)
            {
                kq = (kq * kq) % nx;
                if (a[i] == 1)
                    kq = (kq * mx) % nx;
            }
            return kq;
        }

        //Thuật toán Euclide mở rộng tìm pt nghịch đảo
        public int EuclideMoRong(int a, int n) // a^-1 mod n
        {
            int r, q, y = 0, y0 = 0, y1 = 1, tmp = n;
            while (a > 0)
            {
                r = n % a;
                q = n / a;
                if (r == 0) break;
                y = y0 - q * y1;
                y0 = y1;
                y1 = y;
                n = a;
                a = r;
            }
            if (a > 1) return -1;          // GCD(a,n) # 1
            if (y >= 0) return y;           //a^-1 mod n = y mod n
            else return y + tmp;     //a^-1 mod n = -y mod n = y+n mod n
        }

        //Random ngẫu nhiên
        private int RSA_ChonSoNgauNhien()
        {
            Random rd = new Random();
            return rd.Next(11, 101);// tốc độ chậm nên chọn số bé
        }
        //--------------------------------------------Ký  văn bản---------------------------------------

        //Chuỗi -> Unicode -> Bình phương và nhân -> Chuỗi mã hoá 
        public string F_MaHoa_RSA(string ChuoiVao1)
        {
            byte[] F_mh_temp1 = Encoding.Unicode.GetBytes(ChuoiVao1);
            string F_base64 = Convert.ToBase64String(F_mh_temp1);
            // Chuyển xâu thành mã Unicode
            int[] F_mh_temp2 = new int[F_base64.Length];
            for (int i = 0; i < F_base64.Length; i++)
            {
                F_mh_temp2[i] = (int)F_base64[i];
            }

            //Mảng a chứa các kí tự đã mã hóa
            int[] F_mh_temp3 = new int[F_mh_temp2.Length];
            for (int i = 0; i < F_mh_temp2.Length; i++)
            {
                // Xử lý bằng thuật toán bình phương và nhân
                F_mh_temp3[i] = RSA_mod(F_mh_temp2[i], RSA_soD, RSA_soN); // mã hóa 
            }

            //Chuyển sang kiểu kí tự trong bảng mã Unicode
            string Fmh_str = "";
            for (int i = 0; i < F_mh_temp3.Length; i++)
            {
                Fmh_str += (char)F_mh_temp3[i];
            }

            byte[] Fmh_data = Encoding.Unicode.GetBytes(Fmh_str);
            string F_ChuoiVBkemChuky = string.Empty;
            F_ChuoiVBkemChuky = Convert.ToBase64String(Fmh_data);

            // Dạng mã ASCII
            //byte[] Fmh_data = Encoding.Unicode.GetBytes(Fmh_str);
            //string F_ChuoiVBkemChuky = Convert.ToBase64String(Fmh_data); // chuỗi mã hóa Base64

            //// Chuyển chuỗi Base64 về dạng số
            //byte[] asciiBytes = Encoding.ASCII.GetBytes(F_ChuoiVBkemChuky);
            //string F_SoVBkemChuky = string.Join("", asciiBytes);



            //return F_SoVBkemChuky;
            return F_ChuoiVBkemChuky;
        }

        // Hàm giải mã
        public string F_GiaiMa_RSA(string F_ChuoiVao2)
        {
            byte[] Fgm_temp1 = Convert.FromBase64String(F_ChuoiVao2);       //convert chuoi -> mang byte
            string Fgm_giaima = Encoding.Unicode.GetString(Fgm_temp1);


            int[] Fgm_temp2 = new int[Fgm_giaima.Length];
            for (int i = 0; i < Fgm_giaima.Length; i++)
            {
                Fgm_temp2[i] = (int)Fgm_giaima[i];
            }
            //Giải mã
            int[] Fgm_temp3 = new int[Fgm_temp2.Length];
            for (int i = 0; i < Fgm_temp3.Length; i++)
            {
                Fgm_temp3[i] = RSA_mod(Fgm_temp2[i], RSA_soE, RSA_soN);// giải mã
            }

            string Fgm_str2 = "";
            for (int i = 0; i < Fgm_temp3.Length; i++)
            {
                Fgm_str2 = Fgm_str2 + (char)Fgm_temp3[i];
            }
            byte[] F_gm_data2 = Convert.FromBase64String(Fgm_str2);

            string F_GM_ChuoiVBkemChuky = string.Empty;
            F_GM_ChuoiVBkemChuky = Encoding.Unicode.GetString(F_gm_data2);
            return F_GM_ChuoiVBkemChuky;
        }

        private void txt_vanBanKy_TextChanged(object sender, TextChangedEventArgs e)
        {
            check = 1;
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            txt_hamBam.IsEnabled = false;
            txt_chuKy.IsEnabled = false;
            So_E.IsReadOnly = true;
            So_D.IsReadOnly = true;
            So_N.IsReadOnly = true;
            So_N_copy.IsReadOnly = true;
        }
        // Đọc file word
        private string readFileContent(string path)
        {
            Microsoft.Office.Interop.Word.Application wordApp = new Microsoft.Office.Interop.Word.Application();// Khởi tạo ứng dụng Word
            object file = path;//khai bao Đường dẫn file
            object nullobj = System.Reflection.Missing.Value;// Đối tượng null sử dụng cho các tham số không sử dụng

            Microsoft.Office.Interop.Word.Document doc = wordApp.Documents.Open(
                ref file, ref nullobj, ref nullobj,
                ref nullobj, ref nullobj, ref nullobj,
                ref nullobj, ref nullobj, ref nullobj,
                ref nullobj, ref nullobj, ref nullobj);// Mở file Word

            doc.ActiveWindow.Selection.WholeStory();// Chọn toàn bộ nội dung trong file
            doc.ActiveWindow.Selection.Copy();// Sao chép nội dung đã chọn vào clipboard

            IDataObject data = Clipboard.GetDataObject();// Lấy dữ liệu từ clipboard
            doc.Close(ref nullobj, ref nullobj, ref nullobj);// Đóng tài liệu Word
            wordApp.Quit(ref nullobj, ref nullobj, ref nullobj);// Thoát khỏi ứng dụng Word
            return data.GetData(DataFormats.UnicodeText).ToString();// Trả về nội dung file dưới dạng chuỗi Unicode
        }
        // Đọc file văn bản
        private void btn_taiVanBan_Click(object sender, EventArgs e)
        {
            try
            {
                OpenFileDialog openFileDialog = new OpenFileDialog();//khai bao mo file
                openFileDialog.InitialDirectory = "D:\\";
                if (openFileDialog.ShowDialog() == true)//hien thi file va kiem tra nguoi dung da chon file hay chua
                {
                    fileNameCanKi = openFileDialog.FileName;//lay duong dan file da chon
                    if (fileNameCanKi.EndsWith(".docx", StringComparison.OrdinalIgnoreCase)) // kiểm tra nếu là file docx
                    {
                        MessageBox.Show("Không cho phép nhập file có định dạng .docx", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Warning);
                    } 
                    else //neu khong phai file doc 
                    {
                        FileStream fsFileDaoVao = new FileStream(openFileDialog.FileName, FileMode.Open);//mở filestream 
                        StreamReader fr = new StreamReader(fsFileDaoVao);//khoi tao streamreader de doc file
                        txt_vanBanKy.Text = fr.ReadToEnd();//doc toan bo van ban va gan vao hop van ban
                        fr.Close();
                    }
                    check = 0;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "thong bao", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        //Thực hiện Ký
        private void btn_Ky_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                // thực hiên ký
                if (F_rsa_d_dau != 1)
                {
                    MessageBox.Show("Bạn chưa tạo chữ ký", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                }
                else
                {
                    byte mk = byte.Parse("111");
                    if (txt_vanBanKy.Text == string.Empty)
                    {

                        MessageBox.Show("Bạn chưa chọn file thực hiện ký!", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                    }
                    else
                    {
                        MD5 md5 = MD5.Create();
                        byte[] FileVBKy_temp1;
                        if (check == 0)
                        {
                            FileStream fsFileDauVao = new FileStream(fileNameCanKi, FileMode.Open);
                            FileVBKy_temp1 = md5.ComputeHash(fsFileDauVao);
                            fsFileDauVao.Close();
                            fsFileDauVao.Dispose();
                        }
                        else
                        {
                            FileVBKy_temp1 = md5.ComputeHash(new UTF8Encoding().GetBytes(txt_vanBanKy.Text));
                        }

                        //StringBuilder hash = new StringBuilder();
                        string hash = string.Empty;
                        for (int i = 0; i < FileVBKy_temp1.Length; i++)
                        {
                            //hash.Append(FileVBKy_temp1[i].ToString("x2"));
                            hash += FileVBKy_temp1[i].ToString("x2");
                        }
                        txt_hamBam.Text = hash.ToString();
                        string FileVBKy = Convert.ToBase64String(FileVBKy_temp1);
                        txt_chuKy.Text = F_MaHoa_RSA(FileVBKy);

                        F_rsa_d_dau = 2;
                        MessageBox.Show("Thực hiện ký thành công !", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                        txt_hamBam.IsEnabled = txt_chuKy.IsEnabled = false;
                        btn_Ky.IsEnabled = btn_taiVanBan.IsEnabled = false;

                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        private void btn_luuChuKy_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                if (txt_chuKy.Text == string.Empty)// Kiểm tra nếu text box chứa chữ ký trống
                    MessageBox.Show("Bạn chưa tạo chữ ký", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                else
                {
                    SaveFileDialog saveFile = new SaveFileDialog(); // Tạo đối tượng SaveFileDialog
                    if (saveFile.ShowDialog() == true)
                    {

                        File.WriteAllText(saveFile.FileName, txt_chuKy.Text);// Ghi nội dung chữ ký vào file

                    }

                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }
        //---------------------------------------------------------------Xác thực chữ ký------------------------------------------
        //Phần 3
        // Tải văn bản xác nhận
        private void btn_taiVanBanXacNhan_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                OpenFileDialog openFileDialog = new OpenFileDialog();
                openFileDialog.InitialDirectory = "C:\\";
                if (openFileDialog.ShowDialog() == true)
                {
                    fileNameKiemTra = openFileDialog.FileName;
                    if (fileNameKiemTra.Contains(".docx"))
                        TextNoiDungVBCanKiemTra.Text = readFileContent(fileNameKiemTra);
                    else
                    {
                        FileStream fsFileKiemTra = new FileStream(openFileDialog.FileName, FileMode.Open);
                        StreamReader fr = new StreamReader(fsFileKiemTra);
                        TextNoiDungVBCanKiemTra.Text = fr.ReadToEnd();
                        fr.Close();
                    }
                    
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        // Tải chữ ký xác nhận
        private void btn_taiChuKyXacNhan_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                OpenFileDialog openFileDialog = new OpenFileDialog();
                openFileDialog.InitialDirectory = "C:\\"; 
                if (openFileDialog.ShowDialog() == true)
                {
                    FileStream FileTaiChuKi = new FileStream(openFileDialog.FileName, FileMode.Open, FileAccess.Read);
                    StreamReader fr = new StreamReader(FileTaiChuKi);
                    TextChuKiXacNhan.Text = fr.ReadToEnd();
                    fr.Close();
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        // Xác nhận chữ ký
        private void btn_xacNhan_Click(object sender, RoutedEventArgs e)
        {

            try     //Kiểm tra nội dung văn bản
            {
                if (F_rsa_d_dau == 2)   //Xử lý ngoại lệ
                {
                    if (TextNoiDungVBCanKiemTra.Text == string.Empty)
                        throw new Exception("Bạn chưa chọn Tài liệu kiểm tra chữ ký");
                    else if (TextChuKiXacNhan.Text == String.Empty)
                        throw new Exception("Bạn chưa tải chữ ký lên");
                    else if (E_xacThuc.Text == String.Empty || N_xacThuc.Text == string.Empty)
                        throw new Exception("Bạn chưa nhập đủ E & N");
                    else
                    {
                        if (int.Parse(E_xacThuc.Text) != RSA_soE || int.Parse(N_xacThuc.Text) != RSA_soN)
                            throw new Exception("E & N không chính xác");
                        else if (TextChuKiXacNhan.Text != txt_chuKy.Text)
                            throw new Exception("Chữ ký đã bị thay đổi");
                        else
                        {
                            MD5 md5 = MD5.Create(); //Tạo hàm băm md5
                            byte[] FileVBKy_temp2;
                            if (check == 0)     // Văn bản được tải
                            {
                                FileStream fsFileDauVao = new FileStream(fileNameKiemTra, FileMode.Open);
                                FileVBKy_temp2 = md5.ComputeHash(fsFileDauVao);
                                fsFileDauVao.Close();
                                fsFileDauVao.Dispose();
                            }
                            else
                            {
                                FileVBKy_temp2 = md5.ComputeHash(new UTF8Encoding().GetBytes(TextNoiDungVBCanKiemTra.Text));
                            }
                            string ChuoiVBdiKem = Convert.ToBase64String(FileVBKy_temp2);
                            string VBKemChuKyGM = F_GiaiMa_RSA(TextChuKiXacNhan.Text); // Thực hiện giải mã chữ ký

                            int result = 0;
                            result = string.Compare(VBKemChuKyGM, ChuoiVBdiKem, true);

                            if (result == 0)
                            {
                                MessageBox.Show("Chữ ký đúng!", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Information);
                            }
                            else
                            {
                                MessageBox.Show("Chữ ký sai!", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                            }
                        }
                    }
                }
                else
                {
                    MessageBox.Show("Chưa thực hiện ký và gửi file ký", "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Thông báo", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        //----------------------------------------Thoát chương trình-------------------------------------------
        // Xử lý thoát
        //Thoát tạo khoá
        private void btn_Thoat_Click(object sender, RoutedEventArgs e)
        {


            if (MessageBox.Show("Xác nhận thoát?", "Thông báo", MessageBoxButton.YesNo) == MessageBoxResult.Yes)
            {
                App.Current.Shutdown();
            }
        }
        //Thoát ký văn bản
        private void btn_Thoat2_Click(object sender, RoutedEventArgs e)
        {
            if (MessageBox.Show("Xác nhận thoát?", "Thông báo", MessageBoxButton.YesNo) == MessageBoxResult.Yes)
            {
                App.Current.Shutdown();
            }
        }
        //Thoát xác nhận chữ ký
        private void btn_Thoat3_Click(object sender, RoutedEventArgs e)
        {
            if (MessageBox.Show("Xác nhận thoát?", "Thông báo", MessageBoxButton.YesNo) == MessageBoxResult.Yes)
            {
                App.Current.Shutdown();
            }
        }

        //Kết thúc chương trình
    }//Ngoặc Main

}//Ngoặc namespace