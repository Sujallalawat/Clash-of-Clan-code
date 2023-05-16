#include<iostream>
#include<vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

//important global variables
int elixir=20000;
int gold=20000;
int gem=20;
int dark_elixir=3000;

//classes defining starts here
class Troop {
public:
    static int count;
    int id;
    string name;
    int level;
    int hitpoint;
    int damagepersecond;
    string target;
    int housingspace;
    int upgradecost;
    int max_level=10;
    void seedetails()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"Housing Space: "<<housingspace<<endl;
        cout<<"Hitpoint: "<<hitpoint<<endl;
        cout<<"Damage per Second: "<<damagepersecond<<endl;
        cout<<"Target: "<<target<<endl;
        cout<<"Uprade Cost to level "<<level+1<<": "<<upgradecost<<endl;
    }
};

class Barbarian : public Troop {
public:
    Barbarian() {
        id=++count;
        name = "barbarian";
        level = 1;
        damagepersecond = 8;
        hitpoint = 45;
        target = "ground";
        housingspace=1;
        upgradecost=200;
    }
    void upgrade() {
        if(elixir-upgradecost>0 &&level<max_level){
        level = level + 1;
        hitpoint = hitpoint + 10;
        damagepersecond = damagepersecond + 5;
        upgradecost=upgradecost+150;
        elixir=elixir-upgradecost;
        cout<<name<<" upgraded to level "<<level<<endl;
        }
        else
        cout<<"insufficient elixir"<<endl;
    }
};

class Archer : public Troop {
public:
    Archer() {
        id=++count;
        name = "archer";
        level = 1;
        damagepersecond = 7;
        hitpoint = 20;
        target = "air&ground";
        housingspace=1;
        upgradecost=300;
    }
    void upgrade() {
        if(elixir-upgradecost>0 &&level<max_level){
        level = level + 1;
        hitpoint = hitpoint + 5;
        damagepersecond = damagepersecond + 3;
        upgradecost=upgradecost+150;
        elixir=elixir-upgradecost;
        cout<<name<<" upgraded to level "<<level<<endl;
        }
        else
        cout<<"insufficient elixir"<<endl;
    }
};

class Wizard : public Troop {
public:
    Wizard() {
        id=++count;
        name = "wizard";
        level = 1;
        damagepersecond = 50;
        hitpoint = 75;
        target = "air&ground";
        housingspace=4;
        upgradecost=700;
    }
    void upgrade() {
        if(elixir-upgradecost>0 &&level<max_level){
        level = level + 1;
        hitpoint = hitpoint + 30;
        damagepersecond = damagepersecond + 20;
        upgradecost=upgradecost+500;
        elixir=elixir-upgradecost;
        cout<<name<<" upgraded to level "<<level<<endl;
        }
        else
        cout<<"insufficient elixir"<<endl;
    }
};

class Defense {
public:
    static int count;
    int id;
    string name;
    int level;
    int hitpoint;
    int damagepersecond;
    string target;
    int upgradecost;
    int max_level=10;
    void seedetails()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"Hitpoint: "<<hitpoint<<endl;
        cout<<"Damage per Second: "<<damagepersecond<<endl;
        cout<<"Target: "<<target<<endl;
        cout<<"Upgrade Cost to level "<<level<<": "<<upgradecost<<endl;
    }
};

class Cannon : public Defense {
public:
    Cannon() {
        id=++count;
        name = "cannon";
        level = 1;
        damagepersecond = 9;
        hitpoint = 420;
        target = "ground";
        upgradecost=250;
    }
    void upgrade() {
        if(gold-upgradecost>0 &&level<max_level){
        level = level + 1;
        hitpoint = hitpoint + 50;
        damagepersecond = damagepersecond + 4;
        upgradecost=upgradecost+150;
        gold-=upgradecost;
        cout<<name<<" upgraded to level "<<level<<endl;
        }
        else
        cout<<"insufficient elixir"<<endl;
    }
};

