#include "stdafx.h"
#include "project.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


/*************************************************Banker************************************************/
Banker Banker::operator--()
{
	X--;
	return *this;
}

Banker::Banker()
{
	ACCOUNTNUMBER1 = ACCOUNTNUMBER2 = 0;
}
Banker::Banker(string _USER1NAME, int _ACCOUNTNUMBER1, string _USER2NAME, int _ACCOUNTNUMBER2)
{
	USER1NAME = _USER1NAME;
	ACCOUNTNUMBER1 = _ACCOUNTNUMBER1;

	USER2NAME = _USER2NAME;
	ACCOUNTNUMBER2 = _ACCOUNTNUMBER2;
}

void Banker::getUSER1NAME()
{
	cout << USER1NAME;
}

void Banker::getUSER2NAME()
{
	cout << USER2NAME;
}

int Banker::getX()
{
	return X;
}

int Banker::getY()
{
	return Y;
}

void Banker::setX(int _setX)
{
	X = _setX;
}

void Banker::setY(int _setY)
{
	Y = _setY;
}

int Banker::askUSER(int _passdapassword1, int _passdausername1, int _passdapassword2, int _passdausername2)
{
	cout << "Welcome\n\n";
	cout << "Enter your Username: ";
	cin >> USRNME;

	if(USRNME == _passdausername1)
	{
		cout << "Please Enter Your Password: ";
		cin >> PASS;
		return PASS;
	}

	else if(USRNME == _passdausername2)
	{
		cout << "Please Enter Your Password: ";
		cin >> PASS;
		return PASS;
	}
	return 0;
}

void Banker::Help()
{
	cout << "\n\nHellow Customer,\n";
	cout << "Thank you for using the ATM. ";
	cout << "Your Banking can now become more easier at any ATM." 
		<< "The Following are important to know\n\n"
		<< "* Deposit , withdrwal, or Transfering funds are the only Transactions available in this ATM. "
		<< "However, this ATM is quite useful for basic usage.\n\n"
		<< "* Transfering Funds upto 4 accounts are possible.\n(Cheking, Savings, LineofCredit, CreditCard)\n\n"
		<< "* Banking Statement, Clear screen, and Help are features available in the ATM.\n\n";
	system("pause");
}
/*************************************************Banker************************************************/








/*************************************************User1************************************************/
User1::User1()
{	
	ACCOUNTNUMBER1 = PASSWORD = USERNAME;
	TOTALCHEKINGAMOUNT = TOTALSAVINGSAMOUNT = TOTALLINEOFCREDITAMOUNT = TOTALCREDITCARDAMOUNT = 0;
}
User1::User1(string _NAME, int _ACCOUNTNUMBER1)
{
	NAME = _NAME;
	ACCOUNTNUMBER1 = _ACCOUNTNUMBER1;
}

void User1::setPASSWORD(int _setPASSWORD)
{
	PASSWORD = _setPASSWORD;
}

void User1::setUSERNAME(int _setUSERNAME)
{
	USERNAME = _setUSERNAME;
}

void User1::setTOTALCHEKINGAMOUNT(double _setTOTALCHEKINGAMOUNT)
{
	TOTALCHEKINGAMOUNT = _setTOTALCHEKINGAMOUNT;
}

void User1::setTOTALSAVINGSAMOUNT(double _setTOTALSAVINGSAMOUNT)
{
	TOTALSAVINGSAMOUNT = _setTOTALSAVINGSAMOUNT;
}

void User1::setTOTALLINEOFCREDITAMOUNT(double _setTOTALLINEOFCREDITAMOUNT)
{
	TOTALLINEOFCREDITAMOUNT = _setTOTALLINEOFCREDITAMOUNT;
}

void User1::setTOTALCREDITCARDAMOUNT(double _setTOTALCREDITCARDAMOUNT)
{
	TOTALCREDITCARDAMOUNT = _setTOTALCREDITCARDAMOUNT;
}

int User1::getUSERNAME()
{
	return USERNAME;
}

int User1::getPASSWORD()
{
	return PASSWORD;
}

int User1::getACCOUNTNUMBER1()
{
	return ACCOUNTNUMBER1;
}

void User1::displayTITLE()
{
	cout << "			Automated Teller Machine\n";
	cout << "				(A T M)\n";
}

