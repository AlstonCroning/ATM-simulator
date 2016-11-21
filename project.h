#ifndef PROJECT
#define PROJECT
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


/*************************************************BankerClass************************************************/
class Banker
{
private:
	string USER1NAME;
	string USER2NAME;
	int ACCOUNTNUMBER1;
	int ACCOUNTNUMBER2;

public:
	//variables
	int PASS;	
	int USRNME;
	int X, Y;

	//constructors
	Banker();
	Banker(string _USER1NAME, int _ACCOUNTNUMBER1, string _USER2NAME, int _ACCOUNTNUMBER2);

	//sets
	void setX(int _setX);
	void setY(int _setY);

	//gets
	void getUSER1NAME();
	void getUSER2NAME();
	int getX();
	int getY();

	//Functions
	int askUSER(int, int, int, int);
	Banker operator--();
	void Help();
};
/*************************************************BankerClass************************************************/






/*************************************************User1Class************************************************/

class User1 : public Banker
{
private:
	int MONEY;
	int PASSWORD;
	int USERNAME;
	int SELECT;
	string NAME;
	int ACCOUNTNUMBER1;
	double TOTALCHEKINGAMOUNT;
	double TOTALSAVINGSAMOUNT;
	double TOTALLINEOFCREDITAMOUNT;
	double TOTALCREDITCARDAMOUNT;

public:
	//Constructors
	User1();
	User1(string _NAME, int _ACCOUNTNUMBER1);

	//sets
	void setPASSWORD(int _setPASSWORD);
	void setUSERNAME(int _setUSERNAME);
	void setTOTALCHEKINGAMOUNT(double _setTOTALCHEKINGAMOUNT);
	void setTOTALSAVINGSAMOUNT(double _setTOTALSAVINGSAMOUNT);
	void setTOTALLINEOFCREDITAMOUNT(double _setTOTALLINEOFCREDITAMOUNT);
	void setTOTALCREDITCARDAMOUNT(double _setTOTALCREDITCARDAMOUNT);

	//gets
	int getPASSWORD();
	int getUSERNAME();
	int getACCOUNTNUMBER1();

	//Functions
	void displayTITLE();
	void userTRANSACTIONS();
	double depositMONEY(int _depositMONEY);
	double withdrawalMONEY(int _withdrawalMONEY);
	void clearSCREAN();
	void transferFunds();
	void transferfundsfromCHEKINGACCOUNT(int _passSELECT, int _passMONEY);
	void transferfundsfromSAVINGSACCOUNT(int _passSELECT, int _passMONEY);
	void transferfundsfromLINEOFCREDITACCOUNT(int _passSELECT, int _passMONEY);
	void transferfundsfromCREDITCARDACCOUNT(int _passSELECT, int _passMONEY);
};
/*************************************************User1Class************************************************/








/*************************************************User2Class************************************************/
class User2 : public Banker
{
private:
	int MONEY;
	int SELECT;
	string NAME;
	int ACCOUNTNUMBER2;
	int PASSWORD2;
	int USERNAME2;
	double TOTALCHEKINGAMOUNT;
	double TOTALSAVINGSAMOUNT;
	double TOTALLINEOFCREDITAMOUNT;
	double TOTALCREDITCARDAMOUNT;

public:
	//Constructors
	User2();
	User2(string _NAME, int ACCOUNTNUMBER2);

	//sets
	void setPASSWORD2(int _setPASSWORD);
	void setUSERNAME2(int _setUSERNAME);
	void setTOTALCHEKINGAMOUNT(double _setTOTALCHEKINGAMOUNT);
	void setTOTALSAVINGSAMOUNT(double _setTOTALSAVINGSAMOUNT);
	void setTOTALLINEOFCREDITAMOUNT(double _setTOTALLINEOFCREDITAMOUNT);
	void setTOTALCREDITCARDAMOUNT(double _setTOTALCREDITCARDAMOUNT);

	//gets
	int getPASSWORD2();
	int getUSERNAME2();
	int getACCOUNTNUMBER2();

	//Functions
	void displayTITLE();
	void userTRANSACTIONS();
	double depositMONEY(int _depositMONEY);
	double withdrawalMONEY(int _withdrawalMONEY);
	void clearSCREAN();
	void transferFunds();
	void transferfundsfromCHEKINGACCOUNT(int _passSELECT, int _passMONEY);
	void transferfundsfromSAVINGSACCOUNT(int _passSELECT, int _passMONEY);
	void transferfundsfromLINEOFCREDITACCOUNT(int _passSELECT, int _passMONEY);
	void transferfundsfromCREDITCARDACCOUNT(int _passSELECT, int _passMONEY);
};
/*************************************************User2Class************************************************/



#endif