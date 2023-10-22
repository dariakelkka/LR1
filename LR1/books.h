#pragma once
#include "lib.h"
class Books : public Bibliary
{
private:
	string name;
	string author;
	string yearin;
	string annotation;
	string genre;
	string volume;
	string cost;

public:
	Books();
	Books(string name);
	~Books();
	Books(const Books& Books_copy);

	string get_name() const;
	void set_name(string name_ch);

	string get_author() const;
	void set_author(string author_ch);

	string get_yearin() const;
	void set_yearin(string yearin_ch);

	string get_annotation() const;
	void set_annotation(string annotation_ch);

	string get_genre() const;
	void set_genre(string genre_ch);

	string get_volume() const;
	void set_volume(string volume_ch);

	string get_cost() const;
	void set_cost(string cost_ch);

	virtual void show();
	virtual void rewrite();
	virtual void saving();
	virtual void redact_str(int num_str, string red_str);
	virtual bool SameCost(string SC_ch);

};
