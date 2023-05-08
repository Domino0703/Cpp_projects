#include<iostream>

using namespace std;

template <typename T> 
class ValueContainer
{
private:
    T m_value;
public:
    ValueContainer<T>(T value = 0):
        m_value(value) {}

    T getValue()
    {
        return m_value;
    }

    void setValue(T value)
    {
        m_value = value;
    }

    ValueContainer<T> operator++()
    {
        ++m_value;
        return *this;
    }
    friend ostream& operator<<(ostream& stream, ValueContainer<T> value)
    {
        stream << value.getValue();
        return stream;
    }
};

template <>
 class ValueContainer<char>
 {
private:
    char m_value;
public:
ValueContainer<char>(char value = 0):
        m_value(value) {}

    char getValue()
    {
        return m_value;
    }



    ValueContainer<char> operator++()
    {
        ++m_value;
        return *this;
    }

    friend ostream& operator<<(ostream& stream, ValueContainer<char> value)
    {
        char j = std::toupper(value.getValue());
        stream << j;
        return stream;
    }
 };