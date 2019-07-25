#pragma once

#include <unordered_map>
#include <string>
#include <stdexcept>

class CInstructionTable
{
public:

	static CInstructionTable& Get()
	{
		static CInstructionTable inst;
		return inst;
	}

	const std::string GetDestBinary(const std::string& assembly) const throw(std::logic_error);
	const std::string GetCompBinary(const std::string& assembly) const throw(std::logic_error);
	const std::string GetJmpBinary(const std::string& assembly) const throw(std::logic_error);
	
	
	CInstructionTable(const CInstructionTable&) = delete;
	CInstructionTable& operator=(CInstructionTable&) = delete;
	CInstructionTable(CInstructionTable&&) = delete;
	CInstructionTable& operator=(CInstructionTable&&) = delete;

private:

	CInstructionTable();

	void construct_table(std::istream& in_stream, std::unordered_map<std::string, std::string>& table);

	std::unordered_map<std::string, std::string> dest_table;
	std::unordered_map<std::string, std::string> comp_table;
	std::unordered_map<std::string, std::string> jmp_table;

};