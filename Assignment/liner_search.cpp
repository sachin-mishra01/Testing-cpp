#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
using namespace std;

// Function for linear search
int linearsearch(const vector<int>& v, int key, int& count) {
    count = 0;
    for (int i = 0; i < v.size(); i++) {
        count++;
        if (v[i] == key) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {

    ofstream csvFile("comparisons.csv");
    csvFile << "Data Size,Best Case,Worst Case,Average Case,Time Taken\n";
    srand(time(0)); 

    for (int size = 10; size <= 200; size += 5) {

        vector<int> v;
        vector<int> key;

        // Generate random vector `v` of size `size`
        for (int j = 0; j < size; j++) {
            v.push_back(rand() % 10 + 1);
        }
        // Generate random vector `v` of size `size`
        for (int j = 0; j < size+1; j++) {
            key.push_back(rand() % 10 + 2);
        }

        int count;
        int mincount = INT_MAX;
        int maxcount = 0;
        double totalcount = 0.0;

        auto start = chrono::high_resolution_clock::now();

        // Perform linear search for all elements in `v`
        for (int i = 0; i < size+1; i++) {
            linearsearch(v, key[i], count);
            if(mincount>count)
            {
                mincount=count;
            }
            if(maxcount<count)
            {
                maxcount=count;
            }
            totalcount += count;
        }

        // Calculate average case
        double avgcount = totalcount / (size + 1);
        double total=totalcount;
        auto end= chrono::high_resolution_clock::now();
        chrono::duration<double> duration=end-start;

        // Write results to CSV file
        cout<<duration.count()<<endl;
        csvFile << size << "," << mincount << "," << maxcount << "," << avgcount << "," << duration.count()<<"\n";
    }

    csvFile.close();
    cout << "Results have been exported to 'comparisons.csv'." << endl;
    return 0;
}
