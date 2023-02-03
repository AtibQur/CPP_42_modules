#include "../inc/convert.hpp"

// You have to first detect the type of the literal passed as parameter.
// convert it from string to its actual type.
// then convert it explicitly to the three other data types.
// Lastly, display the results as shown below.

// You have to first detect the type of the literal passed as parameter, convert it from
// string to its actual type, then convert it explicitly to the three other data types. Lastly,
// display the results as shown below.

int	main(int argc, char **argv) {

	if (argc != 2) {
		std::cerr << "Only 1 argument allowed." << std::endl;
		exit(1);
	}
	Convert convert(argv[1]);
	try {
		convert.detectType();
		convert.convertData();
		convert.printData();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
