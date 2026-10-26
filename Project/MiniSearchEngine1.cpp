#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int TABLE_SIZE = 101;
const int MAX_DOCS = 100;
const int MAX_RESULTS = 100;

// Document structure
struct Document {
    int id;
    string title;
    string content;
};

// Linked list storing document IDs and word frequency
struct PostingNode {
    int docID;
    int frequency;
    PostingNode* next;
};

// Linked list storing unique words
struct WordNode {
    string word;
    PostingNode* postings;
    WordNode* next;
};

// Search result structure
struct SearchResult {
    int docID;
    int score;
};

class MiniSearchEngine {
private:
    Document documents[MAX_DOCS];
    int docCount;

    WordNode* hashTable[TABLE_SIZE];
    bool indexBuilt;

    // Hash function
    int hashFunction(const string& word) {
        unsigned long hash = 0;

        for (int i = 0; i < (int)word.length(); i++) {
            hash = (hash * 31 + word[i]) % TABLE_SIZE;
        }

        return hash % TABLE_SIZE;
    }

    // Convert text into lowercase words
    string nextWord(const string& text, int& pos) {
        string word = "";

        while (pos < (int)text.length() &&
               !isalnum((unsigned char)text[pos])) {
            pos++;
        }

        while (pos < (int)text.length() &&
               isalnum((unsigned char)text[pos])) {
            word += (char)tolower((unsigned char)text[pos]);
            pos++;
        }

        return word;
    }

    // Find a word in the hash table
    WordNode* findWord(const string& word) {
        int index = hashFunction(word);
        WordNode* current = hashTable[index];

        while (current != nullptr) {
            if (current->word == word) {
                return current;
            }

            current = current->next;
        }

        return nullptr;
    }

    // Create a new word entry
    WordNode* insertWord(const string& word) {
        int index = hashFunction(word);

        WordNode* node = new WordNode;
        node->word = word;
        node->postings = nullptr;

        // Handle hash collisions using chaining
        node->next = hashTable[index];
        hashTable[index] = node;

        return node;
    }

    // Add a document to a word's posting list
    void addPosting(const string& word, int docID) {
        WordNode* wordNode = findWord(word);

        if (wordNode == nullptr) {
            wordNode = insertWord(word);
        }

        PostingNode* current = wordNode->postings;
        PostingNode* previous = nullptr;

        while (current != nullptr) {
            if (current->docID == docID) {
                current->frequency++;
                return;
            }

            previous = current;
            current = current->next;
        }

        PostingNode* newPosting = new PostingNode;
        newPosting->docID = docID;
        newPosting->frequency = 1;
        newPosting->next = nullptr;

        if (previous == nullptr) {
            wordNode->postings = newPosting;
        } else {
            previous->next = newPosting;
        }
    }

    // Free all dynamically allocated index nodes
    void clearIndex() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            WordNode* current = hashTable[i];

            while (current != nullptr) {
                WordNode* nextWordNode = current->next;

                PostingNode* posting = current->postings;

                while (posting != nullptr) {
                    PostingNode* nextPosting = posting->next;
                    delete posting;
                    posting = nextPosting;
                }

                delete current;
                current = nextWordNode;
            }

            hashTable[i] = nullptr;
        }

        indexBuilt = false;
    }

