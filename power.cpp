#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int p;
        p=(int)pow(a,b);
        cout<<p;
    }
    cout<<endl;
    return 0;
}