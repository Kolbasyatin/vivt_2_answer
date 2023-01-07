#ifndef VIVT_2_ANSWER_CUSTOMARRAY_H
#define VIVT_2_ANSWER_CUSTOMARRAY_H

#include <vector>
#include <string>

using namespace std;
const int arraySize = 5;
const int stringSize = 5;

class CustomArray {
private:
    vector<string> arrayOfString;
    static string getRandomString(int size);
    string name;
    static void showArray(vector<string> &array);
    string getElementById(int elementId) const;
public:
    CustomArray(const string &name);
    void glueElements(CustomArray &fromArray, int elementFrom, int elementWith) const;
    void joinUniqueElements(CustomArray &withArray) const;
    void showElement(int elementId);
    void showAllArray();
    string getName();
    vector<string> getArray();

    int getElementCount();
};
#endif //VIVT_2_ANSWER_CUSTOMARRAY_H