class Archertower : public Defense {
public:
    Archertower() {
        id=++count;
        name = "archer tower";
        level = 1;
        damagepersecond = 11;
        hitpoint = 380;
        target = "air&ground";
        upgradecost=300;
    }
    void upgrade() {
        if(gold-upgradecost>0&&level<max_level){
        level = level + 1;
        hitpoint = hitpoint + 40;
        damagepersecond = damagepersecond + 4;
        upgradecost=upgradecost+200;
        gold-=upgradecost;
        cout<<name<<" upgraded to level "<<level<<endl;
        }
        else
        cout<<"insufficient elixir"<<endl;
    }
};
class Barbarian_King: public Defense,public Troop {
public:
    string name;
    int level;
    int hitpoint;
    int damagepersecond;
    string target;
    int upgradecost;
    int max_level=20;
    Barbarian_King()
    {
        name = "Barbarian King";
        level = 1;
        damagepersecond = 110;
        hitpoint = 3800;
        target = "ground";
        upgradecost=350;

    }
    void seedetails()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Level: "<<level<<endl;
        cout<<"Hitpoint: "<<hitpoint<<endl;
        cout<<"Damage per Second: "<<damagepersecond<<endl;
        cout<<"Target: "<<target<<endl;
        cout<<"Uprade Cost to level "<<level+1<<": "<<upgradecost<<endl;
    }
    void upgrade() 
    {
        if(dark_elixir-upgradecost>0&&level<max_level){
        level = level + 1;
        hitpoint = hitpoint + 55;
        damagepersecond = damagepersecond + 40;
        upgradecost=upgradecost+300;
        dark_elixir-=upgradecost;
        cout<<name<<" upgraded to level "<<level<<endl;
        }
        else
        cout<<"insufficient dark elixir"<<endl;
    }
};
class War {
public:
    vector<Troop*> troops;
    vector<Defense*> defenses;
    int t_damage = 0;
    int t_hitpoint = 0;
    int d_damage = 0;
    int d_hitpoint = 0;
    int hero_barb_troop=0;
    int hero_barb_def=0;
    int number_troops;
    int max_troops;
    int distruction=0;
    int b=0;
    int a=0;
    int w=0;
    int c=0;
    int at=0;
    int t_dam;
    int d_dam;
    int t_hit;
    int d_hit;
    War(int max_troops)
    {
        this->max_troops=max_troops;
        cout<<"War has been declared"<<endl;
    }
    void selectbarbarian(Barbarian* barbarian) {
        if(max_troops-barbarian->housingspace>=0){
            troops.push_back(barbarian);
            max_troops=max_troops-barbarian->housingspace;
            b++;
        }
        
    }
    
