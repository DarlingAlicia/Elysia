#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int flag,i,j;
    int nums[3][2] = { {0,-2},{120,1},{240,4} };
    int com[3][3]= { {1,1,0},{0,1,1},{1,0,1} };
    int k[3];
    cout << "请输入从内到外圆环与天轴的顺时针夹角（0度~360度，如：0 120 180）：" << endl;
    for ( i = 0; i < 3; i++)
    {
        cin >> nums[i][0];
    }
    cout << "请输入从内到外圆环上星位数（顺时针正数，逆时针负数如：2 -1 3）：" << endl;
    for (i = 0; i < 3; i++)
    {
        cin >> nums[i][1];
    }
    cout << "请输入从3个圆环组合（如从内到外依次为例如最里面和中间：1 1 0）：" << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
        {
            cin >>com[i][j];
        }
    }
    for (k[0]=0; k[0] <10; k[0]++)
    {
        for (k[1] = 0; k[1] <10; k[1] ++)
        {
            for (k[2] = 0; k[2] < 10; k[2] ++)
            {
                flag = 0;
                for ( i = 0; i < 3; i++) {
                    if (abs(nums[i][0]+ nums[i][1]*k[0]*com[0][i]*60 + nums[i][1] * k[1] * com[1][i] * 60 + nums[i][1] * k[2] * com[2][i] * 60)%360==0) {
                        flag++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (flag == 3)
                {
                    for (i = 0; i < 3; i++) {
                        cout << "组合" << i + 1 << "转动次数: " << k[i] << endl;
                    }
                }
            }
        }
    }
}
