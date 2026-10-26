#include <iostream>
#include <string>
using namespace std;

string normalize(string text)
{
    string result = "";
    bool lastSpace = true;

    for (int i = 0; i < text.length(); i++)
    {
        char c = text[i];

        if (c >= 'A' && c <= 'Z')
            c = c + 32;

        if ((c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
        {
            result = result + c;
            lastSpace = false;
        }
        else
        {
            if (!lastSpace)
            {
                result = result + ' ';
                lastSpace = true;
            }
        }
    }

    if (result.length() > 0 &&
        result[result.length() - 1] == ' ')
    {
        result.erase(result.length() - 1);
    }

    return result;
}

bool containsPhrase(string document, string query)
{
    if (query.length() == 0)
        return false;

    for (int i = 0; i < document.length(); i++)
    {
        int j = 0;

        while (j < query.length() &&
               i + j < document.length() &&
               document[i + j] == query[j])
        {
            j++;
        }

        if (j == query.length())
        {
            
            if (i == 0 || document[i - 1] == ' ')
            {
            
                if (i + j == document.length() ||
                    document[i + j] == ' ')
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int main()
{
    string documents[5] = {
        "Data structure is important",
        "Data structures and algorithms",
        "Computer science uses algorithms",
        "Computer programming language",
        "Data science uses programming"
    };

    string words[100];
    int docList[100][5] = {0};
    int wordCount = 0;

    
    for (int i = 0; i < 5; i++)
    {
        string text = normalize(documents[i]);
        string word = "";

        for (int j = 0; j <= text.length(); j++)
        {
            if (j < text.length() && text[j] != ' ')
            {
                word = word + text[j];
            }
            else
            {
                if (word != "")
                {
                    int pos = -1;

    
                    for (int k = 0; k < wordCount; k++)
                    {
                        if (words[k] == word)
                        {
                            pos = k;
                            break;
                        }
                    }

    
                    if (pos == -1)
                    {
                        if (wordCount >= 100)
                        {
                            cout << "Index capacity exceeded.\n";
                            return 1;
                        }

                        words[wordCount] = word;
                        pos = wordCount;
                        wordCount++;
                    }

    
                    docList[pos][i] = 1;
                    word = "";
                }
            }
        }
    }

    int choice;

    do
    {
        cout << "\n\n===== MINI SEARCH ENGINE =====\n";
        cout << "1. Display Documents\n";
        cout << "2. Display Inverted Index\n";
        cout << "3. Search Word or Phrase\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice))
        {
            cout << "Please enter a valid menu number.\n";
            return 0;
        }

        cin.ignore(10000, '\n');

        if (choice == 1)
        {
            cout << "\nDOCUMENTS\n";

            for (int i = 0; i < 5; i++)
            {
                cout << "Document " << i + 1
                     << ": " << documents[i] << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "\nINVERTED INDEX\n";

            for (int i = 0; i < wordCount; i++)
            {
                cout << words[i] << " -> ";

                for (int j = 0; j < 5; j++)
                {
                    if (docList[i][j] == 1)
                        cout << "Doc" << j + 1 << " ";
                }

                cout << endl;
            }
        }
        else if (choice == 3)
        {
            string query;

            cout << "Enter any word or phrase: ";
            getline(cin, query);

            query = normalize(query);

            if (query == "")
            {
                cout << "Please enter a valid search query.\n";
                continue;
            }

            cout << "\nSEARCH RESULTS\n";

            int found = 0;

            
            bool singleWord = true;

            for (int i = 0; i < query.length(); i++)
            {
                if (query[i] == ' ')
                {
                    singleWord = false;
                    break;
                }
            }

            if (singleWord)
            {
                int pos = -1;

                
                for (int i = 0; i < wordCount; i++)
                {
                    if (words[i] == query)
                    {
                        pos = i;
                        break;
                    }
                }

                if (pos != -1)
                {
                
                    for (int j = 0; j < 5; j++)
                    {
                        if (docList[pos][j] == 1)
                        {
                            cout << "Document " << j + 1
                                 << ": " << documents[j] << endl;
                            found++;
                        }
                    }
                }
            }
            else
            {
                
                for (int i = 0; i < 5; i++)
                {
                    string text = normalize(documents[i]);

                    if (containsPhrase(text, query))
                    {
                        cout << "Document " << i + 1
                             << ": " << documents[i] << endl;
                        found++;
                    }
                }
            }

            if (found == 0)
                cout << "No matching document found.\n";
            else
                cout << "Total documents found: " << found << endl;
        }
        else if (choice == 4)
        {
            cout << "Search Engine closed.\n";
        }
        else
        {
            cout << "Invalid choice! Enter 1 to 4.\n";
        }

    } while (choice != 4);

    return 0;
}