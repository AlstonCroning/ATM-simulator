// ATMProjectBuildFinal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "project.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Banker bnkuser("Dishan",170,"Ramakanth",187);
	bnkuser.setX(5);
	bnkuser.setY(0);
	
	User1 us1("Dishan",170);
	User1 us1b;	us1b = us1;
	us1.setUSERNAME(300549609);
	us1.setPASSWORD(456);
	us1.setTOTALCHEKINGAMOUNT(5000);
	us1.setTOTALSAVINGSAMOUNT(500);
	us1.setTOTALLINEOFCREDITAMOUNT(2000);
	us1.setTOTALCREDITCARDAMOUNT(1500);

	User2 us2("Ramakanth",187);
	User2 us2b; us2b = us2;
	us2.setUSERNAME2(300577052); 
	us2.setPASSWORD2(123);
	us2.setTOTALCHEKINGAMOUNT(8000);
	us2.setTOTALSAVINGSAMOUNT(800);
	us2.setTOTALLINEOFCREDITAMOUNT(3000);
	us2.setTOTALCREDITCARDAMOUNT(2000);

	ofstream WriteToaFile;
	ifstream ReadFromaFile;
	
	WriteToaFile.open("User1.txt");
	WriteToaFile.write((char*) &us1, sizeof us1);
	WriteToaFile.close();

	ReadFromaFile.open("User1.txt");
	ReadFromaFile.read((char*) &us1b, sizeof us1b);
	ReadFromaFile.close();

	WriteToaFile.open("User2.txt");
	WriteToaFile.write((char*) &us2, sizeof us2);
	WriteToaFile.close();

	ReadFromaFile.open("User2.txt");
	ReadFromaFile.read((char*) &us2b, sizeof us2b);
	ReadFromaFile.close();

	for(int i = 0; ; i++)
	{
		us1.displayTITLE();
		bnkuser.askUSER(us1.getPASSWORD(),us1.getUSERNAME(), us2.getPASSWORD2(), us2.getUSERNAME2());
		
		if( (bnkuser.PASS == us1.getPASSWORD())  && (bnkuser.USRNME == us1.getUSERNAME()) )
		{
			cout << "\nWelcome ";
			bnkuser.getUSER1NAME();
			us1.userTRANSACTIONS();			
		}
		else if( (bnkuser.PASS == us2.getPASSWORD2() ) && (bnkuser.USRNME == us2.getUSERNAME2()) )
		{
			cout << "\nWelcome ";
			bnkuser.getUSER2NAME();
			us2.userTRANSACTIONS();			
		}
		else
		{
			cout << "\nIncorrect Password or Invalid ID\n";
			bnkuser.operator --();

			if(bnkuser.getX() == bnkuser.getY() )
			{
				cout << "Sorry, No More Attempts Allowed\n"; break;
			}
		}
	}

	system("pause");
	return 0;
}