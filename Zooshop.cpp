#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Logo()
{
        cout << "   å▌▌▌▌▌▌,    ▌▌█▌▄      ▄▌▌█▌▄     ╪▌█▌▄  ▄▌▄    ▒▌     ▒▌█▌█    ▄▌▌▌╬▄   \n" ;
        cout << "   █▀▀▀███▀ ║██▀▀▀▀███  ▓██▀▀▀▀██▌ ┌██▀█▀▀  ██▌   ▀██  ▄██▀▀▀▀███  ███▀▀███ \n" ;
        cout << "      ███▀  ███    ▐██═j██╩    ▀██ ╜███▌    ██▌▌▌▌███  ███     ██  ██▌  ███ \n" ;
        cout << "     ██▀    ██═     ██▒▀██     j██  .█▀███╝ ███▀▀▀▀██  ██▒     ██▌ ██████▀  \n" ;
        cout << "    ╫███    ███▄  ▄███  ███, ▄███  ║╬   ██▌ ██▌   ▀██  ███▄  ▄███  ██       \n" ;
        cout << "    ▀▀▀▀▀▀▀▌  █▀████▀▀   █▀███▀▀▀  ▀▀███▀█  ▀▀▌   ╜▀▀   █▀████▀█   ▀▀█      \n" ;   
}

class ANIMAL/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
{

    string type_of_animal = "Dog";
    string sex = "male dog";
    string name = "<from a shelter>";
    double price = 100;
    int number = 1;

public:

    ANIMAL(string type_of_animal1, string sex1, string name1, double price1, int number1)
    {
        type_of_animal = type_of_animal1, sex = sex1, name = name1, price = price1, number = number1;
        show(type_of_animal, sex, name, price, number);
    };
    ANIMAL()
    {
        show(type_of_animal, sex, name, price, number);
    };
    void show(string type_of_animal, string sex, string name, double price, int number)
    {
        cout << " Type of animal: " << type_of_animal << " sex: " << sex << " name: " << name << " price: " << price << "$ " << " number: " << number << endl;
    };
    void show()
    {
       cout << " Type of animal: " << type_of_animal << " sex: " << sex << " name: " << name << " price: " << price << "$ " << " number: " << number << endl;
    }
};



vector <ANIMAL> arrClass(0);//////////////////////////////////////////////создает векторы классов

int function_show_of_list()//////////////////////////////////////////////функция для вывода списка
{
    int num_list = 1;
    for (int i = 0; i < arrClass.size(); i++)
    {
        cout << num_list++ << ". ";
        arrClass[i].show();
        cout << endl;
    }
    return num_list;
}

void creat_object()///////////////////////////////////////////////////////////////////////////////////////////////////
{
    string type_of_animal; string sex; string name; double price; int number;
    int num_user = 1;
    cout << " Enter data " << endl;
    cout << " type of animal: ";
    cin >> type_of_animal;
    cout << "enter sex: ";
    cin >> sex;
    cout << " name: ";
    cin >> name;
    while (true)//////////////////////////////////////////////////////////цикл проверки правильности ввода цены и количество животного
    {
        cout << " price: ";
        cin >> price;
        if (cin.fail()) { false, cout << "Ivalid enter, please enter correct data: "; cin.clear(); cin.ignore(32767, '\n'); }
        else break;
    };
    while (true)//////////////////////////////////////////////////////////цикл проверки правильности ввода цены и количество животно
    {
        cout << " number: ";
        cin >> number;
        if (cin.fail()) { false, cout << "Ivalid enter, please enter correct data: "; cin.clear(); cin.ignore(32767, '\n'); }
        else break;        
    };

        ANIMAL L1(type_of_animal, sex, name, price, number);
        arrClass.push_back(ANIMAL(L1));
        num_user++;    
}

    void menu()
{
    while (1)
    {
        cout << "=================================================================\n";
        cout << "=============      1. Creat new element             =============\n";
        cout << "=============       2. Edit element                   ===========\n";
        cout << "=============        3. Delete all elements               =======\n";
        cout << "=============         4. Delete elements                    =====\n";
        cout << "=============          5. Exit the program                     ==\n";
        cout << "=================================================================\n"; 
        cout << "=============      6. Save the list in new file     =============\n";
        cout << "=============       7. Open file for read             ===========\n";
        cout << "=================================================================\n";
        string i;
        cin >> i;
        cout << endl;
        if ("1" == i)///////////////////////////////////////////////////////////если 1 то создает элемент
        {
            creat_object();           
            function_show_of_list();///////////////////////////////////////////функция для показа списка       
        }
        else if ("2" == i)///////////////////////////////////////////////////////////если 2 то изменяеет элемент
        {
            cout << "Enter the number of the element in the list to change \n";
            int num_user = 0;
            function_show_of_list();///////////////////////////////////////////функция для показа списка            
            cin >> num_user;
            cout << num_user << ". ";
            arrClass[--num_user].show();
            cout << endl;
            creat_object();
            function_show_of_list();///////////////////////////////////////////функция для показа списка            
        }
        else if ("3" == i)///////////////////////////////////////////////////////////удаляет все элементы
        {
            arrClass.clear();
        }
        else if ("4" == i)///////////////////////////////////////////////////////////удаляет определенный элемент
        {
            cout << "Enter the number of the element in the list to delete \n" ;
            int num_user = 0;
            function_show_of_list();/////////////////////////////////////////////////функция для показа списка            
            int n;
            cin >> n;
            auto iter = arrClass.cbegin();
            arrClass.erase(iter + n - 1);
            cout << endl << "Result: \n";
            num_user = 0;
            function_show_of_list();/////////////////////////////////////////////////функция для показа списка            
        }
        else if ("5" == i)///////////////////////////////////////////////////////////выход из программы
        {
            break;
        }        
        else { cout << "You enter not correct data\n" ; menu(); }
    }
}

int main(int argc, char* argv[])
{
    Logo();
    cout << endl;
    cout << endl;
    menu();
    int num_list;
    num_list = function_show_of_list();
    creat_object();    
}