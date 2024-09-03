#ifndef _ARRAY_HPP__
# define _ARRAY_HPP__

template<typename T>
class Array
{
    public:
        Array(void);
        ~Array(void);
        Array(const Array& copy);
        Array& operator=(const Array& obj);

        Array(unsigned int n);
        unsigned int size(void) const;
    private:
        T[] arr;
};

#endif