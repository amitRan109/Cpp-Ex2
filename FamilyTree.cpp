#include "FamilyTree.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace family;
//Tree
Tree:: Tree(string root) :root(new Node(root)){}
Node* Tree:: findNode (string name, Node* temp) {
    if (!temp) return NULL;
    if (temp->getData() == name) return temp;
    Node* f =findNode (name,temp->getFather()); 
    Node* m =findNode (name,temp->getMother());
    if (f) return f;
    else if (m) return m;
    else return NULL;  
}
Tree::~Tree(){ 
    delete root;
}
Tree& Tree:: addFather(string son, string father) {

    Node* s = findNode (son, root);
    if (s == nullptr ||s->getFather()) throw out_of_range {"father: This relation is already exist"};
    s->father = new Node(father);
    s->father->gender = 0;
    return *this;
}
Tree& Tree:: addMother(string son, string mother) {
    Node* s = findNode (son, root);
    if (s == nullptr ||s->getMother()) throw out_of_range {"mother: This relation is already exist"};
    s->mother = new Node(mother);
    s->mother->gender = 1;
    return *this;
}
void Tree:: display (){ 
    disRecurs(this->root) ;
    }
void Tree:: disRecurs (Node* temp){
    if (temp) 
    {
        disRecurs(temp->father);
        cout <<" " << temp->getData() << endl;
        disRecurs(temp->mother);
    }
}
string Tree:: find(string relate) {

    if (!this->root) throw out_of_range {"No such relate"};
    if (relate == "me") {
        return root->getData();
    }
    if (relate == "father"){
        if (!root->getFather()) throw out_of_range {"No such relate"};
        return root->getFather()->getData();
    }
    if (relate == "mother"){
        if (!root->getMother()) throw out_of_range {"No such relate"};
        return root->getMother()->getData();
    }
    if (relate == "grandfather"){
        if (!root->getFather()) {
            if (!root->getMother()) throw out_of_range {"No such relate"};
            else if (!root->getMother()->getFather()) throw out_of_range {"No such relate"};
            else return root->getMother()->getFather()->getData();
        }
        else if (!root->getFather()->getFather()) throw out_of_range {"No such relate"};
        else return root->getFather()->getFather()->getData();
    }
    if (relate == "grandmother"){
        if (!root->getFather()) {
            if (!root->getMother()) throw out_of_range {"No such relate"};
            else if (!root->getMother()->getMother()) throw out_of_range {"No such relate"};
            else return root->getMother()->getMother()->getData();
        }
        else if (!root->getFather()->getMother()) throw out_of_range {"No such relate"};
        else return root->getFather()->getMother()->getData();
    }
    vector <string> result = split (relate);
    int count=0;
    for (int i=0; i<result.size()-1;i++){
        if (result[i] == "great") count++;
    }
    if (count != result.size()-1 || count == 0) throw out_of_range {"The tree cannot handle this relation\n"};
    int gender;
    if (result[result.size()-1] == "grandfather") gender = 0;
    else if (result[result.size()-1] == "grandmother") gender = 1;
    else throw out_of_range {"No such relate"}; 
    string ans=great (getRoot(),count+3,gender);
    if (ans == "") throw out_of_range {"No such relate"};
    return ans;
}
vector <string> Tree:: split (string s) {
    vector <string> ans;
    int i=0;
    while (i < s.size()){
        int j=i;
        while (j < s.size() && s[j] != '-') j++;
        string temp = s.substr(i,j-i);
        ans.push_back(temp);
        i=j+1;
    }
    return ans;
}
string Tree:: relation(string name) {
     Node* temp= findNode(name,this->root);
     if (!temp) return "unrelated";
     int rel=relationRecurs(name,this->root,0);
     switch (rel){
        case 1: return "me";
            break;
        case 2: if (temp->gender ==0) return "father";
            else return "mother";
            break;
        case 3: if (temp->gender ==0) return "grandfather";
            else return "grandmother";
            break;
        default: string ans="";
            for (int i=0; i<rel-3; i++) ans = "great-"+ans;
            if (temp->gender ==0) ans += "grandfather";
            else ans += "grandmother";
            return ans;
    }
 }
 int Tree:: relationRecurs(string name,Node* temp,int sum){
    if (!temp) return (-1)*sum;
    if (temp->getData() == name) return 1;
    else {
        int f =relationRecurs (name,temp->getFather(),sum+1)+1; 
        int m =relationRecurs (name,temp->getMother(),sum+1)+1;
        return (f>0) ? f : m;
    }
    
 }


string Tree:: great (Node* temp, int sum, int gender){
    if (!temp) return "";
    if (sum == 1) {
        if (gender == temp->gender) return temp->getData();
        return "";
    }
    else {
        string f= great(temp->getFather(),sum-1,gender);
        string m= great(temp->getMother(),sum-1,gender);
        if (f !="") return f;
        else return m;
    }
}
void Tree:: remove (string rm) {
    Node* corrent = findNode (rm, this->root);
    if (!corrent || corrent->getData() == this->root->getData()) 
        throw invalid_argument("error");
    Node* son = findSon(rm,this->root);
    if (son->getFather() != nullptr && son->getFather()->getData() == rm) son->father = nullptr;
    else if (son->getMother() != nullptr && son->getMother()->getData() == rm) son->mother = nullptr;
    removeRecurs(corrent);

}
void Tree:: removeRecurs(Node* temp) {
    if (temp) {
    removeRecurs(temp->getFather());
    removeRecurs(temp->getMother());
    temp->father = nullptr;
    temp->mother = nullptr;
    delete temp;
    }
}
Node* Tree:: findSon(string name, Node* temp) {
    if (!temp) return  nullptr;
    if (temp->getFather() != nullptr && temp->getFather()->getData() == name) 
    
        return temp;
    
    else if (temp->getMother() != nullptr && temp->getMother()->getData() == name) 
        return temp;
    else {
        Node* f=findSon(name,temp->getFather());
        Node* m=findSon(name,temp->getMother());
        if (f) return f;
        else return m;
    }
}

//Node
Node::Node () :data("null"), father(NULL),mother(NULL) {}
Node::Node(string data): father(NULL),mother(NULL) {this->data = data;}
string Node:: getData () {return this->data;}
Node* Node:: getFather() {return this->father;}
Node* Node:: getMother() {return this->mother;}
//Node::~Node () {deleteNode();}
//void Node:: deleteNode () {delete this;}
