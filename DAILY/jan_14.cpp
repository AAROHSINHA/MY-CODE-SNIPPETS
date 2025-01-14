#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstdlib> // for random numbers
#include <ctime>
#include <cmath>
using std::vector;

/*HELPER FUNCTION - RANDOM NUMBER GENERATOR*/
int randint(int low, int high){
    std::srand(std::time(0)); // putting the seed
    int gotRandom = std::rand();
    return low + gotRandom % (high - low + 1);
}


/*
PROBLEM STATEMENT 1 - 
In a given range print all numbers having unique digits. i.e if the range is 1 to 20, print all numbers except 11
eg - [10, 20]
O/P - 10, 12, 13, 14, 15, 16, 17, 18, 19, 20
*/

/*
Method 1 - Using a set
Time Complexity = O((end - start)*(m)) where m is the number of digits
Space Complexity = O(M) note that set will at worst case contain 0-9 elements only, so M at worst is 9
*/
void UniqueDigits1(int start, int end){
    for(int i = start; i <= end; i+=1){
        int num = i;
        std::set<int> newSet;
        int numCount = 0;
        while(num > 0){
            newSet.insert(num%10);
            numCount++;
            num/=10;
        }

        if(newSet.size() == numCount){
            std::cout << i << " ";
        }
    }
}

/*
PROBLEM STATEMENT 2 --
Given an array of size N that has elements ranging from 0 to N-1. All elements may not be present in the array. If element is not 
present then there will be a -1 present in the array.Rearrange the array such that A[i] = i and if i is not present, display -1 at its place

input - 10
[-1 -1 6 1 9 3 2 -1 4 -1]
O/P -  [-1 1 2 3 4 -1 6 -1 -1 9]
*/

/*
Method 1 - using a hashmap 
Time Complexity = O(2N)
Space Complexity = O(M)
*/
std::vector<int> RearrangeArray1(std::vector<int> arr, int N){
    std::unordered_map<int, int> hashmap;
    std::vector<int> finalAns(N, -1);
    for(int a : arr){
        hashmap[a] += 1;
    }

    // rearranging
    for(int i = 0; i < N; i+=1){
        finalAns[i] = (hashmap[i] > 0) ? i : -1;
    }
    return finalAns;
}

/*
PROBLEM STATEMENT 3 - GFG POTD
Given an array of integers arr[], the task is to find the first equilibrium point in the array.

The equilibrium point in an array is an index (0-based indexing) such that the sum of all elements before that index is the same as the sum of elements after it. Return -1 if no such point exists. 

Examples:

Input: arr[] = [1, 2, 0, 3]
Output: 2 
Explanation: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 0 + 3 = 3.
Input: arr[] = [1, 1, 1, 1]
Output: -1
Explanation: There is no equilibrium index in the array.
Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explanation: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.
*/
int findSum(std::vector<int>& arr){
    int sum = 0;
    for(int x : arr) sum += x;
    return sum;
}
int findEquilibrium(std::vector<int> &arr) {
    int ls = 0;
    int rs = findSum(arr);
    for(int i = 0; i < arr.size(); i+=1){
        rs -= arr[i];
        if(rs == ls) return i;
        ls += arr[i];
    }
    return -1;

}

/*
PROBLEM STATEMENT - L.C POTD
You are given two 0-indexed integer permutations A and B of length n.

A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

Return the prefix common array of A and B.

A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 

Example 1:

Input: A = [1,3,2,4], B = [3,1,2,4]
Output: [0,2,3,4]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
Example 2:

Input: A = [2,3,1], B = [3,1,2]
Output: [0,1,3]
Explanation: At i = 0: no number is common, so C[0] = 0.
At i = 1: only 3 is common in A and B, so C[1] = 1.
At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
*/

/*
Method 1 - using hashmap
As sizes of both arrays are same, in one loop only first check arr1 then arr2. for new elem in arr1, hashmap[elem] = 1. 
for new elem in arr2, hashmap[elem] = 2. If for arr1, hashmap[elem] = 2, count++ and same vice versa. No need to make count 0 for every loop as it either increases or stays constant  
*/
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    std::unordered_map<int, int> hashmap;       
    int count = 0;
    std::vector<int> res;
    for(int i = 0; i < A.size(); i+=1){
        // arr 1
        if(hashmap.find(A[i])!=hashmap.end() && hashmap[A[i]] == 2){
            count++;
        }else{
            hashmap[A[i]] = 1;
        } 

        if(hashmap.find(B[i])!=hashmap.end() && hashmap[B[i]] == 1){
            count++;
        }else{
            hashmap[B[i]] = 2;
        } 

        res.push_back(count);
    }
    return res;
}

/*
PROBLEM STATEMENT 5 -->
Keshav's Random Number Generator    
Problem
Submissions
Keshav is developing a program to analyze the output of a random number generator that may produce numbers spaced out by a certain value 'k'. He wants to determine the maximum value of 'k' such that the given set of 'n' distinct numbers produces the maximum number of pairs with a difference of 'k'.

Input Format:

The input consists of two lines:

The first line contains an integer 'n' representing the number of distinct numbers generated by the random number generator.

The second line contains 'n' space-separated integers representing the distinct numbers generated by the random number generator.

Output Format:

A single line containing a single integer representing the maximum value of 'k' such that the given set of 'n' distinct numbers produces the maximum number of pairs with a difference of 'k'.

Input Format

7

2 7 14 21 28 35 42

Constraints

1 ≤ n ≤ 10^5

1 ≤ Each number in the set ≤ 10^9.

The numbers in the set are distinct.

Output Format

7

Sample Input 0

7
2 7 14 21 28 35 42
Sample Output 0

7
*/

