﻿#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
        cout << " Type of animal: "<<type_of_animal<<" sex: "<<sex<<" name: "<<name<<" price: "<<price<<"$ "<<" number: "<<number<<endl;
    };
    void show()
    {
       cout <<" Type of animal: "<<type_of_animal<<" sex: "<<sex<<" name: "<<name<<" price: "<<price<<"$ "<<" number: "<<number<<endl;
    }

    ANIMAL& operator= (const ANIMAL& ghost)///////////////////////////////Перегрузка оператора присваивания
    {
        type_of_animal = ghost.type_of_animal;
        sex = ghost.sex;
        name = ghost.name;
        sex = ghost.sex;
        price = ghost.price;
        number = ghost.number;

        return *this;
    }

    friend void save_in_file();
    friend void quicksort();
};



vector <ANIMAL> arrClass(0);//////////////////////////////////////////////создает векторы классов
int show_of_list();
void quicksort()
{
    int first = 0, last = arrClass.size() - 1;     
        int mid, count;
        int f = first, l = last;
        mid = arrClass[(f + l) / 2].price;
        do
        {
            while (arrClass[f].price < mid) f++;
            while (arrClass[l].price > mid) l--;
            if (f <= l)
            {
                ANIMAL ghost = arrClass[f];//////////////////////////////////////////////////////////////////////////////////////////////////////
                arrClass[f] = arrClass[l];
                arrClass[l] = ghost;
                f++;
                l--;
            }
        } while (f < l);
        if (first < l) quicksort();
        if (f < last) quicksort();
        else
        {
            show_of_list();            
        }
}

void open_file()
{
    cout << "Enter address to file: ";
    string address;
    cin >> address;
    ifstream _file(address);
    if (!_file)
    {
        cerr << "file: ", address;
        cerr << "not be opened, check address or the file does not exist!" << endl;
        exit;
    }
    int num_user = 1;
    while (_file)//////////////////////////////////////////////////////////алгоритм инициализации переменных: находит пробели и его позицию
        /////////////////////////////////////////////инициализирует нужную переменную до позиции пробела, удаляет символы до пробела и т.д.
    {
        //C:\\Users\\marek\\Desktop\\filesssssi.txt        
        string line, type_of_animal, sex, name, _price, _number;
        getline(_file, line);
        int pos;
        pos = line.find(".");
        line.erase(0, 2 + pos);
        pos = line.find(" ");
        type_of_animal.replace(0, 0, line, 0, pos);
        line.erase(0, ++pos);

        pos = line.find(" ");
        sex.replace(0, 0, line, 0, pos);
        line.erase(0, ++pos);

        pos = line.find(" ");
        name.replace(0, 0, line, 0, pos);
        line.erase(0, ++pos);


        pos = line.find("$ ");
        _price.replace(0, 0, line, 0, pos++);
        line.erase(0, ++pos);

        pos = line.find(" ");
        _number.replace(0, 0, line, 0, pos);
        line.erase(0, pos);

        double price = atoi(_price.c_str());
        int number = atoi(_number.c_str());
        
        if (number != 0)
        {
            cout << num_user << ". ";
            ANIMAL L1(type_of_animal, sex, name, price, number);
            arrClass.push_back(ANIMAL(L1));
            cout << endl;
            num_user++;
        }

        line = type_of_animal = sex = name = _price = _number = NAN;
    }    
    _file.close();
}

void save_in_file()/////////////////////////////////////////////////////функция для сохранения в файл
{
    string adress;
    cout << "enter the address of the saved file\n";
    cin >> adress;
    ofstream file(adress);
    if (!file)
    {
        cerr << "failed save the file\n";
        exit(1);
    }    
    int num_list = 1;
    for (int i = 0; i < arrClass.size(); i++)
    {
        file << num_list++ << ". ";
        file << arrClass[i].type_of_animal;
        file << " ";
        file << arrClass[i].sex;
        file << " ";
        file << arrClass[i].name;
        file << " ";
        file << arrClass[i].price;
        file << "$ ";
        file << arrClass[i].number;
        file << endl;
    }
    file.close();
    cout << "The File was save.\n";
}

int show_of_list()//////////////////////////////////////////////функция для вывода списка
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
        cout << "=============         4. Delete element                     =====\n";
        cout << "=============          5. Exit the program                     ==\n";
        cout << "=================================================================\n";
        cout << "=============      6. Save the list in new file     =============\n";
        cout << "=============       7. Open file for read             ===========\n";
        cout << "=================================================================\n";
        cout << "=============      8. Sort animals by ascending cost ============\n";
        cout << "=============       9. Sort animals by descending cost ==========\n";
        cout << "=============        10. Sort animals by ascending numbers ======\n";
        cout << "=============         11. Sort animals by descending numbers ====\n";
        cout << "=================================================================\n";

        string i;
        cin >> i;
        cout << endl;
        if ("1" == i)///////////////////////////////////////////////////////////если 1 то создает элемент
        {
            creat_object();
            show_of_list();///////////////////////////////////////////функция для показа списка       
        }
        else if ("2" == i)///////////////////////////////////////////////////////////если 2 то изменяеет элемент
        {
            cout << "Enter the number of the element in the list to change \n";
            int num_user = 0;
            show_of_list();///////////////////////////////////////////функция для показа списка            
            cin >> num_user;
            cout << num_user << ". ";
            arrClass[--num_user].show();
            cout << endl;
            creat_object();
            show_of_list();///////////////////////////////////////////функция для показа списка            
        }
        else if ("3" == i)///////////////////////////////////////////////////////////удаляет все элементы
        {
            arrClass.clear();
        }
        else if ("4" == i)///////////////////////////////////////////////////////////удаляет определенный элемент
        {
            cout << "Enter the number of the element in the list to delete \n";
            int num_user = 0;
            show_of_list();/////////////////////////////////////////////////функция для показа списка            
            int n;
            cin >> n;
            auto iter = arrClass.cbegin();
            arrClass.erase(iter + n - 1);
            cout << endl << "Result: \n";
            num_user = 0;
            show_of_list();/////////////////////////////////////////////////функция для показа списка            
        }
        else if ("5" == i)///////////////////////////////////////////////////////////выход из программы
        {
            break;
        }
        else if ("6" == i)////////////////////////////////////////////////////////////Сохранить список в в новый файл
        {
            //C:\\Users\\marek\\Desktop\\filesssssi.txt            
            save_in_file();
        }
        else if ("7" == i)///////////////////////////////////////////////////////////Открыть файд для чтения
        {
            open_file();
        }
        else if ("8" == i)///////////////////////////////////////////////////////////сортировать по стоймости возрастания
        {

            quicksort();
        }
        else if ("9" == i)///////////////////////////////////////////////////////////сортировать по стоймости убывания
        {

        }
        else if ("10" == i)///////////////////////////////////////////////////////////сортировать по количеству возрастания
        {

        }
        else if ("11" == i)///////////////////////////////////////////////////////////сортировать по количеству убывания
        {

        }

        else { cout << "You enter not correct data\n"; menu(); }

    }
}

int main(int argc, char* argv[])
{
    Logo();
    cout << endl;
    cout << endl;
    menu();
    int num_list;
    num_list = show_of_list();
    creat_object();    
}