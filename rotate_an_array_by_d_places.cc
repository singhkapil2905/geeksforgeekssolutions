#include <iostream>
#include <vector>

int GetTIdx(int idx, int N, int d) {
    if (idx - d >= 0) {
        return idx - d;
    }
    
    return N + (idx - d);
}

void Rotate(std::vector<int>& v, int d) {
    const auto N = int{v.size()};
    
    if (N < 2) {
        return;
    }
    
    if (d % N == 0) {
        return;
    }
    
    auto idx = int{0};
    auto tmp = int{v.at(0)};
    auto count = int{0};
    
    while (count < N) {
        auto t_idx = GetTIdx(idx, N, d);
        
        auto tmp2 = v.at(t_idx);
        v.at(t_idx) = tmp;
        tmp = tmp2;
        
        ++count;
        idx = t_idx;
    }
}

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
    
    Rotate(v, 2);
    
    for (const auto& el : v) {
        std::cout << el << " ";
    }

    return 0;
}