/*
METHOD 1
Time Complexity - O(N*(N-1) + M)
Space Complexity - O(A)
*/
int KeshavRandomGenerator(int n, std::vector<int> randoms){
    std::unordered_map<int, int> hashmap;
    for(int i = 0; i < randoms.size(); i++){
        for(int j = i + 1; j < randoms.size(); j+=1){
            hashmap[std::abs(randoms[j] - randoms[i])] += 1;
        }
    }

    // max
    int maxCount = -1;
    int currDiff = -1;
    for(auto val : hashmap){
        if(val.second > maxCount){
            maxCount = val.second;
            currDiff = val.first;
        }
    }
    return currDiff;
}

/*
PROBLEM STATEMENT 6 -- 
Alice is playing a mobile game Clash of Clans. In the game, Alice's character Witch can perform special attacks. However, one special attack costs X dark elixir.

If Alice currently has Y dark elixir, determine the maximum number of special attacks the Witch can perform.

eg - 
3
10 30
6 41
50 2
0/P - 
3
6
0
*/
int NumberOfAttacks(int spent, int has){
    int count = 0;
    while(has > 0 && (has - spent) >= 0){
        has-=spent;
        count++;
    }
    return count;
}

/*
PROBLEM STATEMENT 7 -- 
Akshat has love for number.
You want to suprise Akshat with a gift present consisting of n rupee.
But Akshat will accpet the gift only if amount has only two factors of it(including itself).
Tell whether Akshat will accept the gift or not

eg - 
3
YES
3 has two factors 1 and 3 .
So Akshat will receive the output
*/
std::string AkshatAcceptsGift(int num){
    if(num <= 1) return "NO";
    int numCount = 0;
    for(int i = 1; i <= num; i+=1){
        if(num%i == 0) numCount++;
        if(numCount > 2) return "NO";
    }
    return "YES";
}

/*
PROBLEM STATEMENT 8 --
Dora, a daring adventurer, has found a mysterious treasure guarded by a sequence of numeric locks. Each lock has a numerical value etched upon it, and to unlock the treasure, Dora must turn this sequence into an increasing one (strictly increasing). A sequence a0, a1, ..., at - 1 is called increasing if ai - 1 < ai for each i: 0 < i < t.

Given an array representing the current sequence of locks, b0, b1, ..., bn - 1, where the i-th lock's value is bi. Dora is equipped with her wits and a magical wand that can add d to any lock's value in a single move. In other words, in each move Dora may choose one element of the given sequence and add d to it.

Help Dora calculate this minimum number of moves needed to transform the sequence of locks into an increasing one and unlock the treasure. With your guidance, she can decipher this enigmatic puzzle and claim the hidden riches.

eg - 
3
4 7 10 9 8
O/P - 3
*/
// int numTurns(std::vector<int> locks, int d){
//     int turns = 0;
//     int currTurn = 0;
//     for(int i = 1; i < locks.size(); i+=1){
//         if(locks[i-1] > locks[i]){
//             currTurn = std::ceil((locks[i-1] - locks[i])%d);
//             locks[i] += currTurn*d;
//             turns += currTurn;
//         }
//     }

//     return turns;
// }

int numTurns(std::vector<int> locks, int d){
    int ptr = 1;
    int turns = 0;
    while(ptr < locks.size()){
        if(locks[ptr - 1] > locks[ptr]){
            turns+=1;
            locks[ptr]+=d;
        }else{
            ptr++;
        }
    }
    return turns;
}

/*
PROBLEM STATEMENT 9 -->
Miss Huehuehue & The Game of Strength

The most famous game of BITistan, The Game of Strength, will be held on 22nd March and Miss Huehuehue will be the referee of the game. The game goes as follows:

Two teams compete against each other, each team has 'n' number of players each having strength of t[i] where i denotes the ith player of the team.
Chits are drawn from boxes of both teams and the player names that come up fight against each other.
The player with the greater strength wins the round. If the strengths of both the players are the same, the round ends up as DRAW.
This is the first time that Miss Huehuehue is going to judge a game. She was very excited and decided to go to bed early to wake up fresh for the big day. Suddenly she gets a text message from the organisers stating they want to know all the cases where a round ends up as a draw. Since Miss Huehuehue is almost asleep, she asks your help to calculate the number of "all possible rounds" ending up as draw if the pairing is done randomly.

eg - 
4
2 3 8 4 
4 1 6 3
O/P - 2
The possible rounds that end up as draws are when a[1] is paired with b[3] and a[3] is paired with b[0]
*/
int numOfDraws(vector<int> player1, vector<int> player2){
    std::unordered_map<int, int> hashmap;
    for(int a : player1){
        hashmap[a] +=  1;
    }
    int count = 0;
    for(int b : player2){
        if(hashmap[b] > 0) count += hashmap[b];
    }
    return count;

}


int main(){
    std::cout << numOfDraws({2, 4, 4, 6, 9, 11}, {1, 2, 2, 2, 6, 12});
    return 0;
}