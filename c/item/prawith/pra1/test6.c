typedef struct people
{
    people *person;
    char i[10];
}
people


int main(int argc,char *argv[])
{
    // suppose that input 3 nums
    people *n = NULL;       //
    for (i = 1;i < argc;i++)
    {
        people *m = malloc(sizeof(people));
        if (m == NULL)
        {
            return 1;
        }
        m->person = n;
        strcpy(m->i,argv[i]);
        n = m;
    }
    people *p = n;
    while(p != NULL)
    {
        printf("%s",p->i);
        p = p->person;
    }
    p = n;
    while(p != NULL)
    {
        people *a = p;
        p = p->person;
        free(a);
    }

}


typedef struct person
{
    person *p1;
    person *p2;
    int i;
}


// 二叉树
bool search(person *p,int i)
{
    if (p == NULL)
    {
        return false;
    }
    else if (p->i > i)
    {
        search(p->p1,i);
    }
    else if (p->i > i)
    {
        search(p->p2,i);
    }
    else if (p->i == i)
    {
        return ture;
    }
}














//在函数内malloc（的空间），并将其返回值赋值给定义在函数内部的变量，函数必须返回该变量                             必须将这个指针返回
//在主函数内创建根节点 其余均利用  创建
