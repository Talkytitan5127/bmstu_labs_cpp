#pragma warning(disable:4996)
#include <exception>
#include <cstdio>
#include <iostream>
#include <string>

struct FileAlreadyOpened
	: public std::exception
{
	FileAlreadyOpened() = default;
	FileAlreadyOpened(const char* const message)
		: std::exception(message)
	{ }
};

class TNotCopyable
{
	class FileHandle
	{
	public:
		FILE * Des;
		FileHandle(FILE * fh)
			: Des(fh)
		{}

		~FileHandle()
		{
			fclose(Des);
		}
	};
	FileHandle Descriptor;
public:
	TNotCopyable()
		: Descriptor(nullptr)
	{ }

	TNotCopyable(const TNotCopyable&) = delete;
	TNotCopyable& operator = (const TNotCopyable&) = delete;

	void OpenToWrite(std::string const & fileName)
	{
		if (Descriptor.Des != nullptr)
			throw FileAlreadyOpened();
		Descriptor = fopen(fileName.c_str(), "w");
	}

	void OpenToRead(std::string const & fileName)
	{
		if (Descriptor.Des != nullptr)
			throw FileAlreadyOpened();
		Descriptor = fopen(fileName.c_str(), "r");
	}

	void Close() throw()
	{
		if (Descriptor.Des != nullptr)
		{
			Descriptor = nullptr;
		}
	}

	FILE * Get()
	{
		return Descriptor.Des;
	}
};

