#include "motor.h"

/*======= MOTOR =======*/
c_motor::c_motor(int pino)
{
	motor = AFMS.getMotor(pino);
	potencia = 100;
	direcao = RELEASE;
}

void c_motor::frente()
{
	if (direcao != FORWARD)
	{
		direcao = FORWARD;
		motor->run(direcao);
	}
}

void c_motor::tras()
{
	if (direcao != BACKWARD)
	{
		direcao = BACKWARD;
		motor->run(direcao);
	}
}

void c_motor::para()
{
	if (direcao != RELEASE)
	{
		direcao = RELEASE;
		motor->run(direcao);
	}
}

void c_motor::set_potencia(int p)
{
	if (p > 255) 	potencia = 255;
	else if (p < 0) potencia = 0;
	else 			potencia = p;

	motor->setSpeed(potencia);
}

void c_motor::print()
{
	Serial.println("Descricao do Motor");
	Serial.println("Potencia: " + potencia);
	Serial.print("Direcao: ");
	if (direcao == FORWARD)  Serial.println("Frente");
	else if (direcao == BACKWARD) Serial.println("Tras");
	else Serial.println("Parado");
}

/*======== EIXO ========*/
c_eixo::c_eixo(int m_e, int m_d)
{
	esquerdo = new c_motor(m_e);
	direito = new c_motor(m_d);
}

void c_eixo::frente()
{
	esquerdo->frente();
	direito->frente();
}

void c_eixo::tras()
{
	esquerdo->tras();
	direito->tras();
}

void c_eixo::para()
{
	esquerdo->para();
	direito->para();
}

void c_eixo::esquerda()
{
	esquerdo->tras();
	direito->frente();
}

void c_eixo::direita()
{
	esquerdo->frente();
	direito->tras();
}

void c_eixo::print()
{
	Serial.println("Motor Esquerdo");
	esquerdo->print();

	Serial.println("Motor Direito");
	direito->print();
}
