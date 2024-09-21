using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace thu_btl
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
            rb_tdRSA.IsChecked = true;
            rb_tcRSA.IsChecked = false;
        }

        int RSA_soP, RSA_soQ, RSA_soN, RSA_soE, RSA_soD, RSA_soPhi_n;
        //int F_rsa_d_dau = 0; //đánh dấu kiểm tra đã tạo khóa và ký chưa 
        int check = 0;//0:tai file | 1: nhap tay
        string fileNameCanKi = "";
        string fileNameKiemTra = "";

        private void btn_TaoKhoa_Click(object sender, RoutedEventArgs e)
        {
            if (rb_tdRSA.IsChecked == true && rb_tcRSA.IsChecked == false)
            {
                reset_rsa();
                RSA_soP = RSA_soQ = 0;
                do
                {
                    RSA_soP = RSA_ChonSoNgauNhien();
                    RSA_soQ = RSA_ChonSoNgauNhien();
                } while (RSA_soP == RSA_soQ || !RSA_kiemTraNguyenTo(RSA_soP) || RSA_kiemTraNguyenTo(RSA_soQ));

                So_P.Text = RSA_soP.ToString();
                So_Q.Text = RSA_soQ.ToString();




            }
        }

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

        private int RSA_ChonSoNgauNhien()
        {
            Random rd = new Random();
            return rd.Next(11, 101);//tốc độ chậm nên chọn số bé
        }

        private bool RSA_kiemTraNguyenTo(int xi)
        {
            bool kiemtra = true;
            if (xi == 2 || xi == 3)
            {
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
                    for (int i = 5; i < Math.Sqrt(xi); i = i + 6)
                    {
                        if (xi % i == 0 || xi % (i + 2) == 0)
                        {
                            kiemtra = false;
                            break;
                        }
                    }
                }
            }
            return kiemtra;
        }

        private void RSA_taokhoa()
        {
            //tinh n=p*q
            RSA_soN = RSA_soP * RSA_soQ;
            So_N.Text = RSA_soN.ToString();
            So_N_copy.Text = RSA_soN.ToString();
            //tinh Phi(n)=(p-1)*(q-1)
            RSA_soPhi_n = (RSA_soP - 1) * (RSA_soQ - 1);
            So_O_le.Text = RSA_soPhi_n.ToString();

            //tinh e la so rnadom co gia tri 0<e<Phi(n)
            do
            {
                Random RSA_rd = new Random();
                RSA_soE = RSA_rd.Next(2, RSA_soPhi_n);
            } while (!nguyenToCungNhau(RSA_soE, RSA_soPhi_n));
            So_E.Text = RSA_soE.ToString();

            RSA_soD = EuclidMoRong(RSA_soE, RSA_soPhi_n);
            So_D.Text = RSA_soD.ToString();

        }

        public bool nguyenToCungNhau(int ai, int bi)
        {
            bool ktx_;
            //giai thuat Euclid
            int temp;
            while (bi != 0)
            {
                temp = ai % bi;
                ai = bi;
                bi = temp;
            }
            if (ai == 1)
            {
                ktx_ = true;
            } else ktx_ = false;
            return ktx_;
        }

        public int EuclidMoRong(int a, int n)
        {
            int r, q, y = 0, y0 = 0, y1 = 1, tmp = n;
            while (a > 0) {
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
            else return y + tmp;
        }
    }
}