void User1::userTRANSACTIONS()
{
	cout << "\nChoose Your Transaction\n\n";
	cout << "1: Deposit		2: Withdraw\n"
			<< "3: Transfer Funds	4: Banking Statement\n"
			<< "5: Clear Screen		6: Log out\n7: Help\n";
		
	cin >> SELECT;

	switch(SELECT)
	{
	case 1:
		{
			cout << "\nHow much money do you want to deposit?" << endl;
			cin >> MONEY;

				if(MONEY <= 0)
				{
					cout << "\nInvalid Amount Entered!!\n\n";
				}

				else
				{
					depositMONEY(MONEY);
					cout << "\n$" << MONEY << " deposited into your Checking Account\n";
					cout << "Total Amount in Checking account is $" << TOTALCHEKINGAMOUNT << "\n" << endl;
				}
				userTRANSACTIONS();
		}break;

	case 2:
		{
			cout << "\nHow much money do you want to withdrawal?" << endl;
			cin >> MONEY;

			if(MONEY <= 0)
			{
				cout << "\nInvalid Amount Entered!!\n\n";
			}

			else if( MONEY > TOTALCHEKINGAMOUNT)
			{
				cout << "\nUnable to Withdrawal money because not enough credit in Account\n\n";
			}

			else
			{
				withdrawalMONEY(MONEY);
				cout << "\n$" << MONEY << " eased from your Account\n";
				cout << "Total Amount in Checking account is $" << TOTALCHEKINGAMOUNT << "\n" << endl;
			}
				userTRANSACTIONS();
		}break;

	case 3:
		{				
			transferFunds();
			userTRANSACTIONS();
		}break;

	case 4:
		{
			cout << "\n\n			Dishan's Bank Statement\n";
			cout << "			     Account #" << getACCOUNTNUMBER1() << "\n\n";
			cout << "\Cheking Account Total is $" << TOTALCHEKINGAMOUNT;
			cout << "\nSavings Account Total is $" << TOTALSAVINGSAMOUNT;
			cout << "\nLine of Credit $" << TOTALLINEOFCREDITAMOUNT;
			cout << "\nCreditCard Account Total is $" << TOTALCREDITCARDAMOUNT;
			cout << "\n\n";
			system("pause");
			cout << "\n";
			userTRANSACTIONS();
		}break;

	case 5:
		{
			clearSCREAN();
			displayTITLE();
			userTRANSACTIONS();
		}break;

	case 6:
		{
			clearSCREAN();
			displayTITLE();
			cout << "\nLogging out...\n";
			cout << "Thank you for using the ATM\n";
				
			//used for delay, before the screen is cleared
			for(int x = 0; x < 2000; x++)
			{
				for(int y = 0; y < 1000000; y++)
				{
				}
			}
			clearSCREAN();
		}break;

	case 7:
		{
			Help();
			userTRANSACTIONS();
		}
	}
}

double User1::depositMONEY(int _depositMONEY)
{
	TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _depositMONEY;

	return TOTALCHEKINGAMOUNT;
}

double User1::withdrawalMONEY(int _withdrawalMONEY)
{
	TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _withdrawalMONEY;
	return TOTALCHEKINGAMOUNT;
}

void User1::clearSCREAN()
{
	system("cls");
}

void User1::transferFunds()
{
	cout << "\nWhich Account do You want to Transfer Money From?\n";
	cout << "1: Checking Account	2: Savings Account	3: Line Of Credit\n4: CreditCard\n";
	cin >> SELECT;

	switch(SELECT)
	{
	case 1:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "2: Savings Account	3: Line Of Credit	4: CreditCard\n";
			cin >> SELECT;

			if(SELECT == 2)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCHEKINGACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 3)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCHEKINGACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 4)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCHEKINGACCOUNT(SELECT,MONEY);
			}
		}break;

	case 2:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "1: Checking Account	3: Line Of Credit	4: CreditCard\n";
			cin >> SELECT;

			if(SELECT == 1)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromSAVINGSACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 3)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromSAVINGSACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 4)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromSAVINGSACCOUNT(SELECT,MONEY);
			}
		}break;

	case 3:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "1: Checking Account	2: Savings Account	4: CreditCard\n";
			cin >> SELECT;

			if(SELECT == 1)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromLINEOFCREDITACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 2)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromLINEOFCREDITACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 4)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromLINEOFCREDITACCOUNT(SELECT,MONEY);
			}
		}break;

	case 4:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "1: Checking Account	2: Savings Account	3: Line Of Credit\n";
			cin >> SELECT;

			if(SELECT == 1)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCREDITCARDACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 2)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCREDITCARDACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 3)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCREDITCARDACCOUNT(SELECT,MONEY);
			}
		}break;
	}
}

void User1::transferfundsfromCHEKINGACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 2)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT + _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _passMONEY;
	}

	else if(_passSELECT == 3)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT + _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _passMONEY;
	}

	else if(_passSELECT == 4)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT + _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _passMONEY;
	}
}

void User1::transferfundsfromSAVINGSACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 1)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT - _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 3)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT - _passMONEY;
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 4)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT - _passMONEY;
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT + _passMONEY;
	}
}

void User1::transferfundsfromLINEOFCREDITACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 1)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT - _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 2)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT - _passMONEY;
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 4)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT - _passMONEY;
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT + _passMONEY;
	}
}

void User1::transferfundsfromCREDITCARDACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 1)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT - _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _passMONEY;
	}
	
	else if(_passSELECT == 2)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT - _passMONEY;
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 3)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT - _passMONEY;
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT + _passMONEY;
	}
}
/*************************************************User1************************************************/











/*************************************************User2************************************************/
User2::User2()
{
	ACCOUNTNUMBER2 = PASSWORD2 = USERNAME2 = 0;
	TOTALCHEKINGAMOUNT = TOTALSAVINGSAMOUNT = TOTALLINEOFCREDITAMOUNT = TOTALCREDITCARDAMOUNT = 0;
}

User2::User2(string _NAME, int _ACCOUNTNUMBER2)
{
	NAME = _NAME;
	ACCOUNTNUMBER2 = _ACCOUNTNUMBER2;
}

void User2::setPASSWORD2(int _setPASSWORD)
{
	PASSWORD2 = _setPASSWORD;
}

void User2::setUSERNAME2(int _setUSERNAME)
{
	USERNAME2 = _setUSERNAME;
}

void User2::setTOTALCHEKINGAMOUNT(double _setTOTALCHEKINGAMOUNT)
{
	TOTALCHEKINGAMOUNT = _setTOTALCHEKINGAMOUNT;
}

void User2::setTOTALSAVINGSAMOUNT(double _setTOTALSAVINGSAMOUNT)
{
	TOTALSAVINGSAMOUNT = _setTOTALSAVINGSAMOUNT;
}

void User2::setTOTALLINEOFCREDITAMOUNT(double _setTOTALLINEOFCREDITAMOUNT)
{
	TOTALLINEOFCREDITAMOUNT = _setTOTALLINEOFCREDITAMOUNT;
}

void User2::setTOTALCREDITCARDAMOUNT(double _setTOTALCREDITCARDAMOUNT)
{
	TOTALCREDITCARDAMOUNT = _setTOTALCREDITCARDAMOUNT;
}

int User2::getUSERNAME2()
{
	return USERNAME2;
}

int User2::getPASSWORD2()
{
	return PASSWORD2;
}

int User2::getACCOUNTNUMBER2()
{
	return ACCOUNTNUMBER2;
}

void User2::displayTITLE()
{
	cout << "			Automated Teller Machine\n";
	cout << "				(A T M)\n";
}

void User2::userTRANSACTIONS()
{

	cout << "\nChoose Your Transaction\n\n";
	cout << "1: Deposit		2: Withdraw\n"
			<< "3: Transfer Funds	4: Banking Statement\n"
			<< "5: Clear Screen		6: Log out\n7: Help\n";
		
	cin >> SELECT;

	switch(SELECT)
	{
	case 1:
		{
			cout << "\nHow much money do you want to deposit?" << endl;
			cin >> MONEY;

			if(MONEY <= 0)
			{
				cout << "\nInvalid Amount Entered!!\n\n";
			}

			else
			{
				depositMONEY(MONEY);
				cout << "\n$" << MONEY << " deposited into your Checking Account\n";
				cout << "Total Amount in Checking account is $" << TOTALCHEKINGAMOUNT << "\n" << endl;
			}
			userTRANSACTIONS();
		}break;

	case 2:
		{
			cout << "\nHow much money do you want to withdrawal?" << endl;
			cin >> MONEY;

			if(MONEY <= 0)
			{
				cout << "\nInvalid Amount Entered!!\n\n";
			}

			else if( MONEY > TOTALCHEKINGAMOUNT)
			{
				cout << "\nUnable to Withdrawal money because not enough credit in Account\n\n";
			}

			else
			{
				withdrawalMONEY(MONEY);
				cout << "\n$" << MONEY << " eased from your Account\n";
				cout << "Total Amount in Cheking account is $" << TOTALCHEKINGAMOUNT << "\n" << endl;
			}
				userTRANSACTIONS();
		}break;

	case 3:
		{				
			transferFunds();
			userTRANSACTIONS();
		}break;

	case 4:
		{
			cout << "\n\n			Ramakanth's Bank Statement\n";
			cout << "			        Account #" << getACCOUNTNUMBER2() << "\n\n";
			cout << "\Cheking Account Total is $" << TOTALCHEKINGAMOUNT;
			cout << "\nSavings Account Total is $" << TOTALSAVINGSAMOUNT;
			cout << "\nLine of Credit $" << TOTALLINEOFCREDITAMOUNT;
			cout << "\nCreditCard Account Total is $" << TOTALCREDITCARDAMOUNT;
			cout << "\n\n";
			system("pause");
			cout << "\n";
			userTRANSACTIONS();
		}break;

	case 5:
		{
			clearSCREAN();
			displayTITLE();
			userTRANSACTIONS();
		}break;

	case 6:
		{
			clearSCREAN();
			displayTITLE();
			cout << "\nLogging out...\n";
			cout << "Thank you for using the ATM\n";
				
			//used for delay, before the screen is cleared
			for(int x = 0; x < 2000; x++)
			{
				for(int y = 0; y < 1000000; y++)
				{
				}
			}
			clearSCREAN();
		}break;

	case 7:
		{
			Help();
			userTRANSACTIONS();
		}
	}
}

