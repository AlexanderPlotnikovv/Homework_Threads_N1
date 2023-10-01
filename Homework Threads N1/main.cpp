#include<iostream>
#include <chrono>
#include <thread>
#include <vector>

void client(int& counter, int& max)
{
	while (max > 0)
	{
		counter += 1;
		std::cout << "Client counter and max: " << counter << " and " << max << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void employee(int& counter, int& max)
{
	while (max > 0)
	{
		max -= 1;
		counter -= 1;
		std::cout << "Employee counter and max: " << counter << " and " << max << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
}

int main()
{
	int max;
	std::cout << "How many clients we have to serve? ";
	std::cin >> max;
	int counter = 0;
	std::thread t1(client, std::ref(counter), std::ref(max));
	std::thread t2(employee, std::ref(counter), std::ref(max));
	t1.join();
	t2.join();
	return 0;
}