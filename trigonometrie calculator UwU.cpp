#include <iostream>
#include <windows.h>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
    system("Color 0B");
    string salut = "no buna ziua\n";
    string intrebare = "ai chef sa faci tema la mate ?: ";
    string raspuns;
    cout << salut;
    bool stay = true;
    while (stay)
    {
        cout << intrebare;
        getline(cin, raspuns);
        raspuns = " " + raspuns + " ";
        if (raspuns.find(" nu ") != std::string::npos) {
            cout << "bine boss hai la tema";
            stay = false;
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
