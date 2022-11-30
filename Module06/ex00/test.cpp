#include <iostream>
#include <string>
#include <stdlib.h> 
bool isNumeric(std::string const &str)
{
	char* p;
	strtol(str.c_str(), &p, 10);
	return *p == 0;
}

int main()
{
	std::string str = "32423fdsfds";

	std::cout << std::boolalpha << isNumeric(str) << std::endl;

	return 0;
}