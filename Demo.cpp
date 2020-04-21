/**
 * Demo for Family Tree
 * 
 * First version by Adam Lev-Ari,  2019-12
 * Second version by Erel Segal-Halevi, 2020-04
 */

#include "FamilyTree.hpp"

#include <iostream>
using namespace std;
using namespace family;
int main() {
	// // Tree t("amit");
	// // t.addFather("amit","ofir");
	// // t.addMother("ofir","rachel");
	// // t.addFather("rachel","meir");
	// // t.display();

	// family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	// T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	//  .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	//  .addFather("Yaakov", "Isaac")
	//  .addMother("Yaakov", "Rivka")
	//  .addFather("Isaac", "Avraham")
	//  .addFather("Avraham", "Terah");
	// //T.display();                        // displays the tree in a human-friendly format.
	
	// // cout << T.relation("Yaakov") << endl;  // prints "father"
	// // cout << T.relation("Rachel") << endl;  // prints "mother"
	// // cout << T.relation("Rivka") << endl;  // prints "grandmother"
	// // cout << T.relation("Avraham") << endl;  // prints "great-grandfather"
	// // cout << T.relation("Terah") << endl;  // prints "great-great-grandfather"
	// // cout << T.relation("xyz") << endl;  // prints "unrelated"
	// // cout << T.relation("Yosef") << endl;  // prints "me"

	// // cout << T.find("mother") << endl;  // prints "Rachel"
	// // cout << T.find("great-great-grandfather") << endl;  // prints "Terach"
	// // try {
	// // 	cout << T.find("uncle") << endl;  // throws an exception
	// // } catch (const exception& ex) {
	// //  	cout << ex.what() << endl;  // prints "The tree cannot handle the 'uncle' relation"
	// // }

	// T.remove("Yaakov"); // removes Avraham and Terah
	// //T.display();
	// cout << T.relation("Avraham") << endl;  // prints "unrelated"
	Tree Amit ("Amit"); 
	Amit.addFather("Amit", "Ofir") 
	.addMother("Amit", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
      .addMother("Rachel", "Becka");

	   Amit.remove("Meir");
	   Amit.display();

Tree Inbar ("Inbar"); 
	Inbar.addFather("Inbar", "Ofir") 
	.addMother("Inbar", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
	.addMother("Rachel", "Becka");

	Inbar.remove("Becka");
    Inbar.remove("Meir");
	Inbar.display();

      cout<<Inbar.relation("Becka")<<endl;//==string("unrelated"));
      cout<<Inbar.relation("Meir")<<endl;//==string("unrelated"));
      cout<<Inbar.relation("Becka")<<endl;//!=Amit.relation("Becka"));
      cout<<Inbar.relation("Meir")<<endl;//!=Amit.relation("Meir"));
    return 0;
	
	
}
