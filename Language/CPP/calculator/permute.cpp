#include <iostream>
#include <vector>
using namespace std;

// Objective: Generate all possible permutations of numbers from 1 to n.
// Input parameters:
//   - permutation: A vector that stores the current permutation sequence.
//   - used: A boolean vector to track which numbers from 1 to n have been used in the current permutation.
//   - n: An integer representing the range of numbers (1 to n) to permute.
// Side effects: Outputs each permutation of numbers from 1 to n to the console.
// Return value: None (void function).
// Approach: 
//   - The function recursively builds each permutation by:
//       - Adding an unused number to the current permutation sequence.
//       - Marking the number as used.
//       - Recursively calling the function to continue building the sequence.
//       - On reaching a complete permutation (permutation.size() == n), the function prints the sequence.
//       - Backtracking occurs by unmarking the number and removing it from the permutation 

void permuteRecur(vector<int>& permutation, vector<bool>& used, int n) {
    if (permutation.size() == n) {
        for (int num : permutation)
            cout << num << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            permutation.push_back(i);  // Insert number at the current position
            used[i] = true;  // Mark number as used

            permuteRecur(permutation, used, n);  // Recurse

            used[i] = false;  // Unmark the number (backtrack)
            permutation.pop_back();  // Remove last element (backtrack)
        }
    } 
}

// Wrapper function for generating permutations
// Objective: Initialize the data structures needed for generating permutations and call the recursive function.
// Input parameter:
//   n: An integer denoting the size of the permutation.
// Example: For n = 3, permutations are: 1 2 3, 1 3 2, 2 1 3, 2 3 1, 3 1 2, 3 2 1.
void permute(int n) {
    vector<int> permutation;          // To store current permutation
    vector<bool> used(n + 1, false);  // To track used numbers
    permuteRecur(permutation, used, n);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    permute(n);

    return 0;
}
