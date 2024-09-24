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

struct stu
{
  int id;
  char name[50];
  char place[50];
  int number;
  int price;
};
struct stu str[1000];
int choose_number;//用于操作选项的数字
int n = 0;//表示库里有多少商品

void wel_come();//欢迎页面
void choo_se00();//选择菜单
void choo_se01();//新购商品入库
void choo_se02();//物品信息删除
void choo_se03();//物品信息修改
void choo_se04();//物品信息查询
void choo_se05();//物品信息浏览
void choo_se06();//程序颜色更改
void choo_se07();//应用程序退出

int main()
{
    initialize();
    sign_in_up();
    up_data();
    if (flag) return printf("正在退出..."),0;
    memset(str, 0, sizeof(str));
    str[0].id = 1;
    strcpy(str[0].name, "苹果");
    strcpy(str[0].place, "烟台");
    str[0].number = 20;
    str[0].price = 3;
    n++;
    wel_come();
    choo_se00();
    while (1) {
        printf("请输入下一步操作\n");
        scanf("%d", &choose_number);
        if (choose_number == 7) {
            system("cls");
            choo_se07();
        }
        if (choose_number == 1) {
            system("cls");
            choo_se01();
        }
        if (choose_number == 2) {
            system("cls");
            choo_se02();
        }
        if (choose_number == 3) {
            system("cls");
            choo_se03();
        }
        if (choose_number == 4) {
            system("cls");
            choo_se04();
        }
        if (choose_number == 5) {
            system("cls");
            choo_se05();
        }
        if (choose_number == 6) {
            system("cls");
            choo_se06();
        }
        system("cls");
        choo_se00();
    }
    return 0;
}
//1欢迎页面
void wel_come()
{
    char a[14][100] = {
        "***************************************************************************************",
        "*                                                                                     *",
        "*                                       欢迎使用                                      *",
        "*                                                                                     *",
        "*-------------------------------------------------------------------------------------*",
        "*                                                                                     *",
        "*                                                                                     *",
        "*                                     超市库管理系统                                  *",
        "*                                                                                     *",
        "*-------------------------------------------------------------------------------------*",
        "*                                                                                     *",
        "*                                      按任意键退出                                   *",
        "*                                                                                     *",
        "***************************************************************************************"
    };
    int i;
    for (i = 0; i < 3; i++) {
        printf("\n");
    }
    for (i = 0; i < 14; i++) {
        printf("                  ");
        printf("%s\n", a[i]);
    }
    getchar();
    system("cls");
}
//2菜单页面
void choo_se00()
{
    int i;
    for (i = 0; i < 3; i++) {
        printf("\n");
    }
    char b[10][100] = {
        "         *******************************【超市库存管理系统】*************************************",
        "         *----------------------------------系统菜单如下---------------------------------------**",
        "         **1====================【          新购商品入库          】===========================**",
        "         **2====================【          物品信息删除          】===========================**",
        "         **3====================【          物品信息修改          】===========================**",
        "         **4====================【          物品信息查询          】===========================**",
        "         **5====================【          物品信息浏览          】===========================**",
        "         **6====================【          系统颜色更改          】===========================**",
        "         **7====================【          应用程序退出          】===========================**",
        "         ****************************************************************************************"
    };
    for (i = 0; i < 10; i++)
        printf("%s\n", b[i]);
}
//3入库
void choo_se01()
{
    printf("物品的编号：\n");
    printf("物品的名称：\n");
    printf("物品的产地：\n");
    printf("物品的数量：\n");
    printf("物品的单价：\n");
    scanf("%d %s %s %d %d", &str[n].id, str[n].name, str[n].place, &str[n].number, &str[n].price);
    n++;
    printf("物品信息已入库成功！");
    printf("是否要继续入库！(y=是,其余是否)\n");
    char a;
    getchar();
    a = getchar();
    while (a == 'y') {
        scanf("%d %s %s %d %d",
              &str[n].id,
              str[n].name,
              str[n].place,
              &str[n].number,
              &str[n].price);
        n++;
        printf("物品信息已入库成功！");
        printf("是否要继续入库！(y=是,其余是否)\n");
        getchar();
        a = getchar();
    }
    system("cls");
    return;
}
//4删除
void choo_se02()
{
    printf("请输入要删除商品名字\n");
    char a = 'y';
    while (a == 'y') {
        char arr[50];
        getchar();
        scanf("%s", arr);
        int i, j = 0;
        for (i = 0; i < n; i++) {
            if (!strcmp(arr, str[i].name)) {
                memset(&str[i], 0, sizeof(str[i]));
                printf("删除成功\n");
                j++;
            }
        }
        if (!j) {
            printf("输入出错\n");
        }
        getchar();
        printf("是否要继续删除(y等于是，其余等于否)\n");
        scanf("%c", &a);
    }
    return;
}
//修改
void choo_se03()
{
    printf("请输入要修改商品名字\n");
    char a = 'y';
    while (a == 'y') {
        char arr[50];
        getchar();
        scanf("%s", arr);
        int i, j = 0;
        for (i = 0; i < n; i++) {
            if (!strcmp(arr, str[i].name)) {
                printf("物品的编号:%d  物品的名称:%s  物品的产地:%s  物品的数量:%d  物品的单价:%d\n",
                       str[i].id,
                       str[i].name,
                       str[i].place,
                       str[i].number,
                       str[i].price);
                j++;
                printf("请选择要修改的选项(1物品的编号 2物品的名称 3物品的产地 4物品的数量 5物品的单价 6退出该商品信息修改)\n");
                while (1) {
                    int k;
                    getchar();
                    scanf("%d", &k);
                    if (k == 1) {
                        printf("请修改物品的编号：\n");
                        getchar();
                        scanf("%d", &str[i].id);
                    }
                    if (k == 2) {
                        char arr[50];
                        printf("请修改物品的名称：\n");
                        getchar();
                        scanf("%s", arr);
                        strcpy(str[i].name, arr);
                    }
                    if (k == 3) {
                        char arr[50];
                        printf("请修改物品的产地：\n");
                        getchar();
                        scanf("%s", arr);
                        strcpy(str[i].place, arr);
                    }
                    if (k == 4) {
                        printf("请修改物品的数量：\n");
                        getchar();
                        scanf("%d", &str[i].number);
                    }
                    if (k == 5) {
                        printf("请修改物品的单价：\n");
                        getchar();
                        scanf("%d", &str[i].price);
                    }
                    if (k == 6)
                        break;
                    printf("请继续选择修改其他选项或者退出\n");
                }
            }
        }
        if (!j) {
            printf("输入出错\n");
        }
        printf("是否要修改其他商品(y等于是，其余等于否)\n");
        getchar();
        scanf("%c", &a);
    }
    return;
}
//查询
void choo_se04()
{
    printf("请输入要查询商品名字\n");
    char a = 'y';
    while (a == 'y') {
        char arr[50];
        getchar();
        scanf("%s", arr);
        int i, j = 0;
        for (i = 0; i < n; i++) {
            if (!strcmp(arr, str[i].name)) {
                printf("物品的编号:%d  物品的名称:%s  物品的产地:%s  物品的数量:%d  物品的单价:%d\n",
                       str[i].id,
                       str[i].name,
                       str[i].place,
                       str[i].number,
                       str[i].price);
                j++;
            }
        }
        if (!j) {
            printf("输入出错\n");
        }
        getchar();
        printf("是否要继续查询(y等于是，其余等于否)\n");
        scanf("%c", &a);
    }
    return;
}
//浏览
void choo_se05()
{
    int i;
    for (i = 0; i < n; i++) {
        if (str[i].id != 0)
            printf("物品的编号:%d  物品的名称:%s  物品的产地:%s  物品的数量:%d  物品的单价:%d\n",
                   str[i].id,
                   str[i].name,
                   str[i].place,
                   str[i].number,
                   str[i].price);
    }
    getchar();
    getchar();
}
//页面颜色更改
void choo_se06()
{
    char arr[8][50] = {
        "0=黑色      8=灰色",
        "1=蓝色      9=淡蓝色",
        "2=绿色      10=淡绿色",
        "3=浅绿色    11=淡浅绿色",
        "4=红色      12=淡红色",
        "5=紫色      13=淡紫色",
        "6=黄色      14=淡黄色",
        "7=白色      15=淡白色"};
    int i;
    for (i = 0; i < 8; i++)
        printf("%s\n", arr[i]);
    printf("!!背景色和前景色请不要选成一样\n");
    char a = 'y';
    while (a == 'y') {
        int bg, fg;
        printf("请选择背景色(0-15):\n");
        scanf("%d", &bg);
        printf("请选择前景色(0-15):\n");
        scanf("%d", &fg);
        char command[50];
        sprintf(command, "color %x%x", bg, fg);
        system(command);
        getchar();
        printf("是否要继续更改颜色(y等于是，其余等于否)\n");
        scanf("%c", &a);
    }
    return;
}
//退出
void choo_se07()
{
    printf("是否要退出(y等于是，其余等于否)\n");
    getchar();
    char a;
    scanf("%c", &a);
    if (a == 'y') {
        exit(0);
    }
    else {
        return;
    }
}

