#include <cstdio>
#include <iostream>
using namespace std;

template <typename K, typename T>
class Map {
    int ok = 0;
    int aux_index = 0;
public:
    struct pairs {
        K key;
        T value;
        int index;
    };
    pairs* v;
    int curent_index;
    Map() { cout << "Default Constructor\n ";  curent_index = 0; v = new pairs[100]; }
    ~Map() { cout << "Delete Constructor\n"; delete[] v; }
    Map<K, T>& operator[](K a) {
        cout << "operator[]\n";
        for (int i = 0; i < curent_index; i++)
            if (v[i].key == a)
            { //daca exista keya,atuncti schimbab indexul curent,si transmitem in operator= sa modifice doar valuarea la keya curenta.
                aux_index = curent_index;
                curent_index = i;
                ok = 1;
                return *this;
            }
        v[curent_index].key = a;
        v[curent_index].index = curent_index;
        return *this;
    }
    Map<K, T>& operator=(T a) {
        cout << "operator=\n";
        if (ok != 1) {//daca nu exista nici u keye,atunci 
            v[curent_index].value = a;
            curent_index++;
        }
        else
        {//dacac existadeja keya ,atunci doar acutaliza value.
            ok = 0;
            v[curent_index].value = a;
            curent_index = aux_index;
            curent_index++;
        }
        return *this;
    }
    class MyIterator {
    public:
        pairs* p;
        MyIterator() { p = new pairs[100]; }
        MyIterator(pairs* v) : p(v) {}
        friend std::ostream& operator<<(std::ostream& os, const MyIterator& iter) {
            os << iter.p->index;
            return os;
        }
        auto operator*() { return std::tie(p->key, p->value, p->index); }
        bool operator!=(const MyIterator& it) { return p->index != it.p->index; }
        MyIterator& operator++() { ++p; return *this; }

    };
    MyIterator begin() { return MyIterator(v); }
    MyIterator end() { return MyIterator(v + curent_index); }
};
int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (int i = 0; i < m.curent_index; i++)
        cout << m.v[i].key << " " << m.v[i].value << " ";
    cout << endl;
    /*MyIterator a = m.begin();
    MyIterator b = m.end();
    cout<<"inceputl = "<<a << " sfarsitul = " << b << "\n";*/
    cout << "------------------------\n";
    /* auto& [key, value, index] = m;
    cout << key << " " << value << " " << index;*/
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    cout << m.v[1].key << " " << m.v[1].value << "\n";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
