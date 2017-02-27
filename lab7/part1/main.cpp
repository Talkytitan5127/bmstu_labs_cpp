#include <iostream>

using namespace std;

string reverse(string word)
{
    int l = word.size();
    string result;
    for (int i = l - 1; i >= 0; i--)
    {
        result.push_back(word[i]);
    }
    return result;
}

int main()
{
    string word;
    while(true)
    {
        cout << "Enter the string" << '\n';
        getline(cin, word);

        if (word == "e" || word == "E")
            break;

        string rev = reverse(word);
        if (word == rev)
        {
            cout << word << " is palindrom" << '\n';
        }
        else
        {
            cout << word << " NOT is palindrom" << '\n';
        }
        cout << "to stop the input, push \'e\' or \'E\'" << '\n';
    }
    return 0;
}
