#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

void sort_data_on_finish_time(vector<tuple<int, int, string>> &data)
{
    bool swapped;
    for (int i = 0; i < data.size() - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < data.size() - i - 1; j++)
        {
            if (get<1>(data[j]) > get<1>(data[j + 1]))
            {
                swap(data[j], data[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}

bool finish_time(const tuple<int, int, string> &p, const tuple<int, int, string> &q)
{
    return get<1>(p) < get<1>(q);
}

void choose_activity(vector<tuple<int, int, string>> data)
{
    vector<tuple<int, int, string>> ans;
    ans.push_back(data[0]);
    int i = 0;
    for (int m = 1; m < data.size(); m++)
    {
        if (get<0>(data[m]) >= get<1>(data[i]))
        {
            ans.push_back(data[m]);
            i = m;
        }
    }

    cout << "Selected Activities are: " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << endl;
    }
}
int main()
{
    tuple<int, int, string> p;
    vector<tuple<int, int, string>> data;

    p = make_tuple(0, 6, "A1");
    data.push_back(p);
    p = make_tuple(1, 2, "A2");
    data.push_back(p);
    p = make_tuple(3, 4, "A3");
    data.push_back(p);
    p = make_tuple(5, 7, "A4");
    data.push_back(p);
    p = make_tuple(5, 9, "A5");
    data.push_back(p);
    p = make_tuple(8, 9, "A6");
    data.push_back(p);

    // sort_data_on_finish_time(data);
    sort(data.begin(), data.end(), finish_time);

    choose_activity(data);
    return 0;
}