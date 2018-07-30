#include <iostream>
#include <cstring>

using namespace std;

class Node
{
public:
    int key;
    Node ** forward;
    Node(int,int);
}
Node::Node(int key, int level) {
    this->key = key;
    //memory to forward
    forward = new Node*[level + 1];
    memset(forward, 0, sizeof(Node) * (level + 1));
};

class skiplist{
    // max level for this skiplist
    int MAXLVL;


    // P is the fraction of the nodes with level
    // i pointers also having level i+1 pointers
    float P;

    // current level of skip list
    int level;

    // pointer to header node
    Node *header;
public:
    skiplist(int, float);
    int randomLevel();            // probability part of the program
    Node* createNode(int, int);   // creating a new node
    void insertElement(int);      // our insert function
    void displayList();           // print function
    void Delete(int n);
};

skiplist::skiplist(int MAXLVL, float P) {
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;

    // create header node and initialize key to -1
    header = new Node(-1, MAXLVL);
}
int skiplist::randomLevel()
{
    float r = (float)rand()/RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand()/RAND_MAX;
    }
    return lvl;
};

// create new node
Node* skiplist::createNode(int key, int level)
{
    Node *n = new Node(key, level);
    return n;
};

void skiplist::insertElement(int key){
    //add insert code
}



void skiplist::displayList(){

// add display code
};

void skiplist::Delete(int n) {
    //add delete code here
	Node* ptr = header;
	Node* update[MAXLVL+1];
	memset(update, 0, sizeof(Node*)*(MAXLVL+1));

	for(int i = level; i >= 0; i--)
	{
	    while(ptr->next != NULL && ptr->next[i]->value < n)
	        ptr = ptr->next[i];
	    update[i] = ptr;
	}

	ptr = ptr->next[0];

	if(ptr != NULL && ptr=>value ==n)
	{
		for(int i = 0; i<= level; i++)
		{
	    	if(update[i]->next[i] != ptr)
			break;
	    	update[i]->next[i] = current->next[i];
		}

		while(level>0 && head->next[level] == 0)
	    		level--;

		cout << "Successfully deleted " << n << endl;

	}

};









int main(){


cout << "hello world" << endl;





};
