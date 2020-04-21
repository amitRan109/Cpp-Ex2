
// string Tree:: relation(string relate) {
//     Node root = getRoot();
//     if (root == NULL) return "unrelated";
//     if (relate == "me") {
//         return root.getData();
//     }
//     if (relate == "father"){
//         if (root.getFather() == NULL) return "unrelated";
//         return root.getFather().getData();
//     }
//     if (relate == "mother"){
//         if (root.getMother() == NULL) return "unrelated";
//         return root.getMother().getData();
//     }
//     if (relate == "grandFather"){
//         if (root.getFather() == NULL) {
//             if (root.getMother() == NULL) return "unrelated";
//             else if (root.getMother().getFather() == NULL) return "unrelated";
//             else return root.getMother().getFather().getData();
//         }
//         else if (root.getFather().getFather() == NULL) return "unrelated";
//         else return root.getFather().getFather().getData();
//     }
//     if (relate == "grandMother"){
//         if (root.getFather() == NULL) {
//             if (root.getMother() == NULL) return "unrelated";
//             else if (root.getMother().getMother() == NULL) return "unrelated";
//             else return root.getMother().getMother().getData();
//         }
//         else if (root.getFather().getMother() == NULL) return "unrelated";
//         else return root.getFather().getMother().getData();
//     }
//     int sum = sum (relate);
//     int gender = 0; //??
//     if (sum == 0) return "unrelated";
//     else return great (relate, root, sum+3,gender);
    
// }
// int Tree:: sum (string relate) { return 3;} //??

// string great (string relate, Node temp, int sum, int gender){
//     if (temp == NULL) return "";
//    // if (sum == 1 ) return temp;
//     if (sum == 2 ) {
//         if (gender == 0 && temp.getFather() !=NULL) return temp.getFather().getData();
//         else if (gender == 1 && temp.getMother() !=NULL) return temp.getMother().getData();
//         else return "";
//     }
//     else {
//         string f= great(relate, temp.getFather(),sum-1,gender);
//         string m= great(relate, temp.getMother(),sum-1,gender);
//         if (f !="") return f;
//         else return m;
//     }
// }

// string Tree:: find (string name) {
    
// }
// void Tree:: remove (string rm){}