public:
    MiniSearchEngine() {
        docCount = 0;
        indexBuilt = false;

        for (int i = 0; i < TABLE_SIZE; i++) {
            hashTable[i] = nullptr;
        }
    }

    ~MiniSearchEngine() {
        clearIndex();
    }

    // Add a new document
    void addDocument() {
        if (docCount >= MAX_DOCS) {
            cout << "Document limit reached!\n";
            return;
        }

        documents[docCount].id = docCount + 1;

        cout << "Enter document title: ";
        getline(cin, documents[docCount].title);

        cout << "Enter document content: ";
        getline(cin, documents[docCount].content);

        docCount++;
        indexBuilt = false;

        cout << "Document added successfully!\n";
    }

    // Display all stored documents
    void displayDocuments() {
        if (docCount == 0) {
            cout << "No documents available.\n";
            return;
        }

        cout << "\n--- DOCUMENT COLLECTION ---\n";

        for (int i = 0; i < docCount; i++) {
            cout << "\nDocument ID: " << documents[i].id;
            cout << "\nTitle: " << documents[i].title;
            cout << "\nContent: " << documents[i].content << "\n";
        }
    }

    // Build the inverted index
    void buildIndex() {
        if (docCount == 0) {
            cout << "Add documents before building the index.\n";
            return;
        }

        clearIndex();

        for (int i = 0; i < docCount; i++) {
            // Index both title and content
            string text = documents[i].title + " " +
                          documents[i].content;

            int pos = 0;
            string word;

            while (pos < (int)text.length()) {
                word = nextWord(text, pos);

                if (!word.empty()) {
                    addPosting(word, documents[i].id);
                }
            }
        }

        indexBuilt = true;
        cout << "Inverted index built successfully!\n";
    }

    // Display the complete inverted index
    void displayIndex() {
        if (!indexBuilt) {
            cout << "Build the index first.\n";
            return;
        }

        cout << "\n--- INVERTED INDEX ---\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            WordNode* wordNode = hashTable[i];

            while (wordNode != nullptr) {
                cout << wordNode->word << " -> ";

                PostingNode* posting = wordNode->postings;

                while (posting != nullptr) {
                    cout << "D" << posting->docID
                         << "(freq:" << posting->frequency << ")";

                    if (posting->next != nullptr) {
                        cout << " -> ";
                    }

                    posting = posting->next;
                }

                cout << "\n";
                wordNode = wordNode->next;
            }
        }
    }

    // Search documents and rank results
    void searchDocuments() {
        if (!indexBuilt) {
            cout << "Build or rebuild the index first.\n";
            return;
        }

        string query;

        cout << "Enter search query: ";
        getline(cin, query);

        SearchResult results[MAX_RESULTS];
        int resultCount = 0;

        int pos = 0;
        string word;

        while (pos < (int)query.length()) {
            word = nextWord(query, pos);

            if (word.empty()) {
                continue;
            }

            WordNode* wordNode = findWord(word);

            if (wordNode == nullptr) {
                continue;
            }

            PostingNode* posting = wordNode->postings;

            while (posting != nullptr) {
                int i = 0;

                // Check whether this document is already scored
                while (i < resultCount &&
                       results[i].docID != posting->docID) {
                    i++;
                }

                if (i == resultCount &&
                    resultCount < MAX_RESULTS) {
                    results[resultCount].docID = posting->docID;
                    results[resultCount].score = 0;
                    resultCount++;
                }

                if (i < resultCount) {
                    results[i].score += posting->frequency;
                }

                posting = posting->next;
            }
        }

        if (resultCount == 0) {
            cout << "No matching documents found.\n";
            return;
        }

        // Bubble sort by relevance score, highest first
        for (int i = 0; i < resultCount - 1; i++) {
            for (int j = 0; j < resultCount - i - 1; j++) {
                if (results[j].score < results[j + 1].score) {
                    SearchResult temp = results[j];
                    results[j] = results[j + 1];
                    results[j + 1] = temp;
                }
            }
        }

        cout << "\n--- SEARCH RESULTS ---\n";

        for (int i = 0; i < resultCount; i++) {
            int id = results[i].docID;

            cout << "\nRank: " << i + 1;
            cout << "\nDocument ID: " << id;
            cout << "\nTitle: " << documents[id - 1].title;
            cout << "\nRelevance Score: " << results[i].score;
            cout << "\n----------------------\n";
        }
    }

    // Main menu
    void run() {
        int choice;

        do {
            cout << "\n====== MINI SEARCH ENGINE ======\n";
            cout << "1. Add Document\n";
            cout << "2. Display Documents\n";
            cout << "3. Build / Rebuild Index\n";
            cout << "4. Search Documents\n";
            cout << "5. Display Inverted Index\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter a number.\n";
                continue;
            }

            cin.ignore(10000, '\n');

            switch (choice) {
                case 1:
                    addDocument();
                    break;

                case 2:
                    displayDocuments();
                    break;

                case 3:
                    buildIndex();
                    break;

                case 4:
                    searchDocuments();
                    break;

                case 5:
                    displayIndex();
                    break;

                case 6:
                    cout << "Exiting Mini Search Engine.\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }

        } while (choice != 6);
    }
};

int main() {
    MiniSearchEngine engine;
    engine.run();

    return 0;
}
