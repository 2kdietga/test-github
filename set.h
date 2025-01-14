#ifndef set_h
#define set_h
#include<iostream>
using namespace std;

class set{
    private:
        int n;
        int *data;
        int size;
    public:
        set(int =10);
        set(int [], int,int=10);
        set(const set &);
        ~set();
        set operator +(int );
        set operator +(const set&);
        set operator -(const set& );
        set operator -(int );
        set operator *(set );
        int operator () (int);
        int &operator [](int )const;
        const set &operator =(const set&);
        friend ostream &operator <<(ostream&,const set&);
};
#endif