#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

int stringToInt(std::string nrString) {
    if (nrString.find("1") != std::string::npos) {
        return 1;
    }
    else if (nrString.find("2") != std::string::npos) {
        return 2;
    }
    else if (nrString.find("3") != std::string::npos) {
        return 3;
    }
    else if (nrString.find("4") != std::string::npos) {
        return 4;
    }
    else return 0;
}

void sin() {
    cout << "no buuuuun, zi care e sinusul: ";
    int sin;
    try
    {
        cin >> sin;
        cout << "wow";
    }
    catch (std::exception& e)
    {
        cout << e.what();
    }
}

int main()
{
    system("Color 0B");
    std::string salut = "no buna ziua\n";
    std::string intrebare = "ai chef sa faci tema la mate?: ";
    std::string raspuns;
    int raspunsInt;
    std::string sinSauCos = "\
zi bro cu ce lucram\n\
1.sin\n\
2.cos\n\
3.tg\n\
4.ctg\n";
    cout << salut;
    bool stay = true;
    while (stay)
    {
        cout << intrebare;
        getline(cin, raspuns);
        raspuns = " " + raspuns + " ";
        if (raspuns.find(" nu ") != std::string::npos) {
            cout << "bine boss hai la tema\n";
            bool done = false;
            while (!done)
            {
                cout << sinSauCos;
                cout << "scrie numarul corespunzator: ";
                getline(cin, raspuns);
                raspunsInt = stringToInt(raspuns);
                switch (raspunsInt)
                {
                case 1:
                    //cout << "1\n";
                    sin();
                    done = true;
                    break;
                case 2:
                    cout << "2\n";
                    done = true;
                    break;
                case 3:
                    cout << "3\n";
                    done = true;
                    break;
                case 4:
                    cout << "4\n";
                    done = true;
                    break;
                default:
                    cout << "ba nebunule, un numar de la 1 la 4 te rog\n";
                    break;
                }
            }
        }
        else if (raspuns.find(" da ") != std::string::npos) {
            cout << "pleaca ba muresan de aici";
            stay = false;
        }
        else {
            cout << "nu prea te-am inteles boss, mai zi odata cu da sau nu\n";
        }


    }
    
}
