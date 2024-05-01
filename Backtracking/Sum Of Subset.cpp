#include <iostream>
#include <vector>
using namespace std;

// Print all subsets if there is at least one subset of set[]
// with sum equal to given sum
bool flag = false;

void PrintSubsetSum(int i, int n, int set[], int targetSum, vector<int> &subset)
{
    // targetSum is zero then there exists a subset.
    if (targetSum == 0)
    {
        // Prints valid subset
        flag = true;
        cout << "[ ";
        for (int i = 0; i < subset.size(); i++)
        {
            cout << subset[i] << " ";
        }
        cout << "]";
        return;
    }

    if (i == n || targetSum < 0)
    {
        // return if we have reached at the end of the array
        // or if targetSum becomes negative
        return;
    }

    // Not considering current element
    PrintSubsetSum(i + 1, n, set, targetSum, subset);

    // consider current element if it is less than or equal
    // to targetSum
    if (set[i] <= targetSum)
    {
        // push the current element in subset
        subset.push_back(set[i]);

        // Recursive call for consider current element
        PrintSubsetSum(i + 1, n, set, targetSum - set[i], subset);

        // pop-back element after recursive call to restore
        // subset's original configuration
        subset.pop_back();
    }
}

int main()
{
    // Test case 1
    int set[] = {3, 5, 6, 7};
    int sum = 15;
    int n = sizeof(set) / sizeof(set[0]);
    vector<int> subset;
    cout << "Output: " << endl;
    PrintSubsetSum(0, n, set, sum, subset);
    cout << endl;
    flag = false;

    return 0;
}
// This code is contributed by Hem Kishan
