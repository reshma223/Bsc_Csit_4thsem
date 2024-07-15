#include <iostream>
#include <string>

enum states { q0, q1, q2, q3, q4, qr };

int main()
{
    std::string input;
    enum states curr_state = q0;

    std::cout << "\n Enter a binary string: ";
    std::getline(std::cin, input);

    int i = 0;
    while (true)
    {
        switch (curr_state)
        {
            case q0:
                if (input[i] == '0')
                {
                    curr_state = q1;
                    input[i] = 'x';
                    i++;
                }
                else if (input[i] == 'y')
                {
                    curr_state = q3;
                    i++;
                }
                else
                    curr_state = qr; // for invalid transition
                break;
            case q1:
                if (input[i] == '0')
                {
                    curr_state = q1;
                    i++;
                }
                else if (input[i] == 'y')
                {
                    curr_state = q1;
                    i++;
                }
                else if (input[i] == '1')
                {
                    curr_state = q2;
                    input[i] = 'y';
                    i--;
                }
                else
                    curr_state = qr;
                break;
            case q2:
                if (input[i] == '0')
                {
                    curr_state = q2;
                    i--;
                }
                else if (input[i] == 'y')
                {
                    curr_state = q2;
                    i--;
                }
                else if (input[i] == 'x')
                {
                    curr_state = q0;
                    i++;
                }
                else
                    curr_state = qr;
                break;
            case q3:
                if (input[i] == 'y')
                {
                    curr_state = q3;
                    i++;
                }
                else if (input[i] == '\0')
                {
                    curr_state = q4;
                }
                else
                    curr_state = qr;
                break;
        }

        if (curr_state == qr || curr_state == q4)
            break;
    }

    if (curr_state == q4)
        std::cout << "\nThe string is accepted." << std::endl;
    else
        std::cout << "\n The string is not accepted." << std::endl;

    return 0;
}
