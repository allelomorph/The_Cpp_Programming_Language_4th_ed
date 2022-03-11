#include <iostream>
#include <string>
#include <cstring>  // strcmp
#include "X13-8_PrintTnodeTree.hh"


namespace X13_8 {


static Tnode *InsertTnodeInBST(Tnode *head, Tnode *node) {
    if (head == nullptr)
        throw std::invalid_argument("nullptr head parameter");
    if (node == nullptr)
        throw std::invalid_argument("nullptr node parameter");
    if (node->word == nullptr)
        throw std::invalid_argument("nullptr word data in node parameter");

    const int diff {std::strcmp(node->word, head->word)};
    if (diff < 0) {
        if (head->left == nullptr) {
            head->left = node;
            return node;
        }
        return InsertTnodeInBST(head->left, node);
    }
    if (diff > 0) {
        if (head->right == nullptr) {
            head->right = node;
            return node;
        }
        return InsertTnodeInBST(head->right, node);
    }
    // (diff == 0) redundant entry, node can be discarded
    delete[] node->word;
    delete node;
    return head;
}


Tnode *AddWordToTnodeBST(const std::string &token, Tnode *head) {
    Tnode *node {new Tnode};
    // Can't simply copy pointer to token.c_str, as token destructor is called later
    char *word = new char[token.size() + 1];
    token.copy(word, token.size());
    word[token.size()] = '\0';  // copy doesn't include null byte even with size + 1
    node->word = word;
    if (head == nullptr)
        return node;
    InsertTnodeInBST(head, node);
    return head;
}


void PrintTnodeTreeInOrder(const Tnode *head) {
    if (head == nullptr)
        return;
    // presumes BST ordering of tree
    PrintTnodeTreeInOrder(head->left);
    std::cout << head->word << std::endl;
    PrintTnodeTreeInOrder(head->right);
}


void DeleteTnodeTree(const Tnode *head) {
    if (head == nullptr)
        return;
    DeleteTnodeTree(head->left);
    DeleteTnodeTree(head->right);
    delete[] head->word;
    delete head;
}


}  // namespace X13_8


int main() {
    X13_8::Tnode *head {nullptr};
    std::string token;
    while (std::cin >> token)
        head = X13_8::AddWordToTnodeBST(token, head);
    std::cout << "\nWords in Tnode tree sorted by current locale order:" << std::endl;
    X13_8::PrintTnodeTreeInOrder(head);
    std::cout << "\nStructure of Tnode tree:" << std::endl;
    X13_8::PrintTnodeTree(head);
    X13_8::DeleteTnodeTree(head);
}
