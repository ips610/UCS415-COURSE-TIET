#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class HuffmanTreeNode
{
public:
    string data;
    int freq;
    int left_weight;
    int right_weight;

    HuffmanTreeNode *left;
    HuffmanTreeNode *right;
    HuffmanTreeNode *parent;

    HuffmanTreeNode(string character, int frequency)
    {
        this->data = character;
        this->freq = frequency;

        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;

        this->left_weight = -1;
        this->right_weight = -1;
    }

    HuffmanTreeNode()
    {
        this->data = "";
        this->freq = -1;

        this->left = NULL;
        this->right = NULL;
        this->parent = NULL;

        this->left_weight = -1;
        this->right_weight = -1;
    }
};

bool comparison(HuffmanTreeNode *first, HuffmanTreeNode *second)
{
    return first->freq > second->freq;
}

void Build(vector<HuffmanTreeNode *> Tree)
{

    int SizeOfTree = Tree.size();
    for (int i = 0; i < SizeOfTree; i++)
    {
        HuffmanTreeNode *newNode;
        
        newNode->freq = Tree[0]->freq + Tree[1]->freq;

        newNode->left = Tree[0];
        newNode->right = Tree[1];

        newNode->left_weight = 0;
        newNode->right_weight = 1;

        Tree[0]->parent = newNode;
        Tree[1]->parent = newNode;
        Tree.erase(Tree.begin());
        Tree.erase(Tree.begin());
        Tree.push_back(newNode);
        sort(Tree.begin(), Tree.end(), comparison);
    }

    
}

void inorderTraversal(HuffmanTreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main()
{
    vector<string> alphabets = {"a", "b", "c", "d", "e", "f"};
    vector<int> frequency = {5, 16, 45, 13, 7, 12};

    vector<HuffmanTreeNode *> final;
    for (int i = 0; i < alphabets.size(); i++)
    {
        HuffmanTreeNode *newNode = new HuffmanTreeNode(alphabets[i], frequency[i]);
        final.push_back(newNode);
    }

    sort(final.begin(), final.end(), comparison);

    for (int i = 0; i < alphabets.size(); i++)
    {
        cout << final[i]->data << ' ' << final[i]->freq << endl;
    }

    Build(final);

    cout << "HI";
}