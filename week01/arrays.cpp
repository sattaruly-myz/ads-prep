#include <bits/stdc++.h>
using namespace std;

void d1(){
    int a;cout<<"Size array:"<<endl;cin>>a;
    int arr[a];
    cout<<"write values arrays:"<<endl;
    for(int i=0;i<a;i++){
        cin>>arr[i];
    }
    int avrg=arr[0];
    int min, max; min=arr[0]; max=arr[0];
    for (int i=1;i<a;i++){
        avrg+=arr[i];
        if(max<arr[i]){
            max=arr[i];
        } else if(min>arr[i]){
            min=arr[i];
        }
    }
    cout<<"MIN:"<<min<<" MAX:"<<max<<" and avrg:"<<avrg/a<<endl;
}

void d2(){
    int a,b;cout<<"Size array:"<<endl; cin>>a>>b;
    int arr[a][b];
    cout<<"write values arrays:"<<endl;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;i++){
            cin>>arr[i][j];
        }
    }
    int avrg,max,min; min,max,avrg=arr[0][0];
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            avrg+=arr[i][j];
            if(min>arr[i][j]){
                min=arr[i][j];
            }else if(max<arr[i][j]){
                max=arr[i][j];
            }
        }
    }
    int size=a+b;
    cout<<"MIN:"<<min<<" MAX:"<<max<<" and avrg:"<<avrg/size<<endl;
}

int main(){
    string choose; cout<<"Choose type of arrays for calculate avrg and find max, min value"<<endl; cout<<"If 1d array write 1d, else if 2d array write 2d:D"<<endl; cin>>choose;
    if (choose=="1d"){
        d1();
    }else if(choose=="2d"){
        d2();
    }else{
        cout<<"only 1d or 2d"<<endl;
    }

    return 0;
}