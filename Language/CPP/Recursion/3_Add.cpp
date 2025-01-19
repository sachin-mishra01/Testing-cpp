#include <iostream>
#include "succ.cpp"
#include "pred.cpp"
using namespace std;

/**
 * @brief Adds two integers using recursion and the successor and predecessor functions.
 *
 * @objective 
 * The objective of this function is to add two integers without using the conventional 
 * addition operator. Instead, it uses the concepts of successor and predecessor to 
 * achieve the addition through recursion.
 *
 * @input 
 * - int a: The first integer to be added.
 * - int b: The second integer to be added.
 *
 * @output 
 * - The function does not directly output any values. However, it returns the sum of 
 *   the two integers, which can be printed or used as needed.
 *
 * @return 
 * - int: The sum of the two input integers.
 *
 * @approach 
 * The function uses recursion to add two integers:
 * - If the second integer `b` is not zero, the function calls itself with the successor 
 *   of `a` and the predecessor of `b`.
 * - This process continues until `b` becomes zero.
 * - When `b` is zero, the function returns the value of `a`, which is the sum of the 
 *   original `a` and `b`.
 *
 * @identifiers 
 * - a: The first integer to be added.
 * - b: The second integer to be added.
 * - succ(a): A function that returns the successor (a + 1) of `a`.
 * - pred(b): A function that returns the predecessor (b - 1) of `b`.
 *
 * @example 
 * int result = Add(3, 4); // result will be 7
 */
int Add(int a, int b)
{
   if(b==0) return a;  // base case
   if(b!=0) return Add(succ(a),pred(b));
}

int main()
{
    int a, b ,c;
    cout << "Enter the two integers :- ";
    cin >> a >> b;
    cout << "The sum of two number is " << Add(a, b);
    return 0;
}
