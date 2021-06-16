//
//  main.cpp
//  PoliceBase
//
//  Created by Анна Горячева on 14.06.2021.
//

#include <iostream>
#include<string>
#include<map>
#include<list>
#include<forward_list>
//#include<Windows.h>
using std::cout;
using std::cin;
using std::endl;
#define delimeter "\n---------------------------------------------------\n"
int menu(std::map<std::string, std::forward_list<std::string>>& base);
void print_base(const std::map<std::string,std::forward_list<std::string>>& base);
void add_crime(std::map<std::string,std::forward_list<std::string>>& base);
void crimes_of(std::string id,const std::map<std::string,std::forward_list<std::string>>& base);
int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "");
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
    std::map<std::string,std::forward_list<std::string>> base =
    {
        std::pair<std::string, std::forward_list<std::string>>("м123кр777",{"Проезд на красный", "Превышение скорости"}),
        std::pair<std::string, std::forward_list<std::string>>("м124кр777",{"Парковка в неположенном месте"}),
        std::pair<std::string, std::forward_list<std::string>>("м555кр777",{"Превышение скорости"}),
        std::pair<std::string, std::forward_list<std::string>>("а555кр178",{"Послал гаишника", "Проезд на красный"})
    };
//    print_base(base);
//    add_crime(base);
//    print_base(base);
//    std::string id;
//    cout << "Введите номер автомобиля: ";cin>>id;
   // crimes_of(id,base);
   // print_base(base);
    menu(base);
    return 0;
}
int menu(std::map<std::string, std::forward_list<std::string>>& base)
{
    cout << "1.Вывод всей базы; " << endl;
    cout << "2.Вывод информации по номеру; " << endl;
    cout << "3.Вывод по диапазону номеров; " << endl;
    cout << "4.Добавление нарушения; " << endl;
    cout << "5. Выход; " << endl;
    int choice;
    cin >> choice;
    std::string id;
    switch (choice) {
        case 1:print_base(base); break;
        case 2:
            cout << "Введите номер машины: "; cin >> id;
            crimes_of(id, base);
            break;
        case 4:add_crime(base); break;
        default: cout << "Недопустимое действие" << endl;
    }
    menu(base);
    return choice;
}
void print_base(const std::map<std::string,std::forward_list<std::string>>& base)
{
    for(std::map<std::string,std::forward_list<std::string>>::const_iterator it=base.begin();it!=base.end();it++)
    {
        cout << it->first << "\n";
        for(std::forward_list<std::string>::const_iterator l_it=it->second.begin(); l_it!=it->second.end();l_it++)
        {
            cout << *l_it << ", ";
        }
        cout << endl;
        cout << delimeter;
    }
}
void add_crime(std::map<std::string,std::forward_list<std::string>>& base)
{
    std::string id, crime;
    cout<< "Введите номер автомобиля: "; cin >> id;
    cout<< "Введите нарушение: ";
    cin.ignore();
    getline(cin,crime);
    base[id].push_front(crime);
}
void crimes_of(std::string id,const std::map<std::string,std::forward_list<std::string>>& base)
{
    std::map<std::string,std::forward_list<std::string>>::const_iterator criminal = base.find(id);
    if(base.find(id)!=base.end())
    {
        cout << "Список нарушений: "<< id << "\n";
        for(std::forward_list<std::string>::const_iterator it=criminal->second.begin();it!=criminal->second.end();it++)
        {
            cout << *it << endl;
        }
    }
}
