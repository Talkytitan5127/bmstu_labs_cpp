#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void Enter(string & word)
{
    for (int i = 0; i < word.size(); i++)
    {
        word[i] = char(tolower(word[i]));
    }
}

vector<string> NewVec(const string & str)
{
    vector<string> res;
    string word;
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            word.push_back(char(tolower(str[i])));
        }
        else if (!word.empty())
        {
            res.push_back(word);
            word = "";
        }
    }
    return res;
}

vector<int> Find(const vector<string> & list, const string & word)
{
    vector<int> result;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == word)
        {
            result.push_back(i);
        }
    }
    return result;
}

void Print(const vector<string> & list, const string & word, const int ind, const int n)
{
    int k;
    int i;
    if (ind != 0)
    {
        k = 0;
        i = ind - 1;
        string res;
        cout << "The left part of " << word << " is = ";
        while (true)
        {
            if (k == n || i < 0)
                break;
            res = list[i] + " " + res;
            k++;
            i--;
        }
        cout << res << '\n';
    }
    if (ind != list.size() - 1)
    {
        k = 0;
        i = ind + 1;

        cout << "The right part of " << word << " is = ";
        while (true)
        {
            if (i == list.size() || k == n)
                break;
            cout << list[i] << " ";
            k++;
            i++;
        }
        cout << '\n';
    }
}

int main()
{
    string path;
    cout << "enter the path to the file" << '\n';
    getline(cin, path);
    fstream pf1(path);

    string word;
    cout << "Enter the word" << '\n';
    getline(cin, word);
    Enter(word);

    int n = 0;
    cout << "enter the number n" << '\n';
    cin >> n;

    string str;
    int st = 1;
    bool flag = false;
    while (getline(pf1, str))
    {
        vector<string> lst = NewVec(str);

        vector<int> ind = Find(lst, word);

        if (!ind.empty())
        {
            flag = true;
            for (int j = 0; j < ind.size(); j++)
            {
                cout << "In string = " << st << " ";
                Print(lst, word, ind[j], n);
            }
        }
        else
        {
            st++;
            continue;
        }
        st++;
    }
    if (!flag)
        cout << "the word = " << word << " wasn't found in a file" << '\n';
    pf1.close();
    return 0;
}