    void selectarcher(Archer* archer) {
        if(max_troops-archer->housingspace>=0){
            max_troops=max_troops-archer->housingspace;
            troops.push_back(archer);
            
        }
        
    }
    void selectwizard(Wizard* wizard) {
        if(max_troops-wizard->housingspace>=0){
            max_troops=max_troops-wizard->housingspace;
            troops.push_back(wizard);
            
        }
        
    }
    void troop_select_Barbarian_King(Barbarian_King* Barbarian_King)
    {
        if(hero_barb_troop==0)
        troops.push_back(Barbarian_King);
        else
        cout<<"Only 1 hero will be appointed"<<endl;
        hero_barb_troop++;
    }
    void defense_select_Barbarian_King(Barbarian_King* Barbarian_King)
    {
        if(hero_barb_def==0)
        defenses.push_back(Barbarian_King);
        else
        cout<<"Only 1 hero will be appointed"<<endl;
        hero_barb_def++;
    }
    void selectcannon(Cannon* cannon) {
        defenses.push_back(cannon);
        distruction++;
    }
    void selectarchertower(Archertower* archertower) {
        defenses.push_back(archertower);
        distruction++;
    }
    void calculations() {
        for (int i = 0; i < troops.size(); i++) {
            t_damage = t_damage + troops[i]->damagepersecond;
           
        t_hitpoint = t_hitpoint + troops[i]->hitpoint;
    }
    for (int i = 0; i < defenses.size(); i++) {
        d_damage = d_damage + defenses[i]->damagepersecond;
        d_hitpoint = d_hitpoint + defenses[i]->hitpoint;
    }
     t_hit=t_hitpoint;
     d_hit=d_hitpoint;
    }
    void battle(){
    
    while(d_hitpoint>0 && t_hitpoint>0)
        {
            
            t_hitpoint=t_hitpoint-d_damage;
            if(t_hitpoint<=0 && d_hitpoint>0)
            {
                cout<<"defense wins! "<<endl;
                break;
            }
            d_hitpoint=d_hitpoint-t_damage;
            if(d_hitpoint<=0 && t_hitpoint>0)
            {
                cout<<"attack wins! "<<endl;
                break;
            }
            
        }

    }
    void summary()
{
    int troopsCount = troops.size();
    int defensesCount = defenses.size();
    int i = 0, j = 0;

    while (i < troopsCount && j < defensesCount)
    {
        Troop* troop = troops[i];
        Defense* defense = defenses[j];

        defense->hitpoint -= troop->damagepersecond;
        troop->hitpoint -= defense->damagepersecond;

        if (defense->hitpoint <= 0)
        {
            cout << "Level " << defense->level << " " << defense->name << " is defeated by " << troop->name << endl;
            j++;
        }
        else if (troop->hitpoint <= 0)
        {
            cout << troop->name << " " << troop->id << " is defeated by " << defense->name << endl;
            i++;
        }
    }

    while (i < troopsCount)
    {
        Troop* troop = troops[i];
        cout << troop->name << " " << troop->id << " is defeated by the remaining defenses" << endl;
        i++;
    }

    while (j < defensesCount)
    {
        Defense* defense = defenses[j];
        cout << "Level " << defense->level << " " << defense->name << " is not defeated by any troops" << endl;
        j++;
    }
}

};
class obstacles
{
    public:
    int cost;
    static int count;
    void remove()
    {
        if(elixir-cost>0)
        {
            if(count%5==0)
            {
               int r=3;
            gem+=r;
            cout<<r<<" gems recieved"<<endl; 
            }
            else if(count%5==1)
            {
               int r=0;
            gem+=r;
            cout<<r<<" gems recieved"<<endl; 
            }
            else if(count%5==2)
            {
               int r=1;
            gem+=r;
            cout<<r<<" gems recieved"<<endl; 
            }
            else if(count%5==3)
            {
               int r=0;
            gem+=r;
            cout<<r<<" gems recieved"<<endl; 
            }
            else
            {
               int r=5;
            gem+=r;
            cout<<r<<" gems recieved"<<endl; 
            }
            
            elixir-=cost;
            count++;
        }
        else
        cout<<"insufficient elixir"<<endl;
    }

};
class gembox:public obstacles
{
    public:
    gembox()
    {
        cout<<"gembox implanted in your village"<<endl;
        cost=200;
        cout<<cost<<" elixir will be need"<<endl;
    }
    void remove_gembox()
    {
        if(elixir-cost>0)
        {
            gem+=25;
            elixir-=cost;
            cout<<"25 gems obtained"<<endl;
        }
        else
        cout<<"insufficient elixir"<<endl;
    }

};
int obstacles::count=0;
int Troop::count=0;
int Defense::count=0;

