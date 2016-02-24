#include "List.h"

template <typename T>
T& List<T>::operator[](int i)
{
	T t;
	if (i >= Length || i < 0) return t;
	return Items[i];
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& items)
{
	Clear();
	AddRange(items);
	return *this;
}

template <typename T>
List<T>::List()
{
	Items = new	T[InitMaxLength];
	MaxLength = InitMaxLength;
	Length = 0;
}

template <typename T>
List<T>::List(List<T>& list)
{
	Length = 0;
	Items = new T[InitMaxLength];
	MaxLength = InitMaxLength;
	if (list.Length > 0)
	{
		for (int i = 0; i < list.Length; i++)Add(list[i]);
	}
}

template <typename T>
List<T>::~List()
{
	if (Items != 0)
	{
		delete[] Items;
		Items = 0;
		Length = 0;
	}
}

template <typename T>
bool List<T>::Any()
{
	return Length != 0;
}

template <typename T>
void List<T>::Clear()
{
	Length = 0;
}

template <typename T>
T List<T>::First()
{
	T t;
	if (Length == 0) return t;
	else return Items[0];
}

template <typename T>
T List<T>::Last()
{
	T t;
	if (Length == 0) return t;
	return Items[Length - 1];
}

template <typename T>
void List<T>::Add(T item)
{
	if (Length == MaxLength)Resize();
	Items[Length] = item;
	Length++;
}

template <typename T>
void List<T>::AddRange(const List<T>& list)
{
	if (FreeSpace() < list.Length)Resize(list.Length);
	CopyItemsBackward(Items + Length, list.Items, list.Length);
	Length += list.Length;
}

template <typename T>
void List<T>::AddRange(const T* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		Add(arr[i]);
	}
}

template <typename T>
int List<T>::IndexOf(T item)
{
	for (int i = 0; i < Length; i++)
	{
		if (Items[i] == item) return i;
	}
	return -1;
}

template <typename T>
int List<T>::LastIndexOf(T item)
{
	int i = Length;
	while (i-->0) if (Items[i] == item) return i;
	return -1;
}

template <typename T>
int List<T>::Remove(T item)
{
	int Index = IndexOf(item);
	if (Index == -1) return -1;
	RemoveAt(Index);
	return Index;
}

template <typename T>
void List<T>::RemoveAll(T item)
{
	while (Remove(item) != -1);
}

template <typename T>
void List<T>::RemoveRange(List<T>& list)
{
	int i = list.Length;
	while (i-- > 0)Remove(list[i]);
}

template <typename T>
void List<T>::RemoveAt(int index)
{
	if (index >= Length) return;
	int MovedCount = Length - index;
	CopyItemsForward(Items + index, Items + index + 1, MovedCount);
	Length -= 1;
}

template <typename T>
bool List<T>::Insert(T item, int index)
{
	if (index >= Length) return false;
	if (Length == MaxLength)Resize();
	int MovedCount = Length - index;
	CopyItemsBackward(Items + index + 1, Items + index, MovedCount);
	Items[index] = item;
	Length++;
	return true;
}

template <typename T>
bool List<T>::InsertRange(List<T> list, int index)
{
	if (index >= Length) return false;
	if (FreeSpace() < list.Length)Resize(list.Length);
	int MovedCount = Length - index;
	CopyItemsBackward(Items + index + list.Length, Items + index, MovedCount);
	CopyItemsBackward(Items + index, list.Items, list.Length);
	Length += list.Length;
	return true;
}

template <typename T>
bool List<T>::Contains(T item)
{
	return IndexOf(item) != -1;
}

template <typename T>
T* List<T>::ToArray()
{
	T* NewArray = new T[Length];
	CopyItemsBackward(NewArray, Items, Length);
	return NewArray;
}

template <typename T>
int List<T>::Count()
{
	return Length;
}

template <typename T>
void List<T>::Reverse()
{
	int half = Length / 2;
	for (int i = 0; i < half; i++)
	{
		T First = Items[i];
		Items[i] = Items[Length - 1 - i];
		Items[Length - 1 - i] = First;
	}
}

template <typename T>
List<T> List<T>::Take(int count)
{
	List<T> take = List<T>();
	if (count > Length) count = Length;
	for (int i = 0; i < count; i++)take.Add(Items[i]);
	return take;
}

template <typename T>
List<T> List<T>::Take(int index, int count)
{
	List<T> take = List<T>();
	if (Length - index < count) count = Length - index;
	for (int i = 0; i < count; i++)take.Add(Items[i + index]);
	return take;
}

template <typename T>
List<T> List<T>::TakeAll(int index = 0)
{
	List<T> take = List<T>();
	int count = Length - index;
	for (int i = 0; i < count; i++)take.Add(Items[i + index]);
	return take;
}

template <typename T>
List<T> List<T>::Distinct()
{
	List<T> dist = List<T>();
	for (int i = 0; i < Length; i++)
	{
		if (!dist.Contains(Items[i])) dist.Add(Items[i]);
	}
	return dist;
}

template <typename T>
T* List<T>::GetPointer()
{
	return Items;
}


template <typename T>
int List<T>::FreeSpace()
{
	return MaxLength - Length;
}

template <typename T>
void List<T>::Resize()
{
	Resize(MaxLength);
}

template <typename T>
void List<T>::Resize(int cnt)
{
	T* NewItems = new T[MaxLength + cnt];
	MaxLength += cnt;
	CopyItemsBackward(NewItems, Items, Length);
	delete[] Items;
	Items = NewItems;
}

template <typename T>
void List<T>::CopyItemsBackward(T* dst, const T* src, int length)
{
	int i = length;
	while (i-- > 0) dst[i] = src[i];
}

template <typename T>
void List<T>::CopyItemsForward(T* dst, const T* src, int length)
{
	for (int i = 0; i < length; i++)dst[i] = src[i];
}