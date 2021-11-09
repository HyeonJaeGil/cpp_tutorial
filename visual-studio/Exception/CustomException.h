#pragma once
#include <exception>

class CustomException : public std::exception
{
public:
	const char* what() const noexcept override 
	{
		return "Custom Exception";
	}
};

class ChildCustomException : public CustomException 
{
public:
	const char* what() const noexcept override 
	{
		return "Child Custom Exception";
	}
};