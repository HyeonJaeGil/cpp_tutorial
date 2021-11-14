#pragma once

class Investment 
{
public:
	virtual ~Investment();
};

class Stock : public Investment {};

class Bond : public Investment {};

class RealEstate : public Investment {};