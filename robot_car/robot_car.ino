#include "ambiente.h"

void setup()
{
	Serial.begin(9600);
	srand(millis());
	inicia_testes();
}

void loop()
{
	testes();
}
