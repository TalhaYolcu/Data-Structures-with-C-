#ifndef TVECTOR_H
#define TVECTOR_H

template <typename T>
class tvector {
private:
    T*data;
    int cap;
    int used;
    void reallocate();
public:
	tvector();
    tvector(const tvector<T> &other);
    ~tvector();
    const tvector<T>& operator=(const tvector<T> &other);
	int size() const;
	int capacity() const;
	void push_back(const T &value);
	T at(const int &index) const;
	bool empty() const;
	T operator[](const int &index) const;
	T front() const;
	T back() const;
	void pop_back();
};

#endif