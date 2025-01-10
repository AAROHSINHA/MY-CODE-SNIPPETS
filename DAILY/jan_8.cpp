#include <iostream>
#include <vector>

/*
PROBLEM STATEMENT -->
tAKE AS INPUT n, THE SIZE OF ARRAY. tAKE n MORE INPUTS AND STORE THAT IN AN ARRAY. TAKE AS INPUT m, A NUMBER
WRITE A RECURSIVE FUNCTION WHICH RETURNS AN ARRAY CONTAINING INDICES OF ALL ITEMS IN THE ARRAY WHICH HAVE VALUE EQUAL TO M. 
PRINT ALL VALUES IN THE RETURNED ARRAY
*/
std::vector<int> getAllIndices(int* arr, int N, int M, std::vector<int>& finalAns){
    if(N==0){
        return finalAns;
    }
    if(arr[N-1] == M){
        finalAns.push_back(N-1);
    }
    return getAllIndices(arr, N-1, M, finalAns);
}



int main(){
    int n;
    int m;
    std::cout << "Enter the size of array - ";
    std::cin >> n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        int num;
        std::cout << "Enter the element - ";
        std::cin >> num;
        *(arr + i) = num; 
    }
    std::cout << "Enter value of M - ";
    std::cin >> m;

    std::vector<int> inp;
    std::vector<int> out = getAllIndices(arr, n ,m, inp);
    for(int x : out){
        std::cout << x << " ";
    }
    std::cout << std::endl;

    


    return 0;
}