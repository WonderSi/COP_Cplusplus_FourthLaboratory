//
// Created by 011ko on 01.03.2025.
//

#include <iostream>
#include <unknwn.h>
#include <objbase.h>

using namespace std;

// Предварительное объявление идентификаторов интерфейса
extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IID_IZ;
extern const IID IID_IUnknown1;

// Интерфейсы
interface IX : IUnknown {
    virtual void __stdcall Fx() = 0;
};

interface IY : IUnknown {
    virtual void __stdcall Fy() = 0;
};

interface IZ : IUnknown {
    virtual void __stdcall Fz() = 0;
};

// Компонент
class CA : public IX, public IY {
    // Реализация методов класса IUnknown
    virtual ULONG __stdcall AddRef();
    virtual ULONG __stdcall Release();
    virtual HRESULT __stdcall QueryInterface(const IID &iid, void **ppv);

    virtual void __stdcall Fx();
    virtual void __stdcall Fy();
};

// Функция создания компонента
IUnknown* CreateInstance();

// Функция определяет, указывают ли pIX и pIY на интерфейсы одного компонента
BOOL SameComponents(IX* pIX, IY* pIY);

// Прототип новой функции f
void f(IX* pIX);

void f2(IX* pIX);

// Прототип функции f3
void f3(IX* pIX);