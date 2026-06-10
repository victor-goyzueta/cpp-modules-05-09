#include "inc/Serializer.hpp"

#include <iostream>

int main()
{
		std::cout << "CREATING DATA" << std::endl;
		Data	data;
		data.s = "Hello 42";
		data.number = 42;

		std::cout << "Data pointer: " << &data << std::endl;
		std::cout << "Data string: " << data.s << std::endl;
		std::cout << "Data number: " << data.number << std::endl;

		std::cout << "SERIALIZATING" << std::endl;
		uintptr_t	raw = Serializer::serialize(&data);
		std::cout << "Serialized (memory address): "
			<< raw << std::endl;

		std::cout << "DESEREALIZATING" << std::endl;
		Data*	deserealized = Serializer::deserialize(raw);
		std::cout << "ptr: " << deserealized << std::endl;
		std::cout << "String: " << deserealized->s << std::endl;
		std::cout << "Number: " << deserealized->number << std::endl;
	
		if (&data == deserealized)
			std::cout << "SUCCESS: The deserialized pointer is equal to the original pointer." << std::endl;
		else
			std::cout << "ERROR: The pointers are different." << std::endl;
		return 0;
}