// LANDING
void sign_in_up()
{
    printf("\n\n");
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                             ┃\n");
    printf("┃        %s        ┃\n", title);
    printf("┃                             ┃\n");
    printf("┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃  \033[1m1. 登录\033[0m                    ┃\n");
    printf("┃  \033[1m2. 注册\033[0m                    ┃\n");
    printf("┃  \033[1m3. 忘记密码\033[0m                ┃\n");
    printf("┃  \033[1m4. 退出\033[0m                    ┃\n");
    printf("┃                             ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
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
            printf("没有这个选项, 请你看清楚后重新选择\n");
            return sign_in_up();
        }
    }
}

// 登陆
void sign_in()
{
    int id;
    char password[50];
    printf("输入ID:\n");
    scanf("%d", &id);
    printf("输入密码:\n");
    scanf("%s", password);
    while (true) {
        if (users[id].id == 0) {
            printf("ID错误\n");
        }
        else if (strcmp(users[id].pass, password)) {
            printf("密码错误\n");
        }
        else {
            printf("登陆成功\n");
            return; // 跳转主菜单
        }
        printf("请选择: \n1. 重新输入\n2. 回到登陆页面\n");
        int choice = 0;
        while (choice != 1 && choice != 2) {
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    printf("输入ID:\n");
                    scanf("%d", &id);
                    printf("输入密码:\n");
                    scanf("%s", password);
                };
                    break;
                case 2: return sign_in_up();
                default: printf("没有这个选项, 请你看清楚后重新选择\n");
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
        printf("请输入ID [1, 99999]: \n");
        scanf("%d", &id);
        printf("请输入密码:\n");
        scanf("%s", password_1);
        printf("请再输入一遍密码: \n");
        scanf("%s", password_2);
        
        if (users[id].id) {
            printf("ID已存在!\n");
            un = 0;
        }
        else {
            if (id < 1 || id > 9999) {
                printf("ID输错了, 不在这个范围\n");
                fid = 0;
            }
            if (strcmp(password_1, password_2)) {
                printf("密码不一致\n");
                fp = 0;
            }
        }
        
        if (fp && fid && un) {
            printf("注册成功...即将返回登陆界面...\n");
            users[id].id = id;
            strcpy(users[id].pass, password_1);
            return sign_in_up();
        }
        else {
            printf("请选择: \n1. 重新输入\n2. 回到登陆页面\n");
            int choice = 0;
            while (choice != 1 && choice != 2) {
                scanf("%d", &choice);
                switch (choice) {
                    case 1: return sign_up();
                    case 2: return sign_in_up();
                    default: printf("没有这个选项, 请你看清楚后重新选择\n");
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
    printf("请输入ID: \n");
    scanf("%d", &id);
    if (users[id].id == 0) {
        printf("ID不存在!\n");
        printf("请选择: \n1. 重新输入\n2. 回到登陆页面\n");
        int choice = 0;
        while (choice != 1 && choice != 2) {
            scanf("%d", &choice);
            switch (choice) {
                case 1: return forget();
                case 2: return sign_in_up();
                default: printf("没有这个选项, 请你看清楚后重新选择\n");
                    break;
            }
        }
    }
    else {
        printf("这是密码:\n%s\n", users[id].pass);
        return sign_in_up();
    }
}

// 初始化
void initialize()
{
    // 初始化user
    int uid;
    char password[50];
    FILE *file_u = fopen("/Users/panyong/Desktop/running/MarketSystem/Users.txt", "r");
    if (file_u == NULL) {
        printf("没有找到文件\n");
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
    FILE *file_u = fopen("/Users/panyong/Desktop/running/MarketSystem/Users.txt", "w");
    for (i = 0; i < 100000; ++i) {
        if (users[i].id) {
            fprintf(file_u, "%d %s\n", users[i].id, users[i].pass);
        }
    }
}




