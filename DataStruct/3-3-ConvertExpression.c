#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char op;
    struct node *next;
} NODE;

// 返回栈顶元素
char top(NODE *stack)
{
    if (stack->next != NULL)
    {
        return stack->next->op;
    }
    else
    {
        return '\0';
    }
}
// 入栈
void push(NODE *stack, char op)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->op = op;
    temp->next = stack->next;
    stack->next = temp;
}
// 出栈
void pop(NODE *stack)
{
    if (stack->next != NULL)
    {
        NODE *temp = stack->next;
        stack->next = stack->next->next;
        free(temp);
    }
    else
    {
        return;
    }
}
// 定义各运算符的优先级
int priority(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else if (op == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}
// 比较各运算符的优先级
int cmp(char a, char b)
{
    /*
    输入：
        a 为栈中运算符，b 为新输入运算符
    输出：
        新输入的运算符的优先级低于栈顶元素 返回 1
        新输入的运算符的优先级高于栈顶元素 返回 0
    */
    int num_a = priority(a);
    int num_b = priority(b);
    if (num_a > num_b)
    {
        return 1;
    }
    else if(num_a < num_b)
    {
        return 0;
    }
    else
    {
        if(num_a != 3)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
// 中缀表达式转后缀表达式
void convert(NODE *stack, char op)
{
    if (op == '(')
    {
        push(stack, op);
    }
    else if (op == ')')
    {
        while (stack->next->op != '(')
        {
            printf("%c", top(stack));
            pop(stack);
        }
        pop(stack);
    }
    else if (op == '#')
    {
        while (stack->next != NULL)
        {
            printf("%c", top(stack));
            pop(stack);
        }
        free(stack);
    }
    else
    {
        if (cmp(top(stack), op) == 0) // 新输入运算符高于栈顶运算符的优先级
        {
            push(stack, op);
        }
        else // 新输入运算符低于栈顶运算符的优先级
        {
            do
            {
                printf("%c", top(stack));
                pop(stack);
            } while (cmp(top(stack), op) == 1);
            push(stack, op);
        }
    }
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        NODE *op_stack = (NODE *)malloc(sizeof(NODE));
        op_stack->next = NULL;
        char op;
        do
        {
            scanf("%c", &op);
            if ((op > 'A' - 1 && op < 'Z' + 1) || (op > 'a' - 1 && op < 'z' + 1))
            {
                printf("%c", op);
                continue;
            }
            else
            {
                convert(op_stack, op);
            }
        } while (op != '#');
        getchar();
        printf("\n");
    }
    return 0;
}
