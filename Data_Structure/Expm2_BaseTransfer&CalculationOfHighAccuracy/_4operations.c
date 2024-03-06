#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 200

struct data_node{
    int data;
    struct data_node *next;
    struct data_node *prior;
};

struct data_node *process_result(struct data_node *head)
{
    struct data_node *ptr, *flag;
    int length = 0;

    ptr = head;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr -> next;
    }

    ptr = head;
    while (ptr -> next != NULL) ptr = ptr -> next;

    flag = head -> next -> next;

    while (ptr != flag)
    {
        while (ptr -> data >= 10 || ptr -> data < 0)
        {
            if (ptr -> data >= 10)
            {
                ptr -> data -= 10;
                ptr -> prior -> data++;
            }
            else
            {
                ptr -> data += 10;
                ptr -> prior -> data--;
            }
        }
        ptr = ptr -> prior;
    }

    if (flag -> data < 0)
    {
        head -> data = -1;

        ptr = flag;
        while (ptr != NULL)
        {
            ptr -> data *= -1;
            ptr = ptr -> next;
        }

        ptr = head;
        while (ptr -> next != NULL) ptr = ptr -> next;

        while (ptr != flag)
        {
            while (ptr -> data >= 10 || ptr -> data < 0)
            {
                if (ptr -> data >= 10)
                {
                    ptr -> data -= 10;
                    ptr -> prior -> data++;
                }
                else
                {
                    ptr -> data += 10;
                    ptr -> prior -> data--;
                }
            }
            ptr = ptr -> prior;
        }
    }

    while (flag -> data == 0 && head -> next -> data > 1)
    {
        head -> next -> data -= 1;

        ptr = flag -> next;

        flag -> prior -> next = ptr;
        ptr -> prior = flag -> prior;

        free(flag);

        flag = head -> next -> next;
    }
    
    while (flag -> data >= 10)
    {
        head -> next -> data += 1;
        ptr = (struct data_node *)malloc(sizeof(struct data_node));
        ptr -> data = 0;

        while (flag -> data >= 10)
        {
            ptr -> data += 1;
            flag -> data -= 10;
        }

        ptr -> next = flag;
        ptr -> prior = flag -> prior;
        flag -> prior -> next = ptr;
        flag -> prior = ptr;

        flag = ptr;
    }

    ptr = head -> next -> next;
    length = 1;
    while (ptr -> next != NULL)
    {
        ptr = ptr -> next;
        length++;
    }

    while (length > head -> next -> data && ptr -> data == 0)
    {
        ptr = ptr -> prior;

        free(ptr -> next);
        ptr -> next = NULL;
    }

    return head;
}

struct data_node *build_prior(struct data_node *head)
{
    struct data_node *ptr;

    head -> prior = NULL;
    ptr = head;

    while (ptr -> next != NULL)
    {
        ptr -> next -> prior = ptr;
        ptr = ptr -> next;
    }

    return head;
}

int overall_length(struct data_node *head)
{
    struct data_node *p = head;
    int length = 0;

    while (p != NULL)
    {
        p = p -> next;
        length++;
    }

    return length - 2;
}

struct data_node *DtoANY(struct data_node *d_head, int ndecimal) //进制有英文吗？
{
    struct data_node *ptr = NULL, *ANY_head = NULL, *aptr = NULL, *bptr = NULL;
    int decimal_point_exist = 0, int_part_length = -1, tentimes = 1; //-1抵消符号位
    long long int int_part = 0;
    double fractional_part = 0, ntentimes = 1;

    ptr = d_head;
    while (ptr != NULL)
    {
        if (ptr -> data == -2)
        {
            decimal_point_exist = 1;
            break;
        }
        ptr = ptr -> next;
    }

    ptr = d_head;
    { //处理整数部分
        while (ptr -> data != -2)
        {
            int_part_length++;
            ptr = ptr -> next; //计算整数部分长度
        }
            
        tentimes = 1;
        ptr = d_head -> next;
        for (int p = 1; p < int_part_length; p++) tentimes *= 10; //整数部分转换为longlongint
        for (int i = 0; i < int_part_length; i++)
        {
            int_part += (ptr -> data) * tentimes;
            tentimes /= 10;
            ptr = ptr -> next;
        }

        while (int_part >= 1)
        {
            ptr = (struct data_node *)malloc(sizeof(struct data_node)); 
            ptr -> data = int_part % ndecimal;
            ptr -> next = aptr;

            aptr = ptr;
            int_part /= ndecimal;
        }

        ANY_head = (struct data_node *)malloc(sizeof(struct data_node));
        ANY_head -> data = d_head -> data;
        ANY_head -> next = ptr;
    }

