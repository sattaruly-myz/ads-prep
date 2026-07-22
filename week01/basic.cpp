#include <bits/stdc++.h>
using namespace std;

string gg(int r){
    if (r==67){
        string dd= "gg";
        return dd;
    }else{
        string ff="eror";
        return ff;
    }
    return 0;
}

double Calculus(){
    double a,b; cin>>a>>b;
    double c=sqrt(a*a + b*b);
    for(int i=0;i<5;i++){
        if (i==2 and !(i==3)){
            return c;
        }
    }
    return 0;
}

int main() {
    int a,b; cin>>a>>b;
    double c,d; cin>>c>>d;
    cout<<a+b<<endl;
    cout<<c*d<<endl;
    int r;cin>>r;
    string fah = gg(r); 
    cout<<fah<<endl;
    double calc=Calculus();
    cout<<calc<<endl;
    return 0;
}