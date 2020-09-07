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
    cout << "````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << "``````````````````````````:ohmmmmdyo:```````````````````````````````````````````````````````````````" << endl;
    cout << "```````````````````````-odNho:-- - / ohNd : ````````````````````````````````````````````````````````" << endl;
    cout << "````````````````+mmmmmmmdo||````````:dNs````````````````````````````````````````````````````````````" << endl;
    cout << "````````````````hMs::: - .``+s``/ / `````.dNo```````````````````````````````````````````````````````" << endl;
    cout << "````````````````sMy``````````-NN``````:MN```````````````````````````````````````````````````````````" << endl;
    cout << "````````````````.dNy + :-....``hMs``````oMM+.``````````````````````````.....````````````````````````" << endl;
    cout << "`````````````````. / shdddddd. / Mm````. / dNysdmy / -......-- - ::||+ossyhhdddddddmdho/.```````````" << endl;
    cout << "`````````````````````...--.`hMs- - / smmy:``. / yddddddddddddhhhyyso++ / ::------:+ymms - ``````````" << endl;
    cout << "````````````````````````````/ddddNM + -```````.------ - ....`````````````````````.oNm / .```````````" << endl;
    cout << "``````````````````````````````...dM / ```````````````````````````````````````````:NNms.`````````````" << endl;
    cout << "`````````````````````````````````dM+```````````````````````````ss/.`````````````dMMM/```````````````" << endl;
    cout << "`````````````````````````````````dM+```````````````````````````/yNm + ````````````mMNM+`````````````" << endl;
    cout << "`````````````````````````````````oMd.```````````````````````. - +symMNy``````````+MddM + ```````````" << endl;
    cout << "``````````````````````````````````oNm+.````````````````.. - +ydmds +||yNh.```````:NN-hMo````````````" << endl;
    cout << "```````````````````````````````````-sNm / ```:hhysssssyyhddmds / .``````oNm+.````-NN:`+mmh.`````````" << endl;
    cout << "`````````````````````````````````````oMd```. / ++oossoo + / :-.```````````-ymd + ```hMo```.::```````" << endl;
    cout << "`````````````````````````````````````hMo```````````````````````````````.:.```hMo````````````````````" << endl;
    cout << "```````````````````````````````````.oMd``````````````````````````````````````-dNo```````````````````" << endl;
    cout << "`````````````````````````````````.sdNy.`````````````````````````````````.ody``-MN.``````````````````" << endl;
    cout << "`````````````````````````````````dMmsooo:```````````````````````````````dMNsoooMN.``````````````````" << endl;
    cout << "`````````````````````````````````syyyyyy+```````````````````````````````oyyyyyyyo```````````````````" << endl;
    cout << "````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;

    cout << "    .:|||.     `:/+/:.       `-/+/:.     `::.        -::       :/`      -::::::`    ./-      `:/+/-    `/.      :-   -/      -: " << endl;
    cout << "   /y+||yMh  .hNy+/+sNd-   `yNy+||smm:   oMmN.      /MmM.     sNNh      NN+++++.   .NmM:    `ho//omN-  /M+    `hMd   yM.     hM " << endl;
    cout << "        mM` `Nm`     `mM. `mN.     `dM-  oM:mm`    -M+yM.    :M\\Mo     Nm         dm`dN`         +M+  /M+   -NyMd   yM.     hM`" << endl;
    cout << "   :+osdh-  +M+       +Mo :Ms       /Ms  oM:.Nh   .Ny yM.   `Ny  yM-    Nm        oM- .Mh    .++ohd+   /M+  oN/ Md   yMsooooomM`" << endl;
    cout << "   .::/sNy` oM+       +M+ /Ms       /Ms  oM: /Mo `md  yM.   hN.``.Nm`   Nm       :Ms```oM+   `:::+dm:  /M+`hm.  Md   yM/:::::dM`" << endl;
    cout << "        sM+ .Md`     `mN. `Nm`     `dM-  oM:  sM/hN`  yM.  oMyyyyyyMy   Nm      `mmyyyyydM-       .Mm  /MyNy`   Md   yM.     hM`" << endl;
    cout << "  so/:/sNd`  :mmo/:/sNd-   -dNs/:/omd:   oM:   dMM-   yM. -My      sM/  Nm      hM.     .Nm`:s/::+dN/  /MN/     Md   yM.     hM`" << endl;
    cout << "  `:+++/.      -/+o+/.       ./+o+/.     -+`   `/-    -/  -/`       ||  ||     `+-       -+. -+++/-    .+.      /:   -/`     :/ " << endl;
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

int creat_object()///////////////////////////////////////////////////////////////////////////////////////////////////
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
        if (cin.fail()) { cin.clear(); cin.ignore(32767, '\n'); }
        else return price;
        cout << " number: ";
        cin >> number;
        if (cin.fail()) { cin.clear(); cin.ignore(32767, '\n'); }
        //break;
    }

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

int main()
{
    Logo();
    ////////////////////////////////////////////////останов здеся, вывести диалог-"либо ввод сразу объекта либо вызов меню"
    cout << endl;
    cout << endl;
    cout << " Enter data about animal: type of animal, type of animal, enter sex, name, price, number" << endl;
    cout << " or use menu " << endl;

    int varINT = 0;
    char varCHAR = 0;
    if (varINT == 1 || 2 || 3 || 4)
    {
        menu();
    }
    else
    {
        int num_list;
        num_list = function_show_of_list();
        creat_object();
    }
}