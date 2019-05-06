#ifndef _HEADER_ //Cac thu vien, hang va cac ham tro giup tinh toan trong chuong trinh
#define _HEADER_
#define MBOOK 100
#define MBOOKB 3
#define MREADER 100
#define DAYBONHO "CO SO DU LIEU DA DAY !!!"
#define KHONGDOCGIA "\nHIEN KHONG CO DOC GIA TRONG CSDL, VUI LONG CAP NHAT THEM !!!"
#define KHONGSACH "\nHIEN KHONG CO SACH TRONG CSDL, VUI LONG CAP NHAT THEM !!!"
#define KHONGTONTAIKT "\nKHONG TON TAI, VUI LONG KIEM TRA LAI !!!"
#define CHUCNANGSAI "CHON CHUC NANG SAI. HAY CHON LAI !!!"
#include<string>
#include<iostream>
#include<iomanip>
#include<fstream>
#include"DataStructure.h"
using namespace std;
bool checkngaythangnam(DATE a);
void dinhdangchu(string &a);
int ngaynam(int nam);
int ngaythang(int thang, int nam);
int vitringaytrongnam(DATE a);
int kcnam(int namtruoc, int namsau);
int ngaychenhlech(DATE a, DATE b);
void ScanDATE(DATE &a);
void Date(DATE a);
int NumberOfBook(int BNUM, BOOK book[MBOOK]);
void loading();
#endif // !_HEADER_