#include <vector>
#include <string>
#include <iostream>
using namespace std;
void ccc(vector<string> s){
    for(auto c:s){
        cout<<c<<endl;
    }
}
int main(){
    ccc({"123"});

    return 0;
}