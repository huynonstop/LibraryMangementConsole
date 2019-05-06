#ifndef _DATASTR_
#define _DATASTR_
#include<string>
#include "Header.h"
using namespace std;
/*
int day;
int month;
int year;
*/
struct DATE
{
	int day;
	int month;
	int year;
};
/*
string Rcode;
string Rname;
string Ridentity;
string Rsex;
string Remail;
string Raddress;
DATE Rdob;
DATE Rstart;
DATE Rend;
bool Rmode;
*/
struct READER
{
	string Rcode;
	string Rname;
	string Ridentity;
	string Rsex;
	string Remail;
	string Raddress;
	DATE Rdob;
	DATE Rstart;
	DATE Rend;
	bool Rmode;
	bool Late;
};
/*
string Bcode;
string Bname;
string Bauthor;
string Bpublisher;
string Bypub;
string Btype;
int Bnum;
int Bprice;
int Bborrownum;
*/
struct BOOK
{
	string Bcode;
	string Bname;
	string Bauthor;
	string Bpublisher;
	string Bypub;
	string Btype;
	int Bnum;
	int Bprice;
	int Bborrownum;
};
/*
string Rcode;
string ISBNBorrow[MBOOKB];
int NumBorrow;
DATE DateBorrow;
DATE DateReturnExpect;
DATE DateReturnReal;
*/
struct BILL
{
	string Rcode;
	int NumBorrow;
	string ISBNBorrow[MBOOKB];
	DATE DateBorrow;
	DATE DateReturnExpect;
	DATE DateReturnReal;
};
#endif