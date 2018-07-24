#include "testes.h"

c_eixo eixo_teste(MOTOR_PIN_ESQ, MOTOR_PIN_DIR);
int p = 1;

void teste_motor();

void inicia_testes()
{
	eixo_teste.esquerdo->set_potencia(128);
	eixo_teste.direito->set_potencia(128);
}

void testes()
{
	teste_motor();
}

void teste_motor()
{
	int pot;
	eixo_teste.frente();

	pot = eixo_teste.esquerdo->get_potencia();

	if (pot == 255 || pot == 0) p = -p;
	pot += p;

	eixo_teste.esquerdo->set_potencia(pot);

	pot = eixo_teste.esquerdo->get_potencia();
	pot -= p;

	eixo_teste.direito->set_potencia(pot);
}
