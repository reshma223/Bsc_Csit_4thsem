#include <iostream>
#include <string>
#define MAX 100

char tape[MAX];

void display() {
    for (int j = 0; j < MAX; j++) {
        std::cout << tape[j];
    }
}

int main() {
    int flag = 0;
    char ch, cs = 'A';
    int i = 0;
    std::cout << "Enter string: ";
    std::cin >> tape;

    while (true) {
        ch = tape[i];

        if (cs == 'A' && ch == 'a') {
            tape[i] = 'B';
            cs = 'B';
            i++;
        } else if (cs == 'B' && ch == 'a') {
            tape[i] = 'B';
            cs = 'C';
            i++;
        } else if ((cs == 'C' && ch == 'a') || (cs == 'C' && ch == 'B')) {
            cs = 'C';
            i++;
        } else if (cs == 'C' && ch == 'b') {
            tape[i] = 'B';
            cs = 'D';
            i--;
        } else if ((cs == 'D' && ch == 'B') || (cs == 'D' && ch == 'a')) {
            cs = 'D';
            i--;
        } else if (cs == 'D' && ch == 'B') {
            cs = 'A';
            i++;
        } else if (cs == 'A' && ch == 'B') {
            cs = 'E';
            i++;
        } else if (cs == 'E') {
            if (ch == 'B') {
                cs = 'E';
                i++;
            } else {
                cs = 'F';
                i++;
            }
        } else if (cs == 'F') {
            flag = 1;
            break;
        } else {
            break;
        }

        display();
        std::cout << std::endl;
    }

    if (flag == 1) {
        std::cout << "Accepted" << std::endl;
    } else {
        std::cout << "Rejected" << std::endl;
    }

    return 0;
}
