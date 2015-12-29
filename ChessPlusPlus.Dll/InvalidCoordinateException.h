#pragma once
#include <exception>
#include <string>

class CHESSPLUSPLUSDLL_API InvalidCoordinateException :
	public std::exception
{
public:
	InvalidCoordinateException();
	InvalidCoordinateException(const std::string&);
	~InvalidCoordinateException();

	virtual const char * what() const;

private:
	std::string m_message;
};

