#include <iostream>
#include <vector>
using namespace std;

int MaxSubArray(vector<int> v, int size)
{
    int ans = INT_MIN;
    for (int start_index = 0; start_index <= size; start_index++)
    {
        int sum = 0;
        for (int sub_array_size = 1; sub_array_size <= size; sub_array_size++)
        {
            if (sub_array_size + start_index >= size)
            {
                break;
            }
            sum = sum + v[start_index + sub_array_size - 1];
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