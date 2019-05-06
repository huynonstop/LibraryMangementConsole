#include "Reader.h"
/*FILE*/
/*
-----------------HAM LAY THONG TIN DOC GIA TU FILE-----------------
+)CHUC NANG: LAY THONG TIN DOC GIA TU FILE
+)Input	:
-	Mang kieu READER
-	Ten file
-	So doc gia
+)Output:
*/
void InputReader(READER reader[MREADER], string file_name, int &RNUM)
{
	cout << "---------- IMPORTING READER ----------" << endl;
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
		getline(fileR, reader[RNUM].Rcode);
		if (fileR.eof()) break;
		getline(fileR, reader[RNUM].Rname);
		getline(fileR, reader[RNUM].Ridentity);
		getline(fileR, reader[RNUM].Rsex);
		getline(fileR, reader[RNUM].Remail);
		getline(fileR, reader[RNUM].Raddress);
		fileR >> reader[RNUM].Rdob.day >> reader[RNUM].Rdob.month >> reader[RNUM].Rdob.year;
		fileR >> reader[RNUM].Rstart.day >> reader[RNUM].Rstart.month >> reader[RNUM].Rstart.year;
		fileR >> reader[RNUM].Rend.day >> reader[RNUM].Rend.month >> reader[RNUM].Rend.year;
		fileR >> reader[RNUM].Rmode;
		fileR >> reader[RNUM].Late;
		fileR.get();
		cout << "Importing reader " << RNUM + 1 << endl;
		RNUM++;
		if (RNUM >= MREADER)
		{
			cout << DAYBONHO << endl;
			break;
		}
	}
	fileR.close();
	cout << "Import successfully." << endl;
}
/*
-----------------HAM XUAT THONG TIN DOC GIA RA FILE-----------------
+)CHUC NANG: XUAT THONG TIN DOC GIA RA FILE
+)Input	:
-	Mang kieu READER
-	Ten file
-	So doc gia
+)Output:
*/
void OutputReader(READER reader[MREADER], string file_name, int RNUM)
{
	cout << "---------- EXPORTING READER ----------" << endl;
	ofstream fileR;
	fileR.open(file_name);
	for (int i = 0; i < RNUM; i++)
	{
		cout << "Exporting reader " << i + 1 << endl;
		fileR << reader[i].Rcode << endl;
		fileR << reader[i].Rname << endl;
		fileR << reader[i].Ridentity << endl;
		fileR << reader[i].Rsex << endl;
		fileR << reader[i].Remail << endl;
		fileR << reader[i].Raddress << endl;
		fileR << reader[i].Rdob.day << " " << reader[i].Rdob.month << " " << reader[i].Rdob.year << endl;
		fileR << reader[i].Rstart.day << " " << reader[i].Rstart.month << " " << reader[i].Rstart.year << endl;
		fileR << reader[i].Rend.day << " " << reader[i].Rend.month << " " << reader[i].Rend.year << endl;
		fileR << reader[i].Rmode << endl;
		fileR << reader[i].Late;
		if (i != RNUM - 1) fileR << endl;
	}
	cout << "Export successfully." << endl;
	fileR.close();
}
/*MENU READER*/
/*
-----------------HAM MO MENU QUAN LI DOC GIA-----------------
+)CHUC NANG: MO MENU QUAN LI DOC GIA
+)Input	:
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void MenuReader(int &RNUM, READER reader[MREADER])
{
	char chon;
	while (true)
	{
		system("cls");
		cout << "============>MENU QUAN LI DOC GIA<============" << endl;
		cout << "   [0]. Ve menu quan li thu vien" << endl;
		cout << "   [1]. Xem danh sach tat ca doc gia" << endl;
		cout << "   [2]. Them moi doc gia" << endl;
		cout << "   [3]. Thong tin doc gia" << endl;
		cout << "   [4]. Tim kiem doc gia " << endl;
		cout << "==============================================" << endl;
		cout << "   Nhap lua chon cua ban: ";
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
			PrintALLReader(RNUM, reader);
			break;
		case '2':
			ScanReader(RNUM, reader);
			break;
		case '3':
			MenuModifyAndDeleteReader(RNUM, reader);
			break;
		case '4':
			MenuSearchReader(RNUM, reader);
			break;
		default:
			cout << CHUCNANGSAI << endl;
			system("pause");
			break;
		}
	}
}
/*
-----------------HAM MO MENU THONG TIN DOC GIA-----------------
+)CHUC NANG: MO MENU THONG TIN DOC GIA
+)Input	:
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void MenuModifyAndDeleteReader(int &RNUM, READER reader[MREADER])
{
	while (1)
	{
		system("cls");
		cout << "===>MENU CHINH SUA VA XOA THONG TIN DOC GIA<===" << endl;
		if (RNUM == 0)
		{
			cout << KHONGDOCGIA << endl;
			system("pause");
			return;
		}
		int flag = 1;
		string readercode;
		int index;
		cout << "+)Nhap ma doc gia : ";
		getline(cin, readercode);
		dinhdangchu(readercode);
		for (int i = 0; i < RNUM; i++)
		{
			if (reader[i].Rcode == readercode)
			{
				flag = 0;
				index = i;
				break;
			}
		}
		if (flag == 1)
		{
			cout << KHONGTONTAIKT << endl;
			system("pause");
			return;
		}
		if (flag == 0)
		{
			MenuInfoReader(index, RNUM, reader);
			return;
		}
	}
}
/*
-----------------MENU THONG TIN DOC GIA-----------------
+)CHUC NANG:
+)Input	:
-	Chi so doc gia
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void MenuInfoReader(int i, int &RNUM, READER reader[MREADER])
{
	char chon;
	string modify;
	while (1)
	{
		system("cls");
		cout << "==>MENU THONG TIN DOC GIA " << reader[i].Rcode << "<===" << endl;
		cout << "[0].Back" << endl;
		cout << "[1].Xem thong tin doc gia" << endl;
		cout << "[2].Sua thong tin doc gia" << endl;
		cout << "[3].Xoa thong tin doc gia" << endl;
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
			PrintReader(i, RNUM, reader);
			system("pause");
			break;
		case '2':
			MenuModifyReader(i, RNUM, reader);
			break;
		case '3':
			MenuDelReader(i, RNUM, reader);
			return;
			break;
		default:
			cout << CHUCNANGSAI << endl;
			system("pause");
			break;
		}
	}
}
/*
-----------------MENU SUA THONG TIN DOC GIA-----------------
+)CHUC NANG: SUA THONG TIN DOC GIA
+)Input	:
-	Chi so doc gia
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void MenuModifyReader(int i, int RNUM, READER reader[MREADER])
{
	while (true)
	{
		char chon;
		system("cls");
		cout << "\n>MENU LENH SUA THONG TIN DOC GIA " << reader[i].Rcode << "<" << endl;
		cout << "[0]. Back" << endl;
		cout << "[1]. Sua ma so" << endl;
		cout << "[2]. Sua ten" << endl;
		cout << "[3]. Sua CMND" << endl;
		cout << "[4]. Sua ngay thang nam sinh" << endl;
		cout << "[5]. Sua gioi tinh" << endl;
		cout << "[6]. Sua email " << endl;
		cout << "[7]. Sua dia chi" << endl;
		cout << "[8]. Sua thoi gian lap the" << endl;
		cout << "===================================================" << endl;
		cout << "Chon chuc nang: ";
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		fflush(stdin);
		system("cls");
		if (chon == '0') break;
		else if (chon == '1')
		{
			cout << "Nhap ma doc gia: " << endl;
			ScanReaderCode(i, RNUM, reader);
			cout << "DA SUA XONG" << endl;
		}
		else if (chon == '4')
		{
			cout << "Nhap ngay thang nam sinh: " << endl;
			ScanDATE(reader[i].Rdob);
			cout << "DA SUA XONG" << endl;
		}
		else if (chon == '5')
		{
			cout << "Nhap gioi tinh: " << endl;
			ScanReaderSex(reader[i].Rsex);
			cout << "DA SUA XONG" << endl;
		}
		else if (chon == '8')
		{
			cout << "Nhap ngay thang nam lap the: " << endl;
			ScanDATE(reader[i].Rstart);
			reader[i].Rend.day = reader[i].Rstart.day;
			reader[i].Rend.month = reader[i].Rstart.month;
			reader[i].Rend.year = reader[i].Rstart.year + 4;
			cout << "DA SUA XONG" << endl;
		}
		else
		{
			switch (chon)
			{
			case '2':
				cout << "Nhap ten doc gia: " << endl;
				getline(cin, reader[i].Rname);
				dinhdangchu(reader[i].Rname);
				fflush(stdin);
				cout << "DA SUA XONG" << endl;
				break;
			case '3':
				cout << "Nhap CMND: " << endl;
				getline(cin, reader[i].Ridentity);
				fflush(stdin);
				cout << "DA SUA XONG" << endl;
				break;
			case '6':
				cout << "Nhap Email: " << endl;
				getline(cin, reader[i].Remail);
				fflush(stdin);
				cout << "DA SUA XONG" << endl;
				break;
			case '7':
				cout << "Nhap dia chi: " << endl;
				getline(cin, reader[i].Raddress);
				fflush(stdin);
				cout << "DA SUA XONG" << endl;
				break;
			default:
				cout << KHONGTONTAIKT << endl;
				break;
			}
		}
		system("pause");
	}
}
/*
-----------------MENU XOA THONG TIN DOC GIA-----------------
+)CHUC NANG: XOA THONG TIN DOC GIA
+)Input	:
-	Chi so doc gia
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void MenuDelReader(int i, int &RNUM, READER reader[MREADER])
{
	system("cls");
	cout << "\n=======>MUC XOA THONG TIN DOC GIA<=======" << endl;
	if (reader[i].Rmode == 1)
	{
		cout << "Doc gia dang muon khong the xoa" << endl;
		system("pause");
		return;
	}
	cout << "Ban se xoa doc gia nay ?" << endl;
	cout << "[0].Khong ve lai menu doc gia" << endl;
	cout << "[1].Xoa" << endl;
	char chon;
	while (1)
	{
		cout << "Nhap lua chon cua ban: ";
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (chon == '1')
		{
			for (int j = i; j < RNUM - 1; j++)
			{
				reader[j] = reader[j + 1];
			}
			RNUM--;
			cout << "\nDA XOA XONG" << endl;
			system("pause");
			break;
			
		}
		else if (chon == '0')
		{
			system("cls");
			break;
		}
		else
		{
			cout << CHUCNANGSAI << endl;
		}
	}
}
/*
-----------------MENU TIM THONG TIN DOC GIA-----------------
+)CHUC NANG: TIM THONG TIN SACH
+)Input	:
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void MenuSearchReader(int RNUM, READER reader[MREADER])
{
	string search;
	int flag=0;
	while (1)
	{
		system("cls");
		cout << "\n===>MENU TIM KIEM DOC GIA<===" << endl;
		cout << "[0]. Back." << endl;
		cout << "[1]. Theo Ma doc gia." << endl;
		cout << "[2]. Theo Ho va ten." << endl;
		cout << "[3]. Theo CMND." << endl;
		cout << "=================================" << endl;
		char chon;
		cout << "\nLua chon cua ban: ";
		cin >> chon;
		if (chon == '0') break;
		else if (chon == '1')
		{
			system("cls");
			cout << ">       THEO MA DOC GIA       <" << endl;
		}
		else if (chon == '2')
		{
			system("cls");
			cout << ">           THEO TEN          <" << endl;
		}
		else if (chon == '3')
		{
			system("cls");
			cout << ">          THEO CMND          <" << endl;
		}
		else
		{
			cout << CHUCNANGSAI << endl;
			system("pause");
			continue;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "NHAP NOI DUNG TIM KIEM : ";
		fflush(stdin);
		getline(cin, search);
		dinhdangchu(search);
		fflush(stdin);
		if (chon == '1')
		{
			for (int i = 0; i < RNUM; i++)
			{
				if (search == reader[i].Rcode)
				{
					PrintReader(i, RNUM, reader);
					flag = 1;
				}
			}
		}
		else if (chon == '2')
		{
			for (int i = 0; i < RNUM; i++)
			{
				if (reader[i].Rname.find(search) != string::npos)
				{
					PrintReader(i, RNUM, reader);
					flag = 1;
				}
			}
		}
		else if (chon == '3')
		{
			for (int i = 0; i < RNUM; i++)
			{
				if (search == reader[i].Ridentity)
				{
					PrintReader(i, RNUM, reader);
					flag = 1;
				}
			}
		}
		if (flag == 0) cout << "KHONG CO KET QUA" << endl;
		system("pause");
	}
}
/*READER FUNITION*/
/*
-----------------HAM NHAP MA DOC GIA-----------------
+)CHUC NANG: NHAP ISBN SACH
+)Input	:
-	Chi so doc gia
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void ScanReaderCode(int i, int RNUM, READER reader[MREADER])
{
	while (1)
	{
		int flag = 1;
		cout << "+)Ma doc gia : ";
		getline(cin, reader[i].Rcode);
		dinhdangchu(reader[i].Rcode);
		for (int j = 0; j < RNUM; j++)
		{
			if (reader[i].Rcode == reader[j].Rcode&&i != j)
			{
				cout << "Da ton tai ma doc gia nay. Moi nhap lai !!!" << endl;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			cout << "Nhap thanh cong" << endl;
			break;
		}
	}
}
/*
-----------------HAM NHAP GIOI TINH DOC GIA-----------------
+)CHUC NANG: NHAP GIOI TINH SACH
+)Input	:
-	Chi so doc gia
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void ScanReaderSex(string &readersex)
{
	int flag = 1;
	while (flag == 1)
	{
		cout << "+)Gioi tinh doc gia : ";
		getline(cin, readersex);
		dinhdangchu(readersex);
		fflush(stdin);
		if (readersex == "NU" || readersex == "NAM") flag = 0;
		else cout << "Hay nhap NAM hoac NU. Moi nhap lai !!!" << endl;
	}
}
/*
-----------------HAM NHAP THONG TIN DOC GIA-----------------
+)CHUC NANG: NHAP THONG TIN DOC GIA
+)Input	:
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void ScanReader(int &RNUM, READER reader[MREADER])
{
	while (1)
	{
		system("cls");
		cout << "\n====>MENU THEM DOC GIA<====" << endl;
		cout << "[0]. Back." << endl;
		cout << "[1]. Them doc gia moi." << endl;
		cout << "===========================" << endl;
		char chon;
		cout << "Lua chon cua ban: ";
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (chon != '0' && chon != '1')
		{
			cout << CHUCNANGSAI << endl;
			system("pause");
		}
		if (chon == '0') break;
		if (chon == '1')
		{
			if (RNUM >= MREADER)
			{
				cout << DAYBONHO << endl;
			}
			else
			{
				system("cls");
				cout << "<++>Nhap thong tin doc gia<++>" << endl;
				fflush(stdin);
				ScanReaderCode(RNUM, RNUM, reader);//Reader code
				cout << "+)Ten doc gia : ";
				getline(cin, reader[RNUM].Rname);
				dinhdangchu(reader[RNUM].Rname);
				fflush(stdin);
				cout << "+)CMND doc gia : ";
				getline(cin, reader[RNUM].Ridentity);
				dinhdangchu(reader[RNUM].Ridentity);
				fflush(stdin);
				cout << "+)Ngay thang nam sinh doc gia : " << endl;
				ScanDATE(reader[RNUM].Rdob);
				fflush(stdin);
				ScanReaderSex(reader[RNUM].Rsex);
				cout << "+)Email doc gia : ";
				getline(cin, reader[RNUM].Remail);
				fflush(stdin);
				cout << "+)Dia chi doc gia : ";
				getline(cin, reader[RNUM].Raddress);
				fflush(stdin);
				cout << "+)Thoi gian lap the : " << endl;
				ScanDATE(reader[RNUM].Rstart);
				reader[RNUM].Rend.day = reader[RNUM].Rstart.day;
				reader[RNUM].Rend.month = reader[RNUM].Rstart.month;
				reader[RNUM].Rend.year = reader[RNUM].Rstart.year + 4;
				reader[RNUM].Rmode = 0;
				reader[RNUM].Late = 0;
				RNUM++;
				cout << "DA THEM DOC GIA" << endl;
				system("pause");
			}
		}
		cout << "\n===========================" << endl;
	}
}
/*
-----------------HAM XUAT THONG TIN 1 DOC GIA-----------------
+)CHUC NANG: XUAT THONG TIN 1 DOC GIA
+)Input	:
-	Chi so doc gia
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void PrintReader(int i, int RNUM, READER reader[MREADER])
{
	if ((i < 0) || (i >= RNUM))
	{
		cout << KHONGTONTAIKT << endl;
	}
	else
	{
		cout << "\n<++>Thong tin doc gia " << reader[i].Rcode << "<++>" << endl;
		cout << "+)Ma so doc gia : " << reader[i].Rcode << endl;
		if (reader[i].Rmode == 0)
			cout << "+)Tinh trang : Chua muon" << endl;
		else
			cout << "+)Tinh trang : Dang muon" << endl;
		cout << "+)Ten doc gia : " << reader[i].Rname << endl;
		cout << "+)CMND doc gia : " << reader[i].Ridentity << endl;
		cout << "+)Ngay thang nam sinh doc gia : ";
		Date(reader[i].Rdob);
		cout << "+)Gioi tinh doc gia : " << reader[i].Rsex << endl;
		cout << "+)Email doc gia : " << reader[i].Remail << endl;
		cout << "+)Dia chi doc gia : " << reader[i].Raddress << endl;
		cout << "+)Thoi gian lap : ";
		Date(reader[i].Rstart);
		cout << "+)Thoi gian het : ";
		Date(reader[i].Rend);
	}
}
/*
-----------------HAM XUAT THONG TIN TAT CA DOC GIA-----------------
+)CHUC NANG: XUAT THONG TIN TAT CA DOC GIA
+)Input	:
-	So doc gia
-	Mang kieu READER
+)Output:
*/
void PrintALLReader(int RNUM, READER reader[MREADER])
{
	system("cls");
	cout << "====>DANH SACH TAT CA DOC GIA<====" << endl;
	if (RNUM == 0)
	{
		cout << KHONGDOCGIA << endl;
	}
	else
	{
		for (int i = 0; i < RNUM; i++)
		{
			PrintReader(i, RNUM, reader);
		}
	}
	cout << "\n==================================" << endl;
	system("pause");
}