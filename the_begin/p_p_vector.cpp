//
// Created by 沙枭 on 2024/4/1.
//
#include "iostream"
#include "vector"
#include "ctime"
#include "cstdlib"

using namespace std;

int main()
{
//    srand(time(NULL));
    vector<vector<int>> arr(5, vector<int>(3,1));
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            arr[i][j] = rand() % (100 -3 + 1) + 3;
        }
        sort(arr[i].begin(), arr[i].end());
    }
//    arr[2].reserve(arr[2].begin(), arr[2].end());
    auto uu = find(arr[2].begin(), arr[2].end(), 39);
    cout << "39: " << distance(arr[2].begin(), uu) << endl;
    cout << "fds: " << *find(arr[2].begin(), arr[2].end(), 33) << endl;
    arr[0].erase(arr[0].begin()+2);
    arr[4].pop_back();
    arr[1].insert(arr[1].begin()+1,6);
    for (auto it = arr.begin(); it != arr.end(); ++it)
    {
        for (auto i = it->begin(); i != it->end(); ++i)
        {
            cout << *i << "  ";
        }
        cout << endl;
    }
    for (auto v : arr[1])
    {
        cout << v << " ";
    }
    cout<< "------" << endl;
    for (const auto & r : arr)
    {
        for (auto c : r) cout << c << ' ';
        cout << endl;
    }

    arr.clear();
}