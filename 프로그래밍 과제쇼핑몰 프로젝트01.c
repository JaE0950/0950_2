#include <stdio.h>
#define MAX_PRODUCTS 100

int main() {
    int num;
    int jego;
    int ipgo;
    int pan;
    int id;
    int cho;
    int i;
    int stock[MAX_PRODUCTS];
    void inven(int stock[], int num_products);


    printf("��ǰ ������ ������ �Է��ϼ��� (1-100): ");
    scanf_s("%d", &num);
    if (num < 1 || num > 100) {
        printf("��ǰ ������ ������ 1���� 100 ���̿��� �մϴ�.\n");
        return 0;
    }

    printf("�� ��ǰ�� �԰� ������ �Է��ϼ���:\n");
    for (i = 0; i < num; i++) {
        printf("��ǰ %d�� �԰� ����: ", i + 1);
        scanf_s("%d", &ipgo);
        stock[i] = ipgo;  
    }
    
    printf("�� ��ǰ�� �Ǹ� ������ �Է��ϼ���:\n");
    for (i = 0; i < num; i++) {
        printf("��ǰ %d�� �Ǹ� ����: ", i + 1);
        scanf_s("%d", &pan);
        stock[i] -= pan;
    }

    
    printf("��� Ȯ���� ��ǰ�� ID�� �Է��ϼ��� (1-%d): ", num);
    scanf_s("%d", &id);

    
    if (id < 1 || id > num) {
        printf("��ȿ���� ���� ��ǰ ID�Դϴ�.\n");
        return 0;
    }
   
    cho = id - pan;
    printf("��ǰ %d�� ��� ����: %d\n", id, stock[id - 1]);

   
    inven(stock, num);

    return 0;
}


void inven(int stock[], int num_products) {
    int total_stock = 0;
    printf("��ü ��� ����:\n");
    for (int i = 0; i < num_products; i++) {
        printf("��ǰ %d: %d\n", i + 1, stock[i]);
        total_stock += stock[i];
    }
    printf("��ü ��� ����: %d\n", total_stock);
}

