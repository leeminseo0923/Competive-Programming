#include <iostream>

using namespace std;

const int TABLE_SIZE = 100000;

class HashTable
{
private:
    struct Node
    {
        string key;
        string value;
        Node *next;
        // Node(const std::string &key, const std::string &value) : key(key), value(value), next(nullptr) {}
    };

    Node *table[TABLE_SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            table[i] = nullptr;
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            Node *curr = table[i];
            while (curr != nullptr)
            {
                Node *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }

    void put(const string &key, const string &value)
    {
        int index = hash(key);
        Node *curr = table[index];
        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        Node *newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    string get(const string &key)
    {
        int index = hash(key);
        Node *curr = table[index];
        while (curr != nullptr)
        {
            if (curr->key == key)
            {
                return curr->value;
            }
            curr = curr->next;
        }
        return "";
    }

private:
    int hash(const string &key)
    {
        long long hash = 0;
        for (char c : key)
        {
            hash = ((hash * 31) + c) % TABLE_SIZE;
        }
        return hash % TABLE_SIZE;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    HashTable sitePass;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string site, password;
        cin >> site >> password;
        sitePass.put(site, password);
    }

    for (int i = 0; i < m; i++)
    {
        string target;
        cin >> target;
        cout << sitePass.get(target) << '\n';
    }

    return 0;
}