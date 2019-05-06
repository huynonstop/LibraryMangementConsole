#include "Header.h"
/******************************CAC HAM TRO GIUP TRONG CHUONG TRINH******************************/
void loading()
{
	for (int i = 1; i <= 20; i++)
	{
		system("cls");
		cout << "  |********************************************************************|" << endl;
		cout << "  |------------------------>   LOADING " << i*5 << " %   <------------------------|" << endl;
		cout << "  |********************************************************************|" << endl;
	}
}
/*----------------------------------------DATE-----------------------------------------------*/

/*
-----------------HAM KIEM TRA NGAY THANG NAM-----------------
+)CHUC NANG: kiem tra ngay thang nam co hop le khong
+)Input	:
-	Ngay, thang, nam

+)Output:
-	1 ngay thang nam hop le
-	0 ngay thang nam khong hop le	
*/
bool checkngaythangnam(DATE a)
{
	int ngaynhuan[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	int ngaybt[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	bool nhuan = 0;
	if ((a.year % 4 == 0 && a.year % 100 != 0) || (a.year % 400 == 0)) nhuan = 1;
	if (a.month <= 0 || a.month > 12) return 0;
	if (nhuan == 1)
	{
		if (a.day <= 0 || a.day > ngaynhuan[a.month - 1]) return 0;
	}
	else
	{
		if (a.day <= 0 || a.day > ngaybt[a.month - 1]) return 0;
	}
	return 1;
}
/*
-----------------HAM TRA VE SO NGAY TRONG NAM-----------------
+)CHUC NANG:
+)Input	:
-	Nam
+)Output:
-	366 so ngay nam nhuan
-	365 so ngay nam thuong
*/
int ngaynam(int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) return 366;
	else return 365;
}
/*
-----------------HAM TRA VE SO NGAY TRONG THANG-----------------
+)CHUC NANG:
+)INPUT	:
-	Thang, nam
+)OUTPUT:
-	So ngay trong thang
*/
int ngaythang(int thang, int nam)
{
	switch (thang)
	{
	case 4:  return 30;
	case 6:  return 30;
	case 9:  return 30;
	case 11: return 30;
	case 2:
		if (ngaynam(nam) == 366) return 28;
		else return 29;
	default: return 31;
	}
}
/*
-----------------HAM TINH SO NGAY KE TU NGAY DAU NAM-----------------
+)CHUC NANG:
+)INPUT	:
-	Ngay, thang, nam
+)OUTPUT:
-	Ngay bao nhieu trong nam
*/
int vitringaytrongnam(DATE a)
{
	int N = 0, i;
	for (i = 1; i<a.month; ++i)
	{
		N = N + ngaythang(i, a.year);
	}
	return (N + a.day);
}
/*
-----------------HAM TINH SO NGAY GIUA 2 NAM-----------------
+)CHUC NANG:
+)INPUT	:
-	Nam truoc, Nam sau
+)OUTPUT:
-	So ngay giua hai nam
*/
int kcnam(int namtruoc, int namsau)
{
	int N = 0, i;
	i = namtruoc;
	for (i; i<namsau; ++i)
	{
		N = N + ngaynam(i);
	}
	return N;
}
/*
-----------------HAM TINH SO NGAY CHENH LECH-----------------
+)CHUC NANG:
+)INPUT	:
-	Ngay thang nam thu nhat, ngay thang nam thu hai
+)OUTPUT:
-	So ngay chenh lech
-	Neu ngay thang nam khong hop le thi tra ve -1
*/
int ngaychenhlech(DATE a,DATE b)
{
	if (checkngaythangnam(a) == 1 && checkngaythangnam(b) == 1)
		return kcnam(a.year, b.year) + vitringaytrongnam(b) - vitringaytrongnam(a);
	else
		return -1;
}
/*
-----------------HAM NHAP NGAY THANG NAM-----------------
+)CHUC NANG:
+)INPUT	:
+)OUTPUT:
*/
void ScanDATE(DATE &a)
{
	int flag = 1;
	while (flag == 1)
	{
		cout << "++)Nhap ngay : ";
		cin >> a.day;
		if (cin.fail())
		{
			cin.clear();// xoa trang thai ham cin
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//xoa ki tu trong bo nho tam
			flag = 2;
		}
		cout << "++)Nhap thang : ";
		cin >> a.month;
		if (cin.fail())
		{
			cin.clear();// xoa trang thai ham cin
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//xoa ki tu trong bo nho tam
			flag = 2;
		}
		cout << "++)Nhap nam : ";
		cin >> a.year;
		if (cin.fail())
		{
			cin.clear();// xoa trang thai ham cin
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//xoa ki tu trong bo nho tam
			flag = 2;
		}
		if (flag == 2)
		{
			cout << "Ngay thang nam khong hop le. Moi nhap lai !!!" << endl;
			flag = 1;
			continue;
		}
		cin.ignore();//getchar();
		if (checkngaythangnam(a) == 1) flag = 0;
		else cout << "Ngay thang nam khong hop le. Moi nhap lai !!!" << endl;
	}
}
/*
-----------------HAM XUAT NGAY THANG NAM THEO DINH DANG-----------------
+)CHUC NANG:
+)INPUT	:
+)OUTPUT:
*/
void Date(DATE a)
{
	cout << a.day << "/" << a.month << "/" << a.year << endl;
}

/*----------------------------------------STRING-----------------------------------------------*/

/*
-----------------HAM DINH DANG CHU-----------------
+)CHUC NANG: chuyen chu thuong thanh in hoa
+)INPUT	:
-	string can chuyen
+)OUTPUT:
-
*/
void dinhdangchu(string &a)
{
	for (int i = 0; i< a.size(); i++)
	{
		if (a[i] <= 'z'&&a[i] >= 'a') a[i] = a[i] - 32;
	}
}

/*----------------------------------------INT-----------------------------------------------*/

/*
-----------------HAM DEM SO SACH TRONG KHO-----------------
+)CHUC NANG: DEM SO SACH TRONG KHO
+)Input	:
-	So sach
-	Mang kieu BOOK
+)Output:
-	SO SACH TRONG KHO
*/
int NumberOfBook(int BNUM, BOOK book[MBOOK])
{
	int s = 0;
	for (int i = 0; i < BNUM; i++)
	{
		s = s + book[i].Bnum;
	}
	return s;
}