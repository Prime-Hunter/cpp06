#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class ScalarConverter
{
    public:
        ScalarConverter();
        virtual ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator =(const ScalarConverter &src);

        static void convert(std::string litt);
};