#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>
#include <cmath>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

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
    bool done = false;
    string num;
    double sin;
    while (!done)
    {
        cout << "no buuuuun, zi care e sinusul (numar te rog): ";
        getline(cin, num);
        try
        {
            sin = stod(num);
            //cout << num << "\n";
            if (sin > 1 || sin < -1) {
                cout << "\
ba tu ori esti prost, ori ma trolezi\n\
dar pt ca sunt om credincios, te mai las sa incerci odata\n";
            }
            else {
                done = true;
            }
        }
        catch (std::exception& e)
        {
            SetConsoleTextAttribute(hConsole, 75);
            cout << e.what() << "\n";
            cout << "\
BOSSSS AM ZIS UN NUMAR, TU VREI SA STRICI PROGRAMUL???\n";
            SetConsoleTextAttribute(hConsole, 11);
            cout << "no hai te mai las sa incerci odata\n";
        }
    }
    double cos = sqrt(1 - pow(sin, 2));
    double tan = sin / cos;
    double ctn = cos / sin;
    cout << "\
no buuun, am calculat asa:\n\
avem sin: " << sin << "\n\
avem cos: " << cos << "\n\
avem tan: " << tan << "\n\
avem ctg: " << ctn << "\n";
}

void cos() {
    bool done = false;
    string num;
    double cos;
    while (!done)
    {
        cout << "no buuuuun, zi care e cosinusul (numar te rog): ";
        getline(cin, num);
        try
        {
            cos = stod(num);
            //cout << num << "\n";
            if (cos > 1 || cos < -1) {
                cout << "\
ba tu ori esti prost, ori ma trolezi\n\
dar pt ca sunt om credincios, te mai las sa incerci odata\n";
            }
            else {
                done = true;
            }
        }
        catch (std::exception& e)
        {
            SetConsoleTextAttribute(hConsole, 75);
            cout << e.what() << "\n";
            cout << "\
BOSSSS AM ZIS UN NUMAR, TU VREI SA STRICI PROGRAMUL???\n";
            SetConsoleTextAttribute(hConsole, 11);
            cout << "no hai te mai las sa incerci odata\n";
        }
    }
    double sin = sqrt(1 - pow(cos, 2));
    double tan = sin / cos;
    double ctn = cos / sin;
    cout << "\
no buuun, am calculat asa:\n\
avem sin: " << sin << "\n\
avem cos: " << cos << "\n\
avem tan: " << tan << "\n\
avem ctg: " << ctn << "\n";
}

void tan() {
    bool done = false;
    string num;
    double tan;
    while (!done)
    {
        cout << "no buuuuun, zi care e tangenta (numar te rog): ";
        getline(cin, num);
        try
        {
            tan = stod(num);
            //cout << num << "\n";
            done = true;
        }
        catch (std::exception& e)
        {
            SetConsoleTextAttribute(hConsole, 75);
            cout << e.what() << "\n";
            cout << "\
BOSSSS AM ZIS UN NUMAR, TU VREI SA STRICI PROGRAMUL???\n";
            SetConsoleTextAttribute(hConsole, 11);
            cout << "no hai te mai las sa incerci odata\n";
        }
    }
    double sin = sqrt(pow(tan, 2) / (1 + pow(tan, 2)));
    double cos = sqrt(1 / (1 + pow(tan, 2)));
    double ctn = cos / sin;
    cout << "\
no buuun, am calculat asa:\n\
avem sin: " << sin << "\n\
avem cos: " << cos << "\n\
avem tan: " << tan << "\n\
avem ctg: " << ctn << "\n";
}

void ctn() {
    bool done = false;
    string num;
    double ctn;
    while (!done)
    {
        cout << "no buuuuun, zi care e tangenta (numar te rog): ";
        getline(cin, num);
        try
        {
            ctn = stod(num);
            //cout << num << "\n";
            done = true;
        }
        catch (std::exception& e)
        {
            SetConsoleTextAttribute(hConsole, 75);
            cout << e.what() << "\n";
            cout << "\
BOSSSS AM ZIS UN NUMAR, TU VREI SA STRICI PROGRAMUL???\n";
            SetConsoleTextAttribute(hConsole, 11);
            cout << "no hai te mai las sa incerci odata\n";
        }
    }
    double tan = 1 / ctn;
    double sin = sqrt(pow(tan, 2) / (1 + pow(tan, 2)));
    double cos = sqrt(1 / (1 + pow(tan, 2)));
    
    cout << "\
no buuun, am calculat asa:\n\
avem sin: " << sin << "\n\
avem cos: " << cos << "\n\
avem tan: " << tan << "\n\
avem ctg: " << ctn << "\n";
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
            bool gata = false;
            while (!gata) {
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
                        //cout << "2\n";
                        cos();
                        done = true;
                        break;
                    case 3:
                        //cout << "3\n";
                        tan();
                        done = true;
                        break;
                    case 4:
                        //cout << "4\n";
                        ctn();
                        done = true;
                        break;
                    default:
                        cout << "ba nebunule, un numar de la 1 la 4 te rog\n";
                        break;
                    }

                }
                bool saRaspuns = false;
                while (!saRaspuns)
                {
                    cout << "mai facem un calcul boss?: ";
                    getline(cin, raspuns);
                    raspuns = " " + raspuns + " ";
                    if (raspuns.find(" nu ") != std::string::npos) {
                        gata = true;
                        saRaspuns = true;
                    }
                    else if (raspuns.find(" da ") != std::string::npos) {
                        cout << "ok boss, hai sa mai facem\n";
                        saRaspuns = true;
                    }
                    else {
                        cout << "scrie mai clar, da sau nu?\n";
                    }
                }
            }
            stay = false;
        }
        else if (raspuns.find(" da ") != std::string::npos) {
            cout << "pleaca ba muresan de aici\n";
            _getch();
            return 0;
        }
        else {
            cout << "nu prea te-am inteles boss, mai zi odata cu da sau nu\n";
        }


    }

    cout << "sal\n";
    
    _getch();
}
