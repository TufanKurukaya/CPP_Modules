#include "Serializer.hpp"
#include <cstdio>
int main()
{
	Data* original = new Data();
	original->_value = 42;
	original->_name = "Deneme";

	uintptr_t serializer = Serializer::serialize(original);
	cout << "Serializer: " << serializer << endl;
	Data* deSerializer = Serializer::deserialize(serializer);
	if (original == deSerializer)
	{
		cout << "Deserialization başarılı!" << endl;
		cout << "Value	: " << deSerializer->_value << endl;
		cout << "Name	: " << deSerializer->_name << endl;
	}
	else
		cout << "Hata: Adresler uyuşmuyor." << endl;
	delete original;
	return 0;
}