double User2::depositMONEY(int _depositMONEY)
{
	TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _depositMONEY;

	return TOTALCHEKINGAMOUNT;
}

double User2::withdrawalMONEY(int _withdrawalMONEY)
{
	TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _withdrawalMONEY;
	return TOTALCHEKINGAMOUNT;
}

void User2::clearSCREAN()
{
	system("cls");
}

void User2::transferFunds()
{
	cout << "\nWhich Account do You want to Transfer Money From?\n";
	cout << "1: Checking Account	2: Savings Account	3: Line Of Credit	4: CreditCard\n";
	cin >> SELECT;

	switch(SELECT)
	{
	case 1:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "2: Savings Account	3: Line Of Credit	4: CreditCard\n";
			cin >> SELECT;

			if(SELECT == 2)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCHEKINGACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 3)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCHEKINGACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 4)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCHEKINGACCOUNT(SELECT,MONEY);
			}
		}break;

	case 2:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "1: Checking Account	3: Line Of Credit	4: CreditCard\n";
			cin >> SELECT;

			if(SELECT == 1)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromSAVINGSACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 3)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromSAVINGSACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 4)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromSAVINGSACCOUNT(SELECT,MONEY);
			}
		}break;


	case 3:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "1: Checking Account	2: Savings Account	4: CreditCard\n";
			cin >> SELECT;

			if(SELECT == 1)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromLINEOFCREDITACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 2)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromLINEOFCREDITACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 4)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromLINEOFCREDITACCOUNT(SELECT,MONEY);
			}
		}break;
		
	case 4:
		{
			cout << "\nWhich Account do you want to Transfer your money To\n";
			cout << "1: Checking Account	2: Savings Account	3: Line Of Credit\n";
			cin >> SELECT;

			if(SELECT == 1)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCREDITCARDACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 2)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCREDITCARDACCOUNT(SELECT,MONEY);
			}

			else if(SELECT == 3)
			{
				cout << "How Much Money?";
				cin >> MONEY;
				transferfundsfromCREDITCARDACCOUNT(SELECT,MONEY);
			}		
		}break;
	}
}

void User2::transferfundsfromCHEKINGACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 2)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT + _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _passMONEY;
	}

	else if(_passSELECT == 3)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT + _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _passMONEY;
	}

	else if(_passSELECT == 4)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT + _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT - _passMONEY;
	}
}

void User2::transferfundsfromSAVINGSACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 1)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT - _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 3)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT - _passMONEY;
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 4)
	{
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT - _passMONEY;
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT + _passMONEY;
	}
}

void User2::transferfundsfromLINEOFCREDITACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 1)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT - _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 2)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT - _passMONEY;
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 4)
	{
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT - _passMONEY;
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT + _passMONEY;
	}
}

void User2::transferfundsfromCREDITCARDACCOUNT(int _passSELECT, int _passMONEY)
{
	if(_passSELECT == 1)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT - _passMONEY;
		TOTALCHEKINGAMOUNT = TOTALCHEKINGAMOUNT + _passMONEY;
	}
	
	else if(_passSELECT == 2)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT - _passMONEY;
		TOTALSAVINGSAMOUNT = TOTALSAVINGSAMOUNT + _passMONEY;
	}

	else if(_passSELECT == 3)
	{
		TOTALCREDITCARDAMOUNT = TOTALCREDITCARDAMOUNT - _passMONEY;
		TOTALLINEOFCREDITAMOUNT = TOTALLINEOFCREDITAMOUNT + _passMONEY;
	}
}
/*************************************************User2************************************************/
