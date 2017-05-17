#include <iostream>
using namespace std;

bool funcPoli(string &s, int i, int j)
{
    if(i == j || i > j)
        return true;
    if(s[i] == s[j])
        return funcPoli(s, ++i, --j);
    return false;
    
}

int main()
{
    string str;
    cin >> str;
    int sz = str.length();
    int ans = 0;
    int ind = 0, ind1 = 0;
    
    for(ind = 0; ind < sz; ind++)
    {
        for(ind1 = ind; ind1 < sz; ind1++)
        {
            if(funcPoli(str, ind, ind + (sz - ind1) - 1) == true)
                ans++;
        }
    }
    cout << ans;
    return 0;
}