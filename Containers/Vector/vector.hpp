#include <memory>
#include <stdexcept>
#include <new>

template<class T>
class vector {
	T *ptr = nullptr;
	size_t capacity = 0;
	size_t size = 0;

	vector() {}
	vector(size_t count, const T& value = T())
		:	capacity(count), size(count), ptr(new T[count])
	{
		for(size_t i = 0; i < count; i++)
			ptr[i] = value;
	}
	vector(const vector& other)
		:	capacity(other.capacity), size(other.size), ptr(new T[other.capacity])
	{
		for(size_t i = 0; i < size; i++)
			ptr[i] = other.ptr[i];
	}
	vector(vector&& other)
		:	capacity(other.capacity), size(other.size), ptr(other.ptr)
	{
		other.capacity = 0;
		other.size = 0;
		other.ptr = nullptr;
	}
	vector(std::initializer_list<T> init)
		:	capacity(init.size()), size(init.size()), ptr(new T[init.size()])	
	{
		for(size_t i = 0; i < capacity; i++) 
			ptr[i] = init[i];
	}

	~vector() {
		delete[] ptr;
	}

	T& at(size_t index) {
		if(index < 0 || index >= capacity)
			throw std::out_of_range;
		return ptr[index];
	}

	T& operator[](size_t index) { return ptr[index]; }
	T& front() { return ptr[0]; }
	T& back() { return ptr[size - 1]; }
	T* data() { return ptr; }
	bool empty() { return !size; }
	size_t size() { return size; }
	size_t capacity() { return capacity; }
	
	void push_back(const T& value) {
		if(size == capacity) {
			capacity *= 2;
			delete[] ptr;
			ptr = new T[capacity];	
		}
		ptr[size++] = value;
	}

	template<class... Args>
	T& emplace_back(Args&&... args) {
		if(size == capacity) {
			capacity *= 2;
			delete[] ptr;
			ptr = new T[capacity];	
		}	
		ptr[size++] = T(std::forward<Args>(args)...);
	}
};
