#include<iostream>
using namespace std;

#define auto_string(s) string s = #s

// struct test {
//     auto_string(hello);
//     auto_string(it);
//     auto_string(is);
//     auto_string(Evil);
// };

int main(){
    // test t;
    cout << auto_string(hello) << endl;
    // cout << "Hello Shaid :P";
    // cout << auto_string(hello);
    // system("Pause"); // Evil code :P
    return 0;
}