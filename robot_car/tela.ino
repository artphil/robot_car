#include "tela.h"

void c_tela::escreve()
{
	if (strcmp(linha1, linha1_nova) != 0)
	{
		strcpy(linha1, linha1_nova);

		lcd.setCursor(0,0);
		lcd.print (linha1);
	}

	if (strcmp(linha2, linha2_nova) != 0)
	{
		strcpy(linha2, linha2_nova);

		lcd.setCursor(0,1);
		lcd.print (linha2);
	}
}

void c_tela::set_linha1(String stxt)
{
	char *txt = stxt.c_str();
	int tamanho = strlen(txt);
	for (int i = 0; i < 16; i++)
	{
		if (i < tamanho) linha1_nova[i] = txt[i];
		else linha2_nova[i] = ' ';
	}
}

void c_tela::set_linha2(String stxt)
{
	char *txt = stxt.c_str();
	int tamanho = strlen(txt);
	for (int i = 0; i < 16; i++)
	{
		if (i < tamanho) linha2_nova[i] = txt[i];
		else linha2_nova[i] = ' ';
	}
}
