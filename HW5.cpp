#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#define MAX_LEVEL 6
const float P = 0.5;
using namespace std;
string Winner_name;

//===================================================
//Skip Node Declaration
//===================================================
class skipNode
{
public:
    int value;
    string name;
    skipNode **forward;
    skipNode(int level, int &value, string &name);
    ~skipNode();
};
//===================================================
//Skip List Declaration
//===================================================
class skiplist
{
public:
    skipNode *header;
    int value;
    int level;
    string name;
    skiplist();
    ~skiplist();

    void display();
    bool contains(int &);
    void insert_element(int &value, string &name);
    void delete_element(int &);
};

//==================================================
//Skip Node Constructor & Destructor
//==================================================
skipNode::skipNode(int level, int &value, string &name)
{
    forward = new skipNode * [level + 1];
    memset(forward, 0, sizeof(skipNode*) * (level + 1));
    this->value = value;
    this->name  = name;
}

skipNode::~skipNode()
{
    delete [] forward;
}

//==================================================
//SkipList Constructor & destructor
//==================================================
skiplist::skiplist()
{
    header = new skipNode(MAX_LEVEL, value, name);
    level = 0;
}
skiplist::~skiplist()
{
    delete header;
}


//==================================================
//Random Value Generator
//==================================================
float frand()
{
    return (float) rand() / RAND_MAX;
}










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
