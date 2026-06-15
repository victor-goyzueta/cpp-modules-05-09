#include "inc/Serializer.hpp"

#include <iostream>

int main()
{
		std::cout << "----- CREATING DATA -----" << std::endl;

		Data	data;
		data.str = "Hello 42";
		data.nbr = 42;

		std::cout << "Data pointer: " << &data << std::endl;
		std::cout << "Data string: " << data.str << std::endl;
		std::cout << "Data number: " << data.nbr << std::endl << std::endl;

		std::cout << "----- SERIALIZATING -----" << std::endl;
		uintptr_t	raw = Serializer::serialize(&data);
		std::cout << "Serialized (memory address): " << raw << std::endl << std::endl;

		std::cout << "----- DESEREALIZATING -----" << std::endl;
		Data*	deserealized = Serializer::deserialize(raw);
		std::cout << "Data pointer: " << deserealized << std::endl;
		std::cout << "Data string: " << deserealized->str << std::endl;
		std::cout << "Data number: " << deserealized->nbr << std::endl << std::endl;
	
		if (&data == deserealized)
			std::cout << "SUCCESS: The deserialized pointer is equal to the original pointer." << std::endl;
		else
			std::cout << "ERROR: The pointers are different." << std::endl;

		return 0;
}
