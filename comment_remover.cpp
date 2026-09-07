#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    char ch, next;
    bool multiComment = false;

    while (input.get(ch)) {

        if (multiComment) {
            if (ch == '*') {
                input.get(next);

                if (next == '/') {
                    multiComment = false;
                } else {
                    input.putback(next);
                }
            }
        }

        else if (ch == '/') {
            input.get(next);

            // Single line comment
            if (next == '/') {
                while (input.get(ch) && ch != '\n');

                output << '\n';
            }

            // Multi-line comment
            else if (next == '*') {
                multiComment = true;
            }

            // Normal slash
            else {
                output << ch;
                input.putback(next);
            }
        }

        else {
            output << ch;
        }
    }

    input.close();
    output.close();

    cout << "Comments removed successfully!" << endl;

    return 0;
}
