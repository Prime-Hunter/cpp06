#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter deconstructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void) src;
    std::cout << "ScalarConverter assignation operator called" << std::endl;
    return *this;
}

static int isPrintable(char c)
{
    if (31 < c && c < 127)
        return (1);
    return (0);
}

static int isNum(char c)
{
    if (47 < c && c < 58)
        return (1);
    return (0);
}

static int isConvertible(std::string litt)
{
    int i = 0;
    int comma = 0;
    int sign = 0;
    int letters = 0;
    while (litt[i] != 0)
    {
        if (isPrintable(litt[i]))
        {
            if (i == 0 && !isNum(litt[i]))
            {
                if (litt[i] == '+' || litt[i] == '-')
                    sign++;
                else if (litt[1] == 0)
                {
                    letters++;
                }
                else
                {
                    std::cout << "---TC1---" << i << std::endl;
                    std::cout << "- i: " << i << std::endl;
                    std::cout << "- sign: " << sign << std::endl;
                    std::cout << "- letters: " << letters << std::endl;
                    std::cout << "- comma: " << comma << std::endl;
                    return (0);
                }
            }
            else
            {
                if (!isNum(litt[i]))
                    letters++;
                if (sign + letters > 1)
                {
                    std::cout << "---TC2---" << i << std::endl;
                    std::cout << "- i: " << i << std::endl;
                    std::cout << "- sign: " << sign << std::endl;
                    std::cout << "- letters: " << letters << std::endl;
                    std::cout << "- comma: " << comma << std::endl;
                    return (0);
                }
                if (litt[i] == '.')
                {
                    if (!comma)
                        comma++;
                    else
                    {
                        std::cout << "---TC3---" << i << std::endl;
                        std::cout << "- i: " << i << std::endl;
                        std::cout << "- sign: " << sign << std::endl;
                        std::cout << "- letters: " << letters << std::endl;
                        std::cout << "- comma: " << comma << std::endl;
                        return (0);
                    }
                }
            }
        }
        else
        {
            std::cout << "- i: " << i << std::endl;
            std::cout << "- sign: " << sign << std::endl;
            std::cout << "- letters: " << letters << std::endl;
            std::cout << "- comma: " << comma << std::endl;
            return (0);
        }
        i++;
    }
    return (1);
}

void ScalarConverter::convert(std::string litt)
{
    if (isConvertible(litt))
        std::cout << "Convertible" << std::endl;
    else
        std::cout << "Non convertible" << std::endl;
}