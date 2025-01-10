#include <iostream>
#include <vector>
#include <map>

/*
given a 2d square matrix of order n, find the sum of elements of both diagonals and all boundary elements
.Boundary elements refer to the elements present on all the four boundaries of matrix.
eg - 
1 2 3
4 5 6
7 8 9
O/P -> 45

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
O/P -> 136

1   2   3   4   5
6   7   8   9  10
11 12  13 14  15
16 17  18 19  20
21 22  23 24  25
O/P -> 273
*/

int getSum(std::vector<std::vector<int>> matrix){
    int count = 0;
    // first let's find the boundary elements except the corner ones as they will be added in the diagonal
    for(int i = 1; i < matrix[0].size() - 1; i+=1){
        count += matrix[0][i];
        count += matrix[i][0];
        count += matrix[matrix.size()-1][i];
        count += matrix[i][matrix.size() - 1];
    }


    // now diagonals
    int lc = 0;
    int rc = matrix.size() - 1;
    for(int i = 0; i < matrix.size(); i+=1){
        count += matrix[i][i];
        if(lc!=rc){
            count += matrix[lc][rc];
        }
        lc++;
        rc--;
    }
    return count;
}

int main()
{
 std::vector<std::vector<int>> m1 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
std::vector<std::vector<int>> m2 = {
    {1, 2, 3, 4, 5},
    {6, 7, 8, 9, 10},
    {11, 12, 13, 14, 15},
    {16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25}
};
std::vector<std::vector<int>> m3 = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}
};
std::vector<std::vector<int>> m4 = {
    {1, 2},
    {3, 4}
};
std::vector<std::vector<int>> m5 = {
    {1, 2, 3, 4, 5, 6},
    {7, 8, 9, 10, 11, 12},
    {13, 14, 15, 16, 17, 18},
    {19, 20, 21, 22, 23, 24},
    {25, 26, 27, 28, 29, 30},
    {31, 32, 33, 34, 35, 36}
};



    std::cout << getSum(m1) << std::endl;
    std::cout << getSum(m2) << std::endl;
    std::cout << getSum(m3) << std::endl;
    std::cout << getSum(m4) << std::endl;
    std::cout << getSum(m5) << std::endl;
    return 0;
}