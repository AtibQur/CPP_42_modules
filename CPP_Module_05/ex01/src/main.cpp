#include "../inc/Form.hpp"

int main() {
        Bureaucrat man2("Jimson", 25);
    try {
        Bureaucrat man1("Billy", 0);
        Form form1("Form1", 4, 5);
        Form declaration1("Declaration of independence", 55, 60);
        man1.signForm(declaration1);
        man1.signForm(form1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Form form2("Form2", 100, 100);
        Form declaration2("Declaration of independence", 55, 60);
        std::cout << "Trying to get someone to sign the Declaration of independence" << std::endl;
        std::cout << std::endl;
        man2.signForm(declaration2);
        std::cout << std::endl;
        std::cout << "Trying to get someone to sign Form2" << std::endl;
        std::cout << std::endl;
        man2.signForm(form2);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}