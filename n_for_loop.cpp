#include <iostream>

using namespace std;

void recursive(int x, int y, int z)
{
    static int start_y = y, start_z = z;

    cout << x << " , " << y << " , " << z << endl;

    if (z > 1)
    {
        recursive(x, y, --z);
        return;
    }
    if (y > 1)
    {
        recursive(x, --y, start_z);
        return;
    }
    if (x > 1)
    {
        recursive(--x, start_y, start_z);
        return;
    }
}

void n_for_loop(int start = 0)
{
    static int arr[] = {1, 2, 3};

    static int size = sizeof(arr)/sizeof(*arr);
    static int* arrTemp(new int[size]);

    if (start >= size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arrTemp[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < arr[start]; i++)
    {
        arrTemp[start] = i;
        n_for_loop(start + 1);
    }
}

int main()
{
    n_for_loop();

    // recursive(3, 3, 3);
    return 0;
}
