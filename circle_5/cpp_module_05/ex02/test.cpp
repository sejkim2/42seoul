#include <iostream>
#include <fstream>
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

class A
{
    private:
        int memberA;
    public:
        A(int n)
        {
            memberA = n;
        }
        A(const A& a)
        {
            *this = a;
        }
        virtual void printMember(void) const
        {
            std::cout << "memberA : " << memberA << '\n';
        }
};

class B : public A
{
    private:
        int memberB;
    public:
        B(int n, int n2) : A(n)
        {
            memberB = n2;
        }
        B(const B& b) : A(b)
        {
            *this = b;
        }
        virtual void printMember(void) const
        {
            A::printMember();
            std::cout << "memberB : " << memberB << '\n';
        }
};

int main()
{
    std::srand(std::time(0));

    // 50% 확률로 처리할 로직
    if (std::rand() % 2 == 0) {
        std::cout << "로직 A를 실행합니다." << std::endl;
    } else {
        std::cout << "로직 B를 실행합니다." << std::endl;
    }
    // std::ofstream file("test.txt");
    // A a1(1);
    // B b1(2, 3);
    // B b2(a1);
    // b2.printMember();
}