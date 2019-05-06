#include "Statistic.h"
#include "Book.h"
/*
-----------------HAM MO MENU THONG KE-----------------
+)CHUC NANG: XUAT THONG TIN 1 DOC GIA
+)Input	:
-	So sach dang muon
-	So doc gia
-	So sach
-	Mang kieu READER
-	Mang kieu BOOK
+)Output:
*/
void MenuStatistic(int BOOKBORROW,int RNUM,int BNUM,READER reader[MREADER],BOOK book[MBOOK])
{
	char chon;
	int kq;
	while (true)
	{
		system("cls");
		cout << "============>       MENU THONG KE      <============" << endl;
		cout << "[0]. Ve menu quan li thu vien" << endl;
		cout << "[1]. Thong ke so luong sach trong thu vien" << endl;
		cout << "[2]. Thong ke so luong sach theo the loai" << endl;
		cout << "[3]. Thong ke so luong doc gia" << endl;
		cout << "[4]. Thong ke so luong doc gia theo gioi tinh" << endl;
		cout << "[5]. Thong ke so luong sach dang duoc muon" << endl;
		cout << "[6]. Thong ke danh sach doc gia tre han" << endl;
		cout << "====================================================" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (chon == '0')
		{
			system("cls");
			break;
		}
		switch (chon)
		{
		case '1':
			cout << "SO LUONG SACH TRONG THU VIEN: "<< NumberOfBook(BNUM,book)  << endl;
			system("pause");
			break;
		case '2':
			StaNumType(BNUM,book);
			system("pause");
			break;
		case '3':
			cout << "SO LUONG DOC GIA: " << RNUM << endl;
			system("pause");
			break;
		case '4':
			cout << "THONG KE THEO GIOI TINH: " << endl;
			NumPerSex(RNUM, reader);
			system("pause");
			break;
		case '5':
			cout << "SO LUONG SACH DANG DUOC MUON : " << BOOKBORROW << endl;
			system("pause");
			break;
		case '6':
			 NumLate(RNUM,reader);
			system("pause");
			break;
		default:
			cout << CHUCNANGSAI << endl;
			system("pause");
			break;
		}
	}
}
/*
-----------------HAM DEM SO THE LOAI SACH-----------------
+)CHUC NANG: DEM SO THE LOAI SACH
+)Input	:
-	So sach
-	Mang kieu BOOK
-	string array temp (luu cac the loai khac nhau)
+)Output:
-	SO THE LOAI
*/
int NumOfType(int BNUM,BOOK book[MBOOK],string temp[MBOOK])
{
	int count = 0;
	for (int i = 0; i < BNUM; i++)
	{
		int flag = 0;
		for (int j = 0; j < i; j++)
		{
			if (book[i].Btype == book[j].Btype)
			{
				flag = 1;
				break;
			}
				
		}
		if (flag == 0)
		{
			temp[count] = book[i].Btype ;
			count++;
		}
	}
	return count;
}
/*
-----------------HAM DEM SO LUONG MOI THE LOAI SACH-----------------
+)CHUC NANG: DEM SO LUONG MOI THE LOAI SACH
+)Input	:
-	So sach
-	So the loai
-	string array temp (luu cac the loai khac nhau)
-	int array NumTemp (luu so luong cac the loai khac nhau)
+)Output:
*/
void NumBookPerType(int BNUM, int KNUM, BOOK book[MBOOK], string temp[MBOOK],int NumTemp[MBOOK])
{
	for (int i = 0; i < KNUM; i++)
	{
		NumTemp[i] = 0;
		for (int j = 0; j < BNUM; j++)
		{
			if (temp[i] == book[j].Btype)
				NumTemp[i] = NumTemp[i] + book[j].Bnum;
		}
	}
}
/*
-----------------HAM THONG KE SO LUONG SACH THEO THE LOAI-----------------
+)CHUC NANG: THONG KE SO LUONG SACH THEO THE LOAI
+)Input	:
-	So sach
-	Mang kieu BOOK
+)Output:
-	DANH SACH THE LOAI VA SO LUONG
*/
void StaNumType(int BNUM, BOOK book[MBOOK])
{
	string temp[MBOOK];
	int NumTemp[MBOOK];
	int KNUM = NumOfType(BNUM, book, temp);
	NumBookPerType(BNUM, KNUM, book, temp, NumTemp);
	cout << "************SO LUONG SACH THEO THE LOAI************" << endl;
	cout << setw(30) << left << "The Loai" << setw(15) << "So Luong" << endl;
	for (int i = 0; i < KNUM; i++)
	{
		cout << setw(30) << left << temp[i] << setw(15) << NumTemp[i] << endl;
	}
	cout << "****************************************************" << endl;
}
/*
-----------------HAM THONG KE DOC GIA THEO GIOI TINH-----------------
+)CHUC NANG: THONG KE DOC GIA THEO GIOI TINH
+)Input	:
-	So doc gia
-	Mang kieu READER
+)Output:
-	SO LUONG DOC GIA THEO GIOI TINH
*/
void NumPerSex(int RNUM, READER reader[MREADER])
{
	int demnam = 0;
	int demnu = 0;
	for (int i = 0; i < RNUM; i++)
	{
		if (reader[i].Rsex == "NAM")
			demnam++;
		if (reader[i].Rsex == "NU")
			demnu++;
	}
	cout << "NAM: " << demnam << " doc gia" << endl;
	cout << "NU: " << demnu << " doc gia" << endl;
}
/*
-----------------HAM THONG KE DOC GIA TRE HAN-----------------
+)CHUC NANG: THONG KE DOC GIA TRE HAN
+)Input	:
-	So doc gia
-	Mang kieu READER
+)Output:
-	DANH SACH DOC GIA TRE HAN
*/
void NumLate(int RNUM,READER reader[MREADER])
{
	int dem = 0;
	cout << "\n*****DANH SACH CAC DOC GIA TRE HAN*****" << endl;
	cout << setw(15) << left << "MaDG" << setw(20) << "Ten doc gia" << endl;
	for (int i = 0; i < RNUM; i++)
	{
		if (reader[i].Late == 1)
		{
			dem++;
			cout << setw(15) << left << reader[i].Rcode << setw(20) << reader[i].Rname << endl;
		}
	}
	cout << "***************************************" << endl;
	cout << "CO " << dem << " DOC GIA TRE HAN " << endl;
}