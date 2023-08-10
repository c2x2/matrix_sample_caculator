#include <iostream>
using namespace std;
class matrix{
private:
    int m,n;
    int **p;
public:
    matrix(int m,int n);
    void print();
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
int main(){
    matrix m(3,3);
    m.print();
    return 0;
}