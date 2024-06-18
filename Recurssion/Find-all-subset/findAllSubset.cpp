#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<int>> findAllSubset(vector<int> arr, int start, vector<int> curResult, 
vector<vector<int>> &finalResult) {
    if (start >= arr.size()) {
        finalResult.push_back(curResult);
        return finalResult;
    }
    // Recurse without including the current element
    findAllSubset(arr, start + 1, curResult, finalResult);
    // Include the current element and recurse
    curResult.push_back(arr[start]);
    findAllSubset(arr, start + 1, curResult, finalResult);
    curResult.pop_back(); // Backtrack to explore other subsets
    return finalResult;
}
void print(const vector<int>& input) 
{
    for (auto i : input) 
    {
        cout << i << " ";
    }
    cout << "\n";
}
void print(vector<vector<int>> subsets)
{
     for (const auto& subset : subsets) {
        cout << "[";
        for (size_t j = 0; j < subset.size(); ++j) {
            cout << subset[j];
            if (j < subset.size() - 1) cout << ", ";
        }
        cout << "]" << "  ";
    }
}
int main() {
    string in, i;
    vector<int> input;
    
    getline(cin, in);
    stringstream str(in);
    while (getline(str, i, ' ')) {
        input.push_back(stoi(i));
    }
    print(input);

    vector<vector<int>> subsets;
    vector<int> currentSubset;
    findAllSubset(input, 0, currentSubset, subsets);
    
    // Print the results
   print(subsets);

    return 0;
}
