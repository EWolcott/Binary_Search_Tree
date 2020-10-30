#include <iostream>
#include <cstdlib>
#include "BSTree.h"

using namespace cs273;

//Default constructor
template <typename T>
BSTree<T>::BSTree()
{
    root = NULL;
}
//Destructor
template <typename T>
BSTree<T>::~BSTree()
{
    RemoveSubtree(root);
}
//create a new node with null pointers to add to end of branch
template <typename T>
typename BSTree<T>::Node *BSTree<T>::CreateLeaf(T data)
{
    Node *n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}
//call the private function
template <typename T>
void BSTree<T>::Insert(T data)
{
    InsertPrivate(data, root);
}
//insert a node with new data
template <typename T>
void BSTree<T>::InsertPrivate(T data, Node *Ptr)
{
    if (root == NULL)
    {
        root = CreateLeaf(data); //begin the tree if not yet established
    }
    else if (data < Ptr->data)
    { //if data is less than current node, travel left
        if (Ptr->left != NULL)
        {
            InsertPrivate(data, Ptr->left); //continue left until no longer less than
        }
        else
        {
            Ptr->left = CreateLeaf(data); //or create a leaf if it's the lowest element
        }
    }
    else if (data > Ptr->data)
    { //if data is greater than current node, travel right
        if (Ptr->right != NULL)
        {
            InsertPrivate(data, Ptr->right); //continue right until no longer greater than
        }
        else
        {
            Ptr->right = CreateLeaf(data); //or create a leaf if it's the highest element
        }
    }
    else
        std::cout << "The data " << data << " has already been added to the tree" << std::endl;
}
//call private version
template <typename T>
void BSTree<T>::PrintInOrder()
{
    PrintInOrderPrivate(root);
}
//prints the nodes in order of lowest to highest
template <typename T>
void BSTree<T>::PrintInOrderPrivate(Node *Ptr)
{
    if (root != NULL)
    { //make sure the tree exists
        if (Ptr->left != NULL)
        {
            PrintInOrderPrivate(Ptr->left); //go all the way left
        }
        std::cout << Ptr->data << " "; //print lowest element
        if (Ptr->right != NULL)
        {
            PrintInOrderPrivate(Ptr->right); //print right if it exists, and continue
        }
    }
    else
    {
        std::cout << "The tree is empty" << std::endl;
    }
}
//call private function
template <typename T>
typename BSTree<T>::Node *BSTree<T>::ReturnNode(T data)
{
    return ReturnNodePrivate(data, root);
}
//return the node pointer containing requested data
template <typename T>
typename BSTree<T>::Node *BSTree<T>::ReturnNodePrivate(T data, Node *Ptr)
{
    if (Ptr != NULL)
    { //return the ptr if found
        if (Ptr->data == data)
        {
            return Ptr;
        }
        else
        {
            if (data < Ptr->data)
            { //iterate left if data is less than starting pointer
                return ReturnNodePrivate(data, Ptr->left);
            }
            else
            { //iterate right if data is greater than starting pointer
                return ReturnNodePrivate(data, Ptr->right);
            }
        }
    }
    else
    {
        return NULL;
    }
}
//return the data value of the root node
template <typename T>
T BSTree<T>::ReturnRootdata()
{
    if (root != NULL)
    {
        return root->data;
    }
    else
        return -1000;
}
//print the children of each node to the terminal
template <typename T>
void BSTree<T>::PrintChildren(T data)
{
    Node *Ptr = ReturnNode(data);
    if (Ptr != NULL)
    {
        std::cout << "Parent Node = " << Ptr->data << std::endl;

        Ptr->left == NULL ? //new switch statements I learned!! Never seen these before, I like them.
            std::cout << "Left Child = NULL" << std::endl
                          : std::cout << "Left Child = " << Ptr->left->data << std::endl;

        Ptr->right == NULL ? std::cout << "Right Child = NULL" << std::endl : std::cout << "Right Child = " << Ptr->right->data << std::endl;
    }
    else
    {
        std::cout << "Data " << data << " is not in the tree." << std::endl;
    }
}
//call private function
template <typename T>
T BSTree<T>::FindSmallest()
{
    return PrivateFindSmallest(root);
}
//return the smallest data value in the tree
template <typename T>
T BSTree<T>::PrivateFindSmallest(Node *Ptr)
{

    if (Ptr->left != NULL)
    {
        return PrivateFindSmallest(Ptr->left); //go left until you can't anymore
    }
    else
    {
        return Ptr->data; //then print the data
    }
}
//call private function
template <typename T>
bool BSTree<T>::erase(T data)
{
    return RemoveNodePrivate(data, root);
}
//remove a node containing specified data
template <typename T>
bool BSTree<T>::RemoveNodePrivate(T data, Node *parent)
{
    if (root != NULL)
    { //make sure tree exists
        if (root->data == data)
        { //if trying to delete the root
            RemoveRootMatch();
            return true;
        }
        else
        {
            if (data < parent->data && parent->left != NULL)
            { //iterate left until found
                parent->left->data == data ? RemoveMatch(parent, parent->left, true) : RemoveNodePrivate(data, parent->left);
                return true;
            }
            else if (data > parent->data && parent->right != NULL)
            { //iterate right until found
                parent->right->data == data ? RemoveMatch(parent, parent->right, false) : RemoveNodePrivate(data, parent->right);
                return true;
            }
            else
            {
                std::cout << "The data " << data << " was not found in the tree\n";
                return false;
            }
        }
    }
    else
    {
        std::cout << "The tree is empty\n";
    }
    return false;
}
//delete root node if requested
template <typename T>
bool BSTree<T>::RemoveRootMatch()
{
    if (root != NULL)
    {
        Node *delPtr = root;
        T rootData = root->data;
        T smallestInRightSubtree;

        if (root->left == NULL && root->right == NULL)
        { //delete if only one node
            root = NULL;
            delete delPtr;
            return true;
        }
        else if (root->left == NULL && root->right != NULL)
        { //move everything to the right up
            root = root->right;
            delPtr->right = NULL;
            delete delPtr;
            std::cout << "The root node with data " << rootData << " was deleted. "
                      << "the new root contains data " << root->data << std::endl;
            return true;
        }
        else if (root->left != NULL && root->right == NULL)
        { //move everything to the left up
            root = root->left;
            delPtr->left = NULL;
            delete delPtr;
            std::cout << "The root node with data " << rootData << " was deleted. "
                      << "the new root contains data " << root->data << std::endl;
            return true;
        }
        else
        {
            smallestInRightSubtree = PrivateFindSmallest(root->right);
            RemoveNodePrivate(smallestInRightSubtree, root); //delete the smallest element
            root->data = smallestInRightSubtree;
            std::cout << "the root data containg data " << rootData << " was overwritten with key " << root->data << std::endl;
            return true;
        }
    }
    else
    {
        std::cout << "Can not remove root. The tree is empty.\n";
    }
    return false;
}
//remove a node with matching data
template <typename T>
bool BSTree<T>::RemoveMatch(Node *parent, Node *match, bool left)
{
    if (root != NULL)
    {
        Node *delPtr;
        T matchData = match->data;
        T smallestInRightSubtree;

        if (match->left == NULL && match->right == NULL)
        {
            delPtr = match;
            left == true ? parent->left = NULL : parent->right = NULL;
            delete delPtr;
            std::cout << "The node containing data " << matchData << " was removed\n";
            return true;
        }
        else if (match->left == NULL && match->right != NULL)
        {
            left == true ? parent->left = match->right : parent->right = match->right;
            match->right = NULL;
            delPtr = match;
            delete delPtr;
            std::cout << "The node containing data " << matchData << " was removed\n";
            return true;
        }
        else if (match->left != NULL && match->right == NULL)
        {
            left == true ? parent->left = match->left : parent->right = match->left;
            match->left = NULL;
            delPtr = match;
            delete delPtr;
            std::cout << "The node containing data " << matchData << " was removed\n";
            return true;
        }
        else
        {
            smallestInRightSubtree = PrivateFindSmallest(match->right);
            RemoveNodePrivate(smallestInRightSubtree, match);
            match->data = smallestInRightSubtree;
            return true;
        }
    }
    else
    {
        std::cout << "Can not remove match. The tree is empty." << std::endl;
    }
    return false;
}
//remove everything below ptr
template <typename T>
bool BSTree<T>::RemoveSubtree(Node *Ptr)
{
    if (Ptr != NULL)
    {
        if (Ptr->left != NULL)
        {
            RemoveSubtree(Ptr->left); //iterate left until end is reached
        }
        if (Ptr->right != NULL)
        {
            RemoveSubtree(Ptr->right); //iterate right until end is reached
        }
        std::cout << "Deleting node containing data " << Ptr->data << std::endl;
        delete Ptr; //delete contents
        return true;
    }
    return false;
}
//call private function
template <typename T>
bool BSTree<T>::search(T data)
{
    if (searchprivate(data, root))
    {
        return true;
    }
    else
        return false;
}
//confirm the existence of a node with the specified data
template <typename T>
bool BSTree<T>::searchprivate(T data, Node *Ptr)
{
    bool found;
    if (root != NULL)
    {
        if (data == Ptr->data)
        { //stop the recursion
            found = true;
        }
        else if (data < Ptr->data && Ptr->left != NULL)
        { //if data is less than ptr's, move left
            found = searchprivate(data, Ptr->left);
        }
        else if (data > Ptr->data && Ptr->right != NULL)
        { //if data is greater than ptr's move right
            found = searchprivate(data, Ptr->right);
        }
        else if (data < Ptr->data && Ptr->left == NULL)
        { //if you reach the left and it isn't found
            found = false;
        }
        else if (data > Ptr->data && Ptr->right == NULL)
        { //if you reach the right and it isn't found
            found = false;
        }
    }
    return found;
}