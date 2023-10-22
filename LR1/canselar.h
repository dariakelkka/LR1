#pragma once
#include "lib.h"
class Canselars : public Bibliary
{
private:
	string type;
	string color;
	string purpose;
	string cost;

public:
	Canselars();
	~Canselars();
	Canselars(const Canselars& Canselars_copy);
	Canselars(string name);

	string get_type() const;
	void set_type(string type_ch);
	string get_color() const;
	void set_color(string color_ch);
	string get_purpose() const;
	void set_purpose(string purpose_ch);
	string get_cost() const;
	void set_cost(string cost_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool SameCost(string SC_ch);
};