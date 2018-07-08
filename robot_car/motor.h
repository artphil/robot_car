#include <Adafruit_MotorShield.h>

class c_motor
{
	Adafruit_DCMotor *motor;
	int potencia;
	int direcao;
public:
	c_motor(int);
	void roda();
	void set_potencia(int);
	void set_direcao(int);

	int get_potencia() {return potencia;}
	int get_direcao()  {return direcao;}
}

class c_eixo
{
public:
	c_motor direito;
	c_motor esquerdo;
	c_eixo(int,int);
	void roda();
}
