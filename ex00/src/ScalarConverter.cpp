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
                    return (0);
                }
            }
            else
            {
                if (!isNum(litt[i]))
                {
                    if (litt[i] == 'f' && litt[i+1] == 0)
                        letters = letters+0;
                    else
                        letters++;
                }
                if (sign + letters > 1)
                {
                    return (0);
                }
                if (litt[i] == '.')
                {
                    if (litt[i+1] == 0 || !isNum(litt[i+1]))
                        return (0);
                    if (!comma)
                        comma++;
                    else
                    {
                        return (0);
                    }
                }
            }
        }
        else
        {
            return (0);
        }
        i++;
    }
    return (1);
}

static int isChar(std::string litt)
{
    if (litt[1] != 0)
    {
        return (0);
    }
    if (isNum(litt[0]))
        return (0);
    return (1);
}

static double reformatLitt(std::string litt)
{
    int i = 0;
    int j = 0;
    int sign = 0;
    std::string *newLitt = new std::string;
    if (litt[0] == '+' || litt[0] == '-')
    {
        if (litt[0] == '-')
            sign++;
        i = 1;
    }
    while (litt[i] != 0)
    {
        if (litt[i] == 'f')
            break;
        newLitt[j] = &litt[i];
        i++;
        j++;
    }
    std::stringstream ss(*newLitt);
    double subNum;
    ss >> subNum;
    if (sign)
        subNum *= -1;
    return (subNum);
}

void ScalarConverter::convert(std::string litt)
{
    if (!isConvertible(litt))
    {
        std::cout << "Non convertible" << std::endl;
        return ;
    }
    else
    {
        if (isChar(litt))
        {
            std::cout << "char   : " << litt[0] << std::endl;
            std::cout << "int    : " << static_cast<int>(litt[0]) << std::endl;
            std::cout << "float  : " << static_cast<float>(litt[0]) << "f" << std::endl;
            std::cout << "double : " << static_cast<double>(litt[0]) << std::endl;
        }
        else
        {
            double subNum = reformatLitt(litt);
            if (isPrintable(subNum))
                std::cout << "char   : " << static_cast<char>(subNum) << std::endl;
            else
                std::cout << "char   : could not convert;" << std::endl;
            std::cout << "int    : " << static_cast<int>(subNum) << std::endl;
            std::cout << "float  : " << static_cast<float>(subNum) << "f" << std::endl;
            std::cout << "double : " << subNum << std::endl;
        }
    }
}