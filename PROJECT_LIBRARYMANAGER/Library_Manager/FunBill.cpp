#include "Bill.h"
/*FILE*/
/*
-----------------HAM LAY THONG TIN PHIEU MUON TU FILE-----------------
+)CHUC NANG: LAY THONG TIN PHIEU MUON TU FILE
+)Input	:
-	Mang kieu BILL
-	Ten file
-	So phieu muon
-	So sach dang muon
+)Output:
*/
void InputBill(BILL bill[MREADER], string file_name, int &BILLNUM,int &BOOKBORROW)
{
	cout << "---------- IMPORTING BILL ----------" << endl;
	ifstream fileR;
	fileR.open(file_name);
	if (!fileR.is_open())
	{
		cout << "Can't open this file." << endl;
		cout << endl;
		return;
	}
	while (!fileR.eof())
	{
		getline(fileR, bill[BILLNUM].Rcode);
		if (fileR.eof()) break;
		fileR >> bill[BILLNUM].DateBorrow.day >> bill[BILLNUM].DateBorrow.month >> bill[BILLNUM].DateBorrow.year;
		fileR >> bill[BILLNUM].DateReturnExpect.day >> bill[BILLNUM].DateReturnExpect.month >> bill[BILLNUM].DateReturnExpect.year;
		fileR >> bill[BILLNUM].NumBorrow;
		for (int i = 0; i < bill[BILLNUM].NumBorrow; i++)
		{
			BOOKBORROW++;
			fileR >> bill[BILLNUM].ISBNBorrow[i];
		}
		fileR.get();
		cout << "Importing bill " << BILLNUM + 1 << endl;
		BILLNUM++;
		if (BILLNUM >= MREADER)
		{
			cout << DAYBONHO << endl;
			break;
		}
	}
	fileR.close();
	cout << "Import successfully." << endl;
}
/*
-----------------HAM XUAT THONG TIN PHIEU MUON RA FILE-----------------
+)CHUC NANG: XUAT THONG TIN PHIEU MUON RA FILE
+)Input	:
-	Mang kieu BILL
-	Ten file
-	So phieu muon
+)Output:
*/
void OutputBill(BILL bill[MREADER], string file_name, int BILLNUM)
{
	cout << "---------- EXPORTING BILL ----------" << endl;
	ofstream fileR;
	fileR.open(file_name);
	for (int i = 0; i < BILLNUM; i++)
	{
		cout << "Exporting bill " << i + 1 << endl;
		fileR << bill[i].Rcode << endl;
		fileR << bill[i].DateBorrow.day << " " << bill[i].DateBorrow.month << " " << bill[i].DateBorrow.year << endl;
		fileR << bill[i].DateReturnExpect.day << " " << bill[i].DateReturnExpect.month << " " << bill[i].DateReturnExpect.year << endl;
		fileR << bill[i].NumBorrow << endl;
		for (int j = 0; j < bill[i].NumBorrow; j++)
		{
			fileR << bill[i].ISBNBorrow[j];
			if (i != BILLNUM - 1 || j!= bill[i].NumBorrow-1) fileR << endl;
		}	
	}
	cout << "Export successfully." << endl;
	fileR.close();
}
/*MENU*/
/*
-----------------HAM MO MENU PHIEU MUON TRA-----------------
+)CHUC NANG: MO MENU PHIEU MUON TRA
+)Input	:
-	So phieu muon
-	So doc gia
-	So sach
-	Mang kieu BILL
-	Mang kieu READER
-	Mang kieu BOOK
-	So sach dang muon
+)Output:
*/
void MenuBill(int &BILLNUM,int RNUM,int BNUM, BILL bill[MREADER],READER reader[MREADER],BOOK book[MBOOK],int &BOOKBORROW)
{
	int flag = 0;
	string tim;
	char chon;
	while (true)
	{
		system("cls");
		cout << "=====>MENU QUAN LI PHIEU MUON VA PHIEU TRA<=====" << endl;
		if (RNUM == 0)
		{
			cout << KHONGDOCGIA << endl;
			flag = 1;
		}
		if (BNUM == 0 || NumberOfBook(BNUM,book) == 0)
		{
			cout << KHONGSACH << endl;
			flag = 1;
		}
		if (flag == 1)
		{
			system("pause");
			break;
		}
		cout << "   [0]. Ve menu quan li thu vien" << endl;
		cout << "   [1]. LAP PHIEU MUON SACH" << endl;
		cout << "   [2]. LAP PHIEU TRA SACH" << endl;
		cout << "Nhap lua chon cua ban: ";
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
		switch (chon)
		{
		case '0':
			system("cls");
			return;
		case '1':
			MenuBorrow(BILLNUM,RNUM,BNUM,bill,reader,book,BOOKBORROW);
			break;
		case '2':
			MenuReturn(BILLNUM,RNUM,BNUM,bill,reader,book,BOOKBORROW);
			break;
		default:
			cout << "Chuc nang khong ton tai vui long chon lai !!!" << endl;
			break;
		}
		system("pause");
	}
}
/*
-----------------HAM MO MENU PHIEU MUON-----------------
+)CHUC NANG: MO MENU PHIEU MUON
+)Input	:
-	So phieu muon
-	So doc gia
-	So sach
-	Mang kieu BILL
-	Mang kieu READER
-	Mang kieu BOOK
-	So sach dang muon
+)Output:
*/
void MenuBorrow(int &BILLNUM, int RNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], int &BOOKBORROW)
{
	cout << "\n=======>LAP PHIEU MUON<=======" << endl;
	if (NumberOfBook(BNUM, book) == 0)
	{
		cout << "KHONG DU SACH" << endl;
		system("pause");
		return;
	}
	int index = -1;
	string rcode;
	cout << "Nhap ma doc gia muon sach: ";
	getline(cin, rcode);
	for (int i = 0; i < RNUM; i++)
	{
		if (reader[i].Rcode == rcode)
		{
			index = i;
			break;
		}
	}
	if (index == -1) cout << KHONGTONTAIKT << endl;
	else
	{
		if (reader[index].Rmode == 0)
		{
			if (reader[index].Late == 1)
			{
				while (1)
				{
					cout << "DOC GIA TRE HAN, XAC NHAN CHO MUON" << endl;
					cout << "[0].KHONG VE LAI MENU QUAN LI" << endl;
					cout << "[1].CHO MUON" << endl;
					char chon;
					cout << "Nhap lua chon cua ban: ";
					cin >> chon;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					if (chon == '1')
					{
						break;
					}
					else if (chon == '0')
					{
						return;
					}
					else
					{
						cout << CHUCNANGSAI << endl;
					}
				}
			}
			bill[BILLNUM].Rcode=rcode;
			ScanBillBorrow(index, BILLNUM, BNUM, bill, reader, book, BOOKBORROW);
			PrintBookBorrow(index, BILLNUM, bill, reader);
			BILLNUM++;
		}
		else
		{
			cout << "Doc gia chua tra sach" << endl;
		}
	}
}
/*
-----------------HAM MO MENU PHIEU TRA-----------------
+)CHUC NANG: MO MENU PHIEU TRA
+)Input	:
-	So phieu muon
-	So doc gia
-	So sach
-	Mang kieu BILL
-	Mang kieu READER
-	Mang kieu BOOK
-	So sach dang muon
+)Output:
*/
void MenuReturn(int &BILLNUM, int RNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], int &BOOKBORROW)
{
	long long tienphat = 0;
	bool matsach[MBOOKB] = { 0 };
	cout << "\n=======>LAP PHIEU TRA<=======" << endl;
	int index = -1;
	string rcode;
	cout << "Nhap ma doc gia tra sach: ";
	getline(cin, rcode);
	for (int i = 0; i < BILLNUM; i++)
	{
		if (bill[i].Rcode == rcode)
		{
			index = i;
			break;
		}
	}
	int temp = -1;
	for (int i = 0; i < RNUM; i++)
	{
		if (reader[i].Rcode == bill[index].Rcode)
		{
			temp = i;
			break;
		}
	}
	if (index == -1) cout << KHONGTONTAIKT << endl;
	else
	{
		if (reader[temp].Rmode == 1)
		{
			ScanBillReturn(temp,index,RNUM,BNUM,bill,reader,book,tienphat,matsach);
			PrintBillReturn(temp,index,RNUM,BILLNUM,bill,reader,tienphat,matsach);
			Processing(temp,index,BILLNUM,BNUM,bill,reader,book,matsach,BOOKBORROW);
		}
		else
		{
			cout << "Doc gia chua lap phieu muon sach" << endl;
		}
	}
}
/*BILL FUNITION*/
/*BORROW*/
/*
-----------------HAM TINH NGAY TRA DU KIEN-----------------
+)CHUC NANG: TINH NGAY TRA DU KIEN
+)Input	:
-	Ngay muon
+)Output:
-	Ngay tra du kien
*/
void DateReturnExpect(DATE dateborrow,DATE &datereturnexpect)
{
	//Xac dinh so ngay thuc te tu thangmuon nhap vao
	int SNTT = ngaythang(dateborrow.month, dateborrow.year);
	/*----------------------Xac Dinh Ngay Tra Du Kien----------------------*/
	// Xu ly cac ngay cuoi thang:
	if (dateborrow.day == SNTT)
	{
		datereturnexpect.day = 6;
		datereturnexpect.month = dateborrow.month + 1;
		datereturnexpect.year = dateborrow.year;
	}
	else
	{
		datereturnexpect.day = dateborrow.day + 7;
		if (datereturnexpect.day > SNTT)//Neu ngaytraDK vuot qua SNTT thi thuc hien khoi lenh nay
		{
			datereturnexpect.day = datereturnexpect.day - SNTT;
			datereturnexpect.month = dateborrow.month + 1;
		}
		else datereturnexpect.month = dateborrow.month; //ngay binh thuong
		datereturnexpect.year = dateborrow.year;
	}
	// Xu ly nhung ngay cuoi nam
	if (datereturnexpect.month > 12)
	{
		datereturnexpect.month = 1;//Thang tra du kien da qua thang 1 nam lien ke nam sau do
		datereturnexpect.year = dateborrow.year + 1;//Nam tra du kien se bang nam truoc do +1
	}
}
/*
-----------------HAM NHAP SACH MUON-----------------
+)CHUC NANG: NHAP SACH MUON
+)Input	:
-	So hoa don
-	So sach
-	Mang kieu BILL
-	Mang kieu BOOK
-	So sach muon
+)Output:
*/
void ScanBookBorrow(int BILLNUM, int BNUM, BILL bill[MREADER], BOOK book[MBOOK], int &BOOKBORROW)
{
NHAPLAIMUON:
	cout << "+)Nhap so luong sach muon (toi da la " << MBOOKB << " cuon) : ";
	cin >> bill[BILLNUM].NumBorrow;
	if (cin.fail() || bill[BILLNUM].NumBorrow <= 0 || bill[BILLNUM].NumBorrow > MBOOKB)
	{
		cin.clear();// xoa trang thai ham cin
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//xoa ki tu trong bo nho tam
		cout << "NHAP SAI HAY NHAP LAI" << endl;
		goto NHAPLAIMUON;
	}
	if (bill[BILLNUM].NumBorrow > NumberOfBook(BNUM, book))
	{
		cout << "KHONG DU SACH CHI CON "<< NumberOfBook(BNUM, book)<<" QUYEN SACH TRONG KHO"<< endl;
		goto NHAPLAIMUON;
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < bill[BILLNUM].NumBorrow; i++)
	{
		fflush(stdin);
		while (1)
		{
			int index = -1;
			cout << "++)Nhap ISBN cua quyen sach thu " << i + 1 << ": ";
			getline(cin, bill[BILLNUM].ISBNBorrow[i]);
			for (int j = 0; j < BNUM; j++)
			{
				if (book[j].Bcode == bill[BILLNUM].ISBNBorrow[i])
				{
					index = j;
					break;
				}
			}
			if (index == -1)
			{
				cout << KHONGTONTAIKT << endl;
			}
			else if (book[index].Bnum == 0)
			{
				cout << "KHONG CO SACH TRONG KHO, HAY NHAP LAI MA ISBN DE CHAC RANG MINH NHAP DUNG" << endl;
			}
			else
			{
				BOOKBORROW++;
				book[index].Bnum--;
				book[index].Bborrownum++;
				cout << "Nhap thanh cong" << endl;
				break;
			}
		}
	}
}
/*
-----------------HAM NHAP PHIEU MUON-----------------
+)CHUC NANG: NHAP PHIEU MUON
+)Input	:
-	Chi so cua doc gia trong mang READER
-	So hoa don
-	So sach
-	Mang kieu BILL
-	Mang kieu READER
-	Mang kieu BOOK
-	So sach muon
+)Output:
*/
void ScanBillBorrow(int index, int BILLNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], int &BOOKBORROW)
{
	cout << "DOC GIA " << bill[BILLNUM].Rcode << " MUON MOI: " << endl;
	cout << "NHAP NGAY MUON: " << endl;
	ScanDATE(bill[BILLNUM].DateBorrow);
	DateReturnExpect(bill[BILLNUM].DateBorrow, bill[BILLNUM].DateReturnExpect);
	ScanBookBorrow(BILLNUM, BNUM, bill, book, BOOKBORROW);
	reader[index].Rmode = 1;
	reader[index].Late = 0;
}
/*
-----------------HAM XUAT PHIEU MUON-----------------
+)CHUC NANG: XUAT PHIEU MUON
+)Input	:
-	Chi so cua doc gia trong mang READER
-	So hoa don
-	Mang kieu BILL
-	Mang kieu READER
+)Output:
- PHIEU MUON TREN MAN CONSOLE
*/
void PrintBookBorrow(int index, int BILLNUM, BILL bill[MREADER], READER reader[MREADER])
{
	if (reader[index].Rmode == 1)
	{
		cout << "*******************************PHIEU MUON*******************************" << endl;
		cout << "Ten nguoi muon: " << reader[index].Rname << endl;
		cout << "Ma nguoi muon : " << reader[index].Rcode << endl;
		cout << "Ngay muon    : ";
		Date(bill[BILLNUM].DateBorrow);
		cout << "Han tra      : ";
		Date(bill[BILLNUM].DateReturnExpect);
		cout << "So sach muon  : " << bill[BILLNUM].NumBorrow << endl;
		cout << "Danh sach sach muon " << endl;
		for (int j = 0; j < bill[BILLNUM].NumBorrow; j++)
		{
			cout << "|Quyen " << j + 1 << " | Ma ISBN: " << bill[BILLNUM].ISBNBorrow[j] << endl;
		}
		cout << "LUU Y: " << endl;
		cout << "+)Doc gia tre han tra sach (7 ngay ke tu ngay muon sach) se bi phat 5000/1ngay." << endl;
		cout << "+)Neu mat sach se phai boi thuong 200% gia tri cua sach." << endl;
		cout << "*************************************************************************" << endl;
	}
	else cout << "Doc gia chua co phieu muon." << endl;
}
/*RETURN*/
/*
-----------------HAM NHAP PHIEU TRA-----------------
+)CHUC NANG: NHAP PHIEU TRA
+)Input	:
-	Chi so cua doc gia trong mang READER
-	Chi so cua doc gia trong mang BILL
-	So hoa don
-	So sach
-	Mang kieu BILL
-	Mang kieu READER
-	Mang kieu BOOK
-	So sach dang muon
+)Output:
*/
void ScanBillReturn(int temp1,int index,int RNUM,int BNUM ,BILL bill[MREADER],READER reader[MREADER],BOOK book[MBOOK],long long &tienphat,bool matsach[MBOOKB])
{
	cout << "DOC GIA " << bill[index].Rcode << " TRA SACH: " << endl;
	ScanDATE(bill[index].DateReturnReal);
	if (temp1 != -1)
	{
		if (ngaychenhlech(bill[index].DateReturnExpect,bill[index].DateReturnReal) > 0)
		{
			reader[temp1].Late = 1;
		}
		cout << "Kiem tra sach:" << endl;
		cout << "[1]. Sach binh thuong" << endl;
		cout << "[2]. Mat Sach" << endl;
		for (int j = 0; j < bill[index].NumBorrow; j++)
		{
			cout << "|Quyen " << j + 1 << " | Ma ISBN: " << bill[index].ISBNBorrow[j] << endl;
			while (1)
			{
				char chon;
				cout << "Lua chon cua ban: ";
				cin >> chon;
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				if (chon != '1' && chon != '2')
				{
					cout << CHUCNANGSAI << endl;
					system("pause");
				}
				if (chon == '1')
				{
					matsach[j] = 0;
					break;
				}
				if (chon == '2')
				{
					int temp2 = -1;
					matsach[j] = 1;
					for (int k = 0; k < BNUM; k++)
					{
						if (book[k].Bcode == bill[index].ISBNBorrow[j])
						{
							temp2 = k;
							break;
						}
					}
					tienphat = tienphat + book[temp2].Bprice * 2;
					break;
				}
			}
		}
	}
	else
	{
		cout << KHONGTONTAIKT << endl;
	}
}
/*
-----------------HAM XUAT PHIEU TRA-----------------
+)CHUC NANG: XUAT PHIEU TRA
+)Input	:
-	Chi so cua doc gia trong mang READER
-	Chi so cua doc gia trong mang BILL
-	So hoa don
-	So sach
-	Mang kieu BILL
-	Mang kieu READER
-	Mang kieu BOOK
-	So sach dang muon
+)Output:
*/
void PrintBillReturn(int temp, int index,int RNUM ,int BILLNUM, BILL bill[MREADER], READER reader[MREADER], long long tienphat, bool matsach[MBOOKB])
{
	int day = ngaychenhlech(bill[index].DateReturnExpect, bill[index].DateReturnReal);
	cout << "*******************************PHIEU TRA*******************************" << endl;
	cout << "Ten nguoi tra: " << reader[temp].Rname << endl;
	cout << "Ma nguoi tra : " << bill[index].Rcode << endl;
	cout << "Ngay muon    : ";
	Date(bill[index].DateBorrow);
	cout << "Han tra      : ";
	Date(bill[index].DateReturnExpect);
	cout << "Ngay tra     : ";
	Date(bill[index].DateReturnReal);
	cout << "Danh sach sach muon " << endl;
	for (int j = 0; j < bill[index].NumBorrow; j++)
	{
		cout << "|Quyen " << j + 1 << " | Ma ISBN: " << bill[index].ISBNBorrow[j] << endl;
		if (matsach[j] == 1) cout << "Tinh trang: Mat" << endl;
		else cout << "Tinh trang: Binh thuong" << endl;
	}
	if (day > 0)
	{
		cout << "Doc gia tre " << day << " ngay" << endl;
		cout << "Tien phat la: " << day * 5000 + tienphat << " Dong" << endl;
	}
	else
	{
		cout << "Tien phat la: " << tienphat << " Dong" << endl;

	}
	cout << "*************************************************************************" << endl;
}
/*
-----------------HAM XU LI PHIEU TRA-----------------
+)CHUC NANG: XU LI PHIEU TRA
+)Input	:
-	Chi so cua doc gia trong mang READER
-	Chi so cua doc gia trong mang BILL
-	So hoa don
-	So sach
-	Mang kieu BILL
-	Mang kieu READER
-	Mang kieu BOOK
-	So sach dang muon
+)Output:
*/
void Processing(int temp1, int index,int &BILLNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], bool matsach[MBOOKB],int &BOOKBORROW)
{
	for (int j = 0; j < bill[index].NumBorrow; j++)
	{
		int temp2 = -1;
		for (int k = 0; k < BNUM; k++)
		{
			if (book[k].Bcode == bill[index].ISBNBorrow[j])
			{
				temp2 = k;
				break;
			}
		}
		BOOKBORROW--;
		if (matsach[j] == 0)
			book[temp2].Bnum++;
		book[temp2].Bborrownum--;
	}
	reader[temp1].Rmode = 0;
	for (int k = index; k < BILLNUM - 1; k++)
	{
		bill[k] = bill[k + 1];
	}
	BILLNUM--;
}