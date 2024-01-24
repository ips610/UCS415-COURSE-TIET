#include <iostream>
#include <vector>
using namespace std;

int MaxSubArray(vector<int> v, int size)
{
    int ans = INT_MIN;
    for (int sub_array_size = 1; sub_array_size <= size; sub_array_size++)
    {
        for (int start_index = 0; start_index <= size; start_index++)
        {
            if (start_index + sub_array_size >= size)
            {
                break;
            }
            int sum = 0;
            for (int i = start_index; i <= (start_index + sub_array_size - 1); i++)
            {
                sum = sum + v[i];
            }
            if (sum > ans)
            {
                ans = sum;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int size = v.size();

    cout << MaxSubArray(v, size) << endl;
}