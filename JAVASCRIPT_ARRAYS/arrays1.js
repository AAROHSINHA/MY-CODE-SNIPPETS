"use strict";

/*
let arr = ["a", "b", "c", "d", "e", "f"];
// 1. SLICE
console.log(arr.slice(2)); // starts at 2
console.log(arr.slice(2, 4)); // starts at 2 and ends at 4 (exclusive)
console.log(arr.slice(-2)); // negetive starts from the end of the array
console.log(arr.slice(1, -1)); // negetive as end (here -1 means except the last)
console.log(arr.slice()); // creates a shallow copy of array
console.log(arr.slice == [...arr]);
*/
//
//
//
//
//
//
/*
// 2. SPLICE - changes the original array
let fruits = ["apple", "banana", "mango", "guava", "strawberry"];
console.log(fruits);
console.log(fruits.splice(2, 2)); // NOTE - MEANS DELETE 2 ELEMENTS AFTER INDEX 2
console.log(fruits);
// splice actually does mutate the original array

// to remove last element of the array
let arr100 = [100, 200, 400];
arr100.splice(-1);
console.log(arr100);
*/
//
//
//
//
//
//
/*
// 3. REVERSE
let letters1 = "abcdefghijk".split("");
let letters2 = "kjihgfedcba".split("");
console.log(letters1.reverse());
console.log(letters1); // does actually mutate the original one
console.log(letters1 == letters2);
*/
//
//
//
//
//
//
/*
// 4. CONCAT
const firstname = ["Aaroh"];
const lastName = ["Sinha"];
const letters = firstname.concat(lastName); // concat doesnot mutate the original array
console.log(letters);
*/
//
//
//
//
//
//
/*
// 5. JOIN
const f1 = ["FRUITS", "ARE"];
const f2 = ["VERY", "HEALTHY"];
console.log(f1.concat(f2).join("-"));
*/
//
//
//
//
//
//
/*
// 6. AT
const arr = [23, 11, 64];
console.log(arr.at(0));
console.log(arr.at(1) === arr[1]); // same
// one particularity of at method which makes it more useful than arr[] method is that we can get last element by using -1 and second last by -2 and so on
console.log(arr.at(-1));
console.log(arr.at(-2));
*/
//
//
//
//
//
//
/*
// 7. ENTRIES
const cars = ["Car1", "Car2", "Car3", "Car4", "Car5"];
for (const [i, car] of cars.entries()) {
  console.log(i, car);
}// returns  [counter, element]
// this is just like enumerate in python
*/
//
//
//
//
//
//
/*
// ----> FOREACH
const movements = [200, 450, -400, 3000, -650, -150, 70, 1300];
for (const movement of movements) {
  if (movement > 0) {
    console.log(`You deposited ${movement}`);
  } else {
    console.log(`You withdrew ${movement}`);
  }
}

console.log("==========     FOREACH     ==========");
// using foreach - foreach requires a callback function means in a sense it is a higher order function
// the return value is undefined, means nothing to return
movements.forEach(function (movement) {
  if (movement > 0) {
    console.log(`You deposited ${movement}`);
  } else {
    console.log(`You withdrew ${movement}`);
  }
});

const animals = ["Dog", "Cat", "Lion", "Giraffe", "Bufalo"];
// parameters of callback function - element, index, array
animals.forEach(function (animal, index, array) {
  console.log(`Animal ${index} of array [${array}] is ${animal}`);
});

// limitations of foreach
// 1. we cannot break or continue the foreach
// 2. we cannot return anyhting
// 3. does not handle asynchronous operations well

// --> Foreach on maps
const currencies = new Map([
  ["USD", "United States Dollar"],
  ["EUR", "Euro"],
  ["GBP", "Pound Sterling"],
]);

currencies.forEach(function (value, key, map) {
  console.log(value, key); // key value pairs in map
  console.log(map); // entire map
});

// --> Foreach on sets
const currenciesUnique = new Set([
  "USD",
  "Eur",
  "Rupee",
  "Rupee",
  "Rupee",
  "USD",
  "USD",
]);
console.log(currenciesUnique);
currenciesUnique.forEach(function (value, key, set) {
  console.log(value, key, set);
  // here the value and key are same

});
*/
//
//
//
//
//
//
/*
///// CHALLENGE 1 ///////
const JuliaDogs = [3, 5, 2, 12, 7];
const KateDogs = [4, 1, 15, 8, 3];

const JuliaDogsCorrect = [];
JuliaDogs.forEach(function (element, index, array) {
  if (index != 0 && index != array.length - 1) {
    JuliaDogsCorrect.push(element);
  }
});

const allDogs = JuliaDogs.concat(KateDogs);

// adult or small
allDogs.forEach((dogAge) => {
  if (dogAge >= 3) {
    console.log(`The age of the dog is ${dogAge} and it is an adult`);
  } else {
    console.log(`The age of the dog is ${dogAge} and it is a puppy`);
  }
});
*/
//
//
//
//
//
//
/*
// MAP - same as foreach but creates a new array
// --> maps value of the original array, does some operation on them and add them in a brand new array
const euroTousd = 1.1;
const movements = [100, 38, 24, 99, 105];
const convertedArray = movements.map(function (element) {
  return element * euroTousd;
});

console.log(movements);
console.log(convertedArray);

// using the arrow functions (IMMPPOORRTTANNT)
const numsToConv = [2, 4, 6, 8, 10];
const numsConverted = numsToConv.map((num) => num ** 2);
console.log(numsToConv);
console.log(numsConverted);

const toConvToZero = [1010, 202, 456, 32];
const convertedToZero = toConvToZero.map((num) => 0);
console.log(toConvToZero);
console.log(convertedToZero);
*/
//
//
//
//
//
//
/*
// FILTER - only looks for elements which satisfy some certain condition and then return a new array
const ages = [12, 43, 31, 9, 17, 19, 26, 15, 18, 72];
const elegibleToVote = ages.filter(function (age) {
  return age >= 18;
});

const words = ["Small", "biG", "HelloWorld", "MyName", "cAR", "wiNe", "hOME"];
const firstLowers = words.filter(function (word) {
  return word == word[0].toLowerCase() + word.slice(1);
});
console.log(words);
console.log(firstLowers);

console.log(ages);
console.log(elegibleToVote);
*/
//
//
//
//
//
//
/*
// REDUCE - Used to boil bown all elements of the array to one element. eg - sum of all element. (acc + current)
const transactions = [100, 125, -19, 99, -249, 429, 12, -345, -25, 42];
const total = transactions.reduce(function (
  accumulator,
  currentElem,
  index,
  array
) {
  return accumulator + currentElem;
});

console.log(total);

// get maximum value of movements array by reduce
const maxMovement = transactions.reduce(function (accumulator, currElem) {
  return accumulator > currElem ? accumulator : currElem;
}, 0);
console.log(maxMovement);
*/
//
//
//
//
//
//
/*
///// CHALLENGE 2 ///////
const dogAges = [5, 2, 4, 1, 15, 8, 3];
const humanAges = dogAges.map(function (currentAge) {
  if (currentAge <= 2) {
    return currentAge * 2;
  } else {
    return currentAge * 4 + 16;
  }
});

const humanAgesExcluded = humanAges.filter((currentAge) => {
  return currentAge > 18;
});

const averageHumanAge =
  humanAges.reduce(function (accumulator, currentAge) {
    return accumulator + currentAge;
  }) / humanAges.length;
console.log(dogAges);
console.log(humanAges);
console.log(humanAgesExcluded);
console.log(averageHumanAge);
*/
//
//
//
//
//
//
/*
// FIND - Used tp find element based on conditions
const numbers = [100, 200, 729, 809, 920, -100, 1002, -1];
const firstNegetive = numbers.find((num) => num < 0);
console.log(firstNegetive);
// returns the first find only
// filter returns all the elements matched the condition whicle filter returns only one element.
*/
//
//
//
//
//
//
/*
// FIND LAST and FINDLASTINDEX
const payments = [125, 99, -100, 429, -29, -19, 58, -233];
const firstWithdrawal = payments.find((mov) => mov < 0);
const lastWithdrawal = payments.findLast((mov) => mov < 0);
const lastIndex = payments.findLastIndex((mov) => mov < 0);
console.log(firstWithdrawal);
console.log(lastWithdrawal);
console.log(lastIndex);
*/
//
//
//
//
//
//
/*
// INCLUDES and SOME
const payments = [125, 99, -100, 429, -29, -19, 58, -233];
console.log(payments.includes(-100));

// include checks if such an element is present. some is used for conditions
// eg - to find if there are any positive transactions in payments array
const anyDeposits = payments.some((mov) => mov >= 0);
console.log(anyDeposits);
const anyDepositsAbove400 = payments.some((mov) => mov >= 400);
console.log(anyDepositsAbove400);
*/
//
//
//
//
//
//
//
/*
// challenge - given a bank account transaction history. Check if bank will provide a loan or not.  The bank gurantees a loan if there is atleast one deposit with 10 percent of the requested loan amount
const bankTransactions = [99, 129, -40, 2000, 1200, -1899, 458];
const loanAmount = 15000; // we want a loan of 15000, we need to check if there is atleast one transaction involving deposit of 10 percent of this 150000.
const areThereDeposits = bankTransactions.some(
  (transaction) => transaction >= 0 && transaction >= loanAmount * 0.1
);
if (areThereDeposits) {
  console.log(`You are granted a loan of ${loanAmount}`);
} else {
  console.log(`You do not match the criteria to get a loan of ${loanAmount}`);
}
//
//
//
//
//
//
//
// EVERY - returns true if all elements apss the conditions
const nums = [1, 3, 3, 11, 7];
const areAllPositives = nums.every((number) => number >= 0);
console.log(areAllPositives);
const areAllOdd = nums.every((number) => number % 2 == 1);
console.log(areAllOdd);
*/
//
//
//
//
//
//
//
/*
const arr_ = [[1, 2, 3], [4, 5, 6], 7, 8];
console.log(arr_.flat(1)); // add the nested elements as one whole array
// parameter 1 means 1 level of nesting - [1, 2, 3, 4, 5, 6, 7, 8]

const arrDeep = [[[1, 2], 3], [[4, 5], 6], 7, 8];
console.log(arrDeep.flat(1)); //[Array(2), 3, Array(2), 6, 7, 8]
console.log(arrDeep.flat(2)); // flattens upto 2 levels and give one array - [1, 2, 3, 4, 5, 6, 7, 8]
*/
//
//
//
//
//
//
//
//
/*
////////////////////////////////////
/////// CHALLENGE 4 ////////////////
////////////////////////////////////
const breeds = [
  {
    breed: "German Shephard",
    averageWeight: 32,
    activities: ["fetch", "swimming"],
  },
  {
    breed: "Dalmatian",
    averageWeight: 24,
    activities: ["running", "fetching", "agility"],
  },
  { breed: "Labrador", averageWeight: 28, activities: ["swimming", "fetch"] },
  { breed: "Beagle", averageWeight: 12, activities: ["digging", "fetch"] },
  {
    breed: "Husky",
    averageWeight: 26,
    activities: ["running", "agility", "swimming"],
  },
  { breed: "Bulldog", averageWeight: 36, activities: ["sleeping"] },
  { breed: "Poodle", averageWeight: 18, activities: ["agility", "fetch"] },
];

// 1. store the average weight of husky in a variable
const huskyWeight = breeds.find(
  (dogBreed) => dogBreed.breed == "Husky"
).averageWeight;
console.log(`The average Husky weight is ${huskyWeight}`);

// 2. find the name of only breed that likes running and fetch
const dogBothActivities = breeds.find(
  (dog) =>
    dog.activities.includes("running") && dog.activities.includes("fetching")
).breed;
console.log(
  `The breed that does both running and fetching is ${dogBothActivities}`
);

// 3 and 4. create array all aactivities of all dog activities
let allActivities = breeds
  .map(function (dogs) {
    return dogs.activities;
  })
  .flat(1);
allActivities = new Set(allActivities);
console.log(`The dog activities are = ${[...allActivities]} `);

// 5. many dog breeds like to swim. what other do these dogs like to d oapart from swimming
const swimmingAdjacent = new Set(
  breeds
    .filter(function (dog) {
      return dog.activities.includes("swimming");
    })
    .map((dogs) => dogs.activities)
    .flat(1)
    .filter((activity) => activity != "swimming")
);
console.log(swimmingAdjacent);

// 6. Do all weights have average weight of 10 kg or more. log true and false for console
breeds.forEach((element) => {
  if (element.averageWeight >= 10) {
    console.log(`${element.breed} -> true`);
  } else {
    console.log(`${element.breed} -> false`);
  }
});

// 7. which dog breeds are active. Active means dogs which have acitivities more than 2
const activeDogBreeds = breeds
  .filter((dogs) => dogs.activities.length >= 3)
  .map((dog) => dog.breed);
console.log(activeDogBreeds);
*/
//
//
//
//
//
//
//
//
/*
// SORTING ARRAY
const owners = ["Jonas", "Zach", "Adam", "Martha"];
console.log(owners.sort()); // mutates the original array

const movements = [100, 200, -150, 25, 35, -125];
console.log(movements.sort());
// [-125, -150, 100, 200, 25, 35]
// we get an unsorted array. Beacuse the sorting method converts everything to string then sorts it, we get this
// as ["-125", "-150"....]
// to fix this we need to add a compare callback function

// a - currentVal___b - nextVal
// return < 0 A,B
// return > 0 B,A
movements.sort((a, b) => {
  if (a > b) return 1;
  if (b > a) return -1;
});
// for descending, interchange 1 and -1
console.log(movements);

// simplified
movements.sort((a, b) => a - b);
console.log(movements);

// this wont work for strings and numbers
*/
//
//
//
//
//
//
//
//
/*
// --> CREATING AND FILLING ARRAYS
const arr1 = new Array(7); // [empty × 7]
// we can use only the fill method on this empty array
// arr1.fill(100); // fills with 7 100s
// arr1.fill(100, 3); // begins at index 3 only
console.log(arr1);

// from method
const arr = [1, 2, 3, 4, 5, 6, 7];
const y = Array.from({ length: 7 }, () => {
  return 1;
});
console.log(y);

const z = Array.from({ length: 7 }, (_, i) => i + 1);
console.log(z);

const HundredRandomDiceRolls = Array.from({ length: 100 }, () =>
  Math.round(Math.random() * 6)
);
console.log(HundredRandomDiceRolls);
*/
//
//
//
//
//
//
//
//
/*
// --> How to not mutate the original array using some methods
const arr1 = [2, 4, 6, 8, 10];
const reverseArr = arr1.reverse();
console.log(arr1);
console.log(reverseArr);
// the original also gets mutiliated above

// alternative - slice and reverse
const arr2 = [1, 3, 5, 7, 9];
const reverse2 = arr2.slice().reverse();
console.log(arr2);
console.log(reverse2);

// other alternative - toReversed
const arr3 = [9, 10, 11, 12, 13];
const rev3 = arr3.toReversed();
console.log(arr3);
console.log(rev3);

// toSorted and toSpliced also used
*/
//
//
//
//
//
//
//
//
//
/*
////////////////////////////////////
/////////// EXCERSISES /////////////
////////////////////////////////////
const account1 = {
  owner: "Jonas Schmedtmann",
  movements: [200, 450, -400, 3000, -650, -130, 70, 1300],
  interestRate: 1.2, // %
  pin: 1111,
};

const account2 = {
  owner: "Jessica Davis",
  movements: [5000, 3400, -150, -790, -3210, -1000, 8500, -30],
  interestRate: 1.5,
  pin: 2222,
};

const account3 = {
  owner: "Steven Thomas Williams",
  movements: [200, -200, 340, -300, -20, 50, 400, -460],
  interestRate: 0.7,
  pin: 3333,
};

const account4 = {
  owner: "Sarah Smith",
  movements: [430, 1000, 700, 50, 90],
  interestRate: 1,
  pin: 4444,
};

const accounts = [account1, account2, account3, account4];

// 1. TOTAL MONEY FROM ALL ACCOUNTS DEPOSITED
const totalDepositedMoney = accounts
  .map((account) => account.movements)
  .flat(1)
  .filter((transaction) => transaction >= 0)
  .reduce((acc, curr) => acc + curr, 0);
console.log(totalDepositedMoney);

// 2. COUNT NUMBER OF DEPOSITS OF ATLEAST 1000 dollars
const NumberOfDeposits1000 = accounts
  .map((account) => account.movements)
  .flat(1)
  .filter((payment) => payment >= 1000).length;
console.log(NumberOfDeposits1000);

// 3.
// const sums = accounts
//   .flatMap((acc) => acc.movements)
//   .reduce(
//     (sums, curr) => {
//       return curr > 0 ? (sums.deposits += curr) : (sums.withdrawals += curr);
//     },
//     { deposits: 0, withdrawals: 0 }
//   );
// // instead of 0 we add {} means we need an object not an int
// console.log(sums);
*/
//
//
//
//
//
//
//
//
//
//
///////////////////////////////////////
// Coding Challenge #4

