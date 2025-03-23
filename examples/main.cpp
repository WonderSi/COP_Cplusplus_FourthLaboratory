//
// Created by 011ko on 01.03.2025.
//

#include <iostream>
#include <unknwn.h>
#include <objbase.h>

#include "interfaces.h"

using namespace std;

int main () {
    cout << "Hello, world!" << endl;

    HRESULT hr;

    cout << "Клиент: получить указатель на IUnknown" << endl;
    IUnknown* pIUnknown = CreateInstance();

    cout << "\nКлиент: получить указатель на IX" << endl;
    IX* pIX = NULL;
    hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IX успешно получен" << endl;
        pIX->Fx(); // Использовать интерфейс IX
    };

    cout << "\nКлиент: получить указатель на IY" << endl;
    IY* pIY = NULL;
    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
    if (SUCCEEDED(hr)) {
        cout << "Клиент: указатель на IY успешно получен" << endl;
        pIY->Fy(); // Использовать интерфейс IY
    };

    cout << "\nКлиент: получить неподдерживаемый интерфейс" << endl;
    IZ* pIZ = NULL;
    hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
    if(SUCCEEDED(hr)) {
        cout << "Клиент: интерфейс IZ успещно получен" << endl;
    } else {
        cout << "Клиент: Не удается получить доступ к интерфейсу IZ" << endl;
    };


    cout << "\nКлиент: получить указатель на IY через IX" << endl;
    IY* pIYfromIX = NULL;
    hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
    if(SUCCEEDED(hr)) {
        cout<< "Клиент: указатель на IY успешно получен" << endl;
        pIYfromIX->Fy();
    } else {
        cout << "Клиент: невозможно получить указатель на IY через IX" << endl;
    }

    if (pIX) pIX->Release();
    if (pIY) pIY->Release();
    if (pIUnknown) pIUnknown->Release();

    
    cout << "\nКлиент: проверить, являются ли IX и IY одним и тем же объектом" << endl;
    if (SameComponents(pIX, pIY)) {
        cout << "Клиент: IX и IY указывают на один и тот же объект" << endl;
    } else {
        cout << "Клиент: IX и IY указывают на разные объекты" << endl;
    }

    cout << "\nКлиент: вызвать функцию f(IX*)" << endl;
    f(pIX); // Вызов функции f

    cout << "\nКлиент: вызвать функцию f2(IX*)" << endl;
    f2(pIX); // Вызов функции f2

    return 0;
};