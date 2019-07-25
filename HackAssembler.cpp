#include <iostream>
#include <fstream>
#include <algorithm>

#include <bitset>

#include <string>
#include <cstring>

#include "CInstructionTable.h"





std::istream& next_command(std::istream& in_stream, std::string& command)
{
	//std::string line;
	while (std::getline(in_stream, command))
	{
		const std::size_t comment_pos = command.find("//");
		command = command.substr(0, comment_pos);
		if (command.length() != 0) return in_stream;
	}

	return in_stream;
}

std::string process_A_command(const std::string& assembler_code)
{
	//std::cout << assembler_code << std::endl;
	unsigned long address = 0;
	try
	{
		address = std::stoul(assembler_code.substr(1));
	}
	catch (...)
	{
		throw std::logic_error("Address in A instruction must be numeric value");
	}

	//std::cout << address << std::endl;

	if (address > 32767) throw std::logic_error("Invalid address in A instruction");

	std::string ret_val{ "0" };
	ret_val.append(std::bitset<15>(address).to_string());

	//std::cout << ret_val << std::endl;

	return ret_val;
}

std::string process_C_command(const std::string& assembler_code)
{



	return std::string();
}

std::string to_binary(const std::string& assembler_code)
{
	const std::size_t Asign_pos = assembler_code.find('@');

	std::string binary;

	if (Asign_pos != std::string::npos)
	{
		binary = process_A_command(assembler_code.substr(Asign_pos));
	}
	else
	{
		binary = process_C_command(assembler_code);
	}

	return binary;
}



int main(int argc, char* argv[]) 
{
	/*if (argc != 2)
	{
		std::cerr << "Provide a file and only file" << std::endl;
		//std::cerr << argv[0]<< std::endl;
		return -1;
	}*/


	std::ifstream in_file;

	try
	{
		//in_file.open(argv[1]);
		in_file.open("E:/nand/HackAssembler/Debug/MaxL.asm");

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return -2;
	}

	/*std::string line;
	while (std::getline(in_file, line))
	{
		std::cout << line << std::endl;
	}*/
	std::string line;
	while (next_command(in_file, line))
	{
		//std::cout << line << std::endl;
		to_binary(line);
	}
	auto &test = CInstructionTable::Get();


	try
	{
		test.GetCompBinary("D+1");
	}
	catch (std::logic_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

