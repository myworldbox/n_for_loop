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

void n_for_loop(int x, int size, int arr[])
{
    static int* arrTemp(new int[size]);
    if (x >= size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arrTemp[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < arr[x]; i++)
    {
        arrTemp[x] = i;
        n_for_loop(x + 1, size, arr);
    }
}

int main()
{
    struct bundle{

        double * arr;

        bundle(int size) {

            arr = new double[size];

            for(int i = 0; i < size; i++) {

                arr[i] = i;
                // cout<<" [ "<< arr[i]<<" ] ";
            }
        }
    };
    bundle c(5);
    cout<< c.arr[4];
    return 0;
}