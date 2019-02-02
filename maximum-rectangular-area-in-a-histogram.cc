//https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram/0


#include <iostream>
#include <vector>
#include <stack>
#include <limits>

using li = long long int;

li GetMaxRect(const std::vector<li>& rects) {
    auto N = rects.size();
    
    if (N == 0)  {
        return 0;
    }
    
    if (N == 1) {
        return rects.at(0);
    }
    
    auto s = std::stack<li>{};
    auto max_area = li{0};
    auto current_area = li{0};
    auto idx = 0;
    
    while (idx < N) {
        if (s.empty() || rects.at(s.top()) <= rects.at(idx)) {
            s.push(idx);
            ++idx;
        } else {
            auto tp = s.top();
            s.pop();
            current_area = rects.at(tp) * 
                           (s.empty() ? idx : (idx - s.top() - 1));
            if (current_area > max_area) {
                max_area = current_area;
            }
        }
    }
    
    while (!s.empty()) {
        auto tp = s.top();
        s.pop();
        current_area = rects.at(tp) *
                       (s.empty() ? idx : (idx - s.top() - 1));
            if (current_area > max_area) {
                max_area = current_area;
            }
    }
    
    return max_area;
}

/*li GetMaxRect(const std::vector<li>& rects) {
    li N = rects.size();
    
    if (N == 0) {
        return 0;
    }
    
    auto l_count = std::vector<li>(N, 0);
    auto r_count = std::vector<li>(N, 0);
    
    for (li idx = 1; idx < N; ++idx) {
        if (rects.at(idx - 1) > rects.at(idx)) {
            l_count.at(idx) = l_count.at(idx - 1) + 1;
        } else {
            l_count.at(idx) = 0;
        }
    }
    
    
    
    for (li idx = N - 2; idx >= 0; --idx) {
        if (rects.at(idx + 1) > rects.at(idx)) {
            r_count.at(idx) = r_count.at(idx + 1) + 1;
        } else {
            r_count.at(idx) = 0;
        }
    }
    
    auto max_area = li{0};
    
    for (li idx = 0; idx < N; ++idx) {
        max_area = std::max(max_area, rects.at(idx) * (l_count.at(idx) + r_count.at(idx) + 1));
    }
    
    return max_area;
}*/

int main() {
    li T, N;
    
    std::cin >> T;
    
    while (T--) {
        std::cin >> N;
        
        auto rects = std::vector<li>(N);
        
        for (auto idx = 0; idx < N; ++idx) {
            std::cin >> rects.at(idx);
        }
        
        std::cout << GetMaxRect(rects) << std::endl;
    }
}
