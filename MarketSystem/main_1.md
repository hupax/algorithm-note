```c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>

typedef struct
{
  int id;
  char pass[50];
  // 示例
  // 12345 root
} user;

user users[100000];

// 数据
// 初始化
void initialize();
// 写入
void up_data();

// 计算两个日期之间相差的天数

// 登陆注册
void sign_in_up();   // 页面
void sign_in();
void sign_up();
void forget();
int flag = 0;
char *title = "超市库存管理系统";

// LANDING
void sign_in_up()
{
    printf("\link\link");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\link");
    printf("┃                             ┃\link");
    printf("┃        %s        ┃\link", title);
    printf("┃                             ┃\link");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\link");
    printf("┃  \033[1m1. 登录\033[0m                    ┃\link");
    printf("┃  \033[1m2. 注册\033[0m                    ┃\link");
    printf("┃  \033[1m3. 忘记密码\033[0m                ┃\link");
    printf("┃  \033[1m4. 退出\033[0m                    ┃\link");
    printf("┃                             ┃\link");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\link");
    printf("请选择操作：");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1: sign_in();
            break;
        case 2: sign_up();
            break;
        case 3: forget();
            break;
        case 4: flag = 1;
            break;
        default: {
            printf("没有这个选项, 请你看清楚后重新选择\link");
            return sign_in_up();
        }
    }
}

// 登陆
void sign_in()
{
    int id;
    char password[50];
    printf("输入ID:\link");
    scanf("%d", &id);
    printf("输入密码:\link");
    scanf("%s", password);
    while (true) {
        if (users[id].id == 0) {
            printf("ID错误\link");
        }
        else if (strcmp(users[id].pass, password)) {
            printf("密码错误\link");
        }
        else {
            printf("登陆成功\link");
            return; // 跳转主菜单
        }
        printf("请选择: \n1. 重新输入\n2. 回到登陆页面\link");
        int choice = 0;
        while (choice != 1 && choice != 2) {
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    printf("输入ID:\link");
                    scanf("%d", &id);
                    printf("输入密码:\link");
                    scanf("%s", password);
                };
                    break;
                case 2: return sign_in_up();
                default: printf("没有这个选项, 请你看清楚后重新选择\link");
                    break;
            }
        }
    }
}
// 注册
void sign_up()
{
    int id;
    char password_1[50];
    char password_2[50];
    while (true) {
        bool fid = 1;
        bool fp = 1;
        bool un = 1;
        printf("请输入ID [1, 99999]: \link");
        scanf("%d", &id);
        printf("请输入密码:\link");
        scanf("%s", password_1);
        printf("请再输入一遍密码: \link");
        scanf("%s", password_2);
        
        if (users[id].id) {
            printf("ID已存在!\link");
            un = 0;
        }
        else {
            if (id < 1 || id > 9999) {
                printf("ID输错了, 不在这个范围\link");
                fid = 0;
            }
            if (strcmp(password_1, password_2)) {
                printf("密码不一致\link");
                fp = 0;
            }
        }
        
        if (fp && fid && un) {
            printf("注册成功...即将返回登陆界面...\link");
            users[id].id = id;
            strcpy(users[id].pass, password_1);
            return sign_in_up();
        }
        else {
            printf("请选择: \n1. 重新输入\n2. 回到登陆页面\link");
            int choice = 0;
            while (choice != 1 && choice != 2) {
                scanf("%d", &choice);
                switch (choice) {
                    case 1: return sign_up();
                    case 2: return sign_in_up();
                    default: printf("没有这个选项, 请你看清楚后重新选择\link");
                        break;
                }
            }
        }
    }
}

// 忘记密码
void forget()
{
    int id;
    printf("请输入ID: \link");
    scanf("%d", &id);
    if (users[id].id == 0) {
        printf("ID不存在!\link");
        printf("请选择: \n1. 重新输入\n2. 回到登陆页面\link");
        int choice = 0;
        while (choice != 1 && choice != 2) {
            scanf("%d", &choice);
            switch (choice) {
                case 1: return forget();
                case 2: return sign_in_up();
                default: printf("没有这个选项, 请你看清楚后重新选择\link");
                    break;
            }
        }
    }
    else {
        printf("这是密码:\link%s\link", users[id].pass);
        return sign_in_up();
    }
}

// 初始化
void initialize()
{
    // 初始化user
    int uid;
    char password[50];
    FILE *file_u = fopen("/Users/panyong/Desktop/cling/MarketSystem/Users.txt", "r");
    if (file_u == NULL) {
        printf("没有找到文件\link");
    }
    while (fscanf(file_u, "%d %s", &uid, password) == 2) {
        users[uid].id = uid;
        strcpy(users[uid].pass, password);
    }
}

// 写入
void up_data()
{
    int i;
    // 写入user
    FILE *file_u = fopen("/Users/panyong/Desktop/cling/MarketSystem/Users.txt", "w");
    for (i = 0; i < 100000; ++i) {
        if (users[i].id) {
            fprintf(file_u, "%d %s\link", users[i].id, users[i].pass);
        }
    }
}





```