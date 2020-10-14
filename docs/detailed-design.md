# 详细设计

stack *stackInit()  
初始化一个栈并获取它的结构指针

```c++
stack *stackInit()
{
    stack *ret = (stack *)malloc(sizeof(stack));
    ret->size = INIT_SIZE;
    ret->bot = (char *)malloc(sizeof(char) * INIT_SIZE);
    ret->top = 0;
    return ret;
}
```

char stackTop(stack *)  
获取栈顶

```c++
char stackTop(stack *s)
{
    return s->top == 0 ? '\0' : *(s->bot + s->top - 1);
}
```

void stackPop(stack *)  
去除栈顶

```c++
void stackPop(stack *s)
{
    if(...)//栈空直接退出
        //...
    //清除栈顶数据
    s->top--;
}
```

void stackPush(stack *, char)  
新元素入栈

```c++
void stackPush(stack *s, char c)
{
    //空间不足,重新申请空间
    {
        s->bot = (char *)realloc(s->bot, s->size + INCRE_SIZE);
        s->size += INCRE_SIZE;
    }
    //添加新元素
}
```

void stackFree(stack *)  
释放栈空间

```c++
void stackFree(stack *s)
{
    free(s->bot);
    free(s);
}
```

queue *queueInit()

初始化队列并获得指针

```c++
queue *queueInit()
{
    queue *ret = (queue *)malloc(sizeof(queue));
    ret->head = ret->tail = (node *)malloc(sizeof(node));
    ret->head->val = '\0';
    ret->tail->nxt = NULL;
    return ret;
}
```

char queueFront(queue *q)

获取队列头部元素

```c++
char queueFront(queue *q)
{
    return q->head->nxt == NULL ? '\0' : q->head->nxt->val;
}
```

bool queueEmpty(queue *q)

队列判空

```c++
bool queueEmpty(queue *q)
{
    return q->head->nxt == NULL;
}
```

void queuePop(queue *q)

去除队列头部元素

```c++
void queuePop(queue *q)
{
    if(队列为空)
        return;
    node *temp = q->head->nxt;
    if (q->tail == temp)
        q->tail = q->head;
    q->head->nxt = temp->nxt;
    free(temp);
}
```

void queuePush(queue *q, char c)

队尾插入新元素

```c++
void queuePush(queue *q, char c)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->val = c;
    q->tail->nxt = temp;
    temp->nxt = NULL;
    q->tail = temp;
}
```

void queueFree(queue *q)

释放队列空间

```c++
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
```

void work()

处理输入,判断回文串

```c++
void work()
{
    string s;
    stack *st = stackInit();
    queue *qu = queueInit();
    cout << "请输入字符串:";
    cin >> s;
    for (string::iterator iter = s.begin(); iter != s.end(); iter++)
    {
        //依次将字符压入栈和队列中
        if (*iter == '#')
            break;
        stackPush(st, *iter);
        queuePush(qu, *iter);
    }
    while (!stackEmpty(st) && !queueEmpty(qu))
    {
        //依次将字符出栈出队列,判断是否相等
        if (stackTop(st) != queueFront(qu))
        {
            cout << "不是回文串\n";
            return;
        }
        stackPop(st);
        queuePop(qu);
    }
    stackFree(st);
    queueFree(qu);
    cout << "是回文串\n";
}
```