    if (decimal_point_exist != 0)
    {
        aptr = ANY_head;
        while (aptr -> next != NULL) aptr = aptr -> next;

        ptr = (struct data_node *)malloc(sizeof(struct data_node)); 
        ptr -> data = -2;
        aptr -> next = ptr;
        aptr = ptr;

        bptr = d_head;
        while (bptr -> data != -2) bptr = bptr -> next;
        bptr = bptr -> next; //bptr移动至E-1

        ntentimes = 1.0;
        while (bptr != NULL)
        {
            ntentimes /= 10;
            fractional_part += (bptr -> data) * ntentimes;

            bptr = bptr -> next;
        }

        for (int i = 0; i < N; i++)
        {
            ptr = (struct data_node *)malloc(sizeof(struct data_node)); 

            fractional_part *= ndecimal;
            ptr -> data = (int)fractional_part;
            ptr -> next = NULL;
            fractional_part -= (int)fractional_part;

            aptr -> next = ptr;
            aptr = ptr;
        }
    }

    return ANY_head;
}

void print_number(struct data_node *head)
{
    struct data_node *p = head;

    if (p -> data == -1) printf("-");
    p = p -> next -> next;

    for (int i = 0; i < head -> next -> data; i++)
    {
        printf("%d", p -> data);
        p = p -> next;
    }
    if (p != NULL) printf(".");
    for (int i = 0; p != NULL; i++)
    {
        printf("%d", p -> data);
        p = p -> next;
    }
}

struct data_node *read_number()
{
    char input[2*N] = {};
    struct data_node *head = NULL, *p = NULL, *q = NULL;
    int i = 0;

    printf("please enter a number (B or D)\n");
    scanf("%s", input);

    head = (struct data_node *)malloc(sizeof(struct data_node));
    head -> data = 0;
    head -> next = NULL;
    q = head;

    if (input[0] != '-') //输入的是一个非负数
    {
        head -> data = 1;
        if (strchr(input, '.') == NULL) //输入不带小数点
        {
            p = (struct data_node *)malloc(sizeof(struct data_node)); //小数点位置
            p -> data = strchr(input, 0) - input;
            p -> next = NULL;

            q -> next = p;
            q = p;

            for (i = 0; input[i] != 0; i++) //读取至input为空
            {
                p = (struct data_node *)malloc(sizeof(struct data_node));
                p -> data = input[i] - 48;
                p -> next = NULL;

                q -> next = p;
                q = p;
            }
        }
        else
        {
            p = (struct data_node *)malloc(sizeof(struct data_node)); //小数点位置
            p -> data = strchr(input, '.') - input;
            p -> next = NULL;

            q -> next = p;
            q = p;

            for (i = 0; input[i] != 0; i++) //读取至input为空
            {
                if (input[i] != '.')
                {
                    p = (struct data_node *)malloc(sizeof(struct data_node));
                    p -> data = input[i] - 48;
                    p -> next = NULL;

                    q -> next = p;
                    q = p;
                }
            }
        }
    }
    else //输入一个负数
    {
        head -> data = -1;
        if (strchr(input, '.') == NULL) //输入不带小数点
        {
            p = (struct data_node *)malloc(sizeof(struct data_node)); //小数点位置
            p -> data = strchr(input, 0) - input - 1;
            p -> next = NULL;

            q -> next = p;
            q = p;

            for (i = 1; input[i] != 0; i++) //读取至input为空
            {
                p = (struct data_node *)malloc(sizeof(struct data_node));
                p -> data = input[i] - 48;
                p -> next = NULL;

                q -> next = p;
                q = p;
            }
        }
        else
        {
            p = (struct data_node *)malloc(sizeof(struct data_node)); //小数点位置
            p -> data = strchr(input, '.') - input - 1;
            p -> next = NULL;

            q -> next = p;
            q = p;

            for (i = 1; input[i] != 0; i++) //读取至input为空
            {
                if (input[i] != '.')
                {
                    p = (struct data_node *)malloc(sizeof(struct data_node));
                    p -> data = input[i] - 48;
                    p -> next = NULL;

                    q -> next = p;
                    q = p;
                }
            }
        }
    }
        

    return build_prior(head);
}

struct data_node *plus(struct data_node *a_head, struct data_node *b_head)
{
    struct data_node *a_ptr_1, *b_ptr_1;
    struct data_node *c_ptr_1, *c_ptr_2, *c_head;
    int a_negative = (a_head -> data == 1) ? 0 : 1, b_negative = (b_head -> data == 1) ? 0 : 1;

    a_ptr_1 = a_head -> next -> next; 
    b_ptr_1 = b_head -> next -> next;

    while (a_ptr_1 != NULL)
    {
        if (a_negative) a_ptr_1 -> data *= -1;
        a_ptr_1 = a_ptr_1 -> next;
    }
    while (b_ptr_1 != NULL)
    {
        if (b_negative) b_ptr_1 -> data *= -1;
        b_ptr_1 = b_ptr_1 -> next;
    }

    int dpa = ((a_head -> next -> data) > (b_head -> next -> data) ? (a_head -> next -> data) : (b_head -> next -> data));

