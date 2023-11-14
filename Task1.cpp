#include "Stack.cpp"
int main()
{

    string s;
    cout << "The type of stack : ";
    cin >> s;
    if (s.compare("int") == 0)
    {
        Stack<int> stk;
        int X, K;
        cout << "The memory chunk size : ";
        cin >> X;
        cout << "The initial length of the stack : ";
        cin >> K;
        cout << "The initial elements of the stack : ";
        stk.init(X, K);
        cout << endl;
        cout << "The initial stack : ";
        stk.print();
        cout << endl;
        while (true)
        {
            int choice;
            cout << "0.Exit" << endl;
            cout << "1.Clear" << endl;
            cout << "2.Push" << endl;
            cout << "3.Pop" << endl;
            cout << "4.Length" << endl;
            cout << "5.TopValue" << endl;
            cout << "6.IsEmpty" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 0)
            {
                break;
            }
            else if (choice == 1)
            {
                stk.clear();
                cout << "The updated stack : ";
                cout << endl;
                stk.print();
                cout << endl;
            }
            else if (choice == 2)
            {
                int c;
                cout << "Enter the element : ";
                cin >> c;
                stk.push(c);
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
            }
            else if (choice == 3)
            {
                if (stk.isEmpty())
                {
                    cout << "Stack underflow " << endl;
                    cout << "The updated stack : ";
                    stk.print();
                    cout << endl;
                }
                else
                {
                    cout << endl;
                    int a = stk.pop();
                    cout << "The updated stack : ";
                    stk.print();
                    cout << endl;
                    cout << "The popped element : " << a << endl;
                }
            }
            else if (choice == 4)
            {
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
                cout << "The length : " << stk.length() << endl;
            }
            else if (choice == 5)
            {
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
                if (stk.isEmpty())
                {
                    cout << "Stack underflow " << endl;
                }
                else
                    cout << "The top element : " << stk.topValue() << endl;
            }
            else if (choice == 6)
            {
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
                if (stk.isEmpty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
            }
            else
            {
                cout << "Wrong option !! Try again." << endl;
            }
        }
    }
    else if (s.compare("char") == 0)
    {
        Stack<char> stk;
        int X, K;
        cout << "The memory chunk size : ";
        cin >> X;
        cout << "The initial length of the stack : ";
        cin >> K;
        cout << "The initial elements of the stack : ";
        stk.init(X, K);
        cout << endl;
        cout << "The initial stack : ";
        stk.print();
        cout << endl;
        while (true)
        {
            int choice;
            cout << "0.Exit" << endl;
            cout << "1.Clear" << endl;
            cout << "2.Push" << endl;
            cout << "3.Pop" << endl;
            cout << "4.Length" << endl;
            cout << "5.TopValue" << endl;
            cout << "6.IsEmpty" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice == 0)
            {
                break;
            }
            else if (choice == 1)
            {
                stk.clear();
                cout << "The updated stack : ";
                cout << endl;
                stk.print();
                cout << endl;
            }
            else if (choice == 2)
            {
                char c;
                cout << "Enter the element : ";
                cin >> c;
                stk.push(c);
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
            }
            else if (choice == 3)
            {
                if (stk.isEmpty())
                {
                    cout << "Stack underflow " << endl;
                    cout << "The updated stack : ";
                    stk.print();
                    cout << endl;
                }
                else
                {
                    char a = stk.pop();
                    cout << endl;
                    cout << "The updated stack : ";
                    stk.print();
                    cout << endl;
                    cout << "The popped element : " << a << endl;
                }
            }
            else if (choice == 4)
            {
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
                cout << "The length : " << stk.length() << endl;
            }
            else if (choice == 5)
            {
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
                if (stk.isEmpty())
                {
                    cout << "Stack underflow " << endl;
                }
                else
                    cout << "The top element : " << stk.topValue() << endl;
            }
            else if (choice == 6)
            {
                cout << endl;
                cout << "The updated stack : ";
                stk.print();
                cout << endl;
                if (stk.isEmpty())
                    cout << "True" << endl;
                else
                    cout << "False" << endl;
            }
            else
            {
                cout << "Wrong option !! Try again." << endl;
            }
        }
    }

    return 0;
}
