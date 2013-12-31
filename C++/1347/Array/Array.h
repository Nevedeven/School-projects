#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h>

template <class X, int bot, int top>
	class Array
	{
		public:
			Array ();
			Array (const Array <X, bot, top> &); //note to self: Every class needs a default and copy constructor.
			~Array (); //I suppose a destructor is nice if you want to make sure, but i dunno if you always need one.
			X& get(int index); //This is the overloaded method for returning arrays within the array.
			X& get(int index) const;//X is a CLASS. no lowercase allowed. REMEMBER THIS.
			Array & copy (const Array <X, bot, top>&); // a copy method is always nice.
			size_t size () const;
			Array & operator = (const Array <X, bot, top>&); //when making a class, make a checklist of everything you need.
			X& operator [] (int); //it basically means surrounding yourself with tools.
		private:
			X Data[top-bot+1]; //I'm confused. When does the Array class reserve memory? These are blocks of memory of static size, and i don't see any indication that the compiler knows what top and bot are.
	}

#endif