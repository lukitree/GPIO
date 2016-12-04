#pragma once

#include <string>

typedef enum { LOW, HIGH, } PIN;

class GPIO
{
public:
	typedef enum { IN, OUT, } DIRECTION;

public:
							GPIO(int pin, DIRECTION dir);
							~GPIO();

public:
	void					setState(PIN state);
	std::string				getState();

	std::string				getPinNumber();

private:
	std::string				gpio_pin;

private:
	static					const std::string export_path;
	static 					const std::string unexport_path;
	const					std::string direction_path;
	const					std::string value_path;
};
