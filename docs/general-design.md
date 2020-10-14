# 概要设计

## 功能思路

根据栈的FILO,队列的FIFO特性,可以将字符串分别压入栈和队列再逐个取出,判断出栈和出队的序列是否相等

## 数据结构类型定义

```c++
typedef struct Stack
{
    char *bot; //栈底
    int top;   //栈顶
    int size;  //栈大小

} stack;

// 队列
typedef struct Node
{
    struct Node *nxt;
    char val;
} node;

typedef struct Queue
{
    node *head;
    node *tail;
    int size;
} queue;
```

## 主程序流程

```c++
int main()
{
    int arg;
    do
    {
        cout << "请输入功能选项\n1.判断回文串\n0.结束程序\n选项:";
        cin >> arg;
        switch (arg)
        {
        case 1:
            work();
            break;
        case 0:
            cout << "感谢使用\n";
            break;
        default:
            cout << "无效的选项\n";
            break;
        }
    } while (arg);
    return 0;
}
```

## 函数调用关系

main()调用work(),work()调用stackInit(),queueInit(),stackPush(),queuePush(),stackTop(),queueTop(),stackPop(),queuePop(),stackFree(),queueFree()
