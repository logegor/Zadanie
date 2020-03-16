// Zadanie.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Header.h"





int main()
{
  
    unsigned int aa[7] = { 0 };
    setlocale(LC_ALL, "Russian");
    const int d = 17;
     char datetime[d];
    string a;
    int i = 0, j, k;
    unsigned int  sam = 0;
    unsigned int res = 0;
    ifstream file ;
    file.open("E:\data.txt");
    if (!file) cout << "При открытии файла возникла ошибка!" << '\n';
    else
    {

        cout << "Файл был открыт!" << '\n'<<'\n';
        file.get(datetime, d);
        cout << datetime << '\n' << '\n';
       
            for ( i ; i < 7; i++)
            {
                file >> a;
                aa[i] = (unsigned int)atoll(a.c_str());
                if (i < 6)
                {
                    sam += aa[i];
                    cout << aa[i] << '\n';
                } 
            }
       

        std::hash <unsigned int> hashsum;
        res = hashsum(sam);
        if (aa[6] - res != 0)
        {
            cout << '\n' << "Hash не соответствует" << '\n' << '\n';
        }
        else
            cout << '\n' << "Hash соответствует" << '\n' << '\n';
      /*  return 1;*/
    }
    
    file.close();
    
    string databin;
    
    file.open("E:\data.txt");
    getline(file, databin);
    file.close();
    ofstream filebin("E:\databin.txt", ios::binary | ios::out);

    for (j = 0; j < size(databin); j++)
    {
        int mass[8] = { 0 };
        int dd = (int)databin[j];
        for (int i = 0; i < 8; i++)
        {
            mass[7 -i] = (dd >> i) & 0x01;

            /*cout << mass[7- i];*/
            filebin << mass[7-i] ;
        }
        
        
        filebin << '\n';
    }
    filebin.close()
   

   






    return 0;
}
