#include <iostream>
#include <windows.h>    //color
#include <string>
#include <conio.h>      //_getch()
#include <cmath>
#include <stdio.h>      //printf

#define PI 3.14159265

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

string welcome = "Bun venit la propriul tau calculator de trigonometrie!\n";

string firstPick = "\
Alege una dintre cele doua optiuni de mai jos:\n\
1.Calculeaza folosind un unghi\n\
2.Calculeaza folosind o functie trigonometrica deja stiuta\n\
Alege numarul unei optiuni (se accepta si propozitii): ";

string functionPick = "\
Alege una dintre optiunile de mai jos:\n\
1.Calculeaza folosind sinusul\n\
2.Calculeaza folosind cosinusul\n\
3.Calculeaza folosind tangenta\n\
4.Calculeaza folosind cotangenta\n\
Alege numarul unei optiuni: ";

string tryAgain = "\
Nu am inteles ce optiune doresti, te rog sa mai incerci odata\n\
Alege numarul unei optiuni (se accepta si propozitii): ";

string repeat = "Doresti sa mai calculezi ceva? da sau nu: ";

string tryAgainNr = "Nu am gasit nici un numar, mai incearca odata: ";

string tryAgainSinOrCos = "\
Functia nu poate fii mai mare decat 1 sau mai mica de cat -1\n\
Te rog mai incearca odata: ";

string degreesOrRadians = "\
Care este unitatea de masura pentru unghi?\n\
1.Grade\n\
2.Radiani\n\
Alege numarul unei optiuni: ";

string askForAngle = "Scrie te rog unghiul dorit: ";

string askForSin = "Scrie te rog sinusul dorit: ";
string askForCosin = "Scrie te rog cosinusul dorit: ";
string askForTan = "Scrie te rog tangenta dorita: ";
string askForCotan = "Scrie te rog tangenta dorita: ";

string angleAnswer = "Pentru un unghi de %s avem:\n\
Sinus de: %f\n\
Cosinus de: %f\n\
Tangenta de: %f\n\
Cotangenta de: %f\n";

string sinAnswer = "Pentru sinus de %f avem:\n\
Unghi de %f radiani sau %f grade\n\
Cosinus de: %f\n\
Tangenta de: %f\n\
Cotangenta de: %f\n";

string cosinAnswer = "Pentru cosinus de %f avem:\n\
Unghi de %f radiani sau %f grade\n\
Sinus de: %f\n\
Tangenta de: %f\n\
Cotangenta de: %f\n";

string tanAnswer = "Pentru tangenta de %f avem:\n\
Unghi de %f radiani sau %f grade\n\
Sinus de: %f\n\
Cosinus de: %f\n\
Cotangenta de: %f\n";

string cotanAnswer = "Pentru cotangenta de %f avem:\n\
Unghi de %f radiani sau %f grade\n\
Sinus de: %f\n\
Cosinus de: %f\n\
Tangenta de: %f\n";

string goodbye = "O zi buna!\n";

string raspuns;

int state = 1;

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

int yesOrNo(std::string yesString) {
    yesString = " " + yesString + " ";
    if (yesString.find(" da ") != std::string::npos) {
        return 1;
    }
    else if (yesString.find(" nu ") != std::string::npos) {
        return 2;
    }
    else return 0;
}

double getNr(bool sinOrCos) {
    double angle = 0;

    while (state == 3)
    {
        getline(cin, raspuns);

        try
        {
            state = 4;
            angle = stod(raspuns);

            if (sinOrCos && (angle > 1 || angle < -1)) {
                cout << tryAgainSinOrCos;
                state = 3;
            }
        }
        catch (const std::exception&)
        {
            cout << tryAgainNr;
            state = 3;
        }
    }

    return angle;
}

void sinus() {
    cout << askForSin;

    double sin = getNr(true);

    double cos = sqrt(1 - pow(sin, 2));
    double tan = sin / cos;
    double ctn = cos / sin;

    double angleRad = asin(sin);
    double angleDegrees = angleRad * 180 / PI;

    printf(sinAnswer.c_str(), sin, angleRad, angleDegrees, cos, tan, ctn);
}

void cosinus() {
    cout << askForCosin;

    double cos = getNr(true);

    double sin = sqrt(1 - pow(cos, 2));
    double tan = sin / cos;
    double ctn = cos / sin;

    double angleRad = asin(sin);
    double angleDegrees = angleRad * 180 / PI;
    
    printf(cosinAnswer.c_str(), cos, angleRad, angleDegrees, sin, tan, ctn);
}

void tangenta() {
    cout << askForTan;

    double tan = getNr(false);

    double sin = sqrt(pow(tan, 2) / (1 + pow(tan, 2)));
    double cos = sqrt(1 / (1 + pow(tan, 2)));
    double ctn = cos / sin;

    double angleRad = asin(sin);
    double angleDegrees = angleRad * 180 / PI;

    printf(tanAnswer.c_str(), tan, angleRad, angleDegrees, sin, cos, ctn);
}

void cotangenta() {
    cout << askForCotan;

    double ctn = getNr(false);
    
    double tan = 1 / ctn;
    double sin = sqrt(pow(tan, 2) / (1 + pow(tan, 2)));
    double cos = sqrt(1 / (1 + pow(tan, 2)));

    double angleRad = asin(sin);
    double angleDegrees = angleRad * 180 / PI;
    
    printf(cotanAnswer.c_str(), ctn, angleRad, angleDegrees, sin, cos, tan);
}

void unghi() 
{
    cout << degreesOrRadians;

    bool usingDegrees = false;

    while (state == 2)
    {
        getline(cin, raspuns);

        switch (stringToInt(raspuns))
        {
            case 1:
                usingDegrees = true;
                state = 3;
                break;
            case 2:
                usingDegrees = false;
                state = 3;
                break;
            default:
                cout << tryAgain;
                break;
        }
    }

    cout << askForAngle;

    double angle = getNr(false);

    string angleStr;

    if (usingDegrees) {
        angleStr = std::to_string(angle) + " grade";
        angle = angle * PI / 180;
    }
    else angleStr = std::to_string(angle) + " radiani";

    double sine = sin(angle);
    double cosine = cos(angle);
    double tangent = tan(angle);
    double cotangent = 1 / tangent;

    printf(angleAnswer.c_str(), angleStr.c_str(), sine, cosine, tangent, cotangent);
}

void functie() {
    cout << functionPick;

    while (state == 2)
    {
        getline(cin, raspuns);

        switch (stringToInt(raspuns))
        {
        case 1:
            state = 3;
            sinus();
            break;
        case 2:
            state = 3;
            cosinus();
            break;
        case 3:
            state = 3;
            tangenta();
            break;
        case 4:
            state = 3;
            cotangenta();
            break;
        default:
            cout << tryAgain;
            break;
        }
    }
}

int main()
{
    system("Color 0B");

    cout << welcome;

    cout << firstPick;

    while (state == 1)
    {
        while (state == 1)
        {
            getline(cin, raspuns);

            switch (stringToInt(raspuns))
            {
            case 1:
                state = 2;
                unghi();
                break;
            case 2:
                state = 2;
                functie();
                break;
            default:
                cout << tryAgain;
                break;
            }
        }

        cout << repeat;

        while (state == 4) 
        {
            getline(cin, raspuns);

            switch (yesOrNo(raspuns))
            {
                case 1:
                    cout << firstPick;
                    state = 1;
                    break;
                case 2:
                    cout << goodbye;
                    state = 0;
                    break;
                default:
                    cout << tryAgain;
                    break;
            }
        }
    }
    
    _getch();
}
