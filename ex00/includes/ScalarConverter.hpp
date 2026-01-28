#include <iostream>
#include <string>

class ScalarConverter
{
    public:
        ScalarConverter();
        ~ScalarConnverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator =(const ScalarConverter &src);

        static void convert(std::string obj);
}