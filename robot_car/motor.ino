#include "motor.h"

/*======= MOTOR =======*/
c_motor::c_motor(int pino)
{
	motor = AFMS.getMotor(pino);
	potencia = 100;
	direcao = RELEASE;
}

void c_motor::roda()
{
	motor->setSpeed(potencia);
	motor->run(direcao);
}

void c_motor::set_potencia(int p)
{
	if (p > 255) potencia = 255;
	else if (p < 0) potencia = 0;
	else potencia = p;
}

void c_motor::set_direcao(int d)
{
	if (p == 1) direcao = FORWARD;
	else if (p == 2) direcao = BACKWARD;
	else direcao = RELEASE;
}

/*======== EIXO ========*/
c_eixo::c_eixo(int m_e, int m_d)
{
	esquerdo = c_motor(m_e);
	direito = c_motor(m_d);
}

void c_eixo::roda()
{
	esquerdo.roda();
	sdireito.roda();
}
