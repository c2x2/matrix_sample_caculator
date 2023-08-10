#include <iostream>
using namespace std;
class matrix{
private:
    int m,n;
    int **p;
public:
    matrix(int m,int n);
    void print();
    friend istream& operator>>(istream &in,matrix &m);// 重载>>运算符;
    matrix& operator+(const matrix &m2);//重载加法
    matrix& operator-(const matrix &m2);//重載减法
    matrix &operator=(const matrix &m2); // 重载=
    ~matrix(){};
}; // 定义矩阵类
matrix::matrix(int m,int n){
    this->m=m;
    this->n=n;
    p=new int*[m];
    for(int i=0;i<m;i++){
        p[i]=new int[n];
        for(int j=0;j<n;j++){
            p[i][j]=0;
        }
    }
}//构造函数
//定义print函数
void matrix::print(){
    for (int i = 0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<p[i][j]<<" ";
        }
        cout<<endl;
    }
}
istream& operator>>(istream &in,matrix &m){
    m.p = new int *[m.m];
    for (int i = 0; i < m.m;i++){
        m.p[i] = new int[m.n];
    }
    for (int i = 0; i < m.m;i++){
        for (int j = 0; j < m.n;j++){
            in>>m.p[i][j];
        }
    }
    return in;
}
//定义+函数
matrix& matrix::operator+(const matrix &m2){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            p[i][j]=p[i][j]+m2.p[i][j];
        }
    }
    return *this;
}
//定义-函数
matrix& matrix::operator-(const matrix &m2){
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){  
            this->p[i][j]=this->p[i][j]-m2.p[i][j];
        }
    }
    return *this;
}
//定义=函数
matrix& matrix::operator=(const matrix &m2){
    if(this==&m2){
        return *this;
    }
    else{
        delete []p;
        m=m2.m;
        n=m2.n;
        p=new int*[m];
        for(int i=0;i<m;i++){
            p[i]=new int[n];
            for(int j=0;j<n;j++){
                p[i][j]=m2.p[i][j];
            }
        }
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                this->p[i][j] = m2.p[i][j];
            }
        }
    }
    return *this;
}
int main(){
    matrix m(3,3);
    cin>>m;
    matrix m2(3,3);
    cin>>m2;    
    (m+m2).print();
    return 0;
}