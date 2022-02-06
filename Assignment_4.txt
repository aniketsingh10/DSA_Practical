-------------------------- Tree Traversal --------------------------------

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class tree
{
  public:

  char data;
  tree *left;
  tree *right;

  tree()
  {
     left=NULL;
     right=NULL;
  }

};

class node
{
  public:

  tree *t;
  node *next;

  node()
  {
  next=NULL;
  t=NULL;
  }

};


class stack1
{
  private:

  node *top;

  public:

  stack1()
  {
  top=NULL;
  }
/*__________________________________________________________________
Function name: Push
Input: tree *temp
Output: NULL
__________________________________________________________________*/

  void push(tree *temp);
  tree *pop();
  node *empty1()
  {
      return top;
  }

};


void stack1::push(tree *temp)
{
  node *p=new node;

  if(top==NULL)
  {

   top=new node;
   p->t=temp;
   p->next=NULL;
   top=p;

  }

 else
 {
   p->t=temp;
   p->next=top;
   top=p;

 }

}
/*__________________________________________________________________
Function name: Pop
Input: Null parameter
Output: NULL
__________________________________________________________________*/

tree* stack1::pop()
{
	node *p=new node;
	tree *t=new tree;

	if(top==NULL)
	{
		cout<<"\nEnter the equation: ";
	}

	p=top;
	top=top->next;

	return p->t;
}

class expression
{
  private:

  char pre[30];
  char post[30];
  stack1 s;

  public:

  void insertPostfix();
  void insertPrefix();
  void Rpost();
  void Rpre();
  void Rin();
  void Rpostorder(tree *r);
  void Rpreorder(tree *r);
  void Rinorder(tree *r);
  void NRpostorder();
  void NRpreorder();
  void NRinorder();

};

/*__________________________________________________________________
Fucntion name: Postfix Expression
Input: Postfix expression
Output: NULL
__________________________________________________________________*/

void expression::insertPostfix()
{
	int i=0;
	cout << "\nEnter postfix expression: ";
	cin >> post;

	while(post[i]!='\0')
	{
		tree *p=new tree;
		p->data=post[i];
		s.push(p);

		if((p->data=='+')||(p->data=='-')||(p->data=='*')||(p->data=='/'))
		{
			tree *temp= new tree;
			temp=s.pop();
            temp->right=s.pop();
            temp->left=s.pop();
			s.push(temp);
		}
		i++;
	}
}
/*__________________________________________________________________
Fucntion name: Prefix Expression
Input: Prefix expression
Output: NULL
__________________________________________________________________*/

void expression::insertPrefix()
{
   int i,len;

   cout<<"\nEnter prefix expression: ";
   cin>>pre;

   len=strlen(pre);
   i=len-1;

   while(i<=len && i>=0)
   {
        tree *p=new tree;
		p->data=pre[i];
		s.push(p);

		if((p->data=='+')||(p->data=='-')||(p->data=='*')||(p->data=='/'))
		{
			tree *temp= new tree;
			temp=s.pop();
			temp->left=s.pop();
            temp->right=s.pop();
			s.push(temp);
		}
              i--;
   }

}


void expression::Rpost()
{
	tree *t;
	t=s.pop();
	s.push(t);
	Rpostorder(t);
}


void expression::Rpostorder(tree *r)
{
	if(r!=NULL)
	{
		Rpostorder(r->left);
		Rpostorder(r->right);
		cout<<r->data;
	}
}


void expression::Rpre()
{
	tree *t;
	t=s.pop();
	s.push(t);
	Rpreorder(t);
}


void expression::Rpreorder(tree *r)
{
	if(r!=NULL)
	{
        cout<<r->data;
		Rpreorder(r->left);
		Rpreorder(r->right);
	}
}


void expression::Rin()
{
	tree *t;
	t=s.pop();
	s.push(t);
	Rinorder(t);
}


void expression::Rinorder(tree *r)
{
	if(r!=NULL)
	{
		Rinorder(r->left);
        cout<<r->data;
		Rinorder(r->right);
	}
}


void expression::NRinorder()
{
    tree *t;
    stack1 s1;

    t=s.pop();
    s.push(t);

    while(t!=NULL)
    {
        s1.push(t);
        t=t->left;
    }

    while(s1.empty1()!=NULL)
    {
       t=s1.pop();
       cout<<t->data;

       t=t->right;

       while(t!=NULL)
       {
        s1.push(t);
        t=t->left;
       }
    }
}


