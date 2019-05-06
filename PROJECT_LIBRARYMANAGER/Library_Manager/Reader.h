#ifndef _READER_
#define _READER_
#include "Header.h"
/*INPUT AND OUTPUT FILE*/
void InputReader(READER reader[MREADER], string file_name,int &RNUM);
void OutputReader(READER reader[MREADER], string file_name, int RNUM);
/*MENU*/
void MenuReader(int &RNUM, READER reader[MREADER]);
void MenuModifyAndDeleteReader(int &RNUM, READER reader[MREADER]);
void MenuInfoReader(int i, int &RNUM, READER reader[MREADER]);
void MenuModifyReader(int i, int RNUM, READER reader[MREADER]);
void MenuDelReader(int i, int &RNUM, READER reader[MREADER]);
void MenuSearchReader(int RNUM, READER reader[MREADER]);
/*FUNITION*/
void ScanReaderCode(int i, int RNUM, READER reader[MREADER]);
void ScanReaderSex(string &readersex);
void ScanReader(int &RNUM, READER reader[MREADER]);
void PrintReader(int i, int RNUM, READER reader[MREADER]);
void PrintALLReader(int RNUM, READER reader[MREADER]);


#endif