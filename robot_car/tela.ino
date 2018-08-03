#include "tela.h"

static LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int verifica_botao ()
{
	int botao = analogRead (0); //Leitura do valor da porta analógica A0

	if (botao < 50) 		return DIREITA;
	else if (botao < 150) 	return CIMA;
	else if (botao < 300) 	return BAIXO;
	else if (botao < 500) 	return ESQUEDA;
	else if (botao < 800) 	return ESCOLHE;
	else					return 0;
}

c_tela::c_tela()
{
	linha1 = 		"                ";
	linha1_nova = 	"                ";
	linha2 =		"                ";
	linha2_nova =	"                ";
	lcd.begin(16, 2);
}

void c_tela::escreve()
{
	if (linha1 != linha1_nova)
	{
		linha1 = linha1_nova;

		lcd.setCursor(0,0);
		lcd.print (linha1);

 		Serial.println("Tela1 alterada");
		Serial.println(linha1);
	}

	if (linha2 != linha2_nova)
	{
		linha2 = linha2_nova;

		lcd.setCursor(0,1);
		lcd.print (linha2);

		Serial.println("Tela2 alterada");
		Serial.println(linha2);
	}
}

void c_tela::set_linha1(String stxt)
{
	char *txt = stxt.c_str();
	int tamanho = strlen(txt);
	linha1_nova = "";

	for (int i = 0; i < 16; i++)
	{
		if (i < tamanho) linha1_nova += txt[i];
		else linha2_nova += ' ';
	}
}

void c_tela::set_linha2(String stxt)
{
	char *txt = stxt.c_str();
	int tamanho = strlen(txt);
	linha2_nova = "";

	for (int i = 0; i < 16; i++)
	{
		if (i < tamanho) linha2_nova += txt[i];
		else linha2_nova += ' ';
	}
}
