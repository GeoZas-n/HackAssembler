#include "CInstructionTable.h"

#include <fstream>

CInstructionTable::CInstructionTable()
{
	std::ifstream in_dest("dest_table.txt");
	std::ifstream in_comp("comp_table.txt");
	std::ifstream in_jmp("jmp_table.txt");

	construct_table(in_dest, dest_table);
	construct_table(in_comp, comp_table);
	construct_table(in_jmp, jmp_table);


}

void CInstructionTable::construct_table(std::istream& in_stream, std::unordered_map<std::string, std::string>& table)
{
	std::string command;
	std::string binary;
	while (in_stream >> command && in_stream >> binary)
	{		
		table[command] = binary;
	}
}

const std::string CInstructionTable::GetDestBinary(const std::string& assembly) const throw(std::logic_error)
{
	auto it = dest_table.find(assembly);

	if (it == dest_table.cend()) throw std::logic_error(assembly + " No such command for destination");

	return it->second;
}

const std::string CInstructionTable::GetCompBinary(const std::string& assembly) const throw(std::logic_error)
{
	auto it = comp_table.find(assembly);

	if (it == comp_table.cend()) throw std::logic_error(assembly + " No such command for computation");

	return it->second;
}

const std::string CInstructionTable::GetJmpBinary(const std::string& assembly) const throw(std::logic_error)
{
	auto it = jmp_table.find(assembly);

	if (it == jmp_table.cend()) throw std::logic_error(assembly + " No such command for jump");

	return it->second;
}
