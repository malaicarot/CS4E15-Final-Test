#include <iostream>
#include <string>

using namespace std;

/*Lop Ve May Bay*/
class VeMayBay
{
private:
    string tenChuyen;
    int giaVe, ngay, thang, nam;

public:
    // Getter
    int getGiaVe();

    // Ham Tao
    VeMayBay(string _tenChuyen = "HaNoi", int _ngay = 10, int _thang = 11, int _nam = 2023, int _giaVe = 4000000);

    // Ham Nhap - Xuat
    void enterTicket()
    {
        cout << "Nhap Thong Tin Ve" << endl;
        cout << "Ten Chuyen: ";
        getline(cin, tenChuyen);
        cout << "Ngay Bay" << endl;
        cout << "Ngay: ";
        cin >> ngay;
        cout << "Thang: ";
        cin >> thang;
        cout << "Nam: ";
        cin >> nam;
        cout << "Gia Ve: ";
        cin >> giaVe;
        cin.ignore();
    }
    void exportTicket()
    {
        cout << "*Thong Tin Ve" << endl;
        cout << "Ten Chuyen: " << tenChuyen << endl;
        cout << "Ngay Bay: " << ngay << "/" << thang << "/" << nam << endl;
        cout << "Gia Ve: " << giaVe << endl;
    }

    // Ham Huy
    ~VeMayBay();
};

VeMayBay::VeMayBay(string _tenChuyen, int _ngay, int _thang, int _nam, int _giaVe)
{
    tenChuyen = _tenChuyen;
    ngay = _ngay;
    thang = _thang;
    nam = _nam;
    giaVe = _giaVe;
}

VeMayBay::~VeMayBay()
{
    tenChuyen = "";
    ngay = 0;
    thang = 0;
    nam = 0;
    giaVe = 0;
}

int VeMayBay::getGiaVe()
{
    return this->giaVe;
}

/*Lop Nguoi*/
class Nguoi
{
private:
    string hoTen, gioiTinh;
    int tuoi;

public:
    // Ham tao
    Nguoi(string _hoTen = "Pham Anh Khoa", string _gioiTinh = "Nam", int _tuoi = 19);

    // Ham Nhap - Xuat
    void enterInfor()
    {
        cout << "Ho Ten: ";
        getline(cin, hoTen);
        cout << "Gioi Tinh: ";
        getline(cin, gioiTinh);
        cout << "Tuoi: ";
        cin >> tuoi;
    }
    void exportInfor()
    {
        cout << "*Thong Tin Ca Nhan" << endl;
        cout << "Ho Ten: " << hoTen << endl;
        cout << "Gioi Tinh: " << gioiTinh << endl;
        cout << "Tuoi: " << tuoi << endl;
    }

    // Ham Huy
    ~Nguoi();
};

Nguoi::Nguoi(string _hoTen, string _gioiTinh, int _tuoi)
{
    hoTen = _hoTen;
    gioiTinh = _gioiTinh;
    tuoi = _tuoi;
}

Nguoi::~Nguoi()
{
    hoTen = "";
    gioiTinh = "";
    tuoi = 0;
}

/*Lop Hanh Khach*/
class HanhKhach : public Nguoi
{
private:
    int soLuong;
    VeMayBay ve[100];

public:
    // Ham Tao
    HanhKhach()
    {
        soLuong = this->soLuong;
        ve[soLuong];
    }

    // Ham Nhap - Xuat
    void enterPassenger()
    {
        Nguoi ::enterInfor();
        cout << "Nhap So Luong ve: ";
        cin >> soLuong;
        ve[soLuong];
        cin.ignore();
        for (int i = 0; i < soLuong; i++)
        {
            ve[i].enterTicket();
        }
    }
    void exportPassenger()
    {
        Nguoi ::exportInfor();
        for (int i = 0; i < soLuong; i++)
        {
            ve[i].exportTicket();
        }
        cout << "-----> Tong Tien: " << tongTien() << endl;
    }
    // Ham Xu Ly
    int tongTien()
    {
        int tongTien = 0;
        for (int i = 0; i < soLuong; i++)
        {
            tongTien += ve[i].getGiaVe();
        }
        return tongTien;
    }

    bool operator<(HanhKhach p)
    {
        if (tongTien() < p.tongTien())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // Ham Huy
    ~HanhKhach();
};

HanhKhach::~HanhKhach()
{
    soLuong = 0;
    ve[0];
}

/*Sap xep theo chieu giam dan cua tong tien*/
// Bubble Sort
void sortZToA(HanhKhach a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    HanhKhach *arr = new HanhKhach[n];

    for (int i = 0; i < n; i++)
    {
        cout << "-------Nhap Thong Tin Hanh Khach " << i + 1 << " -------" << endl;
        arr[i].enterPassenger();
    }

    cout << "-------OUTPUT-------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "-------Thong Tin Hanh Khach " << i + 1 << " -------" << endl;
        arr[i].exportPassenger();
    }

    cout << "-------SORTED-------" << endl;
    sortZToA(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << "-------Thong Tin Hanh Khach " << i + 1 << " -------" << endl;
        arr[i].exportPassenger();
    }

    return 0;
}