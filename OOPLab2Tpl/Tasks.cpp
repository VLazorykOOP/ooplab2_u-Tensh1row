#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
   	cout << "    Examples   \n";
	cout << "    1.  Expression calculation using bitwise operations \n";
	cout << "    2.  Encryption\n";
	cout << "    3.	 Encryption structure \n";
	cout << "    4.  TASK 4 - Bit image 8x8\n";
	cout << "    6.  Exit \n";

}
void Example1()
{
	int a, b, c, d, x, y;
	cout << "An example of calculating an expression using only bitwise operations.\n";
	cout << " Input a  b  c  d: ";

	cin >> a >> b >> c >> d;
	auto st = cin.rdstate();
	if (st != cin.goodbit) { cin.clear(); cout << " error \n"; cin.get(); cin.get(); return; }
	x = (((a << 7) + (a << 6) + (a<<3) + (c << 8) + (c << 6) - (c << 3)) >> 4) - ((d << 7) - (d << 3)) + (c << 7) - (c << 2);
	y = (200 * a + 312 * c) / 16 - d * 120 + c * 124;
	cout << "  x=" << x << "  y=" << y << " a=" << a << "  b=" << b << " c=" << c << " d=" << d << endl;
	cin.get();
}


void MyEncryption(char InS[128], unsigned short OutCoding[128])
{
	unsigned char c;
	unsigned short r, t, i, b;
	short j;
	for (i = 0; i < 128; i++)            
	{
		r = 0;					
		c = InS[i];                     
		t = c;
		r |= t;							
		r = r << 12;					
		r = r >> 12;					
		r |= i << 4;				
		t = t >> 4;				
		r |= t << 11;		 

		t = 1;
		b = 0;
		for (j = 0; j < 15; j++)         
		{
			if (r & t) {
				if (b == 0) b = 1; else b = 0;
			}
			t <<= 1;
		}
		r |= b << 15;                  
		OutCoding[i] = r;

		cout << "coded symbol '" << InS[i] << "' in pos [" << i << "]" << endl;
		cout << bitset<16>(OutCoding[i]) << endl;
	}
}
void Example2()
{
	unsigned short OutCoding[128];
	string string_text;

	cout << "Enter text: ";
	getline(cin, string_text);

	char char_text[128];
	//	strcpy(char_text, text.c_str());
	for (int i = 0; i < string_text.length(); i++)
	{
		char_text[i] = string_text[i];
		cout << char_text[i];
	}
	cout << "\n";
	if (string_text.length() != 128)
	{
		for (int i = string_text.length(); i < 128; i++)
		{
			char_text[i] = ' ';
		}
	}

	MyEncryption(char_text, OutCoding);
}


struct TextCode {
	unsigned short schkb : 4;
	unsigned short posrow : 7;
	unsigned short bitp : 1;
	unsigned short mchkb : 4;
};

unsigned char pbit(unsigned char c)
{
	unsigned char t = 1, b = 0;
	for (int j = 0; j < 16; j++)         
	{
		if (c & t) {
			if (b == 0) b = 1; else b = 0;
		}
		t <<= 1;
	}
	return b;
}

void MyEncryptionS(char InS[128], TextCode OutCoding[128])
{
	unsigned char c;
	unsigned short r, t, i;
	short j;
	for (i = 0; i < 128; i++)            
	{
		c = InS[i];                     
		OutCoding[i].mchkb = c & 0x0f;  
		OutCoding[i].posrow = i;       
		OutCoding[i].schkb = c >> 4;	
		
		r = pbit(c);
		t = pbit(static_cast<unsigned char>(i));
		OutCoding[i].bitp = r ^ t;     

		cout << "coded symbol '" << InS[i] << "' in pos [" << i << "]" << endl;
		cout << "the position of the character in the string : " << bitset<7>(OutCoding[i].posrow) << endl;
		cout << "older part code symbol : " << bitset<4>(OutCoding[i].schkb) << endl;
		cout << "younger part code symbol : " << bitset<4>(OutCoding[i].mchkb) << endl;
		cout << "even bit : " << bitset<1>(OutCoding[i].bitp) << endl;
	}
}


void Example3() {
	TextCode OutCoding[128];
	string string_text;

	cout << "Enter text: ";

	getline(cin, string_text);

	char char_text[128];
	for (int i = 0; i < string_text.length(); i++)
	{
		char_text[i] = string_text[i];
		cout << char_text[i];
	}
	cout << "\n";
	if (string_text.length() != 128)
	{
		for (int i = string_text.length(); i < 128; i++)
		{
			char_text[i] = ' ';
		}
	}

	MyEncryptionS(char_text, OutCoding);
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


