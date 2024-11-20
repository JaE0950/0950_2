#include <stdio.h>

#define MAX_PRODUCTS 5

int stock[MAX_PRODUCTS] = { 0 }, sold[MAX_PRODUCTS] = { 0 }, inventory[MAX_PRODUCTS] = { 0 };

void add_stock() {
    int choice, id, quantity;

    printf("�԰���� �Է�: ��ü ��ǰ ���� �Է�(1), ���� ��ǰ �Է�(2)�� �����ϼ���: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        printf("��ü ��ǰ�� �԰� ������ �Է��ϼ��� (%d��):\n", MAX_PRODUCTS);
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            printf("��ǰ ID %d: ", i + 1);
            scanf_s("%d", &quantity);
            stock[i] += quantity;
            inventory[i] += quantity;
        }
    }
    else if (choice == 2) {
        printf("�԰��� ��ǰ ID�� �Է��ϼ��� (1~%d): ", MAX_PRODUCTS);
        scanf_s("%d", &id);
        if (id < 1 || id > MAX_PRODUCTS) {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
            return;
        }
        printf("��ǰ ID %d�� �԰� ������ �Է��ϼ���: ", id);
        scanf_s("%d", &quantity);
        stock[id - 1] += quantity;
        inventory[id - 1] += quantity;
    }
    else {
        printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
    }
}

void sell_product() {
    int choice, id, quantity;

    printf("�Ǹż��� �Է�: ��ü ��ǰ �Ǹŷ� �Է�(1), ���� ��ǰ �Է�(2)�� �����ϼ���: ");
    scanf_s("%d", &choice);

    if (choice == 1) {
        printf("��ü ��ǰ�� �Ǹ� ������ �Է��ϼ��� (%d��):\n", MAX_PRODUCTS);
        for (int i = 0; i < MAX_PRODUCTS; i++) {
            printf("��ǰ ID %d: ", i + 1);
            scanf_s("%d", &quantity);
            if (inventory[i] < quantity) {
                printf("��ǰ ID %d: ��� ����! ���� ���: %d\n", i + 1, inventory[i]);
            }
            else {
                sold[i] += quantity;
                inventory[i] -= quantity;
            }
        }
    }
    else if (choice == 2) {
        printf("�Ǹ��� ��ǰ ID�� �Է��ϼ��� (1~%d): ", MAX_PRODUCTS);
        scanf_s("%d", &id);
        if (id < 1 || id > MAX_PRODUCTS) {
            printf("�߸��� ��ǰ ID�Դϴ�.\n");
            return;
        }
        printf("��ǰ ID %d�� �Ǹ� ������ �Է��ϼ���: ", id);
        scanf_s("%d", &quantity);
        if (inventory[id - 1] < quantity) {
            printf("��ǰ ID %d: ��� ����! ���� ���: %d\n", id, inventory[id - 1]);
        }
        else {
            sold[id - 1] += quantity;
            inventory[id - 1] -= quantity;
            printf("�Ǹ� �Ϸ�. ���� ���: %d\n", inventory[id - 1]);
        }
    }
    else {
        printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
    }
}

void view_inventory() {
    printf("\n[��ǰ��Ȳ]\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("ID %d: ��� %d, �Ǹŷ� %d\n", i + 1, inventory[i], sold[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n[�޴�]\n1. �԰�\n2. �Ǹ�\n3. ��ǰ��Ȳ\n4. ����\n����: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1: add_stock(); break;
        case 2: sell_product(); break;
        case 3: view_inventory(); break;
        case 4: printf("���α׷� ����\n"); return 0;
        default: printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
}
