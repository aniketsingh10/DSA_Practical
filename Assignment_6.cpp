--------------------- Threaded Binary Tree -------------------------

#include <iostream>

#define MAX_VALUE 65536

using namespace std;

class N { //node declaration
   public:
      int k;
      N *l, *r;
      bool leftTh, rightTh;
};

class ThreadedBinaryTree {
   private:
   N *root;
   public:
   ThreadedBinaryTree() { //constructor to initialize the variables
      root= new N();
      root->r= root->l= root;
      root->leftTh = true;
      root->k = MAX_VALUE;
   }
   
/*---------------------------------------------------------------------
Function Name: insert
Input Parameter: one integer
Output Paramter: NULL
Purpose: inserts the node either at left or right
----------------------------------------------------------------------*/

   void insert(int key) {
      N *p = root;
      for (;;) {
      if (p->k< key) { //move to right thread
         if (p->rightTh)
            break;
         p = p->r;
      }
      else if (p->k > key) { // move to left thread
         if (p->leftTh)
            break;
         p = p->l;
      }
      else {
         return;
      }
   }
   
   N *temp = new N();
   temp->k = key;
   temp->rightTh= temp->leftTh= true;
   if (p->k < key) {
      temp->r = p->r;
      temp->l= p;
      p->r = temp;
      p->rightTh= false;
   }
   else {
      temp->r = p;
      temp->l = p->l;
      p->l = temp;
      p->leftTh = false;
   }
}

/*---------------------------------------------------------------------
Function Name: inorder
Input Parameter: NULL
Output Paramter: NULL
Purpose: Traverse and converts the expression into inorder form
----------------------------------------------------------------------*/

void inorder() { //print the tree
   N *temp = root, *p;
   for (;;) {
      p = temp;
      temp = temp->r;
      if (!p->rightTh) {
         while (!temp->leftTh) {
            temp = temp->l;
         }
      }
      if (temp == root)
         break;
         cout<<temp->k<<" ";
      }
      cout<<endl;
   }
};

int main() {
   ThreadedBinaryTree tbt;
   int d,l1;
   cout<<"Threaded Binary Tree\n";
   do{ 	cout<<"enter data : ";
        cin>> d;
   		tbt.insert(d);
   	 	cout<<"\nDo u want to choose another option? (0/1):";
      	cin>> l1;
   }while(l1==1);
   
   tbt.insert(56);
   tbt.insert(23);
   tbt.insert(89);
   tbt.insert(85);
   tbt.insert(20);
   tbt.insert(30);
   tbt.insert(12);
   tbt.inorder();
   
   return 0;
   
}

---------------------------------------------------
OUTPUT:
---------------------------------------------------

Threaded Binary Tree
enter data : 1

Do u want to choose another option? (0/1):1
enter data : 2

Do u want to choose another option? (0/1):1
enter data : 3

Do u want to choose another option? (0/1):1
enter data : 4

Do u want to choose another option? (0/1):1
enter data : 5

Do u want to choose another option? (0/1):1
enter data : 6

Do u want to choose another option? (0/1):1
enter data : 7

Do u want to choose another option? (0/1):1
enter data : 25

Do u want to choose another option? (0/1):1
enter data : 99

Do u want to choose another option? (0/1):1
enter data : 87

Do u want to choose another option? (0/1):1
enter data : 55

Do u want to choose another option? (0/1):0
1 2 3 4 5 6 7 12 20 23 25 30 55 56 85 87 89 99

--------------------------------
Process exited after 42.15 seconds with return value 0
Press any key to continue . . .
