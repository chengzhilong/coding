/**
 * (Tencent IEG, 5-10)
 * 输出和为1个给定整数的所有组合，相加的数不能重复
 * 例如n=6
 * 6=1+5; 6=2+4; 6=1+2+3.
 * 则输出
 * 1, 5; 2, 4; 1, 2, 3.
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define MAX_NUM 100

int array[MAX_NUM] = {0};
int n;

void print(vector<int> &vect)
{
    for (size_t i = 0; i < vect.size() - 1; i++) {
        printf("%d, ", vect[i]);
    }
    printf("%d; ", vect[vect.size() - 1]);
    printf("\n");
}

void f(int left_value, vector<int> &vect, int start)
{
    if (left_value < 0 || ((left_value > 0) && (left_value < start))) {
        return ;
    }
    else if (left_value == 0) {
        print(vect);
    } else {
        for (int i = start; i < n; i++) {
            if (left_value >= i && array[i]==0)
            {
                vect.push_back(i);
                array[i] = 1;
                f(left_value - i, vect, i + 1);
            }
            else
                f(left_value, vect, i + 1);

            if (array[i] == 1) {
                array[i] = 0;
                vect.pop_back();
            }
        }
    }
}

int main()
{
    vector<int> vect;
    scanf("%d", &n);
    f(n, vect, 1);
    return 0;
}
