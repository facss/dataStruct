#pragma once 

//vector:动态的顺序表

namespace bite{
	template<class T>
	class vector{
	public:
		typedef T* iterator;
		typedef T* reverse_iterator;
	public:
		//construct构造
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofStorage(nullptr){}

		vector(size_t n, const T& value){
			_start = new T[n];
			//向空间中存放n个值为value的元素
			for (size_t i = 0; i < n; ++i)
				_start[i] = value;

			_finish = _endofStorage = _start + n;
		}
		vector(T* first, T* last){
			size_t n = last - first;
			_start = new T[n];
			while (fiwst != last){
				*_finish++ = *first++;
			}
			_endofStorage = _finish;
		}

		//注意浅拷贝
		vector(const vector<T>& v);
		vector<T>& operator=(const vector<T>& v);
		~vector(){
			if (_start){
				delete[]_start;
				_start = _finish = _endofStorage = nullptr;
			}
		}
		//iterator迭代器
		//迭代器类似指针
		//第一个有效元素的位置
		iterator begin(){
			return _start;
		}
		//最后一个有效元素的位置
		iterator end(){
			return _finish;
		}

		reverse_iterator rbegin(){
			return end();
		}
		reverse_iterator rend(){
			return begin();
		}

		//capacity
		size_t size()const{
			return _finish - _start;
		}
		size_t capacity()const{
			return _endofStorage - _start;
		}
		bool empty()const{
			return _start == _finish;
		}
		//T（）：创建一个无名的对象
		//T是内置类型，T()----->0
		//T是自定义类型，T()--->调用该类无参的构造函数创建对象
		void resize(size_t newSize, const & val = T()){
			size_t oldSize = size();
			if (newSize <= oldSize){
				_finish = _start + newSize;
			}
			else{
				//考虑是否需要扩容
				if (newSize > capacity())
					reserve(newSize);
				//填充元素
				for (size_t i = oldSize; i < oldSize; ++i)
					*_finish++ = val;
			}
		}
		void reserve(size_t newCapacity){
			size_t oldCapacity = capacity();
			if (newCapacity>oldCapacity){
				//申请新空间
				T* pTemp = new T[newCapacity];
				//拷贝元素
				size_t n = size();
				if (_start){
					for (size_t i = 0; i < size(); ++i)
						pTemp[i] = _start[i];
					//释放旧空间
					free(_start);
				}
				_start = pTemp;
				_finish = _start + n;
				_endofStorage = _start + oldCapacity;

			}
		}
		//access
		//访问任意位置的元素，index不能大于元素的个数
		T& operator[](size_t index){
			assert(index < size());
			return _start[index];
		}
		const T& operator[](size_t index)const{
			assert(index < size());
			return _start[index];
		}
		T& front(){
			return *_start;
		}
		const T& front()const{
			return *_start;
		}

		T& back()const{
			return *(_finish - 1);
		}
		void push_back(const T& value){
			checkcapacity();
			*_finish++ = value;
		}
		void pop_back(){
			if (empty())
				return;
			--_finsih;
		}
		iterator insert(iterator pos, const T& value){
			checkcapacity();
			//搬移元素
			for (size_t i = size(); i >= pos - _start; i--){
				_start[i] = _start[i - 1];
			}
			//插入元素
			*pos = value;
			++_finish;
			return pos;
		}
		iterator erase(iterator pos){
			if (pos == end())
				return pos;
			for (size_t i = pos - _start; i < size(); ++i){
				_start[i] = _start[i + 1];
			}
			--_finish;
			return pos;
		}
		void swap(vector<T>& v){
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofStorage, v._endofStorage);
		}
		void clear(){
			_finish = _start;
		}
	protected:
		void checkcapacity(){
			if (_finish == _endofStorage)
				reserve(capacity() * 2);
		}
	protected:
		T* _start;
		T* _finish;
		T* _endofStorage;
	};
}
#include<iostream>
using namespace std;
void TestVector1(){
	bite::vector<int> v1;
	bite::vector<int> v2(10, 6);
	cout << v2.sie() << endl;
	cout << v2.capacity() << endl;
	for (auto e : v2)
		cout << e << " ";
	cout << endl;
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	bite::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));
	for (auto e : v3)
		cout << e << " ";
	cout << endl;
}
void Testvector2(){
bite:vector<int>v;
	v.reserve(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.reserve(5);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << v.size() << endl;
	cout << v.front() << endl;
	cout << v.back() << endl;
	cout << v[1] << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	v.pop_back();
	cout << v.size() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.pop_back();
	cout << v.back() << endl;

	v.insert(v.begin(), 0);
	cout << v.front() << endl;

	v.erase(v.begin());
	cout << v.front << endl;

	v.resize(5, 8);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(20);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


#include<iostream>
using namespace std;

#include "Vector.h"

int main(){
	TestVector1();
	Testvector2();
	return 0;
}