#include <iostream>
#include <queue>

#include "arithmeticExpression.h"

using namespace std;

void BFS (TreeNode* root);

int main(){
    string expr1 = "a+b*c";
    arithmeticExpression ex1(expr1);
    ex1.buildTree();
    cout<<"expression 1: "<<expr1<<endl;
    cout<<"infix: "; ex1.infix(); cout<<endl;
    cout<<"prefix: "; ex1.prefix(); cout<<endl;
    cout<<"postfix: "; ex1.postfix(); cout<<endl;
    //ex1.visualizeTree("expr1.dot");
    cout<<endl;

    string expr2 = "(a+b)*(c-d)";
    arithmeticExpression ex2(expr2);
    ex2.buildTree();
    cout<<"expression 2: "<<expr2<<endl;
    cout<<"infix: "; ex2.infix(); cout<<endl;
    cout<<"prefix: "; ex2.prefix(); cout<<endl;
    cout<<"postfix: "; ex2.postfix(); cout<<endl;
    //ex2.visualizeTree("expr2.dot");
    cout<<endl;

    string expr3 = "a + b * c - ( d * e + f ) * g";
    arithmeticExpression ex3(expr3);
    ex3.buildTree();
    cout<<"expression 3: "<<expr3<<endl;
    cout<<"infix: "; ex3.infix(); cout<<endl;
    cout<<"prefix: "; ex3.prefix(); cout<<endl;
    cout<<"postfix: "; ex3.postfix(); cout<<endl;
    //ex3.visualizeTree("expr3.dot");
    cout<<endl;

    string expr4 = "3h8+g9b2k7";
    arithmeticExpression ex4(expr4);
    ex4.buildTree();
    //TreeNode* dummyHead = ex4.getRoot();
    //BFS(dummyHead);
    cout<<"expression 4: "<<expr4<<endl;
    cout<<"infix: "; ex4.infix(); cout<<endl;
    cout<<"prefix: "; ex4.prefix(); cout<<endl;
    cout<<"postfix: "; ex4.postfix(); cout<<endl;
    cout<<"evaluate: "<< ex4.evaluate(); cout<<endl;
    //ex3.visualizeTree("expr4.dot");
    cout<<endl;

    return 0;
}

// void BFS (TreeNode* root) {
//   queue<TreeNode *> q;
//     q.push(root);
//     while (q.empty() == false) {
//         TreeNode *node = q.front();
//         cout << node->data;
//         q.pop();
//         if (node->left != NULL)
//           q.push(node->left);
//         if (node->right != NULL)
//           q.push(node->right);
//     }
// }