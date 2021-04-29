#include<iostream>

using namespace std;

string longest_common(string find1, string find2)
{
    string result;
    int a1 = find1.length(), a2 = find2.length();

    for (int i=0, j=0; i<=a1-1 && j<=a2-1; i++, j++)
    {
        if (find1[i] != find2[j])
        {
            break;
        }
        else
        {
            result.push_back(find1[i]);
        }
    }
    return result;
}

string common(string arr[], int low, int high)
{
    if (low == high)
    {
        return (arr[low]);
    }

    if (high > low)
    {
        int mid = low + (high - low) / 2;

        string find1 = common(arr, low, mid);
        string find2 = common(arr, mid+1, high);

        return longest_common(find1, find2);
    }
}

int main()
{
    string arr[] = {"coronabd", "coronaVirus","corona19", "coronaCovid"};
    int n = sizeof (arr) / sizeof (arr[0]);
    string m = common(arr, 0, n-1);

    m.length();
    cout << " The longest common starting pattern is : "<< m;
}
