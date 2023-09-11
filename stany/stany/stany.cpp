#include <iostream>
#include <Windows.h>

using namespace std;

enum GetState {
    gateClosed,
    gateOpen,
    gateOpening,
    gateClosing,
};

GetState getState = gateClosed;

void OpenGate()
{
    if (getState == gateClosed)
    {
        cout<<"otwieram brame"<<endl;
        Sleep(5000);
        cout << "brama otwarta" << endl;
        getState = gateOpen;
    }
    else
    {
        cout<<"brama otwarta przyglupie"<<endl;
    }
}

void CloseGate()
{
    if (getState == gateOpen)
    {
        cout<<"zamykam brame";
        Sleep(5000);
        cout << "brama zotala zamknitta" << endl;
        getState = gateClosed ;
    }
    else if (getState == gateClosed ) 
    {
        cout << "brama jest zamknieta" << endl;
    }

}

void pilotClick()
{
    if (getState == gateClosed)
    {
        OpenGate();
    } else if ( getState == gateOpen)
    {
        cout << "brama otwarta przyglupie" << endl;
    }
}

int main()
{
    char action;

    while (true)
    {
        cout << "wcisnij 'P' by otworzyc brame, 'z' by zamknac brame oraz 'q' by wyjść" << endl;
        cin >> action;

        if (action == 'p' || action == 'z' || action == 'q')
        {
            if (action == 'q') {
                break;
            }
            else
            {
                pilotClick();
            }
            if (action == 'z')
            {
                CloseGate();
            }
            
        } else
        {
            cout << "nieprawidlowy wybor ziomek" << endl;
        }
        
    }
    return 0;
}