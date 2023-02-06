#include "../inc/convert.hpp"

// OOCP
Convert::Convert() : 
    _data("unset")
 {}

Convert::Convert(std::string data) :
    _data(data)
{}

Convert::Convert(const Convert& other) :
    _data(other._data)
{}

Convert::~Convert() {}

Convert& Convert::operator=(const Convert& other) {
    _data = other._data;
    return *this;
}

// DETECT INCOMING DATA
void Convert::detectType() {
    int dataLen = _data.length();
    int dots = 0;
    if (checkEdgecase(_data))
        return ;
    if (checkF(_data))
        return ;
    for (int i = 0; i < dataLen; i++) {
        if (!isdigit(_data[i]) && _data[i] != '.' && _data[i] != '-' && _data[i] != 'f') {
            if (dataLen == 1)
                _type = "char";
            else
                throw Convert::StringInput();
            return ;
        }
        if (_data[i] == '.') {
            if (dots == 0)
                dots++;
            else
                throw Convert::WrongDots();
        }
    }
    if (!dots)
        _type = "int";
    if (_data[dataLen - 1] == 'f')
        _type = "float";
    else
        _type = "double";
}

// CHECK INCOMING DATATYPE
int Convert::checkF(std::string str) {
    int strLen = str.length();
    int f_count = 0;
    if ((str[0] == 'f' && strLen == 1) && strLen == 1) {
        _type = "char";
        return 1;
    }
    if (str == ".-" || str == "-.")
        throw Convert::WrongDots();
    if (strLen == 2  && str[0] == '.' && str[1] == 'f')
        throw Convert::WrongDots();
    if (strLen == 1 && str[0] == '.') {
        _type = "char";
        return 1;
    }
    for (int i = 0; i < strLen; i++) {
        if (str[i] == 'f') {
            f_count++;
            if (i != strLen - 1)
                throw Convert::WrongF();
        }
    }
    return 0;
}

int Convert::checkEdgecase(std::string str) {
    if (str == "-inff" || str == "+inff" || str == "nanf") {
        _type = "float";
        return 1;
    }
    if (str == "-inf" || str == "+inf" || str == "nan") {
        _type = "double";
        return 1;
    }
    return 0;
}

int Convert::edges() {
    return (_data == "-inff" || _data == "+inff" || _data == "nanf" || _data == "-inf" ||
            _data == "+inf" || _data == "nan");
}

// GETTERS
std::string Convert::getData() const {
    return _data;
}

std::string Convert::getType() const {
    return _type;
}


// CONVERT DATA
void Convert::convertData() {
    if (_type == "char") {
        char_lit = _data[0];
        int_lit = _data[0];
        float_lit = static_cast<float>(_data[0]);
        double_lit = static_cast<double>(_data[0]);
    }
    if (_type == "int") {
        try {
			if (std::stoll(_data) > 2147483647 || std::stoll(_data) < -2147483648)
				int_lit = 0;
			else
				int_lit = std::stoi(_data);
		} catch (std::exception &e) {}
        char_lit = int_lit;
        float_lit = static_cast<float>(int_lit);
        double_lit = static_cast<double>(int_lit);
    }
    if (_type == "float") {
        float_lit = std::stof(_data);
        char_lit = static_cast<char>(float_lit);
        int_lit = static_cast<int>(float_lit);
        double_lit = static_cast<double>(float_lit);
    }
    if (_type == "double") {
        double_lit = std::stod(_data);
        char_lit = static_cast<char>(double_lit);
        int_lit = static_cast<int>(double_lit);
        float_lit = static_cast<double>(double_lit);
    }
}

// PRINT DATA
void Convert::printData() {
    std::cout << "INCOMING DATA TYPE: " << _type << "" << std::endl;
    int i = 0;
	std::cout << "Char: ";
	if (int_lit <= 127 && int_lit >= 0) {
		if (isprint(char_lit))
			std::cout << char_lit << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "Impossible" << std::endl;
	std::cout << "Int: ";
    try {
		if (std::stoll(_data) > 2147483647 || std::stoll(_data) < -2147483648) {
			std::cout << "Impossible" << std::endl;
			i++;
		}
	} catch(std::exception &e) {
		std::cout << "Impossible" << std::endl;
		i++;
	}
    if (edges() && !i)
        std::cout << "Impossible" << std::endl;
    else if (!i)
        std::cout << int_lit << std::endl;
    std::cout << "Float: " << float_lit;
	if (_type == "int" || _type == "char" || (!modf(float_lit, &float_lit) && !edges()))
		std::cout << ".0";
    std::cout << "f" << std::endl;
    std::cout << "Double " << double_lit;
    if (_type == "int" || _type == "char" || (!modf(double_lit, &double_lit) && !edges()))
        std::cout << ".0";
    std::cout << std::endl;
}
