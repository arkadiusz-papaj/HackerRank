#include <iostream>
#include <vector>
#include <limits>

#define toStr(s) #s
#define io(container) std::cin >> container
#define INF std::numeric_limits<int>::max()
#define FUNCTION(funcName, comparator) constexpr auto funcName(int & value, int const& toCompareWith) noexcept -> void { \
                                        if (toCompareWith comparator value) value=toCompareWith;}
#define foreach(container, index) for (auto index = std::size_t{0}; index < container.size(); ++index)

//can NOT change any macro name below
#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	auto n = int{};
    std::cin >> n;
	auto v = std::vector<int>(n);
	foreach(v, i) {
		io(v)[i];
	}
	auto mn = int{INF};
	auto mx = int{-INF};
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	auto ans = int{mx - mn};
	std::cout << toStr(Result =) <<' '<< ans;
	return 0;

}