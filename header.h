#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;

FILE *file;
ofstream token,log;

int lineCount = 1;




/*Item* create(string s,Item* i)
{
    Item *result=new Item;
    result->key=s;
    result->next=i;
    return result;
}*/


class LinkedList
{
	int ver;
	LinkedList *next;
	LinkedList *head;
	LinkedList *prsnt;
	int kcart;
	char *yek;
	char *value;
	double val;
	string code;
	string labelTrue;
    string labelFalse;
		
private:

    

    int length2;

public:

    LinkedList();

    // Inserts an item at the end of the list.
    void insertItem( char *ak,char *bv );

    // Removes an item from the list by item key.

   // bool removeItem( string itemKey );

   	int getItem( char *a );

    int getLength();

    void printList();
    
    LinkedList* itemGet(char *b);

    //~LinkedList();
};


LinkedList::LinkedList()
{
    kcart = 0;
    head=(LinkedList*) malloc (sizeof(LinkedList));
    prsnt=(LinkedList*) malloc(sizeof(LinkedList));
    yek=(char*) malloc(sizeof(char)*100);
    value=(char*) malloc(sizeof(char)*100);
    val=(double*) malloc(sizeof(double)*100);
}

// Inserts an item at the end of the list.
void LinkedList::insertItem(char *ak,char *bk  )
{
    LinkedList *nodenew =(LinkedList*) malloc(sizeof(LinkedList));
    nodenew->yek=(char*) malloc(sizeof(char)*100);
    nodenew->value=(char*) malloc(sizeof(char)*100);
    nodenew->val=(double*) malloc(sizeof(double)*100);
    strcpy(nodenew->yek,ak);
    strcpy(nodenew->value,bk);
    
    if(kcart==0){
    	head=nodenew;
    	prsnt=nodenew;
    	head->next=NULL;
    }
    else if(kcart==1){
    	head->next=nodenew;
    	prsnt=nodenew;
    	head->next=NULL;
    }
    else{
    	prsnt->next=nodenew;
    	prsnt=nodenew;
    	prsnt->next=NULL;
    }
    kcart++;
    
    
}
/*
bool LinkedList::removeItem( string itemKey )
{
    //if (!head -> head) return false;
    Item *p = head;
    Item *q = head;
    while (q)
    {
        if (q -> key == itemKey)
        {
            p -> next = q -> next;
            delete q;
            kcart--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}
*/

// Searches for item
int LinkedList::getItem( char *a )
{
    LinkedList * list;
    int b=1;
    int ter=-1;
    list=(LinkedList*) malloc(sizeof(list));
    list=head;
    while(list!=NULL)
    {
    	if(strcmp(list->yek,a)==0){
    		ter=b;
    		break;
    	}
    	list=list->next;
    	b++;
    }
    return ter;
}

LinkedList* LinkedList::itemGet(char *a)
{
	LinkedList * list;
    int b=1;
    int ter=-1;
    list=(LinkedList*) malloc(sizeof(list));
    list=head;
    while(list!=NULL)
    {
    	if(strcmp(list->yek,a)==0){
    		ter=b;
    		break;
    	}
    	list=list->next;
    	b++;
    }
    if(ter==-1) return NULL;
    else
    	return list;

}


// Display list
void LinkedList::printList()
{
    LinkedList * result;
    result=(LinkedList*) malloc(sizeof(LinkedList));
	result=head;
	int count=0;
	while(result!=NULL)
	{
		log<<"< "<<result->value<<" ";
		
		if(strcmp(result->value,"NUM")==0)
		{
			log<<result->yek <<" ";
			double value;
  			sscanf(result->yek,"%.5lf",&value);
  			log<<value<<endl;
			
		}
		else if(strcmp(result->value,"ID")==0)
		{
			log<<result->yek <<" ";
			double value=0.00000;
  			//sscanf(result->yek,"%lf",&value);
  			log<<"0.00000"<<endl;
			
		}
		else{
			log<<result->yek <<" >"<<endl;
		}
		result=result->next;
		count++;
	}
	
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return kcart;
}

// De-allocates list memory when the program terminates.
/*LinkedList::~LinkedList()
{
    Item *p = head;
    Item *q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}
*/

