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

//===================================================
//Random Level Generator
//===================================================
int random_level()
{
    static bool first = true;
    if (first)
    {
        srand((unsigned)time(NULL));
        first = false;
    }
    int lvl = (int)(log(frand()) / log(1.-P));
    return (lvl < MAX_LEVEL ? lvl : MAX_LEVEL);
}

//====================================================
//Insert Element in Skip List
//====================================================
void skiplist::insert_element(int &value, string &name)
{
    skipNode *x = header;
    skipNode *update[MAX_LEVEL + 1];
    memset(update, 0, sizeof(skipNode*) * (MAX_LEVEL + 1));
    for (int i = level; i >= 0; i--)
    {
        while (x->forward[i] != NULL && x->forward[i]->value < value)
        {
            x = x->forward[i];
        }
        update[i] = x;
    }
    x = x->forward[0];
    if (x == NULL || x->value != value)
    {
        int lvl = random_level();
        if (lvl > level)
        {
            for (int i = level + 1; i <= lvl; i++)
            {
                update[i] = header;
            }
            level = lvl;
        }
        x = new skipNode(lvl, value, name);
        for (int i = 0; i <= lvl; i++)
        {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
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

bool skiplist::contains(int &n)
{
	skipNode* ptr = header;
	skipNode* nxt = header;
	for(int i = level; i >= 0; i--)
	{
		nxt = ptr->forward[i];
		while(nxt->value < n)
		{
		    ptr = nxt;
		    nxt = nxt->forward[i];
		}
	}
	ptr = ptr->forward[0];
	if(ptr->value ==n)
		return true;
	else
		return false;

}





//===================================================
//Print Menu
//===================================================
void PrintMenu()
{
    cout << endl << "=======================" << endl;
    cout << "Operations on lottery R us" << endl;
    cout << "=======================" << endl << endl;
    cout << "1.Insert Contestant" << endl;
    cout << "2.Insert File of Contestants" << endl;
    cout << "3.Delete contestant by Number" << endl;
    cout << "4.Search for a Winner!" << endl;
    cout << "5.Display Pool of Contestants " << endl;
    cout << "6.Exit " << endl << endl;
}

//-----------------------------------------------------------------------
//Name: GetChoice
//Purpose: Gets the choice and error checks
//----------------------------------------------------------------------
int GetChoice()
{
    char choice;  // read the input into a character for safety
    int intChoice;

    do
    {
        cout << "Choose what to do next: ";
        cin >> choice;
    } while (choice < '0' || choice > '9');

    // convert the character to an integer and return it
    intChoice = choice - '0';
    return (intChoice);
}



//===================================================
//Main
//===================================================

int main()
{
    skiplist sl;
    int choice, num;
    string name = " ";
    string filename = " ";

    do
    {
        PrintMenu();
        choice = GetChoice();

        switch(choice)
        {
            case 1:{
                cout << "Enter the number and name to be inserted: ";
                cin >> num;
                cin >> name;
                sl.insert_element(num, name);
                if(sl.contains(num))
                    cout << "contestant has been entered to the pool!" << endl;
                break;}
            case 2:{
                cout << "Enter the file of contestants you wish to read from" << endl;
                cin >> filename;
                ifstream din(filename.c_str());
                if(!din)
                {
                    cerr << "Could not open " << filename << endl;
                }
                while(din >> num >> name)
                {
                    sl.insert_element(num, name);
                }
                break;}
            case 3:{
                cout << "Enter the number corresponding to the name you wish to remove from the pool: ";
                cin >> num;
                if(!sl.contains(num))
                {
                    cout << "Name has not been found not found" << endl;
                    break;
                }
                sl.delete_element(num);
                cout << "Contestant has been deleted" << endl;
                break;}
            case 4:{
                cout << "Search for the luck winners number: ";
                num = rand() % 999999;
                cout << num << endl;
                cin >> num;
                if(sl.contains(num))
                    cout << "With the number " << num << ", " << Winner_name << " has won!!" <<  endl;
                else
                    cout << "Unfortunately no winner has been found." << endl;
                    break;}
            case 5:{
                cout << "The lottery pool, with selected numbers/names is: ";
                sl.display();
                break;}
            case 6:{
                cout << endl << "===================" << endl;
                cout << "    Thank you for playing everyone!    " << endl;
                cout << "===================" << endl;
                break;}
            default:
                cout << "Wrong Choice" << endl;
        }
    }while(choice != 6);


    return 0;
}
