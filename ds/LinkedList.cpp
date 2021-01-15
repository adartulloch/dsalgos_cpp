#include <iostream>

using namespace std;

//Simple implementation of doubly-linked list.
template <typename T>
class Node
{
public:
  T value;
  Node *next;
  Node *previous;

  Node (T value)
  {
    this->value = value;
  }
};

template <typename T>
class LinkedList
{
private:
  int size_;
  Node<T> *head_ = NULL;
  Node<T> *tail_ = NULL;
  Node<T> *itr_ = NULL;

public:
  LinkedList(){
    this->size_ = 0;
  }

  void append(T value)
  {
    if (this->head_ == NULL)
    {
      this->head_ = new Node<T>(value);
      this->tail_ = this->head_;
    } else
    {
      this->tail_->next = new Node<T>(value);
      this->tail_->next->previous = this->tail_;
      this->tail_ = this->tail_->next;
    }
    this->size_++;
  }

  void prepend(T value)
  {
    if (this->head == NULL)
    {
      this->head_ = new Node<T>(value);
      this->tail_ = this->head_;
    }
    else
    {
      this->head_->previous = new Node<T>(value);
      this->head_->previous->next = this->head_;
      this->head_ = this->head_->previous;
    }
    this->size_++;
  }

  Node<T>* iterate()
  {
    if (this->itr_ == NULL)
    {
      this->itr_ = this->head_;
    }
    else
    {
      this->itr_ = this->itr_->next;
    }

    return this->itr_;
  }

  T ptr()
  {
    return this->itr_->value;
  }

  void resetIterator()
  {
    this->itr_ = NULL;
  }
};

int main(int agrc, char** argv)
{
  LinkedList<int> llist;
  llist.append(5);
  llist.append(10);
  llist.append(15);
  llist.append(20);

  while (llist.iterate() != NULL)
  {
    cout << llist.ptr() << "\t";
  }
  cout << endl;
  llist.resetIterator();

  return 0;
}
