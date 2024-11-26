#include <iostream>
#include <string>

using namespace std;

typedef struct Node* pNode;
typedef struct Node{
    pNode left, right;
    char data;
}Node;

Node newNode() {
    Node newNode;
    newNode.left=NULL;
    newNode.right=NULL;
    return newNode;
}

void insertNode(pNode head, char data) {
    Node New = newNode();

}

int main() {

}