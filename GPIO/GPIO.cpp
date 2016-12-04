#include "GPIO.h"

#include <fstream>

const std::string GPIO::export_path = "/sys/class/gpio/export";
const std::string GPIO::unexport_path = "/sys/class/gpio/unexport";


GPIO::GPIO(int pin, DIRECTION dir)
	: direction_path("/sys/class/gpio/gpio" + std::to_string(pin) + "/direction")
	, value_path("/sys/class/gpio/gpio" + std::to_string(pin) + "/value")
	, gpio_pin(std::to_string(pin))
{
	std::ofstream export_file(export_path.c_str());
	export_file << gpio_pin;
	export_file.close();

	std::ofstream direction_file(direction_path.c_str());
	direction_file << (dir == DIRECTION::IN ? "in" : "out");
	direction_file.close();
}

GPIO::~GPIO()
{
	std::ofstream unexport_file(export_path.c_str());
	unexport_file << gpio_pin;
	unexport_file.close();
}

void GPIO::setState(PIN state)
{
	std::ofstream value_file(value_path.c_str());
	value_file << (state != 0 ? "1" : "0");
	value_file.close();
}

std::string GPIO::getState()
{
	std::ifstream value_file(value_path.c_str());
	std::string state;
	value_file >> state;
	value_file.close();
	return (state != "0" ? "HIGH" : "LOW");
}

std::string GPIO::getPinNumber()
{
	return gpio_pin;
}
