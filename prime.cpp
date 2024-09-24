//
// Created by 沙枭 on 2024/4/6.
//
#include<bits/stdc++.h>
#include "iostream"

using namespace std;
typedef long long ll;

inline bool Prime(ll x) {
    if (x == 1) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 6 != 1 && x % 6 != 5) return 0;
    for (ll i = 5; i * i <= x; i += 6)
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    return 1;
}

ll n, x;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (Prime(x))cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
/*好的,我来详细解释一下这段代码:

1. `inline bool Prime(ll x) {`
   - 这是一个名为`Prime`的函数,它接受一个`ll`类型(long long)的参数`x`,并返回一个`bool`类型的值。
   - `inline`关键字表示这是一个内联函数,编译器会尝试在调用点展开该函数,而不是进行函数调用,以提高性能。

2. `if (x == 1) return 0;`
   - 如果输入的数字`x`等于1,则该数字不是质数,函数返回`false`(0)。

3. `if (x == 2 || x == 3) return 1;`
   - 如果输入的数字`x`等于2或3,则该数字是质数,函数返回`true`(1)。

4. `if (x % 6 != 1 && x % 6 != 5) return 0;`
   - 这一行代码利用了一个有趣的性质:所有大于3的质数都可以表示为6k±1的形式。
   - 也就是说,如果一个数`x`既不能被6整除加1,也不能被6整除减1,那么它一定不是质数。
   - 因此,这一行代码先检查`x`是否满足这个条件,如果不满足,则直接返回`false`(0)。

5. `for (ll i = 5; i * i <= x; i += 6)`
   - 接下来,代码使用一个循环来检查`x`是否能被某个质数整除。
   - 循环从5开始,每次增加6(因为除了2和3之外,其他质数都可以表示为6k±1的形式)。
   - 循环的条件是`i * i <= x`,这是因为如果一个数能被某个质数整除,那么它一定能被该质数的平方整除。

6. `if (x % i == 0 || x % (i + 2) == 0) return 0;`
   - 在循环中,代码检查`x`是否能被当前的`i`或`i+2`整除。
   - 如果能被任何一个整除,说明`x`不是质数,函数返回`false`(0)。

7. `return 1;`
   - 如果循环结束后,仍然没有找到能整除`x`的质数,那么`x`一定是质数,函数返回`true`(1)。

总的来说,这段代码实现了一个高效的质数检测算法,利用了质数的一些特性来减少不必要的检查,提高了性能。
 好的,让我详细解释一下第六点:

```cpp
if (x % i == 0 || x % (i + 2) == 0) return 0;
```

这一行代码是在循环中进行质数检测的关键部分。

首先,我们知道,除了2和3之外,所有其他的质数都可以表示为6k±1的形式。这是因为质数必须是奇数(除了2),并且不能被3整除。

在这个循环中,我们从5开始,每次增加6。这意味着我们正在检查形式为6k±1的数字,也就是可能的质数。

现在,让我们具体看一下这一行代码的作用:

1. `x % i == 0`
   - 这个条件检查`x`是否能被当前的数字`i`整除。
   - 如果`x`能被`i`整除,那么`x`一定不是质数,因为它可以被一个小于自身的数整除。
   - 所以,如果这个条件为真,我们就可以直接返回`false`(0),因为`x`一定不是质数。

2. `x % (i + 2) == 0`
   - 这个条件检查`x`是否能被`i+2`整除。
   - 为什么要检查`i+2`呢?
   - 因为我们知道,除了2和3之外,所有其他的质数都可以表示为6k±1的形式。
   - 也就是说,在6k-1和6k+1之间,还有一个数字6k+2,它也可能是一个质数候选。
   - 所以,我们需要同时检查`i`和`i+2`,以确保我们覆盖了所有可能的质数候选。

3. `return 0;`
   - 如果上述任何一个条件为真,说明`x`能被某个小于自身的数整除,因此`x`一定不是质数。
   - 所以,我们直接返回`false`(0),结束函数的执行。

总的  来说,这一行代码是质数检测算法的核心部分,它利用了质数的特性来高效地检查一个数是否为质数。
 */
