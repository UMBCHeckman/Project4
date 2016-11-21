#ifndef HEAP_CPP_
#define HEAP_CPP_
#include "Heap.h"

	template<class T, int m_size>
	Heap<T, m_size>::Heap() {
        currentIndex = 1;
        m_array = new T[m_size+1];
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
	    m_array[]
        PercolateUp(insertable);
            // Percolate up
//        int hole = ++currentSize;
//        for( ; hole >= 1 && x < array[ hole / 2 ]; hole /= 2 )
//            array[ hole ] = array[ hole / 2 ]; // swap, from child to parent
//        array[ hole ] = x;
    }

	template<class T, int m_size>
	void Heap<T, m_size>::PercolateUp(int index) {
        for( ; index >= 1 && index < array[ index / 2 ]; index /= 2 ){
            array[ index ] = array[ index / 2 ]; // swap, from child to parent
        }
        array[ index ] = index;
	}

	template<class T, int m_size>
	void Heap<T, m_size>::PercolateDown(int index) {
        int child;
        Comparable tmp = array[ index ];

        for( ; index * 2 <= currentSize; index = child )
        {
            child = index * 2;
            if( child != currentSize && array[ child + 1 ] < array[ child ] )
                child++;
            if( array[ child ] < tmp ) { array[ index ] = array[ child ]; }
            else { break; }
        }
        array[ index ] = tmp;
	}


#endif /* HEAP_CPP_ */
