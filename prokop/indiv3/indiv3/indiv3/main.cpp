#include <iostream>
#include "queue.cpp"
#include <vector>

queue<int> func(queue<int> q) {
	queue<int> res;
	int temp;
	std::vector<int> vecTemp;
	std::vector<int> resVec;
	while ((temp = q.pop()) != NULL) {
		if (temp < 0)
			vecTemp.push_back(temp);
	}
	for(int i = vecTemp.size(); i > 0; i--) {
		resVec.push_back(vecTemp[i-1]);
	}
	for (int i : resVec) {
		std::cout << i << ' ';
		res.push(i);
	}
	return res;
}

int main()
{

	queue<int> q;
// вставить строки из файла с данными
	q.push(12);
	q.push(-1);
	q.push(-6);
	q.push(34);
	q.push(-123);

	std::cout << "Do you wanna start?" << std::endl << "1.Yes  |  2.No";
	int ans;
	std::cin >> ans;
	if (ans == 1)
		queue<int> res = func(q);
	else
		return 0;
}