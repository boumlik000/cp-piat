#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(/* args */)
{
    std::cout << "ScalarConverter Default constructor" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    (void)obj;
    std::cout << "ScalarConverter copy constructor" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    std::cout << "ScalarConverter operator constructor" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter Deconstructor" << std::endl;
}


// Function that converts ANY input to char and handles display
std::string charr(const std::string& input) {
    // First detect what type the input is
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        // It's a char literal like 'a'
        char c = input[1];
        return std::string("'") + c + "'";
    }
    
    // Check for special values
    if (input == "nanf" || input == "nan" || 
        input == "+inff" || input == "-inff" || input == "+inf" || input == "-inf") {
        return "impossible";
    }
    
    // Try to convert to number first
    double value;
    std::istringstream iss(input);
    if (!(iss >> value)) {
        return "impossible";
    }
    
    int intValue = static_cast<int>(value);
    
    // Check if it's in char range and displayable
    if (intValue < 0 || intValue > 127) {
        return "impossible";
    } else if (intValue < 32 || intValue == 127) {
        return "Non displayable";
    } else {
        char c = static_cast<char>(intValue);
        return std::string("'") + c + "'";
    }
}

// Function that converts ANY input to int
std::string innt(const std::string& input) {
    // Check for special values first
    if (input == "nanf" || input == "nan" || 
        input == "+inff" || input == "-inff" || input == "+inf" || input == "-inf") {
        return "impossible";
    }
    
    // Handle char literal
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        char c = input[1];
        std::ostringstream oss;
        oss << static_cast<int>(c);
        return oss.str();
    }
    
    // Try to convert to double first, then to int
    double value;
    std::istringstream iss(input);
    if (!(iss >> value)) {
        return "impossible";
    }
    
    // Check for overflow
    if (value > INT_MAX || value < INT_MIN) {
        return "impossible";
    }
    
    int intValue = static_cast<int>(value);
    std::ostringstream oss;
    oss << intValue;
    return oss.str();
}

// Function that converts ANY input to float
std::string flooat(const std::string& input) {
    // Handle special float values
    if (input == "nanf" || input == "nan") return "nanf";
    if (input == "+inff" || input == "+inf") return "+inff";
    if (input == "-inff" || input == "-inf") return "-inff";
    
    // Handle char literal
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        char c = input[1];
        float f = static_cast<float>(c);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << f << "f";
        return oss.str();
    }
    
    // Convert to float
    double value;
    std::istringstream iss(input);
    if (!(iss >> value)) {
        return "impossible";
    }
    
    float floatValue = static_cast<float>(value);
    
    // Format the output - detect decimal places from input
    std::ostringstream oss;
    size_t dotPos = input.find('.');
    if (dotPos != std::string::npos) {
        // Count decimal places in original input
        std::string afterDot = input.substr(dotPos + 1);
        if (!afterDot.empty() && afterDot[afterDot.length() - 1] == 'f') {
            afterDot = afterDot.substr(0, afterDot.length() - 1); // Remove 'f' if present
        }
        int precision = afterDot.length();
        oss << std::fixed << std::setprecision(precision) << floatValue << "f";
    } else {
        // Integer input, show as .0f
        oss << std::fixed << std::setprecision(1) << floatValue << "f";
    }
    return oss.str();
}

// Function that converts ANY input to double
std::string doouble(const std::string& input) {
    // Handle special double values
    if (input == "nanf" || input == "nan") return "nan";
    if (input == "+inff" || input == "+inf") return "+inf";
    if (input == "-inff" || input == "-inf") return "-inf";
    
    // Handle char literal
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') {
        char c = input[1];
        double d = static_cast<double>(c);
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(1) << d;
        return oss.str();
    }
    
    // Convert to double
    double value;
    std::istringstream iss(input);
    if (!(iss >> value)) {
        return "impossible";
    }
    
    // Format the output - detect decimal places from input
    std::ostringstream oss;
    size_t dotPos = input.find('.');
    if (dotPos != std::string::npos) {
        // Count decimal places in original input
        std::string afterDot = input.substr(dotPos + 1);
        int precision = afterDot.length();
        oss << std::fixed << std::setprecision(precision) << value;
    } else {
        // Integer input, show as .0
        oss << std::fixed << std::setprecision(1) << value;
    }
    return oss.str();
}


void ScalarConverter::convert(std::string& literal )
{

    std::cout << "ur input : " << literal << std::endl;
    std::cout << "---------------------" <<  std::endl;

    std::cout << "char : " <<  charr(literal) << std::endl;
    std::cout << "int : " << innt(literal) << std::endl;
    std::cout << "float : " << flooat(literal) << std::endl;
    std::cout << "double : " << doouble(literal) << std::endl;

}