#include "Book.h"
/*FILE*/
/*
-----------------HAM LAY THONG TIN SACH TU FILE-----------------
+)CHUC NANG: LAY THONG TIN SACH TU FILE
+)Input	:
-	Mang kieu BOOK
-	Ten file
-	So sach
+)Output:
*/
void InputBook(BOOK book[MBOOK], string file_name, int &BNUM)
{
	cout << "---------- IMPORTING BOOK ----------" << endl;
	ifstream fileB;
	fileB.open(file_name);
	if (!fileB.is_open())
	{
		cout << "Can't open this file." << endl;
		cout << endl;
		return;
	}
	while (!fileB.eof())
	{
		getline(fileB, book[BNUM].Bcode);
		if (fileB.eof()) break; 
		getline(fileB, book[BNUM].Bname);
		getline(fileB, book[BNUM].Bauthor);
		getline(fileB, book[BNUM].Bpublisher);
		getline(fileB, book[BNUM].Bypub);
		getline(fileB, book[BNUM].Btype);
		fileB >> book[BNUM].Bnum;
		fileB >> book[BNUM].Bprice;
		fileB >> book[BNUM].Bborrownum;
		fileB.get();
		cout << "Importing book " << BNUM + 1 << endl;
		BNUM++;
		if (BNUM >= MREADER)
		{
			cout << DAYBONHO << endl;
			break;
		}
	}
	fileB.close();
	cout << "Import successfully." << endl;
}
/*
-----------------HAM XUAT THONG TIN SACH RA FILE-----------------
+)CHUC NANG: XUAT THONG TIN SACH RA FILE
+)Input	:
-	Mang kieu BOOK
-	Ten file
-	So sach
+)Output:
*/
void OutputBook(BOOK book[MBOOK], string file_name, int BNUM)
{
	cout << "---------- EXPORTING BOOK ----------" << endl;
	ofstream fileB;
	fileB.open(file_name);
	for (int i = 0; i < BNUM; i++)
	{
		cout << "Exporting book " << i + 1 << endl;
		fileB << book[i].Bcode << endl;
		fileB << book[i].Bname << endl;
		fileB << book[i].Bauthor << endl;
		fileB << book[i].Bpublisher << endl;
		fileB << book[i].Bypub << endl;
		fileB << book[i].Btype << endl;
		fileB << book[i].Bnum << endl;
		fileB << book[i].Bprice << endl;
		fileB << book[i].Bborrownum ;
		if (i!=BNUM-1) fileB << endl;
	}
	cout << "Export successfully." << endl;
	fileB.close();
}
/*MENU*/
/*
-----------------HAM MO MENU QUAN LI SACH-----------------
+)CHUC NANG: MO MENU QUAN LI SACH
+)Input	:
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void MenuBook(int &BNUM, BOOK book[MBOOK])
{
	char chon;
	while (true)
	{
		system("cls");
		cout << "============>MENU QUAN LI SACH<============" << endl;
		cout << "   [0]. Ve menu quan li thu vien" << endl;
		cout << "   [1]. Xem danh sach tat ca sach" << endl;
		cout << "   [2]. Them moi sach" << endl;
		cout << "   [3]. Thong tin sach" << endl;
		cout << "   [4]. Tim kiem sach " << endl;
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
			PrintALLBook(BNUM, book);
			break;
		case '2':
			ScanBook(BNUM, book);
			break;
		case '3':
			MenuModifyAndDeleteBook(BNUM, book);
			break;
		case '4':
			MenuSearchBook(BNUM, book);
			break;
		default:
			cout << CHUCNANGSAI << endl;
			system("pause");
			break;
		}
	}
}
/*
-----------------HAM MO MENU THONG TIN SACH-----------------
+)CHUC NANG: MO MENU THONG TIN SACH
+)Input	:
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void MenuModifyAndDeleteBook(int &BNUM, BOOK book[MBOOK])
{
	while (1)
	{
		system("cls");
		cout << "===>MENU CHINH SUA VA XOA THONG TIN SACH<===" << endl;
		if (BNUM == 0)
		{
			cout << KHONGSACH << endl;
			system("pause");
			return;
		}
		int flag = 1;
		string bookcode;
		int index;
		cout << "+)Nhap ma ISBN : ";
		getline(cin, bookcode);
		dinhdangchu(bookcode);
		for (int i = 0; i < BNUM; i++)
		{
			if (book[i].Bcode == bookcode)
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
			MenuInfoBook(index, BNUM, book);
			return;
		}
	}
}
/*
-----------------MENU THONG TIN SACH-----------------
+)CHUC NANG:
+)Input	:
-	Chi so sach
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void MenuInfoBook(int i, int &BNUM, BOOK book[MBOOK])
{
	char chon;
	string modify;
	while (1)
	{
		system("cls");
		cout << "==>MENU THONG TIN SACH " << book[i].Bcode << "<===" << endl;
		cout << "[0].Back" << endl;
		cout << "[1].Xem thong tin sach" << endl;
		cout << "[2].Sua thong tin sach" << endl;
		cout << "[3].Xoa thong tin sach" << endl;
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
			PrintBook(i, BNUM, book);
			system("pause");
			break;
		case '2':
			MenuModifyBook(i, BNUM, book);
			break;
		case '3':
			MenuDelBook(i, BNUM, book);
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
-----------------MENU SUA THONG TIN SACH-----------------
+)CHUC NANG: SUA THONG TIN SACH
+)Input	:
-	Chi so sach
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void MenuModifyBook(int i, int BNUM, BOOK book[MBOOK])
{
	while (true)
	{
		char chon;
		system("cls");
		cout << "\n>MENU LENH SUA THONG TIN SACH " << book[i].Bcode << "<" << endl;
		cout << "[0]. Back" << endl;
		cout << "[1]. Sua ma ISBN" << endl;
		cout << "[2]. Sua ten" << endl;
		cout << "[3]. Sua tac gia" << endl;
		cout << "[4]. Sua nha xuat ban" << endl;
		cout << "[5]. Sua nam xuat ban" << endl;
		cout << "[6]. Sua the loai " << endl;
		cout << "[7]. Sua so luong" << endl;
		cout << "[8]. Sua gia" << endl;
		cout << "===================================================" << endl;
		cout << "Chon chuc nang: ";
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		fflush(stdin);
		system("cls");
		if (chon == '0') break;
		else if (chon == '1')
		{
			cout << "Nhap ma ISBN moi: " << endl;
			ScanBookCode(i, BNUM, book);
			cout << "DA SUA XONG" << endl;
		}
		else if (chon=='7')
		{
			cout << "Nhap so luong moi: " << endl;
			ScanBookNum(book[i].Bnum);
			cout << "DA SUA XONG" << endl;
		}
		else if (chon == '8')
		{
			cout << "Nhap gia sach moi: " << endl;
			ScanBookPrice(book[i].Bprice);
			cout << "DA SUA XONG" << endl;
		}
		else
		{
			switch (chon)
			{
			case '2':
				cout << "Nhap ten sach: ";
				getline(cin, book[i].Bname);
				dinhdangchu(book[i].Bname);
				fflush(stdin);
				cout << "DA SUA XONG" << endl;
				break;
			case '3':
				cout << "Nhap ten tac gia: ";
				getline(cin, book[BNUM].Bauthor);
				dinhdangchu(book[BNUM].Bauthor);
				fflush(stdin);
				cout << "DA SUA XONG";
				break;
			case '4':
				cout << "Nhap nha phat hanh: ";
				getline(cin, book[BNUM].Bpublisher);
				fflush(stdin);
				cout << "DA SUA XONG" << endl;
				break;
			case '5':
				cout << "Nhap nam phat hanh: ";
				getline(cin, book[BNUM].Bypub);
				fflush(stdin);
				cout << "DA SUA XONG" << endl;
				break;
			case '6':
				cout << "Nhap the loai: ";
				getline(cin, book[BNUM].Btype);
				dinhdangchu(book[BNUM].Btype);
				fflush(stdin);
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
-----------------MENU XOA THONG TIN SACH-----------------
+)CHUC NANG: XOA THONG TIN SACH
+)Input	:
-	Chi so sach
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void MenuDelBook(int i, int &BNUM, BOOK book[MBOOK])
{
	system("cls");
	cout << "\n=======>MUC XOA THONG TIN SACH<=======" << endl;
	if (book[i].Bborrownum != 0)
	{
		cout << "Sach dang muon khong the xoa" << endl;
		system("pause");
		return;
	}
	cout << "Ban se xoa sach nay ?" << endl;
	cout << "[0].Khong ve lai menu sach" << endl;
	cout << "[1].Xoa" << endl;
	char chon;
	while (1)
	{
		cout << "Nhap lua chon cua ban: ";
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (chon == '1')
		{
			for (int j = i; j < BNUM - 1; j++)
			{
				book[j] = book[j + 1];
			}
			BNUM--;
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
-----------------MENU TIM THONG TIN SACH-----------------
+)CHUC NANG: TIM THONG TIN SACH
+)Input	:
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void MenuSearchBook(int BNUM, BOOK book[MBOOK])
{
	string search;
	int flag = 0;
	while (1)
	{
		system("cls");
		cout << "\n===>MENU TIM KIEM SACH<===" << endl;
		cout << "[0]. Back." << endl;
		cout << "[1]. Theo Ma ISBN." << endl;
		cout << "[2]. Theo Ten sach." << endl;
		cout << "[3]. Theo The loai." << endl;
		cout << "[4]. Theo Tac gia." << endl;
		cout << "=================================" << endl;
		char chon;
		cout << "\nLua chon cua ban: ";
		cin >> chon;
		if (chon == '0') break;
		else if (chon == '1')
		{
			system("cls");
			cout << ">      THEO ISBN       <" << endl;
		}
		else if (chon == '2')
		{
			system("cls");
			cout << ">    THEO TEN SACH     <" << endl;
		}
		else if (chon == '3')
		{
			system("cls");
			cout << ">    THEO THE LOAI     <" << endl;
		}
		else if (chon == '4')
		{
			system("cls");
			cout << ">    THEO TAC GIA      <" << endl;
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
			for (int i = 0; i < BNUM; i++)
			{
				if (search == book[i].Bcode)
				{
					PrintBook(i, BNUM, book);
					flag = 1;
				}
			}
		}
		else if (chon == '2')
		{
			for (int i = 0; i < BNUM; i++)
			{
				if (book[i].Bname.find(search) != string::npos)
				{
					PrintBook(i, BNUM, book);
					flag = 1;
				}
			}
		}
		else if (chon == '3')
		{
			for (int i = 0; i < BNUM; i++)
			{
				if (book[i].Btype.find(search) != string::npos)
				{
					PrintBook(i, BNUM, book);
					flag = 1;
				}
			}
		}
		else if (chon == '4')
		{
			for (int i = 0; i < BNUM; i++)
			{
				if (book[i].Bauthor.find(search) != string::npos)
				{
					PrintBook(i, BNUM, book);
					flag = 1;
				}
			}
		}
		if (flag == 0) cout << "KHONG CO KET QUA" << endl;
		system("pause");
	}
}
/*BOOK FUNITION*/
/*
-----------------HAM NHAP SO LUONG SACH-----------------
+)CHUC NANG: NHAP SO LUONG SACH
+)Input	:
-	So sach
+)Output:
*/
void ScanBookNum(int &numberbook)
{
	while (1)
	{
		cout << "+)So luong : ";
		cin >> numberbook;
		if (cin.fail())
		{
			cin.clear();// xoa trang thai ham cin
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//xoa ki tu trong bo nho tam
			cout << "Du lieu khong hop le. Moi nhap lai !!!" << endl;
			continue;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
}
/*
-----------------HAM NHAP GIA SACH-----------------
+)CHUC NANG: NHAP GIA SACH
+)Input	:
-	Gia sach
+)Output:
*/
void ScanBookPrice(int &price)
{
	while (1)
	{
		cout << "+)Gia sach : ";
		cin >> price;
		if (cin.fail())
		{
			cin.clear();// xoa trang thai ham cin
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//xoa ki tu trong bo nho tam
			cout << "Du lieu khong hop le. Moi nhap lai !!!" << endl;
			continue;
		}
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}
}
/*
-----------------HAM NHAP ISBN SACH-----------------
+)CHUC NANG: NHAP ISBN SACH
+)Input	:
-	Chi so sach
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void ScanBookCode(int i,int BNUM, BOOK book[MBOOK])
{
	while (1)
	{
		int flag = 1;
		cout << "+)Ma ISBN : ";
		getline(cin, book[i].Bcode);
		dinhdangchu(book[i].Bcode);
		for (int j = 0; j < BNUM; j++)
		{
			if (book[i].Bcode == book[j].Bcode&&i != j)
			{
				cout << "Da ton tai ma sach nay. Moi nhap lai !!!" << endl;
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
-----------------HAM NHAP THONG TIN SACH-----------------
+)CHUC NANG: NHAP THONG TIN SACH
+)Input	:
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void ScanBook(int &BNUM, BOOK book[MBOOK])
{
	while (1)
	{
		system("cls");
		cout << "\n====>MENU THEM SACH<====" << endl;
		cout << "[0]. Back." << endl;
		cout << "[1]. Them sach moi." << endl;
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
			if (BNUM >= MBOOK)
			{
				cout << DAYBONHO << endl;
			}
			else
			{
				system("cls");
				cout << "<++>  Nhap thong tin sach  <++>" << endl;
				fflush(stdin);
				ScanBookCode(BNUM, BNUM, book);//Book code
				cout << "+)Ten sach : ";
				getline(cin, book[BNUM].Bname);
				dinhdangchu(book[BNUM].Bname);
				fflush(stdin);
				cout << "+)Ten tac gia : ";
				getline(cin, book[BNUM].Bauthor);
				dinhdangchu(book[BNUM].Bauthor);
				fflush(stdin);
				cout << "+)Nha phat hanh : ";
				getline(cin, book[BNUM].Bpublisher);
				fflush(stdin);
				cout << "+)Nam phat hanh : ";
				getline(cin, book[BNUM].Bypub);
				fflush(stdin);
				cout << "+)The loai : ";
				getline(cin, book[BNUM].Btype);
				dinhdangchu(book[BNUM].Btype);
				fflush(stdin);
				ScanBookPrice(book[BNUM].Bprice);
				ScanBookNum(book[BNUM].Bnum);
				book[BNUM].Bborrownum = 0;
				BNUM++;
				cout << "DA THEM SACH" << endl;
				system("pause");
			}
		}
		cout << "\n===========================" << endl;
	}
}
/*
-----------------HAM XUAT THONG TIN 1 SACH-----------------
+)CHUC NANG: XUAT THONG TIN 1 SACH
+)Input	:
-	Chi so sach
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void PrintBook(int i, int BNUM, BOOK book[MBOOK])
{
	if ((i < 0) || (i >= BNUM))
	{
		cout << KHONGTONTAIKT << endl;
	}
	else
	{
		cout << "\n<++>Thong tin sach " << book[i].Bcode << "<++>" << endl;
		cout << "+)Ma so ISBN : " << book[i].Bcode << endl;
		cout << "+)Ten sach : " << book[i].Bname << endl;
		cout << "+)Tac gia : " << book[i].Bauthor << endl;
		cout << "+)Nha phat hanh : " << book[i].Bpublisher << endl;
		cout << "+)Nam phat hanh : " << book[i].Bypub << endl;
		cout << "+)The loai : " << book[i].Btype << endl;
		cout << "+)So luong : " << book[i].Bnum << "     Dang muon : " << book[i].Bborrownum << endl;
		cout << "+)Gia : " << book[i].Bprice << " dong" << endl;
	}
}
/*
-----------------HAM XUAT THONG TIN TAT CA SACH-----------------
+)CHUC NANG: XUAT THONG TIN TAT CA SACH
+)Input	:
-	So sach
-	Mang kieu BOOK
+)Output:
*/
void PrintALLBook(int BNUM, BOOK book[MBOOK])
{
	system("cls");
	cout << "====>DANH SACH TAT CA SACH<====" << endl;
	if (BNUM == 0)
	{
		cout << KHONGSACH << endl;
	}
	else
	{
		for (int i = 0; i < BNUM; i++)
		{
			PrintBook(i, BNUM, book);
		}
	}
	cout << "\n=============================" << endl;
	system("pause");
}