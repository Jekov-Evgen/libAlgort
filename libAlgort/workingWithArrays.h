#pragma once

namespace array_work
{
	template <typename T>
	class Arr {
	private:
		T* arr;
		int size = 0;
	public:
		Arr(T arr[], const int SIZE);


		T searchForMinimum();
		T searchForMaximum();
		bool sortingCheck(bool descendingAscending);
		T arithmeticMean();
		T findingTheSum();
		void removingDuplicates();
	};
}

namespace aw = array_work;


