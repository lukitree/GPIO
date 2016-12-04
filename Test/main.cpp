#include "../../GPIO/GPIO/GPIO.h"

#include <iostream>
#include <unistd.h>


int main(int argc, char *argv[])
{
	GPIO * pin4 = new GPIO(4, GPIO::OUT);

	const float SLEEP_TIME = 0.01f;

	while (1)
	{
		pin4->setState(LOW);
		//std::cout << "PIN4: " << pin4->getState() << std::endl;
		usleep(SLEEP_TIME * 1000000);

		pin4->setState(HIGH);
		//std::cout << "PIN4: " << pin4->getState() << std::endl;
		usleep(SLEEP_TIME * 1000000);
	}

	return 0;
}