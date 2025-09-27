#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <iomanip>
using namespace std;
const int MAX_NhanVien = 500;
struct VatTu{
    char MAVT[11];
    char TENVT[51];
    char DVT[11];
    int SoLuongTon;
    int height;
};

struct nodeVT {
    VatTu vt;
    nodeVT *left, *right;
};
typedef nodeVT* treeVT;

struct CT_HoaDon {
    char MAVT[21];
    int soluong;
    char DONGIA[21];
    int VAT;
};

struct nodeCTHD{
    CT_HoaDon cthd;
    nodeCTHD* next;
};
typedef nodeCTHD* PTRCTHD;
struct Date {
	int day, month, year;
};
enum type {N,X};
struct HoaDon {
    char SoHD[21];
    Date NgayLapHoaDon;
    type Loai;
    PTRCTHD dscthd = NULL;
};

struct nodeHD {
    HoaDon hd;
    nodeHD* next;
};
typedef nodeHD* PTRHD;


struct NhanVien {
    char MANV[11];
    char HO[51];
    char TEN[51];
    char PHAI[51];
    PTRHD dshd =NULL;
};
struct DSNV{
    int n=0;
    NhanVien*nodes[MAX_NhanVien];
};



//Vat Tu
treeVT CreateNodeVT(VatTu vt);{
    treeVT p=new nodeVT;
    p->vt=vt;
    p->lèft =p->right =Null;
    p
}
void ThemVatTu(treeVT &root, VatTu vt);
bool XoaVatTu(treeVT &root, char maVT[]);
void SuaThongTinVatTu(treeVT &root, VatTu vt);
VatTu* TimVatTu(treeVT root, char maVT[]){
    if (root == NULL) return NULL;
    int cmp = strcmp(maVT, root->vt.MAVT);
    if (cmp == 0) return &root->vt;
    else if (cmp < 0) return TimVatTu(root->left, maVT);
    else return TimVatTu(root->right, maVT);
};
void DuyetVatTuTangDan(treeVT root);
void InThongTinVatTu(VatTu vt);



//Nhan Vien
bool ThemNhanVien(DSNV &ds, NhanVien* nv);
bool XoaNhanVien(DSNV &ds, char maNV[]);
NhanVien* TimNhanVien(DSNV ds, char maNV[]);
void SuaThongTinNhanVien(DSNV &ds, NhanVien* nv);
void InDanhSachNhanVien(DSNV ds);



//Hoa Don
HoaDon* TaoHoaDon(char soHD[], Date ngay, type loai);
bool ThemHoaDon(PTRHD &first, HoaDon hd);
HoaDon* TimHoaDon(PTRHD first, char soHD[]);
void InDanhSachHoaDon(PTRHD first);



//Chi Tiet Hoa Don
CT_HoaDon TaoCTHD(char maVT[], int soluong, char dongia[], int VAT);
bool ThemCTHD(PTRCTHD &first, CT_HoaDon cthd);
void InDanhSachCTHD(PTRCTHD first);
double TinhTriGiaHoaDon(PTRCTHD first);



//Xu Ly Ton Kho
bool KiemTraXuatHang(treeVT root, char maVT[], int soluong);
void CapNhatTonKho(treeVT &root, PTRCTHD dscthd, type loai);



//Thong Ke Bao Cao
void LietKeHoaDonTrongKhoangTG(DSNV ds, Date tuNgay, Date denNgay);
void Top10VatTuDoanhThuCaoNhat(DSNV ds, treeVT root, Date tuNgay, Date denNgay);
void ThongKeDoanhThuTheoThang(DSNV ds, int nam);



//File I/0
void GhiDSNVRaFile(DSNV ds, string filename);
void DocDSNVTuFile(DSNV &ds, string filename);

void GhiVTRaFile(treeVT root, string filename);
void DocVTTuFile(treeVT &root, string filename);

void GhiHDRaFile(DSNV ds, string filename);
void DocHDTuFile(DSNV &ds, string filename);



//Tien ich
bool TrungMAVT(treeVT root, char maVT[]);
bool TrungMANV(DSNV ds, char maNV[]);
int SoSanhNgay(Date d1, Date d2); // -1, 0, 1
bool NgayHopLe(Date d);
Date NhapNgay();


int main(){
    treeVT dsvt=NULL;
    DSNV dsnv;

}