#include <cstdio>
#include <iostream>
#include <string>

#define INIT_SIZE 50
#define INCRE_SIZE 10

using namespace std;

// 栈
typedef struct Stack
{
    char *bot;
    int top;
    int size;

} stack;

stack *stackInit();            // 获取一个栈
char stackTop(stack *);        // 获取栈顶
bool stackEmpty(stack *);      // 判断栈空
void stackPop(stack *);        // 去除栈顶
void stackPush(stack *, char); // 新元素入栈
void stackFree(stack *);       // 删除栈

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

queue *queueInit();            // 获取一个队列
char queueFront(queue *);      // 获取队头元素
bool queueEmpty(queue *);      // 判断队空
void queuePop(queue *);        // 去除队头
void queuePush(queue *, char); // 队尾添加
void queueFree(queue *);       // 删除队列

void work();

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

stack *stackInit()
{
    stack *ret = (stack *)malloc(sizeof(stack));
    ret->size = INIT_SIZE;
    ret->bot = (char *)malloc(sizeof(char) * INIT_SIZE);
    ret->top = 0;
    return ret;
}

char stackTop(stack *s)
{
    return s->top == 0 ? '\0' : *(s->bot + s->top - 1);
}

bool stackEmpty(stack *s)
{
    return s->top == 0;
}

void stackPop(stack *s)
{
    if (s->top == 0)
        return;
    *(s->bot + s->top - 1) = '\0';
    s->top--;
}

void stackPush(stack *s, char c)
{
    if (s->top >= s->size)
    {
        s->bot = (char *)realloc(s->bot, s->size + INCRE_SIZE);
        s->size += INCRE_SIZE;
    }
    s->bot[s->top++] = c;
}

void stackFree(stack *s)
{
    free(s->bot);
    free(s);
}

queue *queueInit()
{
    queue *ret = (queue *)malloc(sizeof(queue));
    ret->head = ret->tail = (node *)malloc(sizeof(node));
    ret->head->val = '\0';
    ret->tail->nxt = NULL;
    return ret;
}

char queueFront(queue *q)
{
    return q->head->nxt == NULL ? '\0' : q->head->nxt->val;
}

bool queueEmpty(queue *q)
{
    return q->head->nxt == NULL;
}

void queuePop(queue *q)
{
    if (q->head->nxt == NULL)
        return;
    node *temp = q->head->nxt;
    if (q->tail == temp)
        q->tail = q->head;
    q->head->nxt = temp->nxt;
    free(temp);
}

void queuePush(queue *q, char c)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = c;
    q->tail->nxt = temp;
    temp->nxt = NULL;
    q->tail = temp;
}

void queueFree(queue *q)
{
    node *temp = q->head;
    node *pre;
    while (temp != NULL)
    {
        pre = temp;
        temp = temp->nxt;
        free(pre);
    }
    free(q);
}

void work()
{
    string s;
    stack *st = stackInit();
    queue *qu = queueInit();
    cout << "请输入字符串:";
    cin >> s;
    for (string::iterator iter = s.begin(); iter != s.end(); iter++)
    {
        if (*iter == '#')
            break;
        stackPush(st, *iter);
        queuePush(qu, *iter);
    }
    while (!stackEmpty(st) && !queueEmpty(qu))
    {
        if (stackTop(st) != queueFront(qu))
        {
            cout << "不是回文串\n";
            return;
        }
        stackPop(st);
        queuePop(qu);
    }
    cout << "是回文串\n";
}
