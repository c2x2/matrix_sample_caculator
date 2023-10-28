# Introduction
## This is my first git respository.I create a program to calculate some easy matrix.
# Instructions
###  **1、Download 'matrix.h' and 'matrix.cpp', then you should create a cpp file in the same floder. There is an example as follow :**
```cpp
#include "matrix.h"
#include "matrix.cpp"
#include <iostream>
using namespace std;
int main(){
    matrix a(3,3);
    matrix b(3,3);
    cin>>a>>b;
    cout<<a * b<<endl;
    return 0;
}
```
### **2、Compile the program and run it. You can see the result as follow:**
```cpp
1 2 3
4 5 6
7 8 9
//enter matrix 'a'
1 2 3
4 5 6
7 8 9
//enter matrix 'b'
30 36 42 
66 81 96 
102 126 150
//output matrix 'a' * matrix 'b'
```
### **3、If you want to use other function, you should add the following code in the cpp file :**
```cpp
//use 3 x 3 a,b as examples

matrix a(3,3);
matrix b(3,3);
int k;

a + b;  //a add b
a - b;  //a minus b
a * b;  //a multiply b
k * a;  //multiply numbers
a.tranpose();   //transpose matrix a
a.inverse();    //inverse matrix a
a.det();    //get a's determiant
a.trace();  //get a's trace
a(1,1); //get a's element
a.getm();   //get a's rows
a.getn();   //get a's columns
```
### **4、If you have any problems, you can contact me at *dzse6297@gmail.com*. Thanks.**  

# SOME PROBLEMS
`Because of the initial error,the caculator can only be used on the int number.We can only output the double type when getting the inverse.`
# ADD
``I make some corrections.Now,we can use the inverse() to get the inverse of a matrix.The type of elements of matrix is changed into double.The old problems are mostly sovled.And we now can use >> to get the ouput.``
# Weclome to my first git respository
``Hope you can get some help from this.and hope you can give me some advice.``