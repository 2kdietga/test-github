#include"set.h"

set::set(int size){
    this->data=new int[size]; for(int i=0;i<size;i++) this->data[i]=0;
    this->n=0;   this->size=size;
}

set::set(int a[], int n,int size){
    this->data=new int[size];
    this->n=n;   this->size=size;
    for(int i=0;i<size;i++) this->data[i]=0;
    for(int i=0;i<n;i++) this->data[i]=a[i];
}

set::set(const set &s){
    this->n=s.n;    this->size=s.size;
    this->data= new int[this->size];
    for(int i=0;i<n;i++) this->data[i]=s.data[i];
}

set::~set(){
    delete []this->data;
}

set set::operator + (int x){
    if(this->n==this->size)
    {
        cout<<"Full";
        return *this;
    }
    for(int i=0;i<this->n;i++) if(this->data[i]==x) return *this;
    this->data[n++]=x;
    return *this;
}


set set::operator + (const set &s){
    set t(this->size+s.size);
    for(int i=0;i<this->n;i++) t=t+this->data[i];
    for(int i=0;i<s.n;i++) t=t+s.data[i];
    return t;
}

set set::operator -(int x){
    if(this->n==0){
        return *this;
    }
    for(int i=0;i<this->n;i++) if(this->data[i]==x){
        this->data[i]=this->data[n-1];
        this->data[n--]=0;
    } 
    return *this;
}

set set::operator -(const set &s){
    set t(*this);
    for(int i=0;i<s.n;i++) t=t-s.data[i];
    return t;
}

set set::operator *(set s){
    set t(this->size+s.size);
    t=*this+s;
    t=t-(*this-s)- (s-(*this));
    return t;
}
 
int set::operator ()(int x)
{
    for(int i=0;i<this->n;i++ ){
        if(this->data[i]==x)
        return i;
    }
    return -1;
}

int &set::operator [] (int x) const{
    return this->data[x];
}


ostream &operator <<(ostream &os, const set &s ){
    for(int i=0;i<s.n;i++) os<<s.data[i]<<" ";
    return os;
}

const set &set::operator =(const set &s){
    if(this!=&s){
        delete []data;
        this->n=s.n; this->size=s.size;
        data=new int [size];
        for(int i=0;i<n;i++) this->data[i]=s.data[i];
    }
    return *this;
}
