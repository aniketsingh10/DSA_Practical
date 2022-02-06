------------------------- Circular Queue ------------------------

#include <iostream>
using namespace std;

int cqueue[5];
int cfront = -1, crear = -1, n=5;

void insertCQ(int val) {
   if ((cfront == 0 && crear == n-1) || (cfront == crear+1)) {
      cout<<"Queue Overflow \n";
      return;
   }
   if (cfront == -1) {
      cfront = 0;
      crear = 0;
   } else {
      if (crear == n - 1)
      crear = 0;
      else
      crear = crear + 1;
   }
   cqueue[crear] = val ;
}


void deleteCQ() {
   if (cfront == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<cqueue[cfront]<<endl;

   if (cfront == crear) {
      cfront = -1;
      crear = -1;
   } else {
      if (cfront == n - 1)
      cfront = 0;
      else
      cfront = cfront + 1;
   }
}

void displayCQ() {
   int f = cfront, r = crear;
   if (cfront == -1) {
      cout<<"Queue is empty"<<endl;
      return;
   }
   cout<<"Queue elements are :\n";
   if (f <= r) {
      while (f <= r){
         cout<<cqueue[f]<<" ";
         f++;
      }
   } else {
      while (f <= n - 1) {
         cout<<cqueue[f]<<" ";
         f++;
      }
      f = 0;
      while (f <= r) {
         cout<<cqueue[f]<<" ";
         f++;
      }
   }
   cout<<endl;
}
int main() {

   int ch, val;
   cout<<"1)Insert\n";
   cout<<"2)Delete\n";
   cout<<"3)Display\n";
   cout<<"4)Exit\n";
   do {
      cout<<"Enter choice : "<<endl;
      cin>>ch;
      switch(ch) {
         case 1:
         cout<<"Input for insertion: "<<endl;
         cin>>val;
         insertCQ(val);
         break;

         case 2:
         deleteCQ();
         break;

         case 3:
         displayCQ();
         break;

         case 4:
         cout<<"Exit\n";
         break;
         default: cout<<"Incorrect!\n";
      }
   } while(ch != 4);
   return 0;
}
--------------------------------------------------------------------
OUTPUT 
--------------------------------------------------------------------
1)Insert
2)Delete
3)Display
4)Exit
Enter choice :
1
Input for insertion:
3
Enter choice :
1
Input for insertion:
4
Enter choice :
1
Input for insertion:
5
Enter choice :
2
Element deleted from queue is : 3
Enter choice :
2
Element deleted from queue is : 4
Enter choice :
1
Input for insertion:
6
Enter choice :
3
Queue elements are :
5 6
Enter choice :
4
Exit
process exited after 43.34  second with return value 0
press any key to continue...............

