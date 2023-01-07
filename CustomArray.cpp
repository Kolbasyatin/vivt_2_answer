#include "CustomArray.h"
#include <iostream>
#include <algorithm>

using namespace std;

CustomArray::CustomArray(const string &name) : name(name) {
    //Инициализируем массив случайными числами
    for (int i = 0; i < arraySize; ++i) {
        arrayOfString.emplace_back(getRandomString(stringSize));
    }
    //Для демонстрации склейки уникальных элементов создаем одинаковые.
    arrayOfString.emplace_back("SAME!");
}

//Генерируем случайные символы
string CustomArray::getRandomString(int size) {
    string generatedString;
    //Без указания resize падает с ошибкой.
    generatedString.resize(size);

    for (int i = 0; i < size; i++) {
        generatedString[i] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[random() % 26];
    }

    return generatedString;
}

void CustomArray::showAllArray() {
    cout << name << endl;
    showArray(arrayOfString);
    cout << endl;
}

vector<string> CustomArray::getArray() {
    return arrayOfString;
}

void CustomArray::showElement(int elementId) {
    try {
        string element = getElementById(elementId);
        cout << name << ": element " << elementId << endl;
        cout << element << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
}

void CustomArray::glueElements(CustomArray &fromArray, int elementFrom, int elementWith) const {
    try {
        cout << "Результат склейки элементов: ";

        string from = fromArray.getElementById(elementFrom);
        string with = getElementById(elementWith);
        vector<string> glued = {from, with};

        showArray(glued);
        cout << endl;
    } catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
}

string CustomArray::getElementById(int elementId) const {
    if (elementId >= 0 && elementId < arrayOfString.size()) {
        return arrayOfString[elementId];
    }

    throw invalid_argument("Out of range");
}
 void CustomArray::showArray(vector<string> &array) {
    for (int i = 0; i < array.size(); ++i) {
        cout << i+1 << ":" << array[i] << " ";
    }
}

void CustomArray::joinUniqueElements(CustomArray &withArray) const {
    //Объединим векторы, и выкинем повторы.
    vector<string> joined(withArray.getArray());
    joined.insert(joined.end(), arrayOfString.begin(), arrayOfString.end());

    //Выкинули повторы
    sort(joined.begin(), joined.end() );
    joined.erase( unique( joined.begin(), joined.end() ), joined.end() );

    cout << "Объединенный массив: ";
    showArray(joined);
}

int CustomArray::getElementCount() {
    return arrayOfString.size();
}

string CustomArray::getName() {
    return name;
}
