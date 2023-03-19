#include <iostream>
using namespace std;
class Hero
{
public:
    char score;
    int level;

    char getscore()
    {
        return score;
    }
    int getlevel()
    {
        return level;
    }

    void setscore(char new_score)
    {
        score = new_score;
    }
    void setlevel(int new_level)
    {
        level = new_level;
    }
};
int main()
{

    // * static allocation of object->>
    Hero ramesh;
    ramesh.setscore('A');
    ramesh.setlevel(15);
    cout << "score is->>" << ramesh.getscore() << endl;
    cout << "level is->>" << ramesh.getlevel() << endl;

    // * Dyanamic allocation of object
    Hero *Dhiraj = new Hero;
    Dhiraj->setlevel(50);
    Dhiraj->setscore('H');

    // *fetch the value in dyanamically allocation

    cout << "score is->>" << (*Dhiraj).getscore() << endl;
    cout << "level is->>" << (*Dhiraj).getlevel() << endl;

    // *fetch the value->> 2nd method

    cout << "score is->>" << Dhiraj->getscore() << endl;
    cout << "level is->>" << Dhiraj->getlevel() << endl;
    return 0;
}