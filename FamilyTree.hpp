#include <string>
#include <iostream>
using namespace std;
namespace family {
    class Tree {
        public:
        Tree (string root);
        Tree& addFather(string son, string father){return *this;}
        Tree& addMother(string son, string mother){return *this;}
        void display();
        string relation(string relate);
        string find (string name);
        void remove (string rm);
    };
}