#include <iostream>

class IntArray {
private:
    int m_length = 0;
    int *m_array = nullptr;
    
public:
    IntArray(int length) {
        m_length = length;
        m_array = new int[m_length] { 0 };
    }
    
    IntArray(const IntArray &array) {
        m_length = array.m_length;
        m_array = new int[m_length];
        for (int i = 0; i < array.m_length; i++) {
            m_array[i] = array.m_array[i];
        }
    }
    
    ~IntArray() {
        delete[] m_array;
    }
    
    friend std::ostream& operator<<(std::ostream &out, const IntArray &array) {
        for (int i = 0; i < array.m_length; i++) {
            out << array.m_array[i] << ' ';
        }
        
        return out;
    }
    
    int& operator[] (const int i) {
        return m_array[i];
    }
    
    IntArray& operator= (const IntArray &array) {
        if (this == &array) {
            return *this;
        }

        delete[] m_array;
        m_length = array.m_length;
        m_array = new int[m_length];
        
        for (int i = 0; i < array.m_length; i++) {
            m_array[i] = array.m_array[i];
        }
        
        return *this;
    }
};

IntArray fillArray() {
    IntArray a(5);
    a[0] = 5;
    a[1] = 8;
    a[2] = 2;
    a[3] = 3;
    a[4] = 6;
    return a;
}

int main() {
    IntArray a = fillArray();

    std::cout << a << '\n';
    
    IntArray b(1);
    b = a;
    
    std::cout << b << '\n';
}
