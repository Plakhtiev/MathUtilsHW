#include <iostream>
#include <vector>
#include <iterator>
#include <future>

class MathUtils
{
public:

	int Multiplier(std::vector<int>::iterator  begin, std::vector<int>::iterator end) {
		int result = 1;
		for (
			std::vector<int>::iterator it = begin;
			it != end;
			++it
			) {
			result *= *it;
		}
		return result;
	}

	size_t Fibonacci(size_t n) {
		size_t a = 1;
		size_t b = 1;
		for (size_t i = 3; i <= n; i++) {
			size_t c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
private:
};

int main() {
	std::vector<int> myVector = { 10,11,12,13,14 };

	MathUtils mathUtils;

	std::future<int> f = std::async(&MathUtils::Multiplier, &mathUtils, myVector.begin(), myVector.end());
	int  multipliedVector = f.get();
	std::cout << multipliedVector << std::endl;

	const size_t fibonacciCount = 10;
	//size_t fib = mathUtils.Fibonacci(fibonacciCount);
	std::future<size_t> ftr = std::async(&MathUtils::Fibonacci, &mathUtils, fibonacciCount);
	size_t fib = ftr.get();

	std::cout << fib << std::endl;
}