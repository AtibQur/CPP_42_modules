#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <stack>

class RPN
{
private:
    std::stack<int> _stack;
public:
    RPN();
    RPN(RPN const &other);
    ~RPN();
    RPN &operator=(RPN const &other);

    void readInput(std::string input);

};

#endif
