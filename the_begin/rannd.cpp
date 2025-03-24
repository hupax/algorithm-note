//
// Created by 沙枭 on 2024/3/27.
//

// 如何生成指定范围的随机数呢？
// C++11 提供了 std::uniform_int_distribution 类模板来生成指定范围的随机数。
// 为了使用 std::uniform_int_distribution，我们首先需要包含 <random> 头文件。
// 该类模板的模板参数是整型类型，它的构造函数接受两个参数，即随机数的最小值和最大值。
// 然后，我们可以使用 operator() 方法来生成随机数。
// 下面的代码展示了如何生成 1 到 6 之间的随机数：
#include <iostream>
#include <random>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 99);
    for (int n = 0; n < 10; ++n) {
        std::cout << dis(gen) << ' '; // 输出 1 到 6 之间的随机数
    }
    std::cout << '\n';
    return 0;
}
// 这段代码生成了 10 个 1 到 6 之间的随机数。
// 代码中的 std::random_device 是一个非确定性的随机数生成器，它可以用来生成随机数种子。
// std::mt19937 是一个伪随机数生成器，它使用 Mersenne Twister 算法生成随机数。
// std::uniform_int_distribution 是一个随机数分布类模板，它用来生成指定范围的随机数。
// 代码中的 dis(gen) 生成了一个 1 到 6 之间的随机数。
// 为了生成不同的随机数，我们需要传递不同的种子给 std::mt19937 构造函数。
// 通常情况下，我们可以使用 std::random_device 来生成随机数种子。
// 为了生成不同的随机数，我们需要传递不同的种子给 std::mt19937 构造函数。
// 通