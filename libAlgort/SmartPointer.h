#pragma once
#include <stdexcept>

namespace SmartPointer
{
	template <typename T>
	class SmartPtr {
	public:
		SmartPtr(int);
		SmartPtr(const SmartPtr&);
		SmartPtr(SmartPtr&& other) noexcept;
		SmartPtr& operator=(SmartPtr&& other) noexcept;
		~SmartPtr();

		T& operator[](int);
		SmartPtr& operator=(const SmartPtr&);
		T* operator->();
		T& operator*();
		operator bool() const;
		bool operator==(const SmartPtr&);
		bool operator!=(const SmartPtr&);
		int GetSize();
		void reset(int);
	private:
		T* sPtr;
		int size;
	};
}

namespace sp = SmartPointer;