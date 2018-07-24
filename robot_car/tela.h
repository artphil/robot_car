#ifndef _TELA_
#define _TELA_

#include <LiquidCrystal.h>
#include <string.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

class c_tela
{
	char linha1[16];
	char *linha1_nova;
	char linha2[16];
	char *linha2_nova;
public:
	void escreve();
	void set_linha1(String);
	void set_linha2(String);

	String get_linha1() {return linha1;}
	String get_linha2() {return linha2;}
};

#endif
