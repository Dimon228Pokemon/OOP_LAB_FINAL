#include "sixarray.h"

Six::Six() : _size(0), _array{nullptr} {}

Six::Six(const size_t &n, unsigned char t) {
   _array = new unsigned char[n];
   for (size_t i = 0; i < n; ++i) _array[i] = t;
   _size = n;
}

Six::Six(const initializer_list<unsigned char> &t) {
   size_t i;
   this->_size = t.size();
   i = t.size() - 1;
   this->_array = new unsigned char[this->_size];
   for (unsigned char value : t) {
      if (value >= 6) {
         throw "ERROR. The diger of number is greater than 6.";
      }
      this->_array[i] = value;
      i--;
   }
}
Six::Six(const string &temp) {
   string s;
   size_t n = temp.size();
   size_t counter_end = n;
   size_t counter_start = 0;

   for (size_t i = 0; i < n; i++) {
      if (temp[i] != '0') {
         break;
      } else if (temp[i] == '0' and counter_end == 1) {
         break;
      }
      counter_end--;
      counter_start++;
   }

   this->_array = new unsigned char[counter_end];
   this->_size = counter_end;

   for (size_t i = counter_start; i < n; ++i) {
      s = temp[i];
      if (stoi(s) >= 6) {
         throw "ERROR. The diger of number is greater than 6.";
      }
      this->_array[n - i - 1] = stoi(s);
   }
}
Six::Six(const Six &other) {
   _size = other._size;
   _array = new unsigned char[_size];

   for (size_t i{0}; i < _size; ++i) _array[i] = other._array[i];
}

Six::Six(Six &&other) noexcept {
   _size = other._size;
   _array = other._array;

   other._size = 0;
   other._array = nullptr;
}


Six &Six::operator=(const Six &array) {
   delete[] this->_array;
   this->_size = array._size;
   this->_array = new unsigned char[this->_size];
   memcpy(this->_array, array._array, this->_size);
   return *this;
}
bool Six::operator==(const Six &array) const {
   size_t MAX = max(this->_size, array._size);
   unsigned char *tempA = new unsigned char[MAX]{0};
   unsigned char *tempB = new unsigned char[MAX]{0};
   memcpy(tempA, this->_array, this->_size);
   memcpy(tempB, array._array, array._size);

   for (size_t i = 0; i < MAX; i++) {
      if (tempA[i] != tempB[i]) {
         delete[] tempA;
         delete[] tempB;
         return false;
      }
   }
   delete[] tempA;
   delete[] tempB;
   return true;
}
bool Six::operator<(const Six &array) const {
   size_t MAX = max(this->_size, array._size);
   unsigned char *tempA = new unsigned char[MAX]{0};
   unsigned char *tempB = new unsigned char[MAX]{0};
   memcpy(tempA, this->_array, this->_size);
   memcpy(tempB, array._array, array._size);

   for (size_t i = 0; i < MAX; i++) {
      if (tempA[MAX - i - 1] > tempB[MAX - i - 1]) {
         delete[] tempA;
         delete[] tempB;
         return false;
      }
      if (tempA[MAX - i - 1] < tempB[MAX - i - 1]) {
         delete[] tempA;
         delete[] tempB;
         return true;
      }
   }
   delete[] tempA;
   delete[] tempB;
   return false;
}

