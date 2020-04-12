#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace family;

TEST_CASE("make tree"){
Tree T ("Chen"); 
	T.addFather("Chen", "Avi") 
	 .addMother("Chen", "Tzafit")   
	 .addFather("Avi", "Israel")
	 .addMother("Avi", "Ita")
	 .addFather("Tzafit", "Ido")
	 .addMother("Tzafit", "Nava")
       .addFather("Nava", "Nathan")
	 .addMother("Nava", "Tzipora");


Tree Hila ("Hila"); 
	Hila.addFather("Hila", "Avi") 
	.addMother("Hila", "Tzafit")   
	.addFather("Avi", "Israel")
	.addMother("Avi", "Ita")
	.addFather("Tzafit", "Ido")
	.addMother("Tzafit", "Nava")
      .addFather("Nava", "Nathan")
	.addMother("Nava", "Tzipora");


Tree Amit ("Amit"); 
	Amit.addFather("Amit", "Ofir") 
	.addMother("Amit", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
      .addMother("Rachel", "Becka");

Tree Inbar ("Inbar"); 
	Inbar.addFather("Inbar", "Ofir") 
	.addMother("Inbar", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
	.addMother("Rachel", "Becka");
}

TEST_CASE("Checking relation"){ //35
Tree T ("Chen"); 
	T.addFather("Chen", "Avi") 
	 .addMother("Chen", "Tzafit")   
	 .addFather("Avi", "Israel")
	 .addMother("Avi", "Ita")
	 .addFather("Tzafit", "Ido")
	 .addMother("Tzafit", "Nava")
       .addFather("Nava", "Nathan")
	 .addMother("Nava", "Tzipora");


Tree Hila ("Hila"); 
	Hila.addFather("Hila", "Avi") 
	.addMother("Hila", "Tzafit")   
	.addFather("Avi", "Israel")
	.addMother("Avi", "Ita")
	.addFather("Tzafit", "Ido")
	.addMother("Tzafit", "Nava")
      .addFather("Nava", "Nathan")
	.addMother("Nava", "Tzipora");

        CHECK(T.relation("Chen")==string("me"));
        CHECK(T.relation("Avi")==string("father"));
        CHECK(T.relation("Tzafit")==string("mother"));
        CHECK(T.relation("Ido")==string("grandfather"));
        CHECK(T.relation("Israel")==string("grandfather"));
        CHECK(T.relation("Ita")==string("grandmother"));
        CHECK(T.relation("Nava")==string("grandmother"));
        CHECK(T.relation("Nathan")==string("great-grandfather"));
        CHECK(T.relation("Tzipora")==string("great-grandmother"));
        CHECK(T.relation("Naomi")==string("unrelated"));

        CHECK(Hila.relation("Hila")==string("me"));
        CHECK(Hila.relation("Avi")==string("father"));
        CHECK(Hila.relation("Tzafit")==string("mother"));
        CHECK(Hila.relation("Ido")==string("grandfather"));
        CHECK(Hila.relation("Israel")==string("grandfather"));
        CHECK(Hila.relation("Ita")==string("grandmother"));
        CHECK(Hila.relation("Nava")==string("grandmother"));
        CHECK(Hila.relation("Nathan")==string("great-grandfather"));
        CHECK(Hila.relation("Tzipora")==string("great-grandmother"));
        CHECK(Hila.relation("Naomi")==string("unrelated"));
      
        CHECK(T.relation("Avi")!=string("mother"));
        CHECK(T.relation("Ido")!=string("mother"));
         CHECK(T.relation("Tzipora")!=string("mother"));
       CHECK(T.relation("Ita")!=string("mother"));
         CHECK(T.relation("Israel")!=string("mother"));


      CHECK(T.relation("Ita")==Hila.relation("Nava"));
      CHECK(T.relation("Avi")==Hila.relation("Avi"));
      CHECK(T.relation("Israel")==Hila.relation("Ido"));
      CHECK(T.relation("Tzafit")==Hila.relation("Tzafit"));
      CHECK(T.relation("Israel")!=Hila.relation("Nava"));
      CHECK(T.relation("Ita")!=Hila.relation("Nathan"));
      CHECK(T.relation("Avi")!=Hila.relation("Nava"));
      CHECK(T.relation("Chen")==Hila.relation("Hila"));
      CHECK(T.relation("Ido")!=Hila.relation("Hila"));
      CHECK(T.relation("Chen")!=Hila.relation("Tzafit"));
       
}
TEST_CASE("Checking find"){ //8
Tree T ("Chen"); 
	T.addFather("Chen", "Avi") 
	 .addMother("Chen", "Tzafit")   
	 .addFather("Avi", "Israel")
	 .addMother("Avi", "Ita")
	 .addFather("Tzafit", "Ido")
	 .addMother("Tzafit", "Nava")
       .addFather("Nava", "Nathan")
	 .addMother("Nava", "Tzipora");


Tree Hila ("Hila"); 
	Hila.addFather("Hila", "Avi") 
	.addMother("Hila", "Tzafit")   
	.addFather("Avi", "Israel")
	.addMother("Avi", "Ita")
	.addFather("Tzafit", "Ido")
	.addMother("Tzafit", "Nava")
      .addFather("Nava", "Nathan")
	.addMother("Nava", "Tzipora");

         
        CHECK(T.find("father")==string("Avi"));
        CHECK(T.find("mother")==string("Tzafit"));
        CHECK(T.find("grandfather")==string("Israel"));
        CHECK(T.find("grandfather")==string("Ita"));
        CHECK(T.find("great-grandfather")==string("Nathan"));
        CHECK(T.find("great-grandMother")==string("Tzipora"));

      try {
		T.find("uncle");  // throws an exception
	} catch (const exception& ex) {
            CHECK(string("The tree cannot handle the 'uncle' relation")==ex.what());
	}

      try {
		T.find("sister");  // throws an exception
	} catch (const exception& ex) {
            CHECK(string("The tree cannot handle the 'sister' relation")==ex.what());
	}

      
}
     
TEST_CASE("Checking remove"){ //6
Tree T ("Chen"); 
	T.addFather("Chen", "Avi") 
	 .addMother("Chen", "Tzafit")   
	 .addFather("Avi", "Israel")
	 .addMother("Avi", "Ita")
	 .addFather("Tzafit", "Ido")
	 .addMother("Tzafit", "Nava")
       .addFather("Nava", "Nathan")
	 .addMother("Nava", "Tzipora");


Tree Hila ("Hila"); 
	Hila.addFather("Hila", "Avi") 
	.addMother("Hila", "Tzafit")   
	.addFather("Avi", "Israel")
	.addMother("Avi", "Ita")
	.addFather("Tzafit", "Ido")
	.addMother("Tzafit", "Nava")
      .addFather("Nava", "Nathan")
	.addMother("Nava", "Tzipora");

         remove("Avi");
        CHECK(T.relation("Avi")==string("unrelated"));
        CHECK(T.relation("Israel")==string("unrelated"));
        CHECK(T.relation("Ita")==string("unrelated"));
         T.remove("Chen");
        CHECK(T.relation("Chen")==string("unrelated"));
        CHECK(T.relation("Tzafit")==string("unrelated"));
        CHECK(T.relation("Nava")==string("unrelated"));
}







TEST_CASE("Checking relation"){ //18
Tree Amit ("Amit"); 
	Amit.addFather("Amit", "Ofir") 
	.addMother("Amit", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
      .addMother("Rachel", "Becka");

Tree Inbar ("Inbar"); 
	Inbar.addFather("Inbar", "Ofir") 
	.addMother("Inbar", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
	.addMother("Rachel", "Becka");


      CHECK(Amit.relation("Amit")==string("me"));
      CHECK(Amit.relation("Ofir")==string("father"));
      CHECK(Amit.relation("Chen")==string("mother"));
      CHECK(Amit.relation("Micha")==string("grandfather"));
      CHECK(Amit.relation("Rachel")==string("grandmother"));
      CHECK(Amit.relation("Meir")==string("great-grandfather"));
      CHECK(Amit.relation("Becka")==string("great-grandmother"));
      CHECK(Amit.relation("Yaakov")==string("unrelated"));
      CHECK(Amit.relation("Micha")!=string("mother"));

      CHECK(Amit.relation("Rachel")==Amit.relation("Gila"));
      CHECK(Amit.relation("Micha")==Amit.relation("David"));
      CHECK(Amit.relation("Amit")!=Amit.relation("Ofir"));

      CHECK(Amit.relation("Ofir")==Inbar.relation("Ofir"));
      CHECK(Amit.relation("Chen")==Inbar.relation("Chen"));
      CHECK(Amit.relation("Micha")==Inbar.relation("Micha"));
      CHECK(Amit.relation("Micha")==Inbar.relation("David"));
      CHECK(Amit.relation("Rachel")==Inbar.relation("Gila"));
      CHECK(Amit.relation("Micha")!=Inbar.relation("Meir"));
       
}
TEST_CASE("Checking find"){ //20
Tree Amit ("Amit"); 
	Amit.addFather("Amit", "Ofir") 
	.addMother("Amit", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
      .addMother("Rachel", "Becka");

Tree Inbar ("Inbar"); 
	Inbar.addFather("Inbar", "Ofir") 
	.addMother("Inbar", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
	.addMother("Rachel", "Becka");


      CHECK(Amit.find("me")==string("Amit"));
      CHECK(Amit.find("father")==string("Ofir"));
      CHECK(Amit.find("mother")==string("Chen"));
      CHECK(Amit.find("grandfather")==string("Micha"));
      CHECK(Amit.find("grandmother")==string("Rachel"));
      CHECK(Amit.find("great-grandfather")==string("Meir"));
      CHECK(Amit.find("great-grandMother")==string("Becka"));

      CHECK(Amit.find("father")!=string("Amit"));
      CHECK(Amit.find("grandfather")!=string("Chen"));
      CHECK(Amit.find("mother")!=string("Meir"));
      CHECK(Amit.find("great-grandMother")!=string("Ofir"));

      CHECK(Amit.find("father")==Inbar.find("father"));
      CHECK(Amit.find("mother")==Inbar.find("mother"));
      CHECK(Amit.find("grandfather")==Inbar.find("grandfather"));
      CHECK(Amit.find("grandmother")==Inbar.find("grandmother"));
      CHECK(Amit.find("great-grandfather")==Inbar.find("great-grandfather"));
      CHECK(Amit.find("great-grandMother")==Inbar.find("great-grandMother"));
      CHECK(Amit.find("me")!=Inbar.find("me"));

      try {
		Amit.find("uncle");  // throws an exception
	} catch (const exception& ex) {
            CHECK(string("The tree cannot handle the 'uncle' relation")==ex.what());
	}

      try {
		Amit.find("sister");  // throws an exception
	} catch (const exception& ex) {
            CHECK(string("The tree cannot handle the 'sister' relation")==ex.what());
	}

      
}
     
TEST_CASE("Checking remove"){ //15
Tree Amit ("Amit"); 
	Amit.addFather("Amit", "Ofir") 
	.addMother("Amit", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
      .addMother("Rachel", "Becka");

Tree Inbar ("Inbar"); 
	Inbar.addFather("Inbar", "Ofir") 
	.addMother("Inbar", "Chen")   
	.addFather("Chen", "David")
	.addMother("Chen", "Gila")
	.addFather("Ofir", "Micha")
	.addMother("Ofir", "Rachel")
      .addFather("Rachel", "Meir")
	.addMother("Rachel", "Becka");


      Amit.remove("Chen");
      CHECK(Amit.relation("Gila")==string("unrelated"));
      CHECK(Amit.relation("David")==string("unrelated"));
      CHECK(Amit.relation("Chen")==string("unrelated"));

      CHECK(Amit.relation("Rachel")!=Amit.relation("Gila"));
      CHECK(Amit.relation("Micha")!=Amit.relation("David"));

      CHECK(Amit.relation("Chen")!=Inbar.relation("Chen"));
      CHECK(Amit.relation("David")!=Inbar.relation("David"));
      CHECK(Amit.relation("Gila")!=Inbar.relation("Gila"));
      CHECK(Amit.relation("Ofir")==Inbar.relation("Ofir"));
      CHECK(Amit.relation("Micha")==Inbar.relation("Micha"));
      
      

      Inbar.remove("Becka");
      Inbar.remove("Meir");
      CHECK(Inbar.relation("Becka")==string("unrelated"));
      CHECK(Inbar.relation("Meir")==string("unrelated"));
      CHECK(Inbar.relation("Becka")!=Amit.relation("Becka"));
      CHECK(Inbar.relation("Meir")!=Amit.relation("Meir"));

      try {
		Inbar.find("great-grandfather");  // throws an exception
	} catch (const exception& ex) {
            CHECK(string("relation not found")==ex.what());
	}
}