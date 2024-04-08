#include"list.h"

int main(void)
{
    printf("创建链表：\n");
    PNODE pHead = NULL;//定义头结点指针
    pHead = create_list();
    showmenu();
    int op = 0;

    do {

        scanf_s("%d", &op);
        switch (op) {
        case 1:system("cls");
            break;
        case 2: traverse_list(pHead);
            break;
        case 3: {
            int pos, val;
            printf("请依次输入插入的位置及数据\n");
            scanf_s("%d %d", &pos, &val);
            insert_list(pHead, pos, val);
        }
              break;
        case 4: {
            int pos;
            printf("请输入删除的位置");
            scanf_s("%d", &pos);
            int* pVal = NULL;
            if (delete_list(pHead, pos, pVal)) {
                printf("删除成功\n");
            }
            else {
                printf("删除失败\n");
            }
        }
              break;
        case 5: sort_list(pHead);
            break;
        default:break;

        }

    } while (op != -1);

    return 0;
}