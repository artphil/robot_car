#ifndef _TELA_
#define _TELA_

#include <LiquidCrystal.h>
#include <string.h>
#include "ambiente.h"

class c_tela
{
	String linha1;
	String linha1_nova;
	String linha2;
	String linha2_nova;
public:
	c_tela();
	void escreve();
	void set_linha1(String);
	void set_linha2(String);

	String get_linha1() {return linha1;}
	String get_linha2() {return linha2;}
};

int verifica_botao (); // Identifica qual botao foi acionado

#endif