bool Six::operator>(const Six &array) const {
   size_t MAX = max(this->_size, array._size);
   unsigned char *tempA = new unsigned char[MAX]{0};
   unsigned char *tempB = new unsigned char[MAX]{0};
   memcpy(tempA, this->_array, this->_size);
   memcpy(tempB, array._array, array._size);

   for (size_t i = 0; i < MAX; i++) {
      if (tempA[MAX - i - 1] < tempB[MAX - i - 1]) {
         delete[] tempA;
         delete[] tempB;
         return false;
      }
      if (tempA[MAX - i - 1] > tempB[MAX - i - 1]) {
         delete[] tempA;
         delete[] tempB;
         return true;
      }
   }
   delete[] tempA;
   delete[] tempB;
   return false;
}
Six Six::operator+(const Six &array) const {
   string final = "";
   unsigned char six = 6;
   size_t MAX = max(this->_size, array._size);
   unsigned char *tempA = new unsigned char[MAX]{0};
   unsigned char *tempB = new unsigned char[MAX]{0};
   unsigned char *res = new unsigned char[MAX + 1]{0};
   memcpy(tempA, this->_array, this->_size);
   memcpy(tempB, array._array, array._size);
   for (size_t i = 0; i < MAX; i++) {
      if (tempA[i] + tempB[i] >= six) {
         res[i] += tempA[i] + tempB[i] - six;
         res[i + 1] += 1;
      } else {
         res[i] += tempA[i] + tempB[i];
      }
   }
   for (size_t i = 0; i < MAX + 1; i++) {
      final += to_string((int)res[MAX - i]);
   }
   delete[] tempA;
   delete[] tempB;
   delete[] res;
   return Six(final);
}
Six Six::operator-(const Six &array) {
   string final = "";
   size_t MAX = max(this->_size, array._size);
   unsigned char *tempA = new unsigned char[MAX]{0};
   unsigned char *tempB = new unsigned char[MAX]{0};
   unsigned char *res = new unsigned char[MAX]{0};
   memcpy(tempA, this->_array, this->_size);
   memcpy(tempB, array._array, array._size);

   for (size_t i = 0; i < MAX; i++) {
      if (tempA[i] < tempB[i]) {
         one_in_mind(tempA, tempB, MAX, i);
      }
      res[i] = tempA[i] - tempB[i];
   }

   for (size_t i = 0; i < MAX; i++) {
      final += to_string((int)res[MAX - i - 1]);
   }
   delete[] tempA;
   delete[] tempB;
   delete[] res;
   return Six(final);
}

void Six::one_in_mind(unsigned char *arr1, unsigned char *arr2, size_t n,size_t position) {
   unsigned char six = 6;
   size_t donor = 0;
   for (size_t i = position + 1; i < n; i++) {
      if (arr1[i] > arr2[i]) {
         donor = i;
         break;
      }
   }

   if (donor == 0) {
      throw "ERROR. The result of the operation is a negative number";
   }

   for (size_t i = position; i <= donor; i++) {
      if (i == donor) {
         arr1[i] -= 1;
      } else if (i == position) {
         arr1[i] += six;
      } else {
         arr1[i] += six - 1;
      }
   }
}
//Запись в файл
void Six::serialize(const char* name)
{
	string str="";
	try {
		for (size_t i = 0; i < this->_size; i++) {
			str += to_string((int)this->_array[this->_size-i-1]);
		}
		ofstream outF(name, ios::out);
		if (outF.is_open())
		{
			outF << str << std::endl;
		}else {
			throw "can not open file.";
		}
		outF.close();

	}
	catch (...) {
		throw "Can not serialize object.";
	}
}

//Выгрузка из файла
Six Six::fromFile(const char* name)
{
	string str;
	try {
		ifstream inF(name);

		if (inF.is_open())
		{
			getline(inF, str);
		}
		else {
			throw "can not open file.";
		}
		inF.close();   
	}
	catch (const char* errS) {
		cout << errS << endl;
	}
	return Six(str);
}

string Six::getValue() {
   string str = "";

   for (size_t i = 0; i < this->_size; i++) {
      str += to_string((int)this->_array[this->_size - i - 1]);
   }

   return str;
}

unsigned char *Six::get_array() { return this->_array; }

size_t Six::get_size() { return this->_size; }

void Six::print() {
   for (size_t i = 0; i < this->_size; i++) {
      cout << "[" << i << "]=" << (int)this->_array[i] << endl;
   }
}

Six::~Six() noexcept {
   if (_size > 0) {
      _size = 0;
      delete[] _array;
      _array = nullptr;
   }
}