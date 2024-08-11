#include<iostream>
using namespace std;

struct Test{
int A[5];
int n;
};

void fun(struct Test t1){
    t1.A[0]=10; //won't change original
    cout<<t1.A[0]<<endl;

}

// can we send struct by call by value ? yes
// can we send array by call by value ? no ,only by call by address

// juggad .....array inside stuct :



int main()
{
    /* code */
    struct Test t={{2,4,6,8,10},5};

    cout<<(t.A[0])<<endl;
    fun(t);
    cout<<(t.A[0])<<endl;
    return 0;
}
/*
PS C:\Users\Siddhant bali\BaliGit\balisalgorithm\ch1> cd "c:\Users\Siddhant bali\BaliGit\balisalgorithm\ch1\" ; if ($?) { g++ StrucAsParameter.cpp -o StrucAsParameter } ; if ($?) { .\StrucAsParameter }
2
10
2
PS C:\Users\Siddhant bali\BaliGit\balisalgorithm\ch1>

*/