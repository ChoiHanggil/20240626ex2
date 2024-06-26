
#include <iostream>
#include<array>
#include <algorithm>
#include<numeric>
#include<vector>
/*
컨테이터
    모두.size();
Sequence Container
    순차 컨테이너 (순서가 있음)
    std::string
    std::array
    std::vector
    std::deque
    std::list
    std::forward_list

Associative Container
    연관 컨테이너 (키 - 값)
    중복 X
    std::set        키   
    std::map        키 - 값   Dictionary 사전
    중복 O
    std::multiset    
    std::multmap

Adapter container
    다른 컨테이너를 연결해서 특정 목적으로 사용
    std::stack
    std::queue
    std::priority_queue

*/
class MyClass
{
public:
    int mValue;
    MyClass(int val) : mValue(val){}

    friend std::ostream& operator << (std::ostream& os, const MyClass& param)
    {
        os << param.mValue;
        return os;
    }

    bool operator < (const MyClass& param)
    {
        return mValue < param.mValue;
    }

    friend bool MyConmpare(const MyClass& a, const MyClass& b)
    {
        return a.mValue < b.mValue;
    }
};
int main()
{
    /*
    int array1[5] = { 1,2,3,4,5 };
    for (int i = 0; i < 5; i++)
    {
        std::cout << array1[i] << std::endl;
    }

    std::array<int, 5> array2{ 1,2,3,4,5 };
    for (int i = 0; i < array2.size(); i++)
    {
        std::cout << array2[i] << std::endl;
    }

    std::array<int, 5>::iterator itr = array2.begin();
    while (itr != array2.end())
    {
        std::cout << *itr << std::endl;
        itr++;
    }
   

    //Modern c++
    //auto - 컴파일러가 코드로 추측 
    for (auto it = array2.begin(); it != array2.end(); it++)
    {
        std::cout << *it << std::endl;
    }
    //range_based for loop
    for (auto value : array2)
    {
        std::cout << value << std::endl;
    }
    */
    std::array<int, 5> container{ 1,2,3,4,5 };
    //이터레이터를 사용해 출력
    std::array<int, 5>::iterator itr = container.begin();
    while (itr != container.end())
    {
        std::cout << *itr << std::endl;
        itr++;
    }

    //범위기반 반복문으로 최소값을 구해 봅시다.
    int min = container[0];

    for (auto e : container)
    {
        if (e < min)
        {
            min = e;
        }
    }

    auto result = std::min_element(container.begin(), container.end());

    int sum = std::accumulate(container.begin(), container.end(), 0);
    
    //std::array<std::string, 4> container2{ "doggy", "kitty", "bunny", "piggy" };
    std::array<MyClass, 4> container2{ MyClass(4), MyClass(3), MyClass(2), MyClass(1) };
    for (const auto& e : container2)
    {
        std::cout << e << std::endl;
    }
    
    auto itr2 = std::min_element(container2.begin(), container2.end());
    /*
    auto itr2 = std::min_element(container2.begin(), container2.end(),
        [](const MyClass& a, const Myclass& b) -> bool { eturn a.mValue < b.mValue; })
    
    */
    //[] (const MyClass& a, const Myclass& b) -> bool 람다함수
    std::cout << *itr2 << std::endl;
    

    //lambda expression
    /*
    [](param - list) -> returntype
    {
        code
    }
    */
    std::for_each(container2.begin(), container2.end(), 
        [](const MyClass& a) {std::cout << a.mValue << std::endl;} );

    std::vector<int> v{ 1,2,3 };

}

