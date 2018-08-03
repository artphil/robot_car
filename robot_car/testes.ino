#include "testes.h"

// Funcoes internas
void teste_motor();
void teste_eixo();
void teste_tela();

// Implementacoes
void inicia_testes()
{

}

void testes()
{
	// teste_motor();
	teste_eixo();
	// teste_tela();
}

void teste_motor()
{
	c_motor motor_E(MOTOR_PIN_ESQ);
	c_motor motor_D(MOTOR_PIN_DIR);
	int pot, p = 1;

	while (true)
	{
		Serial.println("Motor E");
		motor_E.print();
		Serial.println("Motor D");
		motor_D.print();

		motor_E.frente();
		motor_D.frente();

		pot = motor_E.get_potencia();

		if (pot == 255 || pot == 0) p = -p;
		pot += p;

		motor_E.set_potencia(pot);

		pot = motor_D.get_potencia();
		pot -= p;

		motor_D.set_potencia(pot);

		delay(50);
	}
}

void teste_eixo()
{
	c_eixo eixo_teste(MOTOR_PIN_ESQ, MOTOR_PIN_DIR);
	int pot, p = 1;

	while (true)
	{
		eixo_teste.print();

		eixo_teste.frente();

		pot = eixo_teste.esquerdo->get_potencia();

		if (pot == 255 || pot == 0) p = -p;
		pot += p;

		eixo_teste.esquerdo->set_potencia(pot);

		eixo_teste.direito->set_potencia(pot);

		delay(50);
	}
}

void teste_tela()
{
	c_tela tela_teste;

	Serial.println("prints");
	Serial.println(tela_teste.get_linha1());
	Serial.println(tela_teste.get_linha2());

	tela_teste.set_linha1("Testa tela");
	tela_teste.escreve();

	while (true)
	{
		int b = verifica_botao();
		switch (b)
		{
			case DIREITA:
			tela_teste.set_linha2("DIREITA");
			break;

			case ESQUEDA:
			tela_teste.set_linha2(" ESQUEDA");
			break;

			case CIMA:
			tela_teste.set_linha2("  CIMA");
			break;

			case BAIXO:
			tela_teste.set_linha2("   BAIXO");
			break;

			case ESCOLHE:
			tela_teste.set_linha2("    ESCOLHE");
			break;

		}
		tela_teste.escreve();
	}
}

/**/
