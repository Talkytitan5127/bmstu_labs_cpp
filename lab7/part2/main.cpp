#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<string> NewVec(const string str)
{
    vector<string> res;
    string word;
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
        {
            word.push_back(char(tolower(str[i])));
        }
        else if (word != "")
        {
            res.push_back(word);
            word = "";
        }
    }
    return res;
}

int Find(const vector<string> list, string word)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i] == word)
        {
            return i;
        }
    }
    return -1;
}

void print(const vector<string> list, string word, int ind, int n)
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

    string str;
    int st = 1;
    bool flag = false;
    while (getline(pf1, str))
    {
        vector<string> lst = NewVec(str);

        int ind = Find(lst, word);

        if (ind != -1)
        {
            flag = true;
            cout << "In string = " << st << " ";
            print(lst, word, ind, 2);
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
