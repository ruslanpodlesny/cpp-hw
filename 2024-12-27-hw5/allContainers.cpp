

#include <iostream>
#include <vector>
#include <array>
#include <list>

using namespace std;

void static printCont(const vector<int>& vect)  {
    for (auto st{ vect.begin() }; st != vect.end(); ++st) {
        cout << *st << " ";
    }
    cout << endl;
}

void static printCont(array<int, 7>& arr) {
    for (int i=0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void static printCont(list<int> lst) {
    for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;
}


int main()
{
    vector<int> vect1 {1, 2, 3, 4, 5, 6, 7};
    auto vect1_iter = vect1.begin();

    vector<int> vect2{ 3, 3, 3, };
    auto vect2_begin = vect2.begin();
    auto vect2_end = vect2.end();

    vect1.insert(vect1_iter, 8);
    vect1_iter = vect1.end();
    vect1.insert(vect1_iter, 3, 9);
    vect1_iter = vect1.end()-3;
    vect1.insert(vect1_iter, vect2_begin, vect2_end);

    cout << vect1[3] << vect1.at(2) << vect1.front() << vect1.back() << endl;

    printCont(vect1);

    vect1.pop_back();
    vect1_iter = vect1.end();
    vect1.erase(vect1_iter-1);
    printCont(vect1);

    vect1.resize(5);
    printCont(vect1);

    vect1.assign(11, 11);
    printCont(vect1);

    vect1.swap(vect2);
    printCont(vect1);

    vect1.clear();
    if (vect1.empty()) {
        cout << "Vector is empty" << endl;
    }

    array<int, 7> arr;

    for (int i = 0; i < 7; ++i) {
        arr[i] = i;
    }
    
    printCont(arr);

    cout << arr.size() << endl;
    cout << arr.at(3) << endl;
    cout << arr.front() << endl;
    cout << arr.back() << endl;

    arr.fill(9);
    printCont(arr);

    list<int>lst{ 1,2,3,4,5,6,7 };
    auto iter1 = lst.begin();
    list<int>lst2{ 3,3,3 };
    auto iter2 = lst2.begin();
    auto iter3 = lst2.end();

    if (lst.empty()) {
        cout << "List is empty" << endl;
    }
    else {
        cout << "List is not empty" << endl;
    }

    printCont(lst);
     
    cout << lst.front() << lst.back() << '\n' << "Size: " << lst.size() << endl;

    lst.resize(5);
    printCont(lst);

    lst.resize(9,7);
    printCont(lst);

    lst.assign(3, 3);
    printCont(lst);

    lst.push_back(7);
    lst.push_front(5);
    iter1 = lst.end();
    lst.insert(iter1, iter2, iter3);
    printCont(lst);

    lst.swap(lst2);
    printCont(lst);

    lst.pop_back();
    lst.pop_front();
    lst.clear();

    if (lst.empty()) {
        cout << "List is empty" << endl;
    }

}