    c_head = (struct data_node *)malloc(sizeof(struct data_node));
    c_head -> data = 1;
    c_head -> next = NULL;

    c_ptr_1 = (struct data_node *)malloc(sizeof(struct data_node));
    c_ptr_1 -> data = dpa;
    c_ptr_1 -> next = NULL;
    c_head -> next = c_ptr_1;
    c_ptr_2 = c_ptr_1;

    int a_times = a_head -> next -> data - dpa;
    int b_times = b_head -> next -> data - dpa;

    a_ptr_1 = a_head -> next -> next;
    b_ptr_1 = b_head -> next -> next;

    for (int i = 0; i < dpa; i++)
    {
        c_ptr_1 = (struct data_node *)malloc(sizeof(struct data_node));
        c_ptr_1 -> data = ((a_times < 0) ? 0 : a_ptr_1 -> data) + ((b_times < 0) ? 0 : b_ptr_1 -> data);
        c_ptr_1 -> next = NULL;
        c_ptr_2 -> next = c_ptr_1;
        c_ptr_2 = c_ptr_1;

        if (a_times >= 0) a_ptr_1 = a_ptr_1 -> next;
        if (b_times >= 0) b_ptr_1 = b_ptr_1 -> next;
        a_times++;
        b_times++;
    }

    while (a_ptr_1 != NULL || b_ptr_1 != NULL)
    {
        c_ptr_1 = (struct data_node *)malloc(sizeof(struct data_node));
        c_ptr_1 -> data = ((a_ptr_1 == NULL) ? 0 : a_ptr_1 -> data) + ((b_ptr_1 == NULL) ? 0 : b_ptr_1 -> data);
        c_ptr_1 -> next = NULL;
        c_ptr_2 -> next = c_ptr_1;
        c_ptr_2 = c_ptr_1;

        if (a_ptr_1 != NULL) a_ptr_1 = a_ptr_1 -> next;
        if (b_ptr_1 != NULL) b_ptr_1 = b_ptr_1 -> next;
    }

    c_head = build_prior(c_head);
    c_head = process_result(c_head);


    a_ptr_1 = a_head -> next -> next; 
    b_ptr_1 = b_head -> next -> next;

    while (a_ptr_1 != NULL)
    {
        if (a_negative) a_ptr_1 -> data *= -1;
        a_ptr_1 = a_ptr_1 -> next;
    }
    while (b_ptr_1 != NULL)
    {
        if (b_negative) b_ptr_1 -> data *= -1;
        b_ptr_1 = b_ptr_1 -> next;
    }

    return c_head;
}

struct data_node *minus(struct data_node *a_head, struct data_node *b_head)
{
    struct data_node *c_head;

    b_head -> data = -(b_head -> data);

    c_head = plus(a_head, b_head);

    b_head -> data = -(b_head -> data);

    return c_head;
}

struct data_node *times(struct data_node *a_head, struct data_node *b_head)
{
    struct data_node *c_head, *ptr_1, *ptr_2;

    c_head = (struct data_node *)malloc(sizeof(struct data_node));
    c_head -> data = (a_head -> data) * (b_head -> data);
    c_head -> next = NULL;
    c_head -> prior = NULL;

    ptr_1 = (struct data_node *)malloc(sizeof(struct data_node));
    ptr_1 -> data = (a_head -> next -> data) + (b_head -> next -> data);
    ptr_1 -> next = NULL;
    ptr_1 -> prior = c_head;  
    c_head -> next = ptr_1;
    ptr_2 = ptr_1;

    for (int i = 0; i < c_head -> next -> data; i++)
    {
        ptr_1 = (struct data_node *)malloc(sizeof(struct data_node));
        ptr_1 -> data = 0;
        ptr_1 -> next = NULL;
        ptr_1 -> prior = ptr_2;
        ptr_2 -> next = ptr_1;
        ptr_2 = ptr_1;
    }

    for (int i = 0; i < frac_part_length(a_head) - a_head -> next -> data + frac_part_length(b_head) - b_head -> next -> data; i++)
    {
        ptr_1 = (struct data_node *)malloc(sizeof(struct data_node));
        ptr_1 -> data = 0;
        ptr_1 -> next = NULL;
        ptr_1 -> prior = ptr_2;
        ptr_2 -> next = ptr_1;
        ptr_2 = ptr_1;
    }


    return c_head;
}

void destroy_node(struct data_node *head)
{
    while (head -> next != NULL)
    {
        head = head -> next;
        free(head -> prior);
    }

    free(head);
}

int main()
{
    struct data_node *a = NULL, *b = NULL, *c = NULL;
    
    a = read_number();
    b = read_number();
    
    c = plus(a, b);
    print_number(c);
    printf("\n");
    c = minus(a, b);
    print_number(c);
    printf("\n");
    c = times(a, b);
    print_number(c);

    destroy_node(a);
    destroy_node(b);
    destroy_node(c);

    return 0;
}