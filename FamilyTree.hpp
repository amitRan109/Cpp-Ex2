#include <string>
#include <iostream>
#include <vector>
using namespace std;
namespace family {
    class Node {
        public:
        string data;
        Node* father;
        Node* mother;
        int gender; //0-male, 1-female
        public:
        Node ();
        Node (string data);
        string getData();
        Node* getFather();
        Node* getMother();
        void print() {cout << getData() << " ";}
        //~Node ();
        //void deleteNode ();
    };

    class Tree {
        Node* root;
        public:
        Tree (string root);
        Tree& addFather(string son, string father);
        Tree& addMother(string son, string mother);
        void display();
        string relation(string name);
        string find (string relate);
        void remove (string ancestor);
        string great (Node* temp, int sum, int gender);
        Node* getRoot () {return this->root;}
        Node* findNode (string name,Node* temp);
        void disRecurs(Node* temp);
        int relationRecurs(string relate,Node* temp,int sum);
        vector <string> split (string s);
        void removeRecurs(Node* temp);
        Node* findSon (string name, Node* temp);
        //~Tree ();
    };
}