int main() {

    cout<<"Enter the housing space for war "<<endl;
            int space;
            cin>>space;
            War game(space);
    Barbarian* b1 = new Barbarian();
    Archer* a1 = new Archer();
    Wizard* w1 = new Wizard();
    Cannon* c1 = new Cannon();
    Archertower* at1 = new Archertower();
    Barbarian_King* h1= new Barbarian_King();
    Barbarian_King* h2= new Barbarian_King();
    

    

    int t=true;
    while (t) 
    {
        // Display game status and options to the user
        cout << "Elixir: " << elixir << endl;
        cout << "Gold: " << gold << endl;
        cout << "Dark Elixir: " << dark_elixir << endl;
        cout << "Housing Space Remaining: "<< game.max_troops<<endl;
        cout << "Gems: " << gem << endl;
        cout << "1. Train troops" << endl;
        cout << "2. Upgrade troops" << endl;
        cout << "3. View troops" << endl;
        cout << "4. Build defenses" << endl;
        cout << "5. Upgrade defenses" << endl;
        cout << "6. View defenses" << endl;
        cout << "7. War Battle Results:  "<<endl;
        cout << "8. War Battle summary: "<<endl;
        cout << "9. Exit game" << endl;

        // Get user input and execute corresponding action
        int choice;
        cout<<"Please select the numbers to start the game "<<endl;
        cin >> choice;
        switch (choice)
        {
        
            case 1:
            {
            cout << "Which troop do you want to train?" << endl;
                cout << "1. Barbarian" << endl;
                cout << "2. Archer" << endl;
                cout << "3. Wizard" << endl;
                cout<<"4. Hero Barbarian King "<<endl;
                int troop_choice;
                cout<<"Enter the number to select the type of troop "<<endl;
                cin >> troop_choice;
                switch (troop_choice)
                {
                    case 1:
                    {
                        
                        int c_b;
                        cout<<"Enter number for barbarian "<<endl;
                        cin>> c_b;
                        for(int i=0;i<c_b;i++)
                        game.selectbarbarian(b1);
                        break;
                    }
                    case 2:
                    {
                        
                        int c_a;
                        cout<<"Enter number for archer "<<endl;
                        cin>> c_a;
                        for(int i=0;i<c_a;i++)
                        game.selectarcher(a1);
                        break;
                    }
                    case 3:
                    {
                        
                        int c_w;
                        cout<<"Enter number for wizard "<<endl;
                        cin>> c_w;
                        for(int i=0;i<c_w;i++)
                        game.selectwizard(w1);
                        break;
                    }
                    case 4:
                    {
                        game.troop_select_Barbarian_King(h1);
                        break;
                    }
                    default:
                    {
                        cout<<"invalid"<<endl;
                        break;
                    }
                }
                break;
            }    
            case 2:
            {
                cout << "Which troop do you want to upgrade?" << endl;
                cout << "1. Barbarian" << endl;
                cout << "2. Archer" << endl;
                cout << "3. Wizard" << endl;
                cout<< "4. Barbarian King"<<endl;
                int troop_up;
                cout<<"Enter the number to select the type of troop "<<endl;
                cin >> troop_up;
                switch (troop_up)
                {
                    case 1:
                    {
                        
                        int c_b;
                        cout<<"Enter number for barbarian "<<endl;
                        cin>> c_b;
                        for(int i=0;i<c_b;i++)
                        b1->upgrade();
                        break;
                    }
                    case 2:
                    {
                        
                        int c_a;
                        cout<<"Enter number for archer "<<endl;
                        cin>> c_a;
                        for(int i=0;i<c_a;i++)
                        a1->upgrade();
                        break;
                    }
                    case 3:
                    {
                        
                        int c_w;
                        cout<<"Enter number for wizard "<<endl;
                        cin>> c_w;
                        for(int i=0;i<c_w;i++)
                        w1->upgrade();
                        break;
                    }
                    case 4:
                    {
                        int c_h;
                        cout<<"Enter number for hero "<<endl;
                        cin>> c_h;
                        for(int i=0;i<c_h;i++)
                        h1->upgrade();
                        break;
                    }
                    default:
                    {
                        cout<<"invalid"<<endl;
                        break;
                    }
                    break;
                }
            }
            case 3:
            {
                // int tracker=0;
                // for(int i=0;i<game.troops.size();i++)
                // {
                //     if(game.troops[i]->name==game.troops[i+1]->name)
                //     {
                //         tracker++;
                //     }
                //     else
                //     {

                //         cout<<"("<<(game.troops[i])->name<<" level: "<<(game.troops[i])->level<<")"<<"x"<<tracker+1<<endl;
                //         tracker=0;
                //     }
                //     if(tracker==(game.troops.size()-1))
                //     {
                //         cout<<"("<<(game.troops[i])->name<<" level: "<<(game.troops[i])->level<<")"<<"x"<<tracker+1<<endl;
                //     }
                //     if(i==(game.troops.size()-1))
                //     cout<<"("<<(game.troops[i])->name<<" level: "<<(game.troops[i])->level<<")"<<"x"<<tracker+1<<endl;
                // }
                for(int i=0;i<game.troops.size();i++)
                {
                    cout<<(game.troops[i])->name<<" "<<(game.troops[i])->level<<endl;
                }
                break;
            }
            case 4:
            {
                cout << "Which defenses do you want to put to your village?" << endl;
                cout << "1. Cannon" << endl;
                cout << "2. Archer Tower" << endl;
                cout<< "3. Hero Barbarian king "<<endl;
                
                int troop_choice;
                cout<<"Enter the number to select the type of defense "<<endl;
                cin >> troop_choice;
                switch (troop_choice)
                {
                    case 1:
                    {
                        
                        int c_b;
                        cout<<"Enter how much number for cannon "<<endl;
                        cin>> c_b;
                        for(int i=0;i<c_b;i++)
                        game.selectcannon(c1);
                        break;
                    }
                    case 2:
                    {
                        
                        int c_a;
                        cout<<"Enter how much number for archer tower"<<endl;
                        cin>> c_a;
                        for(int i=0;i<c_a;i++)
                        game.selectarchertower(at1);
                        break;
                    }
                    case 4:
                    {
                        game.defense_select_Barbarian_King(h2);
                        break;
                    }
                    default:
                    {
                        cout<<"invalid"<<endl;
                        break;
                    }
                }
                break;
            }
            case 5:
            {
                cout << "Which defense do you want to upgrade?" << endl;
                cout << "1. Cannon" << endl;
                cout << "2. Archer Tower" << endl;
                cout<< "3. Barbarian King"<< endl;
                
                int troop_up;
                cout<<"Enter the number to select the type of defense to upgrade "<<endl;
                cin >> troop_up;
                switch (troop_up)
                {
                    case 1:
                    {
                        
                        int c_b;
                        cout<<"Enter number for cannon "<<endl;
                        cin>> c_b;
                        for(int i=0;i<c_b;i++)
                        c1->upgrade();
                        break;
                    }
                    case 2:
                    {
                        
                        int c_a;
                        cout<<"Enter number for archer tower "<<endl;
                        cin>> c_a;
                        for(int i=0;i<c_a;i++)
                        at1->upgrade();
                        break;
                    }
                    case 3:
                    {
                        int c_h;
                        cout<<"Enter number for hero "<<endl;
                        cin>> c_h;
                        for(int i=0;i<c_h;i++)
                        h2->upgrade();
                        break;
                    }
                    default:
                    {
                        cout<<"invalid"<<endl;
                        break;
                    }
                    break;
                }
            }
            case 6:
            {
                for(int i=0;i<game.defenses.size();i++)
                {
                    cout<<(game.defenses[i])->name<<" "<<(game.defenses[i])->level<<endl;
                }
                break;
            }              
            case 7:
            {
                game.calculations();
                game.battle();
                break;
            }
            case 8:
            {
                game.summary();
                break;
            }
            case 9:
            {
                t=false;
                cout<<"Successfully Exited!"<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid"<<endl;
                break;
            }

        }
        

    }
        

// War game(40);
// Barbarian* b1 = new Barbarian();
// b1->upgrade();
// b1->upgrade();
// b1->upgrade();
// b1->upgrade();
// for(int i=0;i<10;i++)
// game.selectbarbarian(b1);



// Archer* a1 = new Archer();
// Wizard* w1 = new Wizard();
// Cannon* c1 = new Cannon();
// a1->upgrade();
// for(int i=0;i<9;i++)
// game.selectarcher(a1);



// w1->upgrade();
// for(int i=0;i<8;i++)
// game.selectwizard(w1);


// c1->upgrade();
// for(int i=0;i<2;i++)
// game.selectcannon(c1);

// Archertower* at1 = new Archertower();
// at1->upgrade();
// for(int i=0;i<4;i++)
// game.selectarchertower(at1);

// cout<<"elixir left is "<<elixir<<endl;
// game.calculations();
// game.battle();
// // game.summary();

// obstacles trees;
// obstacles t1;
// t1.cost=100;
// trees.cost=100;
// trees.remove();
// t1.remove();

// gembox g1;
// g1.remove_gembox();
// cout<<gem<<endl;

// b1->seedetails();
// b1->upgrade();
// b1->seedetails();
// for(int i=0;i<game.troops.size();i++)
// (game.troops[i])->seedetails();
// for(int i=0;i<game.defenses.size();i++)
// (game.defenses[i])->seedetails();

return 0;
}