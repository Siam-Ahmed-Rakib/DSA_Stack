#include "Stack.cpp"
#include<cstring>
int main()
{
    char s[100];
    cin>>s;
    int t;
    cin>>t;
    Stack<int> stk;
    int k=-1;
    for(int i=strlen(s);i>=t;i--)
    {
        if(s[i]==']')
            stk.push(i);
        else if(s[i]=='[')
        {
            int m=stk.pop();
            if(i==t)
                k=m;
        }
    }
    cout<<k<<endl;
    return 0;
}