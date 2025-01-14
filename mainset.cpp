#include"set.h"

int main(){
    int a[5]={1,2,3,4,5};
    set s1(a,5,10);
    s1+3;
    set s2(10);
    s2+2; s2+3; s2+7; s2+8;
    set s3(10);
    set s4(10);
    set s5(10);
    s3=s2*s1;
    s4=s1+s2;
    s5=s1-s2;
    cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl<<s5<<endl;
    cout<<s1(2)<<", "<<s1[2];
    return 0;  
}