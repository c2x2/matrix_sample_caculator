#pragma once
#include <iostream>
using namespace std;
class matrix{
private:
    int m,n;
    double **p;
public:
    matrix(int m,int n);
    friend istream& operator>>(istream &in,matrix &m);// 重载>>运算符;
    friend ostream& operator<<(ostream &out,matrix m);//重载<<运算符
    matrix& operator+(const matrix &m2);//重载加法
    matrix& operator-(const matrix &m2);//重载减法
    matrix& operator*(const matrix &m2);//重载乘法
    matrix &operator*(const int &k);//重载数乘
    matrix transpose();//转置
    matrix inverse();//求逆
    matrix &operator=(const matrix &m2); // 重载=
    double det();//求行列式
    double trace();//求迹
    int rank();//求秩
    int getm();
    int getn();
    double operator()(int i,int j);//访问元素
    ~matrix() {};
};