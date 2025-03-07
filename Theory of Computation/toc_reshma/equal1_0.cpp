#include <iostream>
#include <cstring>
#define MAX 100
enum states { q0, q1, qf };

void push(char ch);
void pop();
char get_stack_top();
enum states delta(enum states, char, char);

struct stack
{
    char symbols[MAX];
    int top;
};
struct stack s;

int main()
{
    char input[20];
    enum states curr_state = q0;
    s.top = -1;
    int i = 0;
    char ch = 'e';    // e indicating epsilon
    char st_top = 'e';
    curr_state = delta(curr_state, ch, st_top);

    std::cout << "Enter a binary string: ";
    std::cin >> input;

    ch = input[i];
    st_top = get_stack_top();
    int c = 0;

    while (c <= strlen(input))
    {
        curr_state = delta(curr_state, ch, st_top);
        ch = input[++i];
        st_top = get_stack_top();
        c++;
    }
    if (curr_state == qf)
        std::cout << "The string " << input << " is accepted." << std::endl;
    else
        std::cout << "The string " << input << " is not accepted." << std::endl;

    return 0;
}

enum states delta(enum states s, char ch, char st_top)
{
    enum states curr_state;
    switch (s)
    {
        case q0:
            if (ch == 'e' && st_top == 'e')
            {
                curr_state = q1;
                push('$');    // $ is stack bottom marker
            }
            break;
        case q1:
            if ((ch == '0' && (st_top == '$' || st_top == '0')) || (ch == '1' && (st_top == '$' || st_top == '1')))
            {
                curr_state = q1;
                push(ch);
            }
            else if ((ch == '1' && st_top == '0') || (ch == '0' && st_top == '1'))
            {
                curr_state = q1;
                pop();
            }
            else if (ch == '\0' && st_top == '$')
            {
                curr_state = qf;
                pop();
            }
            break;
    }
    return curr_state;
}

// Function to get stack top symbol
char get_stack_top()
{
    return (s.symbols[s.top]);
}

// Push function
void push(char ch)
{
    if (s.top < MAX - 1)
    {
        s.symbols[++s.top] = ch;
    }
    else
    {
        std::cout << "Stack Full." << std::endl;
    }
}

// Pop function
void pop()
{
    if (s.top > -1)
    {
        s.symbols[s.top] = ' ';
        s.top--;
    }
    else
    {
        std::cout << "Stack Empty." << std::endl;
    }
}
