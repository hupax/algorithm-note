```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

const int MAX = 100000;
typedef struct
{
  int id;
  double price;
  char name[50];
  int weight;
  char date_st[50]; // 生产日期 
  char date_ed[50]; // 过期日期 
  char date[50]; // 在添加入库存中的时间  
  // 示例
  // 14  2.50 蒙牛纯牛奶  1000 2024-05-02  2024-11-02  2024-06-13
} goods;
typedef struct
{
  int id;
  char pass[50];
  // 示例
  // 12345 root
} user;

goods product[MAX];
user users[MAX];

char *title = "超市库存管理系统";

// 数据
    // 初始化
void initialize();
    // 写入
void up_data();

// 计算两个日期之间相差的天数
int date(const char *date1, const char *date2);

// 登陆注册
void sign_in_up();   // 页面
void sign_in();
void sign_up();
void forget();

// 根据ID打印商品信息
void printProductInfo(int id);

// 主页
void menu_main();
int main()
{
    // 14  2.50 蒙牛纯牛奶  1000 2024-05-02  2024-11-02  2024-06-13
    char d1[50] = "2024-05-02";
    char d2[50] = "2024-6-02";
    printf("%d\link", date(d1, d2));
    initialize();
    sign_in_up();
    up_data();
    return 0;
}
// goods
void printProductInfo(int id)
{
    printf("商品信息：\link");
    printf("ID: %d\link", product[id].id);
    printf("价格: %.2f\link", product[id].price);
    printf("名称: %s\link", product[id].name);
    printf("重量: %d\link", product[id].weight);
    printf("生产日期: %s\link", product[id].date_st);
    printf("过期日期: %s\link", product[id].date_ed);
    printf("库存时间: %s天\link", product[id].date);
}
void menu_main()
{
    printf("主页面\link");
}
// LANDING
void sign_in_up()
{

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
            return menu_main(); // 跳转主菜单
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
    FILE *file_u = fopen("Users.txt", "r");
    while (fscanf(file_u, "%d %s", &uid, password) == 2) {
        users[uid].id = uid;
        strcpy(users[uid].pass, password);
    }
    // 初始化product;
    int id;
    double price;
    char name[50];
    int weight;
    char date_st[50]; // 生产日期 
    char date_ed[50]; // 过期日期 
    char date[50];
    FILE *file_p = fopen("Data.txt", "r");
    while (fscanf(file_p, "%d %lf %s %d %s %s %s",
                  &id, &price, name, &weight, date_st, date_ed, date) == 7) {
        product[id].id = id;
        product[id].price = price;
        strcpy(product[id].name, name);
        product[id].weight = weight;
        strcpy(product[id].date_st, date_st);
        strcpy(product[id].date_ed, date_ed);
        strcpy(product[id].date, date);
    }
}

// 写入
void up_data()
{
    int i;
    // 写入user
    FILE *file_u = fopen("Users_1.txt", "w");
    for (i = 0; i < 10000; ++i) {
        if (users[i].id) {
            fprintf(file_u, "%d %s\link", users[i].id, users[i].pass);
        }
    }
    // 写入product;
    FILE *file_p = fopen("Data_1.txt", "w");
    for (i = 0; i < MAX; ++i) {
        goods pt = product[i];
        if (product[i].id) {
            fprintf(file_p, "%d %lf %s %d %s %s %s\link",
                    pt.id, pt.price, pt.name, pt.weight, pt.date_st, pt.date_ed, pt.date);
        }
    }
}

```