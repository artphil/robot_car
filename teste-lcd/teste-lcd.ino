// Programa : Teste LCD 16x2 com Keypad

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
// LiquidCrystal lcd(12, 11, 19, 4, 5, 6, 7);


void setup()
{
	lcd.begin(16, 2);
	lcd.setCursor(0,0);
	lcd.print("LCD Key Shield Test size");
	lcd.setCursor(0,1);
	lcd.print("Tecla: ");

	Serial.begin(9600);
}

void loop()
{
	int botao;
	botao = analogRead (0);  //Leitura do valor da porta analógica A0

	Serial.print(" Tecla valor: ");
	Serial.println(botao);

	lcd.setCursor(7,1);
	if (botao < 50) {
		lcd.print ("Direita");
	}
	else if (botao < 150) {
		lcd.print ("Cima    ");
	}
	else if (botao < 350){
		lcd.print ("Baixo    ");
	}
	else if (botao < 500){
		lcd.print ("Esquerda");
	}
	else if (botao < 800){
		lcd.print ("Select   ");
	}
}
