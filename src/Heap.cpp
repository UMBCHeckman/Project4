#ifndef HEAP_CPP_
#define HEAP_CPP_
#include "Heap.h"

	template<class T, int m_size>
	Heap<T, m_size>::Heap() {

	}

	template<class T, int m_size>
	Heap<T, m_size>::Heap(const Heap<T, m_size>& origHeap) {
        Heap<T, m_size> *newHeap = new Heap<T, m_size>;
        newHeap->m_array = origHeap->m_array;
	}

	template<class T, int m_size>
	bool Heap<T, m_size>::Contains(const T& needle) const {
        //if Find(needle);
	}


	template<class T, int m_size>
	const T* Heap<T, m_size>::Find(const T& needle) const {
        //for(unsigned int i = 0; i < m_array.size(); i++){
          //  if
        //}
	}

	template<class T, int m_size>
	T& Heap<T, m_size>::Remove() {

	}

	template<class T, int m_size>
	void Heap<T, m_size>::Insert(T& insertable) {

	}

	template<class T, int m_size>
	void Heap<T, m_size>::PercolateUp(int index) {

	}

	template<class T, int m_size>
	void Heap<T, m_size>::PercolateDown(int index) {

	}


#endif /* HEAP_CPP_ */
