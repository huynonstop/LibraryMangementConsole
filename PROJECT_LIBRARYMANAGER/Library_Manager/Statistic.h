#ifndef _THONGKE_
#define _THONGKE_
#include "Header.h"
void MenuStatistic(int BOOKBORROW, int RNUM, int BNUM, READER reader[MREADER], BOOK book[MBOOK]);
int NumOfType(int BNUM, BOOK book[MBOOK], string temp[MBOOK]);
void NumBookPerType(int BNUM, int KNUM, BOOK book[MBOOK], string temp[MBOOK], int NumTemp[MBOOK]);
void StaNumType(int BNUM, BOOK book[MBOOK]);
void NumPerSex(int RNUM, READER reader[MREADER]);
void NumLate(int RNUM, READER reader[MREADER]);
#endif