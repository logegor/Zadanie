// Zadanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"





int main()
{
    setlocale(LC_ALL, "Russian");
    const int d = 17;
    unsigned int  sam = 0, res = 0;

    struct Row
    {
        string strdt;
        unsigned int intdt[9] = { 0 }; 
    };
    Row one, two;
  
    ifstream file("E:\data.txt");
    ofstream filebin("E:\databin.txt", ios::binary | ios::out);
    ifstream filebinopen("E:\databin.txt", ios::binary | ios::in);
        
    if (!file) cout << "При открытии файла возникла ошибка!" << '\n';
    else
    {

        cout << "Файл был открыт!" << '\n'<<'\n';
        
       
            for (int i=0 ; i < 9; i++)
            {
                file >> one.strdt;
                one.intdt[i] = (unsigned int)atoll(one.strdt.c_str());
                filebin.write(reinterpret_cast<char*>(&one.intdt[i]), sizeof(one.intdt[i]));
                if (i < 2)
                {
                    cout << one.intdt[i] << '\t';
                }
                else
                    cout << '\n' << one.intdt[i];
                if ( i > 1 & i < 8)
                {
                    sam += one.intdt[i];
                   
                    
                }    
            }
        std::hash <unsigned int> hashsum;
        res = hashsum(sam);
        if (one.intdt[8] - res != 0)
        {
            cout << '\n' << '\n' << "Hash не соответствует" << '\n' << '\n';
        }
        else
            cout << '\n' << '\n' << "Hash соответствует" << '\n' << '\n';
    }
    
    file.close();
    filebin.close();

    cout << "Данные бинарного файла" << '\n';

    for (int i = 0; i < 9; i++)
    {
        filebinopen.read(reinterpret_cast<char*>(&two.intdt[i]), sizeof(two.intdt[i]));
        cout << two.intdt[i] << '\t';
    }
  return 0;
}
