#include <tuple>

std::tuple<int, double> returnTuple() {
	return { 3, 4.5 };
}

int main() {

	// using std::tie
	 int a;
	 double b;
	 std::tie(a, b) = returnTuple(); 

	// C++17, structured binding declaration
	auto [a, b] {returnTuple()};      
	return 0;
}