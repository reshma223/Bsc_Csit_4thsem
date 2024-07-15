#include <iostream>
#include <stack>
#include <string>

enum states { q0, q1 };
enum symbols { ZERO, ONE };

bool isAccepted(const std::string& input) {
    std::stack<int> stack;
    stack.push(-1); // Stack bottom marker

    states currentState = q0;

    for (char ch : input) {
        symbols symbol;

        if (ch == '0')
            symbol = ZERO;
        else if (ch == '1')
            symbol = ONE;
        else
            continue;

        switch (currentState) {
            case q0:
                if (symbol == ZERO) {
                    stack.push(ZERO);
                    currentState = q0;
                } else if (symbol == ONE && stack.top() == ZERO) {
                    stack.pop();
                    currentState = q0;
                } else if (symbol == ONE && stack.top() == ONE) {
                    stack.pop();
                    currentState = q0;
                }
                break;
        }
    }

    return stack.top() == -1; // Accepted if stack is empty
}

int main() {
    std::string input;
    std::cout << "Enter a binary string: ";
    std::cin >> input;

    if (isAccepted(input))
        std::cout << "The string " << input << " is accepted." << std::endl;
    else
        std::cout << "The string " << input << " is not accepted." << std::endl;

    return 0;
}
