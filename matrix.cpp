#include "matrix.h"
using namespace std;
int matrix::getm(){
    return this->m;
}
int matrix::getn(){
    return this->n;
}  
//构造函数
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
} 
//定义求秩函数
int matrix::rank(){
    int rank = 0;
    for (int i = 0; i < n;i++){
        int flag = -1;
        for (int j = rank; j < m;j++){
            if(p[j][i]!=0){
                flag = j;
                break;
            }
        }
            if(flag==-1){
                continue;
            }       
            swap(p[rank],p[flag]);
            for (int k = rank+1; k < m;k++){
                double tem = p[k][i]/p[rank][i];
                for (int l = i; l < n;l++){
                    p[k][l] = p[k][l] - tem*p[rank][l];
                }
            }
        rank++;
    }
    return rank;
}
//定义求迹函数
double matrix::trace(){
    double tem = 0;
    for (int i = 0; i < m;i++){
        tem+=this->p[i][i];
    }
    return tem;
}
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
    matrix m1(3,4);
    cin >> m1;
    cout<<m1.transpose();
}