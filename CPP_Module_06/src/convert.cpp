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
        if (!isdigit(_data[0]) && isprint(_data[i])) {
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
    if (_data[dataLen - 1] == 'f')
        _type = "float";
    else if (dots == 1)
        _type = "double";
    else
        _type = "int";
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

int Convert::convertEdges() const {
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

char Convert::getChar() const {
    return _char_lit;
}

// CONVERT DATA
void Convert::convertData() {
    if (_type == "char") {
        _char_lit = _data[0];
        _int_lit = _data[0];
        _float_lit = static_cast<float>(_data[0]);
        _double_lit = static_cast<double>(_data[0]);
    }
    if (_type == "int") {
        try {
			if (std::stoll(_data) > 2147483647 || std::stoll(_data) < -2147483648)
				_int_lit = 0;
			else
				_int_lit = std::stoi(_data);
		} catch (std::exception &e) {}
        _char_lit = _int_lit;
        _float_lit = static_cast<float>(_int_lit);
        _double_lit = static_cast<double>(_int_lit);
    }
    if (_type == "float") {
        _float_lit = std::stof(_data);
        _char_lit = static_cast<char>(_float_lit);
        _int_lit = static_cast<int>(_float_lit);
        _double_lit = static_cast<double>(_float_lit);
    }
    if (_type == "double") {
        _double_lit = std::stod(_data);
        _char_lit = static_cast<char>(_double_lit);
        _int_lit = static_cast<int>(_double_lit);
        _float_lit = static_cast<double>(_double_lit);
    }
}

// PRINT DATA
void Convert::printData() const {
    std::cout << "========== INCOMING DATA TYPE: " << _type << " =========" << std::endl;
    int i = 0;
	std::cout << "Char: ";
	if (_int_lit <= 127 && _int_lit >= 0) {
		if (isprint(_char_lit))
			std::cout << _char_lit << std::endl;
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
    if (convertEdges() && !i)
        std::cout << "Impossible" << std::endl;
    else if (!i)
        std::cout << _int_lit << std::endl;
    std::cout << "Float: " << _float_lit;
	if (_type == "int" || _type == "char" || (!modf(_float_lit, &_float_lit) && !convertEdges()))
		std::cout << ".0";
    std::cout << "Double " << _double_lit;
    if (_type == "int" || _type == "char" || !convertEdges())
        std::cout << ".0";
    std::cout << std::endl;
}
