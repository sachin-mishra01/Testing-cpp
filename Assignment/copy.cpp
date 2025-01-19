#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <fstream>
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
    vector<int> bestComparisons;
    vector<int> worstComparisons;
    vector<int> avgComparisons;
    vector<int> dataSizes;

    ofstream csvFile("search_comparisons.csv");
    csvFile << "Data Size,Best Case,Worst Case,Average Case\n";
    srand(time(0)); 

    for (int size = 10; size <= 50; size += 5) {
        dataSizes.push_back(size);
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

        // Perform linear search for all elements in `v`
        for (int i = 0; i < size+1; i++) {
            linearsearch(v, key[i], count);
            mincount = min(mincount, count);
            maxcount = max(maxcount, count);
            totalcount += count;
        }

        // Perform an unsuccessful search
        int diffkey = rand() % 20 + 11; // Generate a key not in the range [1, 10]
        linearsearch(v, diffkey, count);
        mincount = min(mincount, count);
        maxcount = max(maxcount, count);
        totalcount += count;

        // Calculate average case
        double avgcount = totalcount / (size + 1);

        bestComparisons.push_back(mincount);
        worstComparisons.push_back(maxcount);
        avgComparisons.push_back(avgcount);

        cout << "Data Size: " << size << endl;
        cout << "Best Case Comparisons: " << mincount << endl;
        cout << "Worst Case Comparisons: " << maxcount << endl;
        cout << "Average Case Comparisons: " << avgcount<< endl;
        cout << "--------------------------" << endl;

        // Write results to CSV file
        csvFile << size << "," << mincount << "," << maxcount << "," << avgcount << "\n";
    }


    cout<<"Best Case :";
    for(int i=0;i<bestComparisons.size();i++)
    {
        cout<<bestComparisons[i]<<" ";
    }
    cout<<endl;
    cout<<"Worst Case :";
    for(int i=0;i<worstComparisons.size();i++)
    {
        cout<<worstComparisons[i]<<" ";
    }
     cout<<endl;
    cout<<"Average Case :";
    for(int i=0;i<avgComparisons.size();i++)
    {
        cout<<avgComparisons[i]<<" ";
    }
     cout<<endl;
    csvFile.close();
    cout << "Results have been exported to 'search_comparisons.csv'." << endl;
    return 0;
}
