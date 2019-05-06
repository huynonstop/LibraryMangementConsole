#ifndef _BOOK_
#define _BOOK_
#include "Header.h"
/*INPUT AND OUTPUT FILE*/
void InputBook(BOOK book[MBOOK], string file_name, int &BNUM);
void OutputBook(BOOK book[MBOOK], string file_name, int BNUM);
/*MENU*/
void MenuBook(int &BNUM, BOOK book[MBOOK]);
void MenuModifyAndDeleteBook(int &BNUM, BOOK book[MBOOK]);
void MenuInfoBook(int i, int &BNUM, BOOK book[MBOOK]);
void MenuModifyBook(int i, int BNUM, BOOK book[MBOOK]);
void MenuDelBook(int i, int &BNUM, BOOK book[MBOOK]);
void MenuSearchBook(int BNUM, BOOK book[MBOOK]);
/*FUNITION*/
void ScanBookNum(int &numberbook);
void ScanBookPrice(int &price);
void ScanBookCode(int i, int BNUM, BOOK book[MBOOK]);
void ScanBook(int &BNUM, BOOK book[MBOOK]);
void PrintBook(int i, int BNUM, BOOK book[MBOOK]);
void PrintALLBook(int BNUM, BOOK book[MBOOK]);
#endif