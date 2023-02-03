#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <cmath>

class Convert
{
	private:
		std::string _data; // incoming string
		std::string _type; // datatype

		char	_char_lit;
		int		_int_lit;
		float	_float_lit;
		double	_double_lit;
	public:
	// OOCP
		Convert();
		Convert(std::string data);
		Convert(const Convert& other);
		~Convert();
		Convert& operator=(const Convert& other);


	// CHECK INCOMING DATATYPE
		void detectType();
		int	checkEdgecase(std::string str);
		int checkF(std::string str);

	// GETTERS
		std::string getData() const;
		std::string getType() const;
		char		getChar() const;

	// CONVERT DATA
		void convertData();
		int  convertEdges() const;
		int  convertEdgecase();

	// PRINT DATA
		void printData() const;

	// EXCEPTIONS
		class WrongInput : public std::exception
		{
			public:
				const char *what() const throw() { return "Throw: input is not valid"; }
		};
		class StringInput : public std::exception
		{
			public:
				const char *what() const throw() { return "Throw: String input is not allowed"; }
		};
		class WrongDots : public std::exception
		{
			public:
				const char *what() const throw() { return "Throw: Too many dots"; }
		};
		class WrongF : public std::exception
		{
			public:
				const char *what() const throw() { return "Throw: Wrong f input"; }
		};
};

std::ostream &operator<<(std::ostream &os, const Convert& convert);
