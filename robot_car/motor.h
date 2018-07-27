#ifndef _MOTOR_
#define _MOTOR_

#include "ambiente.h"
#include <AFMotor.h>

class c_motor
{
	AF_DCMotor *motor;
	int potencia;
	int direcao;
public:
	c_motor(int);

	void set_potencia(int);

	int get_potencia() {return potencia;}
	int get_direcao()  {return direcao;}

	void frente();
	void tras();
	void para();

	void print();
};

class c_eixo
{
public:
	c_motor *direito;
	c_motor *esquerdo;
	c_eixo(int,int);

	void frente();
	void tras();
	void para();
	void esquerda();
	void direita();

	void print();
};
/**/
#endif
