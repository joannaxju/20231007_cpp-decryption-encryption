#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    string method;
    string map;   
    string word; 
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    cout << "What is the method (encryption or decryption)? ";
    cin >> method;
    cout << endl;

    if(method != "encryption" && method != "decryption")
    {
        cout << "Error: invalid method choice." << endl;
    }
    else
    {
        cout << "What is the translation map (type 'default' ";
        cout << "to use default): ";
        cin >> map;
        cout << endl;

        if(map.size() != 26 && map != "default")
        {
            cout << "Error: invalid translation map size." << endl;
        }
        else if(map == "default" || map.size() == 26)
        {
            if(map == "default")
                map = "zyxwvutsrqponmlkjihgfedcba";

            cout << "What is the single word to translate: ";
            cin >> word;
            cout << endl;

            if(method == "encryption")
            {
                bool lowercase = true;
                for(int i = 0; i < word.size(); i++)
                {
                    int ch = word.at(i);
                    int a = 'a';
                    int z = 'z';
                    if(ch < a || ch > z)
                        lowercase = false;
                }
                if(!lowercase)
                {
                    cout << "Error: encryption cannot be performed." << endl;
                }
                else
                {
                    cout << "Encrypted word: ";
                    for(int i = 0; i < word.size(); i++)
                    {
                        for(int j = 0; j < alphabet.size(); j++)
                        {
                            if(word.at(i) == alphabet.at(j))
                            {
                                cout << map.at(j);
                            }
                        }
                    }
                    cout << endl;
                }
            }
            else if(method == "decryption")
            {
                int count = 0;
                for(int i = 0; i < word.size(); i++)
                {
                    for(int j = 0; j < 26; j++)
                    {
                        if(word.at(i) == map.at(j))
                            count++;
                    }
                }
                if(word.size() != count)
                {
                    cout << "Error: decryption cannot be performed." << endl;
                }
                else
                {
                    cout << "Decrypted word: ";
                    for(int i = 0; i < word.size(); i ++)
                    {
                        for(int j = 0; j < map.size(); j++)
                        {
                            if(word.at(i) == map.at(j))
                            {
                                cout << alphabet.at(j);
                            }
                        }
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}