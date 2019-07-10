#include <iostream>
#include <set>
#include <random>
#include <thread>
#include 

using namespace std;

int main()
{
	std::set<int> int_set;
	auto f = [&int_set]() {
try {
        	std::random_device rd;
        	std::mt19937 gen(rd());
        	std::uniform_int_distribution<> dis(1, 1000);
        	for(std::size_t i = 0; i != 100000; ++i) {
            	int_set.insert(dis(gen));
        	}
    	} catch(...) {}
	};
	std::thread td1(f), td2(f);
	td1.join();
	td2.join();
}
