#include<iostream>
using namespace std;

// int farboo(int const *a,const int *c,int * const b) {
//     c++;
//     // const在*左边，const修饰指针指向的变量
//     *c = 10;
//     *a = 10;
//     *b = 1;
//     // const在*右边，const修饰的是指针本身
//     b++;
//     cout << "a:" << *a << endl;
//     return 0;
// }

// int main() {
//     cout << "hello world" << endl;
//     // const int *a, 表示指向的地址数据不变？
//     // int const *a,
//     int a = 100;
//     int b = 200;
//     farboo(&a,&b,&b);
// }

int main()  
{  
   int i=10;  
   int j=1;  
   const int *p1;//(1)  
   int const *p2=&i; //(2)  
   p2=&j;//(3)  
   int *const p3=&i;//(4)  
   *p3=20;//(5)  
   *p2=30;//(6)  
   p3=&j;//(7)  
return 0;  
}  
