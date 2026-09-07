#include <bits/stdc++.h>
using namespace std;

int main() {

    string s = "int a = b + 25;";
    string token[20];
    int count = 0;
    string temp = "";

    // Tokenization
    for (int i = 0; i < s.length(); i++) {  

        if (isalnum(s[i])) {  // check alphabet or digit
            temp += s[i];
        } else {

             if (s[i] != ' ') {
                token[count] = s[i];
                count++;
            }

            if (temp != "") {
                token[count] = temp;
                count++;
                temp = "";
            }
        }
    }

    // Classification
    for (int i = 0; i < count; i++) {

        cout << token[i] << " : ";

        if (token[i] == "int")
            cout << "Keyword";

        else if (isdigit(token[i][0]))
            cout << "Number";

        else if (token[i] == "=" || token[i] == "+" ||
                 token[i] == "-" || token[i] == "*")
            cout << "Operator";

        else if (token[i] == ";")
            cout << "Separator";

        else
            cout << "Identifier";

        cout << endl;
    }

    return 0;
}
