#ifndef ARRAY_HPP

# define ARRAY_HPP

template <typename T>
class Array
{
    public:
        Array ();
        Array ( unsigned int size );
		Array ( const Array& copy );
        virtual ~Array ();

		Array& operator=( const Array& other );

		T& operator[]( unsigned int index );
		const T& operator[]( unsigned int index ) const;
		unsigned int size() const;

    private:
		T* content;
		unsigned int _size;
		
};

# include <../src/Array.tpp>

#endif
