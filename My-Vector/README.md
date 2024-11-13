# My Vector Class  
A **basic** vector class

This is my first vector class it is work in progress, this is some basic documentation.

Vector Class Documentation:

	General:
		This is a simple vector class focused on usability and ease of use.  
		This vector class allocates memory dynamically so the user doesn't have to worry about memory management.  
		An object is created like this:  
		vec <typename> objectName(optional size);  
		size by default is set to 20.
	Public Methods:
	T is a typename template that is specified when creating the vector
	constructors:
		default constructor (unsigned int size)
		the default constructor take one optional unsigned integer parameter which by default is set to 20
		this  parameter controls the starting size of the vector

		copy constructor which does just that and takes an object reference of vector

	destructor:
		performs basic memory clean-up 

	printVector() :
		prints the contents of the vector with a space in between elements and a newline after the contents is printed to the console

	append(toBeAdded) :
		checks if more space needs to be allocated then adds toBeAdded to the end of the vector

	operator (std::initializer_list) : 
		by using the brackets operator I have done something that some consider to be stupid
		it just appends a bunch of elements to the end of the vector
		example:
			vec <char> vec2;
			vec2({'A','B','C'});

	operator [unsigned int index] :
		will return the specified index as a reference

	at(unsigned int index) :
		will return the specified index

	Size() :
		will return the amount of elements in the vector as an unsigned int

	replace(unsigned int index,T whatToReplaceWith) :
		will replace what is at the index with whatToReplaceWith

	remove(unsigned int index) :
		will remove the desired index

	insert(T toInsert,unsigned int index)
		will insert toInsert after index

	pop(unsigned int amount) :
		amount is an optional  parameter which by default is set to 1
		pop will remove the desired amount of elements off the end of the vector

	sort () :
		will sort the vector in alphabetical order 
		will work with chars and ints but std::strings I am not sure about

	sort(unsiged int start, unsigned int end) :
		is just the same as sort but will only sort within the start and end boundries

	reverse() :
		will reverse the vector

	reverse(unsigned int start, unsigned int end) :
		will reverse the vector but will only reverse within the start and end boundries

	erase() :
		sets size to 0 effectively removing all elements in the vector

	count(T t) :
		will return an unsigned int
		will return the amount of that element in the vector  
		
	includes(T t) :
		will return bool
		if t is in the vector returns true
		else returns false  
		
	find(T t) :
		will return an unsigned int
		will return where an elements position in vector
		if element is not in vector will return 4294967295
