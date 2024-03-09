#include<iostream>
using namespace std;
int counter = 0;
void move(int n, string source,string buffer,string destination){
    if(n == 0) return;
    if(n == 1) {
        counter++;
        cout<<"Moving "<<n<<" from "<<source<<" "<<destination<<endl;
        return ;
    }
    move(n-1,source,destination,buffer);
    move(n-1,buffer,source,destination);
    counter++;
}

int main(){

    int n;cin>>n;
    move(n,"Source","Buffer","Destination");
    cout<<counter<<endl;

    return 0;
}