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
    HuffmanTreeNode *newNode;
    for (int i = 0; i < Tree.size(); i++)
    {
        newNode -> data = Tree[0] -> data + Tree[1] -> data;
    }
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
}