#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>

#include "Logger.hpp"

Logger::Logger(std::string filename)
{
	this->file.open(filename, std::ios::app);
	if (!this->file.is_open())
		std::cerr << "Error opening the file" << std::endl; 
}

Logger::~Logger()
{
	if (this->file.is_open())
		this->file.close();
}

void	Logger::logToConsole(std::string const &message)
{
	std::cerr << this->makeLogEntry(message) << std::endl;
}

void	Logger::logToFile(std::string const &message)
{
	this->file << this->makeLogEntry(message) << std::endl;
}

std::string	Logger::makeLogEntry(std::string const &message)
{
	auto	chrono_now = std::chrono::system_clock::now();
	std::time_t date = std::chrono::system_clock::to_time_t(chrono_now);
	std::string	logEntry =  std::ctime(&date);
	logEntry.pop_back();
	logEntry.append(" - ");
	logEntry.append(message);
	return (logEntry);
}

void	Logger::log(std::string const &dest, std::string const &message)
{
	std::string	dest_array[] = { "console", "file"};
	void	(Logger::*dest_fptr[])(std::string const&) =
	{
		&Logger::logToConsole,
		&Logger::logToFile
	};
	for (size_t i = 0; i < (sizeof(dest_fptr) / sizeof(dest_fptr[0])); ++i)
		if (dest == dest_array[i])
			(this->*dest_fptr[i])(message);
}
