#include<bits/stdc++.h>
using namespace std;

bool Bitwise_Tricks(int x){
    //? 1. check the number is odd or even.
    auto check_is_even_or_odd = [&](int x) -> bool {
        // The formula: (x & 1);
        return (x & 1);
    };
    //! Function call
    // return (check_is_even_or_odd(x)? true : false);

    //? 2. check the number is power of 2 or not.
    auto is_power_of_2_or_not = [&](int x) -> bool {
        // The formula: (x & (x - 1)).
        return x && !(x & (x - 1)); // return true if the number is power of 2.
    };
    //! Function call
    // return (is_power_of_2_or_not(x)? true : false);

    /*
        ? 3. Playing with the k-th bit - k-th bit = k-th last signification
        (1 << k) = 2^k, 
            i. Check is kth bit is set or not - x & (1 << k), where '&' is and.
            ii. Toggle the kth bit - x ^ (1 << k), where '^' is xor.
            iii. 
    */

    auto playing_with_kth_bit = [&](int x) -> void {
        // return 
    };



    cout << "No function execute" << endl;
    return false;
};

int main (){
    int x = 16;
    cout << (Bitwise_Tricks(x)? "Yes" : "No") << endl;
}