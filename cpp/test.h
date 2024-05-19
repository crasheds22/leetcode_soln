
#include <vector>
#include <tuple>
#include <iostream>

template<typename ... T>
class test {
public:
    void add_case(T... args) {
        std::tuple<T ...> tc(args ...);
        cases.push_back(tc);
    }

    int run_tests(int(*judge)(std::tuple<T ...>)) {
        for (unsigned int i = 0; i < cases.size(); i++) {
            std::cout << "Test Case " << i + 1 << std::endl;
            if (!judge(cases[i])) {
                return 0;
            }
        }
        return 1;
    }

private:
    std::vector<std::tuple<T ...>> cases;
};
