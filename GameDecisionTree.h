#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H
using namespace std;

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // Constructor
    GameDecisionTree() : root(nullptr) {}


    void loadStoryFromFile(const string& filename, char delimiter) {
        string readFile;
        ifstream File;
        File.open(filename);
        if (!File.is_open()) {
            cerr << "Error: Could not open file " << filename << endl;
            return;
        }
        while (getline(File, readFile)) {

            int eventNum = stoi(readFile.substr(0, readFile.find(delimiter))); // first token
            string cur = readFile.substr(readFile.find(delimiter) + 1); // the rest of the original line minus first token
            string description = cur.substr(0, cur.find(delimiter));
            cur = cur.substr(cur.find(delimiter) + 1); // the rest of the original line minus second token
            int left = stoi(cur.substr(0, cur.find(delimiter)));
            int right = stoi(cur.substr(cur.find(delimiter) + 1));

            T story(description, eventNum, left, right);

            if (root == nullptr) {
                root = new Node<T>(story);
                //cout << "Inserted root: " << description << endl;
            } else {
                // Traverse through the tree to add the events where they need to be
                // I used https://www.geeksforgeeks.org/iterative-searching-binary-search-tree/ to help with the traversal logic
                stack<Node<T>*> nodeStack;
                nodeStack.push(root);
                while (!nodeStack.empty()) {
                    Node<T>* current = nodeStack.top();
                    nodeStack.pop();

                    if (current->data.leftEventNumber == eventNum) {
                        current->left = new Node<T>(story);

                    }
                    if (current->data.rightEventNumber == eventNum) {
                        current->right = new Node<T>(story);

                    }
                    if (current->left != nullptr) {
                        nodeStack.push(current->left);
                    }
                    if (current->right != nullptr) {
                        nodeStack.push(current->right);
                    }
                }
            }
        }
        File.close();
    }


    void playGame() {
        bool flag = true;
        Node<T>* cur = root;
        while (flag) {
            if (cur->left == nullptr && cur->right == nullptr) {
                cout << cur->data.description << endl;
                break;
            }
            cout << cur->data.description << " Choose an option:" << endl;
            string previewLeft = cur->left->data.description.substr(0, cur->left->data.description.find('.'));
            string previewRight = cur->right->data.description.substr(0, cur->right->data.description.find('.'));
            cout << "A) " << previewLeft << endl;
            cout << "B) " << previewRight << endl;
            string answer;
            cout << "Enter your answer (A or B): ";
            cin >> answer;
            if (answer == "A" || answer == "a") {
                cur = cur->left;
            } else if (answer == "B" || answer == "b") {
                cur = cur->right;
            } else {
                cout << "Invalid input. Try again." << endl;
            }
        }
    }
};

#endif // GAMEDECISIONTREE_H