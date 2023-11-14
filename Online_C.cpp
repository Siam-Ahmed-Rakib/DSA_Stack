#include "Stack.cpp"
#include<cstring>
int main()
{
    int m=0;
    Stack<char> stk;
    char s[100];
    cin>>s;
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]=='(')
        {
            stk.push('(');
            if(stk.length()>m)
                m=stk.length();
        }
        else if(s[i]==')')
            stk.pop();
    }
    cout<<m<<endl;
    return 0;
}