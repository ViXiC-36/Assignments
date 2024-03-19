#include<stdio.h>
#include<math.h>
int LENGTH(int x)
{
    int i = 0, inte = 9;
    while(inte != 0)
    {
        i += 1;
        inte = x/(pow(10,i));
    }
    return i;
}
int posnum(int x, int pos) // number of a particular position;
{
    int y;
    y = pow(10, pos);
    return (x % y / pow(10, pos - 1));
}
int main(){
    int x, p, length_p;
    scanf("%d", &p);
    length_p = LENGTH(p);
    x = posnum(p, 1);
    printf("%d %d", length_p, x);
    return 0;
    
    // long a, b;
    // scanf("%ld:%ld", &a, &b);
    // printf("%ld %ld", a,b);

}