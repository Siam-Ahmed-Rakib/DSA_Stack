#include<iostream>
using namespace std;
template<typename T>
class Stack
{
     T* list;
     int chunksize,len;
    public:
      Stack()
      {
            list=new T[10];
            chunksize=10;
            len=0;
      }
      void init(int x,int k)
      {
            delete[] list;
            list=new T[x];
            chunksize=x;
            len=k;
            for(int i=0;i<k;i++)
            {
                cin>>list[i];
            }
      }
      void push(T item)
      {
            if(len==chunksize)
            {
                chunksize*=2;
                T * tem;
                tem=new T[chunksize];
                for(int i=0;i<len;i++)
                {
                    tem[i]=list[i];
                }
                delete[] list;
                list=tem;
            }
            list[len++]=item;
      }
      void clear()
      {
            len=0;
      }
      T pop()
      {
            len-=1;
            return list[len];
      }
      int length()
      {
            return len;
      }
      T topValue()
      {
           if(len==0)
            {
                cout<<"Stack underflow "<<endl;
                return '0';
            }
            return list[len-1];
      }
      bool isEmpty()
      {
            if(len==0)
                return true;
            else
                return false;
      }
      void print()
      {
            cout<<"< ";
            for(int i=0;i<len;i++)
            {
                cout<<list[i]<<" ";
                if(i!=len-1)
                    cout<<",";
            }
            cout<<" >";
      }
};