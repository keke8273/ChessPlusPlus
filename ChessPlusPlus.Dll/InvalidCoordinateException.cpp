#include "stdafx.h"
#include "InvalidCoordinateException.h"

InvalidCoordinateException::InvalidCoordinateException()
{
	m_message.append("Invalid coordinate!");
}

InvalidCoordinateException::InvalidCoordinateException(const std::string& invalidCoordinate_str)
{
	m_message.append(invalidCoordinate_str);
	m_message.append(" is not an valid coordinate!");
}

InvalidCoordinateException::~InvalidCoordinateException()
{
}

const char * InvalidCoordinateException::what() const
{
	return m_message.c_str();
}
