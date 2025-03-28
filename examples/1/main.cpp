////
//// Created by 011ko on 01.03.2025.
////
//
//#include <iostream>
//#include <unknwn.h>
//#include <objbase.h>
//#include <cassert>
//
//using namespace std;
//
//// Предварительное объявление идентификаторов интерфейса
//extern const IID IID_IX;
//extern const IID IID_IY;
//extern const IID IID_IZ;
//extern const IID IID_IUnknown1;
//
//// Определение IID
//// {32bb8320-b41b-11cf-a6bb-0080c7b2d682}
//const IID IID_IX =
//        {0x32bb8320, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//// {32bb8321-b41b-11cf-a6bb-0080c7b2d682}
//const IID IID_IY =
//        {0x32bb8321, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//// {32bb8322-b41b-11cf-a6bb-0080c7b2d682}
//const IID IID_IZ =
//        {0x32bb8322, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//// {32bb8323-b41b-11cf-a6bb-0080c7b2d682}
//const IID IID_IUnknown1 =
//        {0x32bb8323, 0xb41b, 0x11cf,
//         {0xa6, 0xbb, 0x0, 0x80, 0xc7, 0xb2, 0xd6, 0x82}};
//
//
//// Интерфейсы
//interface IX : IUnknown {
//    virtual void __stdcall Fx() = 0;
//};
//
//interface IY : IUnknown {
//    virtual void __stdcall Fy() = 0;
//};
//
//interface IZ : IUnknown {
//    virtual void __stdcall Fz() = 0;
//};
//
//// Компонент
//class CA : public IX, public IY {
//    // Реализация методов класса IUnknown
//    virtual ULONG __stdcall AddRef() { return 0; };
//    virtual ULONG __stdcall Release() { return 0; };
//    virtual HRESULT __stdcall QueryInterface(const IID& iid, void** ppv) {
//        if (iid == IID_IUnknown1) {
//            cout << "QueryInterface: возвращаю указатель на IUnknown" << endl;
//            *ppv = static_cast<IX*>(this);
//        } else if (iid == IID_IX) {
//            cout << "QueryInterface: возвращаю указатель на IX" << endl;
//            *ppv = static_cast<IX*>(this);
//        } else if (iid == IID_IY) {
//            cout << "QueryInterface: возвращаю указатель на IY" << endl;
//            *ppv = static_cast<IY*>(this);
//        } else {
//            cout << "Интерфейс не поддерживается" << endl;
//            *ppv = NULL;
//            return E_NOINTERFACE;
//        }
//        reinterpret_cast<IUnknown*>(*ppv)->AddRef();
//        return S_OK;
//    }
//
//    // Реализация интерфейса IX
//    virtual void __stdcall Fx() { cout << "CA::Fx" << endl; };
//
//    // Реализация интерфейса IY
//    virtual void __stdcall Fy() { cout << "CA::Fy" << endl; };
//};
//
//// Функция создания компонента
//IUnknown* CreateInstance() {
//    IUnknown* pI = static_cast<IX*>(new CA);
//    pI->AddRef();
//    return pI;
//}
//
//BOOL SameComponents(IX* pIX, IY* pIY) {
//    IUnknown* pI1 = NULL;
//    IUnknown* pI2 = NULL;
//
//    // Получить указатель на IUnknown через pIX
//    pIX->QueryInterface(IID_IUnknown1, (void**)&pI1);
//
//    // Получить указатель на IUnknown через pIY
//    pIY->QueryInterface(IID_IUnknown1, (void**)&pI2);
//
//    // Сравнить полученные указатели
//    return pI1 == pI2;
//}
//
//// Новая функция f
//void f(IX* pIX) {
//    IX* pIX2 = NULL;
//    HRESULT hr = pIX->QueryInterface(IID_IX, (void**)&pIX2);
//    assert(SUCCEEDED(hr)); // Запрос должен быть успешным
//}
//
//void f2(IX* pIX) {
//    HRESULT hr;
//
//    IX* pIX2 = NULL;
//    IY* pIY = NULL;
//
//    // Получить IY через IX
//    hr = pIX->QueryInterface(IID_IY, (void**)&pIY);
//    if (SUCCEEDED(hr)) {
//        // Получить IX через IY
//        hr = pIY->QueryInterface(IID_IX, (void**)&pIX2);
//
//        // QueryInterface должна отработать успешно
//        assert(SUCCEEDED(hr));
//    }
//}
//
//// Реализация функции f3
//void f3(IX* pIX) {
//    HRESULT hr;
//
//    IY* pIY = NULL;
//
//    // Запросить IY у IX
//    hr = pIX->QueryInterface(IID_IY, (void**)&pIY);
//
//    if (SUCCEEDED(hr)) {
//        IZ* pIZ = NULL;
//
//        // Запросить IZ у IY
//        hr = pIY->QueryInterface(IID_IZ, (void**)&pIZ);
//
//        if (SUCCEEDED(hr)) {
//            // Запросить IZ у IX
//            hr = pIX->QueryInterface(IID_IZ, (void**)&pIZ);
//
//            assert(SUCCEEDED(hr)); // Это должно работать
//        }
//    }
//}
//
//
//// Клиент
//int main() {
//    cout << "Hello, world!" << endl;
//
//    HRESULT hr;
//
//    cout << "Клиент: получить указатель на IUnknown" << endl;
//    IUnknown* pIUnknown = CreateInstance();
//
//    cout << "\nКлиент: получить указатель на IX" << endl;
//    IX* pIX = NULL;
//    hr = pIUnknown->QueryInterface(IID_IX, (void**)&pIX);
//    if (SUCCEEDED(hr)) {
//        cout << "Клиент: указатель на IX успешно получен" << endl;
//        pIX->Fx(); // Использовать интерфейс IX
//    };
//
//    cout << "\nКлиент: получить указатель на IY" << endl;
//    IY* pIY = NULL;
//    hr = pIUnknown->QueryInterface(IID_IY, (void**)&pIY);
//    if (SUCCEEDED(hr)) {
//        cout << "Клиент: указатель на IY успешно получен" << endl;
//        pIY->Fy(); // Использовать интерфейс IY
//    };
//
//    cout << "\nКлиент: получить неподдерживаемый интерфейс" << endl;
//    IZ* pIZ = NULL;
//    hr = pIUnknown->QueryInterface(IID_IZ, (void**)&pIZ);
//    if(SUCCEEDED(hr)) {
//        cout << "Клиент: интерфейс IZ успещно получен" << endl;
//    } else {
//        cout << "Клиент: Не удается получить доступ к интерфейсу IZ" << endl;
//    };
//
//
//    cout << "\nКлиент: получить указатель на IY через IX" << endl;
//    IY* pIYfromIX = NULL;
//    hr = pIX->QueryInterface(IID_IY, (void**)&pIYfromIX);
//    if(SUCCEEDED(hr)) {
//        cout<< "Клиент: указатель на IY успешно получен" << endl;
//        pIYfromIX->Fy();
//    } else {
//        cout << "Клиент: невозможно получить указатель на IY через IX" << endl;
//    }
//
//    cout << "\nКлиент: получить указатель на IUnknown через IY" << endl;
//    IUnknown *pIUnknownFromIY = NULL;
//    hr = pIY->QueryInterface(IID_IUnknown1, (void **) &pIUnknownFromIY);
//    if (SUCCEEDED(hr)) {
//        cout << "Равны два ли два указателя?" << endl;
//        if (pIUnknownFromIY == pIUnknown) {
//            cout << "ДА" << endl;
//        } else {
//            cout << "НЕТ" << endl;
//        }
//    }
//
//    cout << "\nКлиент: проверить, являются ли IX и IY одним и тем же объектом" << endl;
//    if (SameComponents(pIX, pIY)) {
//        cout << "Клиент: IX и IY указывают на один и тот же объект" << endl;
//    } else {
//        cout << "Клиент: IX и IY указывают на разные объекты" << endl;
//    }
//
//    cout << "\nКлиент: вызвать функцию f(IX*)" << endl;
//    f(pIX); // Вызов функции f
//
//    cout << "\nКлиент: вызвать функцию f2(IX*)" << endl;
//    f2(pIX); // Вызов функции f2
//
//    // Удалить компонент
//    delete pIUnknown;
//
//    return 0;
//}