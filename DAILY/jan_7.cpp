#include <iostream>

int nBits(unsigned int num){
    int count = 0;
    while(num > 0){
        count += (num%2 == 0) ? 0 : 1;
        num/=2;
    }
    return count;
}

/*
11/2 --> 1
5/2 --> 1
2/2 -->1
1/2 --> 0
*/

int main(){
    std::cout << nBits(11);
    return 0;
}