class HashTable
{
	HashTable *next;
	HashTable *HEAD;
	HashTable *prsnt;
	LinkedList vortex;
	int col;
	

private:

    LinkedList *array;

    // Length is the size of the Hash Table array.
    int length;

    // Returns an array location for a given item key.
    int hash( string itemKey );

public:

    // Constructs the empty Hash Table object.
    HashTable( int n );

    // Adds an item to the Hash Table.
    void insertItem( int hash,char *key, char *value );
    Item addItem();

    // Deletes an Item by key from the Hash Table.
   // bool removeItem( string itemKey );

    // Returns an item from the Hash Table by key.
   // Item *getItemByKey( string itemKey );

    void printTable();

    int getLength();
	
	LinkedList* itemGet(int hash,char *key);
   // ~HashTable();
};

HashTable::HashTable( int n )
{
    /*if (tableLength <= 0) tableLength = 13;
    array = new LinkedList[ tableLength ];
    length = tableLength;
	*/
	next=(HashTable*) malloc(sizeof(HashTable));
      HEAD=(HashTable*) malloc(sizeof(HashTable));
      prsnt=(HashTable*) malloc(sizeof(HashTable));
      int i=0;
      for(i=0;i<n;i++){
         HashTable * newTable;
         newTable=(HashTable*) malloc(sizeof(HashTable));
         LinkedList a;
         newTable->vortex=a;
         if(i==0){
            HEAD=newTable;
            prsnt=newTable;
            HEAD->next=NULL;
         }
         else {
            prsnt->next=newTable;
            prsnt=newTable;
            prsnt->next=NULL;
         }
      }
}

// Returns an array location for a given item key.
int HashTable::hash( string itemKey )
{
    int value = 0;
    for ( int i= 0; i < itemKey.length(); i++ )
        value =value + (itemKey[i]*(i+1));
    return (value * itemKey.length() ) % length;
}

// Adds an item to the Hash Table.
void HashTable::insertItem( int hash, char *key, char *value )
{
/*
    int index = hash( newItem -> key );
    array[ index ].insertItem( newItem );
*/
	HashTable *table1;
	table1=(HashTable*) malloc(sizeof(HashTable));
	table1=HEAD;
	int y=1;
	while(table1!=NULL)
	{
	if(y==hash){
		table1->vortex.insertItem(key,value);
		table1->col=hash;
		
	}
	table1=table1->next;
	y++;
	}
}


/*
Item HashTable::addItem()
{
    Item *b=new Item;

    string a2,str_typ;
    cin>>a2;
    cin>>str_typ;
    b->key=a2;
    b->typ=str_typ;
    b->next=NULL;
    return *b;
    delete[] b;
}
*/
/*
//to remove item
bool HashTable::removeItem( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].removeItem( itemKey );
}

Item *HashTable::getItemByKey( string itemKey )
{
    int index = hash( itemKey );
    return array[ index ].getItem( itemKey );
}
*/

// Display the contents of the Hash Table to console window.

LinkedList* HashTable::itemGet(int hash,char *key)
{
		HashTable *table1;
		table1=(HashTable*) malloc(sizeof(HashTable));
		table1=HEAD;
		int y=1;
		while(table1!=NULL)
		{
		if(y==hash){
		table1->vortex.itemGet(key);
		table1->col=hash;
		
	}
	table1=table1->next;
	y++;
	}

}

void HashTable::printTable()
{
    //myfile.open ("example.txt");
   /* cout << "\nHash Table:"<<endl;
    for ( int i = 0; i < length; i++ )
    {
        //myfile.open ("example.txt");
        logg<<"\n" << "Symbol: " << i + 1 << ": ";
        array[i].printList();
        //myfile.close();
    }
    */
    
     int c=1;
      HashTable *result2;
      result2=(HashTable*) malloc(sizeof(HashTable));
      result2=HEAD;
      while(result2!=NULL){
          c++;
          if(result2->vortex.getLength()>0){
              log<<"["<<result2->col<<"] ";
             result2->vortex.printList();
             
             


          }

          result2=result2->next;
      }
}
HashTable a(28);
int h(char *a){
    
    int value = 0;
    for ( int i= 0; i < strlen(a); i++ )
        value =value + (a[i]*(i+1));
    return (value * strlen(a) ) % 29;
   
}

