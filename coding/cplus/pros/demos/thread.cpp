#include <iostream>
#include <thread>

using namespace std;

void output(int i)
{
    cout << i << endl;
}

void test()
{
    cout << "hello" << endl;
}

int main()
{
    cout << "main start..." << endl;

    for (int  i = 0; i < 4; i++)
    {
        cout << i << endl;
        thread t(test);
        t.detach();
        // thread t(output, i);
        // t.detach();
    }

    cout << "main end..." << endl;
    getchar();
    return 0;
}