#ifndef _PHIEUMUONTRA_
#define _PHIEUMUONTRA_
#include "Header.h"
#include "Bill.h"
/*FILE*/
void InputBill(BILL bill[MREADER], string file_name, int &BILLNUM, int &BOOKBORROW);
void OutputBill(BILL bill[MREADER], string file_name, int BILLNUM);
/*MENU*/
void MenuBill(int &BILLNUM, int RNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], int &BOOKBORROW);
void MenuBorrow(int &BILLNUM, int RNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], int &BOOKBORROW);
void MenuReturn(int &BILLNUM, int RNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], int &BOOKBORROW);
/*FUNITION*/
/*BORROW*/
void DateReturnExpect(DATE dateborrow, DATE &datereturnexpect);
void ScanBookBorrow(int BILLNUM, int BNUM, BILL bill[MREADER], BOOK book[MBOOK], int &BOOKBORROW);
void ScanBillBorrow(int index, int BILLNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], int &BOOKBORROW);
void PrintBookBorrow(int index, int BILLNUM, BILL bill[MREADER], READER reader[MREADER]);
/*RETURN*/
void ScanBillReturn(int temp1, int index, int RNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], long long &tienphat, bool matsach[MBOOKB]);
void PrintBillReturn(int temp, int index, int RNUM, int BILLNUM, BILL bill[MREADER], READER reader[MREADER], long long tienphat, bool matsach[MBOOKB]);
void Processing(int temp1, int index, int &BILLNUM, int BNUM, BILL bill[MREADER], READER reader[MREADER], BOOK book[MBOOK], bool matsach[MBOOKB], int &BOOKBORROW);

#endif