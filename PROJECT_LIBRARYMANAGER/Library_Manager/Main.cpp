#include "Reader.h"
#include "Book.h"
#include "Bill.h"
#include "Statistic.h"
int main()
{
	/*---------------------------------------PROGRAM INFO---------------------------------------*/
	cout << "  |***********************************************************************|" << endl;
	cout << "  |    CHUONG TRINH QUAN LY THU VIEN  -- TRAN TUAN HUY -- 17CK1_CL        |" << endl;
	cout << "  |***********************************************************************|" << endl;
	cout << "  |                    BAI TAP CUOI KI NHAP MON LAP TRINH                 |" << endl;
	cout << "  |                       CHUONG TRINH QUAN LY THU VIEN                   |" << endl;
	cout << "  |              Sinh Vien  : Tran Tuan Huy                               |" << endl;
	cout << "  |              Lop        : 17CK1_CL                                    |" << endl;
	cout << "  |              MSSV       : 1760327                                     |" << endl;
	cout << "  |              Dien Thoai : 0120.3542.785                               |" << endl;
	cout << "  |              Email      : trantuanhuy17ck1_CL@gmail.com               |" << endl;
	cout << "  |***********************************************************************|" << endl;
	cout << "  |      <!!!!!!!!!!!!!!!!!!!!>   LUU Y   <!!!!!!!!!!!!!!!!!!!!>          |" << endl;
	cout << "  |                     De su dung chuong trinh                           |" << endl;
	cout << "  |Hay nhap MOT ky tu SO DUY NHAT o dau moi dong yeu cau trong cac menu!!!|" << endl;
	cout << "  |***********************************************************************|" << endl;
	system("pause");
	/*---------------------------------------SETUP PROGRAM---------------------------------------*/
	system("cls");
	READER ALLREADER[MREADER];//Mang luu tru thong tin doc gia
	BOOK ALLBOOK[MBOOK];//Mang luu tru thong tin sacch
	BILL ALLBILL[MREADER];//Mang luu tru thong tin phieu muon tra
	int RNUM = 0;//So doc gia
	int BNUM = 0;//So sach
	int BILLNUM = 0;//So phieu muon tra
	int BOOKBORROW = 0;//So sach dang muon
	InputReader(ALLREADER, "Reader.txt", RNUM);
	InputBook(ALLBOOK, "Book.txt", BNUM);
	InputBill(ALLBILL, "Bill.txt", BILLNUM, BOOKBORROW);
	loading();
	/*---------------------------------------MAIN PROGRAM---------------------------------------*/
	while (true)
	{
		system("cls");
		cout << "  |********************************************************************|" << endl;
		cout << "  |------------>  MENU QUAN LI THU VIEN TREN NEN CONSOLE  <------------|" << endl;
		cout << "  |********************************************************************|" << endl;
		cout << "  |          TRUONG DAI HOC KHOA HOC TU NHIEN T.P HO CHI MINH          |" << endl;
		cout << "  |********************************************************************|" << endl;
		cout << "  |[1]. Menu quan li doc gia                                           |" << endl;
		cout << "  |[2]. Menu Quan li sach thu vien                                     |" << endl;
		cout << "  |[3]. Menu Quan phieu muon tra sach                                  |" << endl;
		cout << "  |[4]. Thong ke                                                       |" << endl;
		cout << "  |********************************************************************|" << endl;
		cout << "  |[0]. Thoat chuong trinh                                             |" << endl;
		cout << "  |********************************************************************|" << endl;
		cout << "      So doc gia :  " << RNUM << "  So dau sach:  " << BNUM <<  "  So sach dang duoc muon:" << setw(3)<< BOOKBORROW << endl;
		cout << "  **********************************************************************" << endl;
		cout << "  Nhap lua chon cua ban: ";
		char chon;
		cin >> chon;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (chon == '0') break;
		switch (chon)
		{
		case '1':
			MenuReader(RNUM, ALLREADER);
			break;
		case '2':
			MenuBook(BNUM, ALLBOOK);
			break;
		case '3':
			MenuBill(BILLNUM, RNUM, BNUM, ALLBILL, ALLREADER, ALLBOOK, BOOKBORROW);
			break;
		case '4':
			MenuStatistic(BOOKBORROW,RNUM,BNUM, ALLREADER, ALLBOOK);
			break;
		default:
			cout << CHUCNANGSAI << endl;
			system("pause");
			break;
		}
	}
	/*---------------------------------------END PROGRAM---------------------------------------*/
	system("cls");
	OutputReader(ALLREADER, "Reader.txt", RNUM);
	OutputBook(ALLBOOK, "Book.txt", BNUM);
	OutputBill(ALLBILL, "Bill.txt", BILLNUM);
	system("cls");
	cout << "  |********************************************************************|" << endl;
	cout << "  |------------------>  TAM BIET VA HEN GAP LAI <3  <------------------|" << endl;
	cout << "  |********************************************************************|" << endl;
	system("pause");
	return 0;
}