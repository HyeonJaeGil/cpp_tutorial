#pragma once

class MyArray {
private:
	int m_data[5];

public:
	
	MyArray() {};

	MyArray(int input[]) {
		"initialize with input";
	}

	int& operator [] (const int& index) 
	{
		if (index < 0 || index > 4) throw - 1;		
		return m_data[index];
	}

};