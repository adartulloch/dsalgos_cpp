#include <iostream>

using namespace std;

//Simple implementation of dynamic array
class DynamicArray
{
private:
  int size_;
  int max_;
  int *arrayholder_;

public:
  DynamicArray()
  {
    this->size_ = 0;
    this->max_ = 7;
    this->arrayholder_ = new int[7];
  }

  ~DynamicArray()
  {
    delete[] this->arrayholder_;
  }

  int size()
  {
    return this->size_;
  }

  //Operator overload
  int& operator[](int i)
  {
    assert(i >= 0 && i < this->size_);
    return this->arrayholder_[i];
  }

  void add(int n)
  {
    if (this->size_ >= this->max_) { //We must resize
      this->max_ *= 2;
      int *tmp_ = new int[this->max_];

      for (size_t i=0; i<this->max_; ++i)
      {
        tmp_[i] = this->arrayholder_[i];
      }

      delete[] this->arrayholder_;
      this->arrayholder_ = tmp_;
      this->arrayholder_[this->size_] = n;
    } else {
      this->arrayholder_[this->size_] = n;
    }
    ++this->size_;
  }
};

int main(int argc, char **argv)
{
  DynamicArray darray;
  for (size_t i = 0; i < 2000; i++) {
    darray.add(i);
    cout << darray[i]  << endl;
  }

  return 0;
}
