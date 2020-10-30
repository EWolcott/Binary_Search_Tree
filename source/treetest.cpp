#include <iostream>
#include <cstdlib>
#include <vector>

#include "BSTree.h"
#include "Student.h"

using namespace cs273;

std::string getname()
{
    std::vector<std::string> _firstNames;
    std::vector<std::string> _lastNames;

    _firstNames = {"Roy", "Wyatt", "Owen", "Herschel", "Bill", "Florencio", "Guy", "Renato", "Octavio", "Alexis",
                   "Gaylord", "Kyle", "Danny", "Aurelio", "Wilfredo", "Mel", "Rosario", "Clay", "Max", "Dino", "Elvin",
                   "Donnell", "Darrell", "Seymour", "Chong", "Lionel", "Noel", "Victor", "Marc", "Trevor", "Rusty", "Russ",
                   "Jonathan", "Chris", "Chauncey", "Emmitt", "Antony", "Deandre", "Anthony", "Raymond", "Eliseo", "Kris",
                   "Travis", "Felton", "Britt", "Pierre", "Patrick", "Mauro", "Erwin", "Gregorio"};
    _lastNames = {"Parrish", "Garner", "Blackwell", "Valentine", "Guerra", "Cox", "Kirk", "Clements", "Pratt",
                  "Coffey", "Romero", "Mayo", "Patel", "Page", "Oneal", "Bowen", "Chapman", "Buchanan", "Schmitt", "Mckee",
                  "Foster", "Collier", "Shea", "Velez", "Booth"};

    std::string first = _firstNames[rand() % 50];
    std::string last = _lastNames[rand() % 25];
    std::string name = first + " " + last;
    return name;
}

std::string getcourse()
{
    std::vector<std::string> _courses;
    _courses = {"Philosophy", "Business", "Computer Science", "English", "Biology"};
    std::string course = _courses[rand() % 5];
    return course;
}

int getid()
{
    int id = (rand() % 9999999);
    return id;
}

int main()
{

    int TK[16] = {50, 76, 21, 32, 4, 64, 15, 52, 14, 100, 83, 2, 3, 70, 87, 80};
    BSTree<int> myTree;
    int input = 0;
    //test the print function
    std::cout << "Printing the tree in order\nBefore adding numbers\n";
    myTree.PrintInOrder();

    for (int i = 0; i < 16; i++)
    {
        myTree.Insert(TK[i]);
    }

    std::cout << "Printing the tree in order\nAfter adding numbers\n"
              << std::endl;
    myTree.PrintInOrder();
    //test the insert function
    myTree.Insert(72);

    std::cout << "Printing the tree in order\nAfter inserting 72\n"
              << std::endl;
    myTree.PrintInOrder();
    //display the contents
    std::cout << "Printing all the parent nodes and children\n";
    for (int i = 0; i < 16; i++)
    {
        myTree.PrintChildren(TK[i]);
        std::cout << std::endl;
    }

    std::cout << "The smallest value in the tree is " << myTree.FindSmallest() << std::endl;

    std::cout << "Enter a value to search for: " << std::endl;
    std::cin >> input;
    //test the search function
    if (myTree.search(input))
    {
        std::cout << input << " is in the tree!" << std::endl;
    }
    else
        std::cout << input << " is NOT in the tree!" << std::endl;
    //test the erase and destructor
    while (input != -1)
    {
        std::cout << "Select a node to delete or enter -1 to delete all of them and test the destructor" << std::endl;
        std::cout << "Delete node: ";
        std::cin >> input;
        {
            if (input != -1)
            {
                std::cout << std::endl;
                myTree.erase(input);
                myTree.PrintInOrder();
                std::cout << std::endl;
            }
        }
    }

    Student TO[20];

    for (int i = 0; i < 20; i++)
    {
        TO[i] = Student(getname(), getcourse(), getid());
    }

    BSTree<Student> newTree;
    input = 0;
    //test the print function
    std::cout << "Printing the tree in order\nBefore adding Students\n";
    newTree.PrintInOrder();

    for (int i = 0; i < 20; i++)
    {
        newTree.Insert(TO[i]);
    }

    std::cout << "Printing the tree in order\nAfter adding Students\n"
              << std::endl;
    newTree.PrintInOrder();
    //test the insert function
    newTree.Insert(Student(getname(), getcourse(), getid()));

    std::cout << "Printing the tree in order\nAfter inserting new student\n"
              << std::endl;
    newTree.PrintInOrder();
    //display the contents
    std::cout << "Printing all the parent nodes and children\n";
    for (int i = 0; i < 20; i++)
    {
        newTree.PrintChildren(TO[i]);
        std::cout << std::endl;
    }

    std::cout << "Enter a value to search for: " << std::endl;
    std::cin >> input;
    //test the search function
    for (int i = 0; i < 20; i++)
    {
        if (input == TO[i].getNumber())
        {
            if (newTree.search(TO[i]))
            {
                std::cout << input << " is in the tree!" << std::endl;
            }
            else
                std::cout << input << " is NOT in the tree!" << std::endl;
        }
    }

    while (input != -1)
    {
        std::cout << "Select a node to delete by student number or enter -1 to delete all of them and test the destructor" << std::endl;
        std::cout << "Delete node: ";
        std::cin >> input;
        {
            if (input != -1)
            {
                std::cout << std::endl;
                for (int i = 0; i < 20; i++)
                {
                    if (input == TO[i].getNumber())
                    {
                        newTree.erase(TO[i]);
                    }
                }
                newTree.PrintInOrder();
                std::cout << std::endl;
            }
        }
    }

    return 0;
}