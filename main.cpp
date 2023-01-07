#include <iostream>
#include "CustomArray.h"

using namespace std;

int Menu();

int GetNumber(int, int);

void ExitBack();

void Show(CustomArray *[], int);

void ShowByIndex(CustomArray *[], int);

CustomArray *ArraySelect(CustomArray *[], int);

int ElementNumberSelect(int);

void JoinElements(CustomArray *arrayHolder[], int arrayCount);

void GlueElements(CustomArray *arrayHolder[], int arrayCount);

int main() {
    CustomArray array1 = CustomArray("Array1");
    CustomArray array2 = CustomArray("Array2");

    CustomArray *arrayHolder[] = {&array1, &array2};
    int arrayCount = sizeof(arrayHolder) / sizeof(arrayHolder[0]);

    bool done = false;
    while (!done) {
        switch (Menu()) {
            case 1:
                Show(arrayHolder, arrayCount);
                break;
            case 2:
                ShowByIndex(arrayHolder, arrayCount);
                break;
            case 3:
                GlueElements(arrayHolder, arrayCount);
                break;
            case 4:
                JoinElements(arrayHolder, arrayCount);
                break;
            case 5:
                cout << "Конец работы." << endl;
                done = true;
                break;
        }
    }

    return 0;
}

int Menu() {
    cout << "\n============= Г л а в н о е м е н ю =============" << endl;
    cout << "1 - вывести все массивы\t 3 - сцепить элементы массивов" << endl;
    cout << "2 - вывод строки по индексу\t\t 4 - соединить два массива" << endl;
    cout << "\t\t 5 - выход" << endl;

    return GetNumber(1, 5);
}

void Show(CustomArray *arrayHolder[], int arrayCount) {
    for (int i = 0; i < arrayCount; ++i) {
        arrayHolder[i]->showAllArray();
    }
    ExitBack();
}

void ShowByIndex(CustomArray *arrayHolder[], int arrayCount) {
    CustomArray *customArray = ArraySelect(arrayHolder, arrayCount);
    int elementNum = ElementNumberSelect(customArray->getElementCount());
    customArray->showElement(elementNum);

    ExitBack();
}

void GlueElements(CustomArray *arrayHolder[], int arrayCount) {
    cout << "Выберите первый массив" << endl;
    CustomArray *array1 = ArraySelect(arrayHolder, arrayCount);
    cout << "Выберите элемент для сцепления массива " << array1->getName() << endl;
    int element1 = ElementNumberSelect(array1->getElementCount());
    cout << "Выберите второй массив" << endl;
    CustomArray *array2 = ArraySelect(arrayHolder, arrayCount);
    cout << "Выберите элемент для сцепления массива " << array2->getName() << endl;
    int element2 = ElementNumberSelect(array2->getElementCount());
    array1->glueElements(*array2, element2, element1);

    ExitBack();
}

void JoinElements(CustomArray *arrayHolder[], int arrayCount) {
    cout << "Выберите первый массив для слияния" << endl;
    CustomArray *array1 = ArraySelect(arrayHolder, arrayCount);
    cout << "Выберите второй массив для слияния" << endl;
    CustomArray *array2 = ArraySelect(arrayHolder, arrayCount);
    array1->joinUniqueElements(*array2);

    ExitBack();
}

CustomArray *ArraySelect(CustomArray *arrayHolder[], int arrayCount) {
    cout << "Выберите номер массива от 1 до " << arrayCount << endl;
    int arrayNum = GetNumber(1, arrayCount) - 1;

    return arrayHolder[arrayNum];

}

int ElementNumberSelect(int maxElement) {
    cout << "Выберите номер элемента от 1 до " << maxElement << endl;

    return GetNumber(1, maxElement) - 1;
}

//ввод целого числа в заданном диапазоне
int GetNumber(int min, int max) {
    int number = min - 1;
    while (true) {
        cin >> number;
        if ((number >= min) && (number <= max) && (cin.peek() == '\n'))
            break;
        else {
            cout << "Повторите ввод (ожидается число от " << min
                 << " до " << max << "):" << endl;
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }

    return number;
}

// возврат в функцию с основным меню
void ExitBack() {
    cout << "Нажмите Enter." << endl;
    cin.get();
    cin.get();
}

