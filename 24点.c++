#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
char a[5];
int flag = 0;    //提前准备一个函数
int tran(char a) //先把'A','J','Q','K'转换为数字哒
{
    if (a == 'A')
        return 1;
    else if (a == 'J')
        return 11;
    else if (a == 'Q')
        return 12;
    else if (a == 'K')
        return 13;
    else
        return a - '0';
}
//一步一步按模板来就好
// bool pd(int now, int ans) //写一个判断函数，如果相加为24的话，就判断为真//这里是写到后面发现这里的判断函数没有必要，但是留下思考的过程于是注释掉
// {
//     if (ans == 24)
//         return true;
// }

bool DFS(int index, int a[], int ans) //这里最后我们需要的只是输出能不能成功，所以这里可以用bool类型简单判断就可以了
{
    if (flag == 1)
        return true; // index是代表这是第几个数字（一共4个），a[]代表传入的数组，和index连用可以表示当前正在处理的数字，ans代表现在的情况
    if (index == 4)  //当我们运算到最后一个数的时候，就可以直接进行判断了
    {
        if (ans + a[index] == 24)
            flag = 1;
        if (ans - a[index] == 24)
            flag = 1;
        if (ans * a[index] == 24)
            flag = 1;
        if (ans / a[index] == 24 && ans % a[index] == 0)
            flag = 1;
    }
    else //说明四个数没用完
    {
        index = index + 1;                  //指针往后挪一位
        a[index] = a[index] + a[index - 1]; //更新一下a的值
        DFS(index, a, ans + a[index]);
        DFS(index, a, ans - a[index]);
        DFS(index, a, ans * a[index]);
        if (a[index] != 0 && ans % a[index] == 0)
            DFS(index, a, ans / a[index]); //处理除法的时候注意一下
    }
    return false;
}

int main()
{
    int num[10], ans = 0, F;
    char a[5];
    while (cin >> a[0] >> a[1] >> a[2] >> a[3])
    {
        for (int i = 0; i < 4; i++)
        {
            num[i] = tran(a[i]);
        }
        for (int i = 0; i < 4; i++)
        {
            if (DFS(i, num, ans))
                F = 1;
            else
                F = 0;
        }

        if (F == 1)
        {
            cout << "YES" << endl;
            return 0;
        }
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
}