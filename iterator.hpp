#ifndef ITERATOR_HPP
 #define ITERATOR_HPP

# include <cstddef> // ptrdiff_t
# include <typeinfo>

namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag: public input_iterator_tag {};
	struct bidirectionnal_iterator_tag: public forward_iterator_tag {};
	struct random_access_iterator_tag: public bidirectionnal_iterator_tag {};
	template <typename Category, typename T, typename Distance, typename Pointer, typename Reference>
	struct iterator
		{
			typedef	T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
		};
	template<typename Iterator>
	struct iterator_traits
	{
		typedef	typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};
	
	template<typename T>
	struct iterator_traits<T*>
	{
		typedef	ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef random_access_iterator_tag		iterator_category;
	};
	
	template<typename T>
	struct iterator_traits<T *const>
	{
		typedef	ptrdiff_t						difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef random_access_iterator_tag		iterator_category;
	};
	template <typename InputIterator, typename Distance>
	void	advance(InputIterator & it, Distance n)
	{
		typename iterator_traits<InputIterator>::difference_type dist = n;

		if (typeid(typename iterator_traits<InputIterator>::iterator_category) == typeid(random_access_iterator_tag))
		{
			it = it + dist;
		}
		else if (typeid(typename iterator_traits<InputIterator>::iterator_category) == typeid(bidirectionnal_iterator_tag))
		{
			if (dist < 0)
			{
				while (dist++)
					it--;
			}
			else
			{
				while (dist--)
					it++;
			}
		}
		else
		{
			while (dist--)
				it++;
		}
	}
	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type	distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type diff = 0;

		while (first != last)
		{
			diff++;
			first++;
		}
		return (diff);
	}
	template<typename Iterator, typename Container>
	class normal_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
							typename iterator_traits<Iterator>::value_type,
							typename iterator_traits<Iterator>::difference_type,
							typename iterator_traits<Iterator>::pointer,
							typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator	m_current;
		
		public:
			typedef Iterator											iterator_type;
			typedef Container											container_type;
			typedef typename iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename iterator_traits<Iterator>::pointer			pointer;
			typedef typename iterator_traits<Iterator>::reference		reference;

			normal_iterator(void) {}
			explicit normal_iterator(const Iterator & it) : m_current(it) {}
			template<typename It>
			normal_iterator(const normal_iterator<It, Container> & src): m_current(src.base()) {}
			~normal_iterator() {}

			Iterator	base(void) const
			{
				return (m_current);
			}
			reference	operator*(void) const
			{
				return (*m_current);
			}
			normal_iterator	operator+(difference_type n) const
			{
				return (normal_iterator(m_current + n));
			}
			normal_iterator &	operator++(void)
			{
				m_current++;
				return (*this);
			}
			normal_iterator operator++(int)
			{
				normal_iterator temp(*this);

				m_current++;
				return (temp);
			}
			normal_iterator &	operator+=(difference_type n)
			{
				m_current += n;
				return (*this);
			}
			normal_iterator	operator-(difference_type n) const
			{
				return (normal_iterator(m_current - n));
			}
			normal_iterator &	operator--(void)
			{
				m_current--;
				return (*this);
			}
			normal_iterator operator--(int)
			{
				normal_iterator temp(*this);

				m_current--;
				return (temp);
			}
			normal_iterator &	operator-=(difference_type n)
			{
				m_current -= n;
				return (*this);
			}
			pointer	operator->(void) const
			{
				return (&(operator*()));
			}
			reference	operator[](difference_type n) const
			{
				return (m_current[n]);
			}
	};
	template <typename IteratorL, typename IteratorR, typename Container>
	bool	operator==(const normal_iterator<IteratorL, Container> & lhs, const normal_iterator<IteratorR, Container> & rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <typename IteratorL, typename IteratorR, typename Container>
	bool	operator!=(const normal_iterator<IteratorL, Container> & lhs, const normal_iterator<IteratorR, Container> & rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <typename IteratorL, typename IteratorR, typename Container>
	bool	operator<(const normal_iterator<IteratorL, Container> & lhs, const normal_iterator<IteratorR, Container> & rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <typename IteratorL, typename IteratorR, typename Container>
	bool	operator<=(const normal_iterator<IteratorL, Container> & lhs, const normal_iterator<IteratorR, Container> & rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <typename IteratorL, typename IteratorR, typename Container>
	bool	operator>(const normal_iterator<IteratorL, Container> & lhs, const normal_iterator<IteratorR, Container> & rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <typename IteratorL, typename IteratorR, typename Container>
	bool	operator>=(const normal_iterator<IteratorL, Container> & lhs, const normal_iterator<IteratorR, Container> & rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <typename IteratorL, typename IteratorR, typename Container>
		typename normal_iterator<IteratorL, Container>::difference_type
			operator-(const normal_iterator<IteratorL, Container> & lhs, const normal_iterator<IteratorR, Container> & rhs)
	{
		return (lhs.base() - rhs.base());
	}
	template <typename Iterator, typename Container>
		normal_iterator<Iterator, Container>
			operator+(typename normal_iterator<Iterator, Container>::difference_type n, const normal_iterator<Iterator, Container> & it)
	{
		return (normal_iterator<Iterator, Container>(it.base() + n));
	}
	template<typename Iterator>
	class reverse_iterator
		: public iterator<typename iterator_traits<Iterator>::iterator_category,
							typename iterator_traits<Iterator>::value_type,
							typename iterator_traits<Iterator>::difference_type,
							typename iterator_traits<Iterator>::pointer,
							typename iterator_traits<Iterator>::reference>
	{
		protected:
			Iterator	m_current;
		
		public:
			typedef Iterator											iterator_type;
			typedef typename iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename iterator_traits<Iterator>::pointer			pointer;
			typedef typename iterator_traits<Iterator>::reference		reference;

			reverse_iterator(void) {}
			explicit reverse_iterator(const Iterator & it) : m_current(it) {}
			template<typename It>
			reverse_iterator(const reverse_iterator<It> & src): m_current(src.base()) {}
			~reverse_iterator() {}

			Iterator	base(void) const
			{
				return (m_current);
			}
			reference	operator*(void) const
			{
				Iterator	it = m_current;

				return (*(--it));
			}
			reverse_iterator	operator+(difference_type n) const
			{
				return (reverse_iterator(m_current - n));
			}
			reverse_iterator &	operator++(void)
			{
				m_current--;
				return (*this);
			}
			reverse_iterator operator++(int)
			{
				reverse_iterator temp(*this);

				m_current--;
				return (temp);
			}
			reverse_iterator &	operator+=(difference_type n)
			{
				m_current -= n;
				return (*this);
			}
			reverse_iterator	operator-(difference_type n) const
			{
				return (reverse_iterator(m_current + n));
			}
			reverse_iterator &	operator--(void)
			{
				m_current++;
				return (*this);
			}
			reverse_iterator operator--(int)
			{
				reverse_iterator temp(*this);

				m_current++;
				return (temp);
			}
			reverse_iterator &	operator-=(difference_type n)
			{
				m_current += n;
				return (*this);
			}
			pointer	operator->(void) const
			{
				return (&(operator*()));
			}
			reference	operator[](difference_type n) const
			{
				return (m_current[-n - 1]);
			}
	};
	template <typename IteratorL, typename IteratorR>
	bool	operator==(const reverse_iterator<IteratorL> & lhs, const reverse_iterator<IteratorR> & rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <typename IteratorL, typename IteratorR>
	bool	operator!=(const reverse_iterator<IteratorL> & lhs, const reverse_iterator<IteratorR> & rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <typename IteratorL, typename IteratorR>
	bool	operator<(const reverse_iterator<IteratorL> & lhs, const reverse_iterator<IteratorR> & rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <typename IteratorL, typename IteratorR>
	bool	operator<=(const reverse_iterator<IteratorL> & lhs, const reverse_iterator<IteratorR> & rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <typename IteratorL, typename IteratorR>
	bool	operator>(const reverse_iterator<IteratorL> & lhs, const reverse_iterator<IteratorR> & rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <typename IteratorL, typename IteratorR>
	bool	operator>=(const reverse_iterator<IteratorL> & lhs, const reverse_iterator<IteratorR> & rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <typename IteratorL, typename IteratorR>
		typename reverse_iterator<IteratorL>::difference_type
			operator-(const reverse_iterator<IteratorL> & lhs, const reverse_iterator<IteratorR> & rhs)
	{
		return (rhs.base() - lhs.base());
	}
	template <typename Iterator>
		reverse_iterator<Iterator>
			operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> & it)
	{
		return (reverse_iterator<Iterator>(it.base() - n));
	}
}

#endif