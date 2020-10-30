//Ethan Wolcott
//Data Structures
//June 23rd, 2020
//This is a template binary search tree, organizing data of diffrent types
//in a fashion where each element is compared as greater than or less than
//the connected element, and nodes are assigned accordingly.
//With assistance from Paul Programming: https://www.youtube.com/watch?v=sf_9w653xdE&list=PLTxllHdfUq4d-DE16EDkpeb8Z68DU7Z_Q&index=1

#ifndef BSTREE_H
#define BSTREE_H

namespace cs273
{
    template <typename T>
    class BSTree
    {
    private:
        struct Node
        {                //make a node
            Node *left;  //track the left pointer
            Node *right; //track the right pointer
            T data;      //track the data within the node
        };
        //a great deal of these functions are private versions of public functions, simply to limit access to the root node.
        //this seemed to be recommended a lot, so I gave it a shot.
        Node *root;                                             //pointer to first node
        void InsertPrivate(T data, Node *Ptr);                  //insert a node into the tree
        void PrintInOrderPrivate(Node *Ptr);                    //print contents in order
        Node *ReturnNodePrivate(T data, Node *Ptr);             //return the node containig the requested data
        T PrivateFindSmallest(Node *Ptr);                       //find the smallest element in the tree
        bool RemoveNodePrivate(T data, Node *parent);           //remove the node with requested data
        bool RemoveRootMatch();                                 //remove roots that match
        bool RemoveMatch(Node *parent, Node *match, bool left); //remove nodes that match
        Node *CreateLeaf(T data);                               //add a leaf to the tree
        Node *ReturnNode(T data);                               //return node containing requested data
        bool RemoveSubtree(Node *Ptr);                          //remove nodes in a subtree
        bool searchprivate(T data, Node *Ptr);                  //search for a data type within the tree

    public:
        //Default constructor
        BSTree();
        //Destructor
        ~BSTree();
        void Insert(T data);        //insert a node into the tree
        void PrintInOrder();        //print nodes in order
        T ReturnRootdata();         //return the data value in the root node
        void PrintChildren(T data); //print the parent and children nodes to terminal
        T FindSmallest();           //find the smallest element in the tree
        bool erase(T data);         //erase node with requested data
        bool search(T data);        //search to confirm presence of node with requested data
    };
} // namespace cs273
#include "BSTree.cpp"

#endif