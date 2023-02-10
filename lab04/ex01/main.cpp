#include "header.hpp"



bool is_prime(int n, std::vector<int> primes)
{
	if (n == 1) return false;
	if (n == 2) return true;
	for (int i = 0; i < primes.size(); i++) {
		if (n % primes[i] == 0) return false;
	}
	return true;
}

template <class T>
	T median(std::vector<T> vec)
	{
	using std::sort;
	using std::vector;
	if (!vec.size()) return 0;
	sort(vec.begin(), vec.end());
	const auto size = vec.size();
	const auto mid = size / 2;
	return size % 2 != 0 ? (vec[mid] + vec[mid + 1]) / 2: vec[mid] ;
}


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	//1.1
	cout << "Enter the upper limit: ";
	int n;
	cin >> n;
	std::vector<int> primes = {};
	
	for (int i = 1; i <= n; i++) {
		if (is_prime(i, primes))
		{	
			
			primes.push_back(i);
			cout << i << endl;
		}
		
	}

	//1.2 
	std::vector<int> vec = {};
	cout << "The median of the vector is: " << median(vec) << endl;

	return 0;
}