void expression::NRpreorder()
{
    tree *t;
    stack1 s1;

    t=s.pop();
    s.push(t);

    while(t!=NULL)
    {
        cout<<t->data;
        s1.push(t);
        t=t->left;
    }

    while(s1.empty1()!=NULL)
    {
       t=s1.pop();
       t=t->right;

       while(t!=NULL)
       {
        cout<<t->data;
        s1.push(t);
        t=t->left;
       }
    }
}


void expression::NRpostorder()
{
    tree *t;
    stack1 s1,s2;

    t=s.pop();
    s.push(t);

    s1.push(t);

    while(s1.empty1()!=NULL)
    {
      t=s1.pop();
      s2.push(t);

      if((t->left)!=NULL)
      s1.push(t->left);

      if((t->right)!=NULL)
      s1.push(t->right);
    }


    while(s2.empty1()!=NULL)
    {
       t=s2.pop();
       cout<<t->data;
    }
}


int main()
{
  expression e;

 int ch,f,l,l1,m,w;

 do
 {
   cout<<"\n1.prefix expression";
   cout<<"\n2.postfix expression";
   cout<<"\nEnter your choice:";
   cin>>ch;

   switch(ch)
   {
     case 1:

     e.insertPrefix();

     do
     {
        cout<<"\n1.Recursive ";
        cout<<"\n2.Non-Recursive ";
        cout<<"\nEnter your choice:";
        cin>>l;

      switch(l)
       {
          case 1:

          cout<<"\nInorder traversal:\n";
          e.Rin();

          cout<<"\nPreorder traversal:\n";
          e.Rpre();

          cout<<"\nPostorder traversal:\n";
          e.Rpost();

          break;


         case 2:

         cout<<"\nInorder traversal:\n";
         e.NRinorder();

         cout<<"\nPreorder traversal:\n";
         e.NRpreorder();

         cout<<"\nPostorder traversal:\n";
         e.NRpostorder();

         break;

       }

       cout<<"\nDo u want to choose another option? (0/1):";
       cin>>l1;

      }
       while(l1==1);


       case 2:

       e.insertPostfix();

       do
       {
        cout<<"\n1.Recursive ";
        cout<<"\n2.Non-Recursive ";
        cout<<"\nEnter your choice:";
        cin>>m;

       switch(m)
        {
          case 1:

          cout<<"\nInorder traversal:\n";
          e.Rin();

          cout<<"\nPreorder traversal:\n";
          e.Rpre();

          cout<<"\nPostorder traversal:\n";
          e.Rpost();

          break;


          case 2:

          cout<<"\nInorder traversal:\n";
          e.NRinorder();

          cout<<"\nPreorder traversal:\n";
          e.NRpreorder();

          cout<<"\nPostorder traversal:\n";
          e.NRpostorder();

          break;

        }

        cout<<"\nDo u want to choose another option? (0/1):";
        cin>>w;

       }
       while(w==1);
   }

   cout<<"\nDo u want to choose another option? (0/1):";
   cin>>f;

 }
 while(f==1);

 return 0;

}

---------------------------------------------------
OUTPUT:
---------------------------------------------------




1.prefix expression
2.postfix expression
Enter your choice:1

Enter prefix expression: +*ABC

1.Recursive
2.Non-Recursive
Enter your choice:1

Inorder traversal:
A*B+C
Preorder traversal:
+*ABC
Postorder traversal:
AB*C+
Do u want to choose another option? (0/1):1

1.Recursive
2.Non-Recursive
Enter your choice:2

Inorder traversal:
A*B+C
Preorder traversal:
+*ABC
Postorder traversal:
AB*C+
Do u want to choose another option? (0/1):0

Enter postfix expression: ABC*+

1.Recursive
2.Non-Recursive
Enter your choice:1

Inorder traversal:
A+B*C
Preorder traversal:
+A*BC
Postorder traversal:
ABC*+
Do u want to choose another option? (0/1):1

1.Recursive
2.Non-Recursive
Enter your choice:2

Inorder traversal:
A+B*C
Preorder traversal:
+A*BC
Postorder traversal:
ABC*+
Do u want to choose another option? (0/1):0

Do u want to choose another option? (0/1):0

--------------------------------
Process exited after 31.08 seconds with return value 0
Press any key to continue . . .





