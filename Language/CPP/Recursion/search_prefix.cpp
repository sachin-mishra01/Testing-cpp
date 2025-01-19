#include <iostream>
using namespace std;

int prefix(string st, string tar, int count, int i, int j) // st= My name is sachin
{
    if (st[j] != '\0')
    {                                                           // trg = nam
        if (st[j] == ' ')
        {
            count++;
            j++;
            i = 0;
        }
        if (i < tar.size() && st[j] == tar[i]){
            if(i==tar.size()-1){
                return count;
            }
            return prefix(st, tar, count, i + 1, j + 1);
        }
        else
        {
            while (st[j] != '\0' && st[j] != ' ')
            {
                j++;
            }
            return prefix(st, tar, count + 1, 0, j+1);
        }
    }
    return -1;
}

int isPrefixOfWord1(string sentence, string searchWord)
{
    return prefix(sentence, searchWord, 1, 0, 0);
}

int main()
{
    string sentence = "hello from the other side";
    string searchWord = "they";
    int j = isPrefixOfWord1(sentence, searchWord);
    cout << endl
         << j;
    // int j=0;
    // while(sentence[j]!='\0'){
    //     cout<<sentence[j];
    //     j++;
    // }
    return 0;
}
