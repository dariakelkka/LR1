#pragma once
#include "lib.h"
class Textbooks :
    public Bibliary
{
private:
    string name;
    string author;
    string yearin;
    string WhStudy;
    string Ystudy;
    string volume;
    string cost;

public:
    Textbooks();
    ~Textbooks();

    Textbooks(const Textbooks& Textbook_copy);
    Textbooks(string name);

    string get_name() const;
    void set_name(string name_ch);

    string get_author() const;
    void set_author(string author_ch);

    string get_yearin() const;
    void set_yearin(string yearin_ch);

    string get_WhStudy() const;
    void set_WhStudy(string WhStudy_ch);

    string get_Ystudy() const;
    void set_Ystudy(string Ystudy_ch);

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