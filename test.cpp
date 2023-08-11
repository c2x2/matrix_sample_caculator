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
    matrix& operator-(const matrix &m2);//重載减法
    matrix& operator*(const matrix &m2);//重载乘法
    matrix &operator*(const int &k);//重载数乘
    matrix transpose();//转置
    matrix inverse();//求逆
    matrix &operator=(const matrix &m2); // 重载=
    double det();//求行列式
    int getm();
    int getn();
    double operator()(int i,int j);//访问元素
    ~matrix() {};
};
int matrix::getm(){
    return this->m;
}
int matrix::getn(){
    return this->n;
}  
// 定义矩阵类
matrix::matrix(int m, int n)
{
    this->m = m;
    this->n = n;
    p = new double *[m];
    for (int i = 0; i < m; i++)
    {
        p[i] = new double[n];
        for (int j = 0; j < n; j++)
        {
            p[i][j] = 0;
        }
    }
} // 构造函数
// 定义访问元素函数
double matrix::operator()(int i, int j)
{
    return this->p[i][j];
}
int pan(int x)
{
    if (x % 2 == 0)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
// 定义求逆函数
matrix matrix::inverse()
{
    double det=this->det();
    if (this->det() == 0 || m != n)
    {
        matrix tem(1, 1);
        tem.p[0][0] = 2147483647;
        return tem;
    }
    else
    {
        matrix inv(m, n);
        for (int t = 0; t < m; t++)
        {
            for (int i = 0; i < n; i++)
            {
                matrix m2(m - 1, n - 1);
                for (int j = 0; j < m; j++)
                {
                    for (int k = 0; k < n; k++)
                    {
                        if (k < i && j < t)
                        {
                            m2.p[j][k] = p[j][k];
                        }
                        if (k < i && j > t)
                        {
                            m2.p[j - 1][k] = p[j][k];
                        }
                        if (k > i && j < t)
                        {
                            m2.p[j][k - 1] = p[j][k];
                        }
                        if (k > i && j > t)
                        {
                            m2.p[j - 1][k - 1] = p[j][k];
                        }
                    }
                }
                inv.p[t][i] = pan(t) * pan(i) * m2.det()/det;
            }
        }
        return inv.transpose();
    }
}
//定义行列式函数
double matrix::det(){
    if(m!=n){
        return 2147483647;
    }else{
        if(m==1&&n==1){
            return p[0][0];
        }
        int det = 0;
        for(int i=0;i<n;i++){
            matrix m2(m-1,n-1);
            for (int j = 0; j <  m - 1 ; j++){
                for(int k = 0; k< n ; k++){
                    if(k<i){
                        m2.p[j][k]=p[j+1][k];
                    }
                    if(k>i){
                        m2.p[j][k-1]=p[j+1][k];
                    }
                }
            }
            det+=pan(i)*p[0][i]*m2.det();
        }
        return det;
    }
}
istream& operator>>(istream &in,matrix &m){
    m.p = new double *[m.m];
    for (int i = 0; i < m.m;i++){
        m.p[i] = new double[m.n];
    }
    for (int i = 0; i < m.m;i++){
        for (int j = 0; j < m.n;j++){
            in>>m.p[i][j];
        }
    }
    return in;
}
//定义>>函数
ostream &operator<<(ostream &out, matrix m)
{
    if (m.p[0][0] == 2147483647)
    {
        out << "error:the matrix is not a square matrix or the determinant is 0" << endl;
    }
    else
    {
        for (int i = 0; i <m.m ; i++)
        {
            for (int j = 0; j < m.n; j++)
            {
                out << m.p[i][j] << " ";
            }
            out << endl;
        }
    }
    return out;
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
//定义*函数
matrix& matrix::operator*(const matrix &m2){
    matrix m3(m,n);
    m3 = *this;
    delete[] this->p;
    n=m2.n;
    p=new double*[m];
    for (int i = 0; i < m;i++){
        p[i] = new double[n];
    }
    for (int i = 0; i < m;i++){
        for (int j = 0;j<n;j++){
            p[i][j]=0;
            for(int k = 0;k<m2.m;k++){
                p[i][j]+=m3.p[i][k]*m2.p[k][j];
            }
        }
    }
    return *this;
}
//定义数乘
matrix& matrix::operator*(const int &k){
    for (int i = 0; i < m;i++){
        for (int j = 0; j < n;j++){
            p[i][j] = p[i][j] * k;
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
        p=new double*[m];
        for(int i=0;i<m;i++){
            p[i]=new double[n];
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
//定义转置
matrix matrix::transpose(){
    matrix m3(this->n,this->m);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            m3.p[i][j] = this->p[j][i];
        }
    }
    return m3;
}
int main(){
    matrix m(2,2);
    cin>>m;
    cout<<m.det()<<endl;
    cout<<m.inverse()<<endl;
    return 0;
}