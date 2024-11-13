#include <iostream>
#include <vector>

using namespace std;

struct Message
{
    char sender;
    int num_unread;
};

int main()
{
    int num_people, num_messages, message_num;
    cin >> num_people >> num_messages >> message_num;

    vector<Message> messages(num_messages);

    for (int i = 0; i < num_messages; i++)
        cin >> messages[i].num_unread >> messages[i].sender;
    
    char sender = messages[message_num - 1].sender;
    int num_unread = messages[message_num - 1].num_unread;

    if (!num_unread)
    {
        cout << -1;
        return 0;
    }

    bool read[26] = {0};
    read[0] = read[sender - 'A'] = 1;

    for (int i = message_num - 2; i >= 0; i--)
    {
        if (messages[i].num_unread == num_unread)
            read[messages[i].sender - 'A'] = 1;
        else
            break;
    }

    for (int i = message_num; i < num_messages; i++)
        read[messages[i].sender - 'A'] = 1;

    for (int i = 1; i < num_people; i++)
    {
        if (!read[i])
            cout << (char)('A' + i) << ' ';
    }

    return 0;
}