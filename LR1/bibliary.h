#pragma once
#include "lib.h"

using namespace std;
class Bibliary
{
public:
	Bibliary() {};
	virtual ~Bibliary() {};
	virtual void show() = 0;
	virtual void rewrite() = 0;
	virtual void saving() = 0;
	virtual void redact_str(int num_str, string red_str) = 0;
	virtual bool SameCost(string SC_ch) = 0;
};

typedef struct Elem
{
	Bibliary* m_data;
	Elem* next;
} Elem; 
