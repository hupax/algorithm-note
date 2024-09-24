//
// Created by 沙枭 on 2024/3/27.
//
/*
#include "iostream"
#include "vector"
#include "iomanip"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n >= 2 && n <=100)
    {
        vector<double> arr;
        double score;
        for (int i = 0; i < n; ++i) {
            cin >> score;
            arr.push_back(score);
        }
        double m = *max_element(arr.begin(), arr.end());
        double min = *min_element(arr.begin(), arr.end());
        arr.erase(remove(arr.begin(), arr.end(), m), arr.end());
        arr.erase(remove(arr.begin(), arr.end(), min), arr.end());
        double sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            sum += arr[i];
        }
        double avg = sum / (n - 2);
        cout << fixed << setprecision(2);
        cout << avg << endl;
    }
}
*/
#include "iostream"
#include "iomanip"

using namespace std;

int main()
{
    int n;
    while (cin >> n && n >= 2 && n <=100)
    {
        auto* arr = new double[n];
        double score;
        for (int i = 0; i < n; ++i) {
            cin >> score;
            arr[i] = score;
        }
        double max = arr[0];
        double min = arr[0];
        for (int i = 0; i < n; ++i) {
            if (arr[i] > max)
            {
                max = arr[i];
            }
             if (arr[i] < min)
            {
                min = arr[i];
            }
        }
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == max || arr[i] == min)
            {
                continue;
            }
            sum += arr[i];
        }
        double avg = sum / (n - 2);
        cout << fixed << setprecision(2);
        cout << avg << endl;

        delete[] arr;
    }
}
