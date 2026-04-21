#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for (string html; getline(cin, html) && html != "#";) {
        stack<string> tag_stack;
        for (size_t base = 0; base < html.length();) {
            size_t t = html.find('<', base);
            if (t == -1) {
                break;
            }

            bool is_closing = html[++t] == '/';
            if (is_closing) {
                t++;
            }

            size_t end = html.find('>', t + 1);
            if (html[end - 1] == '/') { // self closing
                base = end + 1;
                continue;
            }

            string tag; {
                size_t tn_end;
                for (tn_end = t; tn_end < end && html[tn_end] != ' '; tn_end++);
                tag = html.substr(t, tn_end - t);
            }

            if (is_closing) {
                if (tag_stack.empty() || tag_stack.top() != tag) {
                    goto illegal;
                }
                tag_stack.pop();
            } else {
                tag_stack.push(tag);
            }

            base = end + 1;
        }

        if (!tag_stack.empty()) {
        illegal:
            cout << "il";
        }
        cout << "legal\n";
    }
}