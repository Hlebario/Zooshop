/*Необходимо создать класс — зоомагазин.В классе должны быть следующие поля : животное(напр.волк, пингвин, собака), пол, имя, цена, количество.
Включить в состав класса необходимый минимум методов, обеспечивающий полноценное функционирование объектов указанного класса :
Конструкторы(по умолчанию, с параметрами, копирования);
Деструктор;
Переопределить возможные для класса операции, продумать порядок их выполнения;
Добавить необходимые методы.
Предоставить возможность вводить данные с клавиатуры или из файла(с помощью конструктора или операцией »).*/
#include <iostream>
#include <string>
#include <vector>
//#include <typeinfo>//////////////////////////////////////////////////////////библиотека для определения типа переменной
using namespace std;
// выдать ошибку при вводе .,\/\"":{}[]11111111111111111111111111111111111
// присобачить конструктор копирования
// создать деструктор для класса и векторов
// сделать возможным ввода данных через файл
void Logo()
{
        cout << "   å▌▌▌▌▌▌,    ▌▌█▌▄      ▄▌▌█▌▄     ╪▌█▌▄  ▄▌▄    ▒▌     ▒▌█▌B    ▄▌▌▌╬▄   " << endl;
        cout << "   █▀▀▀███▀ ║██▀▀▀▀███  ▓██▀▀▀▀██▌ ┌██▀█▀▀  ██▌   ▀██  ▄██▀▀▀▀███  ███▀▀███ " << endl;
        cout << "      ███▀  ███    ▐██═j██╩    ▀██ ╜███▌    ██▌▌▌▌███  ███    └██R ██▌  ███ " << endl;
        cout << "     ██▀    ██═     ██▒▀██     j██  .█▀███╝ ███▀▀▀▀██  ██▒     ██▌ ██████▀  " << endl;
        cout << "    ╫███    ███▄  ▄███  ███, ▄███  ║╬   ██▌ ██▌   ▀██  ███▄  ▄███  ██       " << endl;
        cout << "    ▀▀▀▀▀▀▀▌  █▀████▀▀   █▀███▀▀▀  ▀▀███▀█  ▀▀▌   ╜▀▀   █▀████▀█   ▀▀█      " << endl;   
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
    while (true)//////////////////////////////////////////////////////////цикл проверки правильности ввода цены и количество животного
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
        cout << "1. Creat new element" << endl;
        cout << "2. Edit element" << endl;
        cout << "3. Delete all elements" << endl;
        cout << "4. Delete elements" << endl;
        cout << "5. Exit the program" << endl;
        char i;
        cin >> i;
        cout << endl;
        if ('1' == i)///////////////////////////////////////////////////////////если 1 то создает элемент
        {
            creat_object();
            //arrClass.push_back(ANIMAL() );/////////////////////////////////////добавляет элемент в конец 
            function_show_of_list();///////////////////////////////////////////функция для показа списка       
        }
        if ('2' == i)///////////////////////////////////////////////////////////если 2 то изменяеет элемент
        {
            cout << "Enter the number of the element in the list to change " << endl;
            int num_user = 0;
            function_show_of_list();///////////////////////////////////////////функция для показа списка            
            cin >> num_user;
            cout << num_user << ". ";
            arrClass[--num_user].show();
            cout << endl;
            /*string type_of_animal; string sex; string name; double price; int number;
            cout << "Введите вид: ";
            cin >> type_of_animal;
            cout << "Введите пол: ";
            cin >> sex;
            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите цену: ";
            cin >> price;
            cout << "Введите количество: ";
            cin >> number;
            ANIMAL L1(type_of_animal, sex, name, price, number);*/
            creat_object();
            //arrClass.at(num_user) = L1;            
            function_show_of_list();///////////////////////////////////////////функция для показа списка            
        }
        if ('3' == i)///////////////////////////////////////////////////////////удаляет все элементы
        {
            arrClass.clear();
        }
        if ('4' == i)///////////////////////////////////////////////////////////удаляет определенный элемент
        {
            cout << "Enter the number of the element in the list to delete " << endl;
            int num_user = 0;
            function_show_of_list();///////////////////////////////////////////функция для показа списка            
            int n;
            cin >> n;
            auto iter = arrClass.cbegin();
            arrClass.erase(iter + n - 1);
            cout << endl << "Result: " << endl;
            num_user = 0;
            function_show_of_list();///////////////////////////////////////////функция для показа списка            
        }
        if ('5' == i)///////////////////////////////////////////////////////////выход из программы
        {
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    Logo();
    ////////////////////////////////////////////////останов здеся, вывести диалог-"либо ввод сразу объекта либо вызов меню"
    cout << endl;
    cout << endl;
    cout << " Enter data about animal: type of animal, type of animal, enter sex, name, price, number" << endl;
    cout << " or use menu " << endl;

    //int varINT = 0;
    //char varCHAR = 0;
    //if (varINT == 1 || 2 || 3 || 4)
    //{
        menu();
    //}
    //else
    //{
        int num_list;
        num_list = function_show_of_list();
        creat_object();
    //}
}