#include "Stack.cpp"
#include <sstream>

using namespace std;

int main() {
    int n;
    cin >> n;

    string* exp;
    exp = new string[n];

    Stack<int> operands;

    for (int i = 0; i < n; i++) {
        cin >> exp[i];

        if (isdigit(exp[i][0]) || (exp[i][0] == '-' && isdigit(exp[i][1]))) {
            int num;
            stringstream(exp[i]) >> num;
            operands.push(num);
        } else {
            char a = exp[i][0];
            int r = operands.pop();
            int l = operands.pop();
            int result;

            if (a == '+') {
                result = l + r;
            } else if (a == '-') {
                result = l - r;
            } else if (a == '*') {
                result = l * r;
            } else if (a == '/') {
                result = l / r;
            }

            operands.push(result);
        }
    }

    cout << operands.topValue() << endl;

    delete[] exp;
    return 0;
}