/* 
Julia and Kate are still studying dogs, and this time they are studying if dogs are eating too much or too little.
Eating too much means the dog's current food portion is larger than the recommended portion, and eating too little is the opposite.
Eating an okay amount means the dog's current food portion is within a range 10% above and 10% below the recommended portion (see hint).

1. Loop over the array containing dog objects, and for each dog, calculate the recommended food portion and add it to the object as a new property. Do NOT create a new array, simply loop over the array. Forumla: recommendedFood = weight ** 0.75 * 28. (The result is in grams of food, and the weight needs to be in kg)
2. Find Sarah's dog and log to the console whether it's eating too much or too little. HINT: Some dogs have multiple owners, so you first need to find Sarah in the owners array, and so this one is a bit tricky (on purpose) 🤓
3. Create an array containing all owners of dogs who eat too much ('ownersEatTooMuch') and an array with all owners of dogs who eat too little ('ownersEatTooLittle').
4. Log a string to the console for each array created in 3., like this: "Matilda and Alice and Bob's dogs eat too much!" and "Sarah and John and Michael's dogs eat too little!"
5. Log to the console whether there is any dog eating EXACTLY the amount of food that is recommended (just true or false)
6. Log to the console whether there is any dog eating an OKAY amount of food (just true or false)
7. Create an array containing the dogs that are eating an OKAY amount of food (try to reuse the condition used in 6.)
8. Create a shallow copy of the dogs array and sort it by recommended food portion in an ascending order (keep in mind that the portions are inside the array's objects)

HINT 1: Use many different tools to solve these challenges, you can use the summary lecture to choose between them 😉
HINT 2: Being within a range 10% above and below the recommended portion means: current > (recommended * 0.90) && current < (recommended * 1.10). Basically, the current portion should be between 90% and 110% of the recommended portion.

TEST DATA:
const dogs = [
  { weight: 22, curFood: 250, owners: ['Alice', 'Bob'] },
  { weight: 8, curFood: 200, owners: ['Matilda'] },
  { weight: 13, curFood: 275, owners: ['Sarah', 'John'] },
  { weight: 32, curFood: 340, owners: ['Michael'] }
];

GOOD LUCK 😀
*/

const dogs = [
  { weight: 22, curFood: 250, owners: ["Alice", "Bob"] },
  { weight: 8, curFood: 200, owners: ["Matilda"] },
  { weight: 13, curFood: 275, owners: ["Sarah", "John"] },
  { weight: 32, curFood: 340, owners: ["Michael"] },
];

// question 1
dogs.forEach((dog) => (dog.recommendedFood = dog.weight ** 0.75 * 28));
console.log(dogs);

// question 2
const SarahsDog = dogs.find((dog) => dog.owners.includes("Sarah"));
if (SarahsDog.curFood > SarahsDog.recommendedFood) {
  console.log("Eating too much");
} else {
  console.log("Eating not too much");
}

// question 3
const ownersEatTooMuch = dogs
  .filter((dog) => dog.curFood > dog.recommendedFood)
  .map((dog) => dog.owners)
  .flat(1);
const ownersEatTooLittle = dogs
  .filter((dog) => dog.curFood <= dog.recommendedFood)
  .map((dog) => dog.owners)
  .flat(1);
console.log(ownersEatTooMuch);
console.log(ownersEatTooLittle);

// question 4


// question 5


// question 6

