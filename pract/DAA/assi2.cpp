#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node of Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for Min Heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string code) {

    if (root == NULL)
        return;

    // If it is a leaf node, print the character and code
    if (root->left == NULL && root->right == NULL) {
        cout << root->ch << " : " << code << endl;
    }

    // Left = 0, Right = 1
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    string text;

    cout << "Enter text: ";
    getline(cin, text);

    // Count frequency of each character
    unordered_map<char, int> freq;

    for (char ch : text) {
        freq[ch]++;
    }

    // Create Min Heap
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert each character into Min Heap
    for (auto x : freq) {
        pq.push(new Node(x.first, x.second));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {

        // Get two nodes with minimum frequency
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        // Create a new node
        Node* newNode = new Node('$', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        // Insert new node back into heap
        pq.push(newNode);
    }

    // Get root of Huffman Tree
    Node* root = pq.top();

    cout << "\nHuffman Codes:\n";

    // Print codes
    printCodes(root, "");

    return 0;
}

// tc=n log n
// sc=n