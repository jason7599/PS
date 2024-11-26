#include <iostream>
#include <vector>

using namespace std;

struct Record
{
    int key;
    int value;
    Record* prev = nullptr;
    Record* next = nullptr;
};

void insert(vector<Record>& database, Record* record)
{
    cout << "==== Insert " << record->key << " ====\n";

    // if (record.next != nullptr)
        // cout << "fahiuhdakjsh";

    int left = 0;
    int right = database.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        
        if (database[mid].key < record->key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    if (right != -1)
    {
        database[right].next = record;
        record->prev = &database[right];

        cout << "left = " << database[right].key << '\n';
    }

    if (left != database.size())
    {
        database[left].prev = record;
        record->next = &database[left];

        cout << "right = " << database[left].key << '\n';
        // cout << key << " -> " << database[left].key << '\n';
    }

    database.insert(database.begin() + left, *record);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int numRecords, numCommands, searchRange;
    vector<Record> database;
    
    cin >> numRecords >> numCommands >> searchRange;

    while (numRecords--)
    {
        int key, value;
        cin >> key >> value;
        Record* record = new Record();
        record->key = key;
        record->value = value;
        if (record->next != nullptr)
            cout << "rajdlkjakl";
        insert(database, record);
    }

    // cout << "============\n";

    // for (Record record : database)
    // {
    //     cout << record.key << ' ' << record.value << '\n';
    // }

    cout << "============\n";

    for (Record record : database)
    {
        if (record.prev != nullptr)
            cout << record.prev->key << " -> ";
        cout << record.key;
        if (record.next != nullptr)
            cout << " -> " << record.next->key;
        cout << '\n'; 
        // cout << record.key << ": left = " << record.prev->key << ", right = " << record.next->key << '\n';
    }

    // Record* ptr = &database[0];
    // while (ptr != nullptr)
    // {
    //     cout << ptr->key << ' ' << ptr->value << '\n';
    //     ptr = ptr->next;
    // }

    return 0;
}