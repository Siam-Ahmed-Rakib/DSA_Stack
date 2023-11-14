#include "Stack.cpp"
#include <cstring>
bool brac_valid(char *exp)
{
    Stack<char> s;
    int l = strlen(exp);
    for (int i = 0; i < l; i++)
    {
        if (exp[i] == '(')
        {
            s.push('(');
        }
        else if (exp[i] == ')')
        {
            if (!s.isEmpty())
            {
                char a = s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return s.isEmpty();
}
int precedence(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/' || a == '%')
        return 2;
    else if (a == '~')
        return 3;
    else
        return 0;
}
bool isOperators(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
        return true;
    return false;
}
bool valid_other(char *exp)
{
    bool t = true;
    if (exp[0] == '+' || exp[0] == '/' || exp[0] == '*')
    {
        return false;
    }
    if (isOperators(exp[strlen(exp) - 1]))
        return false;
    for (int i = 0; i < strlen(exp) - 1; i++)
    {
        if (isOperators(exp[i]) && (isOperators(exp[i + 1]) || exp[i + 1] == ')'))
        {
            t = false;
            return t;
        }
        if (exp[i] == '(' && (exp[i + 1] == '+' || exp[i + 1] == '/' || exp[i + 1] == '*'))
            return false;
    }
    return true;
}
double cal(const char *exp)
{
    Stack<double> operands;
    Stack<char> operators;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (isOperators(exp[i]))
        {
            if (exp[i] == '-' && (i == 0 || exp[i - 1] == '('))
            {
                operators.push('~');
            }
            else
            {
                while (!operators.isEmpty() && precedence(operators.topValue()) >= precedence(exp[i]))
                {
                    char a = operators.pop();
                    double r = operands.pop();
                    double l = operands.pop();
                    double result;
                    if (a == '+')
                    {
                        result = l + r;
                    }
                    else if (a == '-')
                    {
                        result = l - r;
                    }
                    else if (a == '*')
                    {
                        result = l * r;
                    }
                    else if (a == '/')
                    {
                        result = l / r;
                    }
                    else if (a == '~')
                    {
                        result = (-1) * r;
                        operands.push(l);
                    }
                    operands.push(result);
                }
                operators.push(exp[i]);
            }
        }
        else if (exp[i] == '(')
        {
            operators.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (operators.topValue() != '(')
            {
                char a = operators.pop();
                double r = operands.pop();
                double l = operands.pop();
                double result;
                if (a == '+')
                {
                    result = l + r;
                }
                else if (a == '-')
                {
                    result = l - r;
                }
                else if (a == '*')
                {
                    result = l * r;
                }
                else if (a == '/')
                {
                    result = l / r;
                }
                else if (a == '~')
                {
                    result = (-1) * r;
                    operands.push(l);
                }
                operands.push(result);
            }
            operators.pop(); 
        }
        else
        {
            double s = exp[i] - '0';
            while (i + 1 < strlen(exp) && (isdigit(exp[i + 1]) || exp[i + 1] == '.'))
            {
                if (isdigit(exp[i + 1]))
                    s = 10 * s + (exp[++i] - '0');
                else if (exp[i + 1] == '.')
                {
                    i++;
                    double fraction = exp[i] - '0';
                    double divisor = 10.0;
                    while (i + 1 < strlen(exp) && isdigit(exp[i + 1]))
                    {
                        fraction = fraction + (exp[++i] - '0') / divisor;
                        divisor *= 10.0;
                    }
                    s += fraction;
                }
            }
            operands.push(s);
        }
    }
    while (!operators.isEmpty())
    {
        char a = operators.pop();
        double r = operands.pop();
        double l = operands.pop();
        double result;
        if (a == '+')
        {
            result = l + r;
        }
        else if (a == '-')
        {
            result = l - r;
        }
        else if (a == '*')
        {
            result = l * r;
        }
        else if (a == '/')
        {
            result = l / r;
        }
        else if (a == '~')
        {
            result = (-1) * r;
            operands.push(l);
        }
        operands.push(result);
    }

    return operands.pop();
}

int main()
{
    char *exp;
    exp = new char[1000];
    cout << "Enter expression: ";
    cin.getline(exp, 1000);
    if (valid_other(exp) && brac_valid(exp))
    {
        cout << "Valid expression" << endl;
        cout << "Computed value : " << cal(exp) << endl;
    }
    else
    {
        cout << "Not valid " << endl;
    }
    return 0;
}
