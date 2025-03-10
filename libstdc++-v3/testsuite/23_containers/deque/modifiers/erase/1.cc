// 2005-11-25  Paolo Carlini  <pcarlini@suse.de>

// Copyright (C) 2005-2025 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 23.2.1.3 deque modifiers

#include <deque>
#include <testsuite_hooks.h>

const int  A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const int A1[] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const int A2[] = {0, 2, 3, 4, 10, 11, 12, 13, 14, 15};
const int A3[] = {0, 2, 3, 4, 10, 11};
const int A4[] = {4, 10, 11};
const int A5[] = {4, 10};
const unsigned  N = sizeof(A)  / sizeof(int);
const unsigned N1 = sizeof(A1) / sizeof(int);
const unsigned N2 = sizeof(A2) / sizeof(int);
const unsigned N3 = sizeof(A3) / sizeof(int);
const unsigned N4 = sizeof(A4) / sizeof(int);
const unsigned N5 = sizeof(A5) / sizeof(int);

void
test01()
{
  typedef std::deque<int>                deque_type;
  typedef deque_type::iterator        iterator_type;

  deque_type v(A, A + N);

  iterator_type it1 = v.erase(v.begin() + 1);
  VERIFY( it1 == v.begin() + 1 );
  VERIFY( v.size() == N1 );
  VERIFY( std::equal(v.begin(), v.end(), A1) );
  
  iterator_type it2 = v.erase(v.begin() + 4, v.begin() + 9);
  VERIFY( it2 == v.begin() + 4 );
  VERIFY( v.size() == N2 );
  VERIFY( std::equal(v.begin(), v.end(), A2) );
  
  iterator_type it3 = v.erase(v.begin() + 6, v.end());
  VERIFY( it3 == v.begin() + 6 );
  VERIFY( v.size() == N3 );
  VERIFY( std::equal(v.begin(), v.end(), A3) );

  iterator_type it4 = v.erase(v.begin(), v.begin() + 3);
  VERIFY( it4 == v.begin() );
  VERIFY( v.size() == N4 );
  VERIFY( std::equal(v.begin(), v.end(), A4) );

  iterator_type it5 = v.erase(v.begin() + 2);
  VERIFY( it5 == v.begin() + 2 );
  VERIFY( v.size() == N5 );
  VERIFY( std::equal(v.begin(), v.end(), A5) );

  iterator_type it6 = v.erase(v.begin(), v.end());
  VERIFY( it6 == v.begin() );
  VERIFY( v.empty() );
}

void
test02()
{
  typedef std::deque<std::deque<int> >   deque_type;
  typedef deque_type::iterator        iterator_type;

  deque_type v, v1, v2, v3, v4, v5;
  for (unsigned i = 0; i < N; ++i)
    v.push_back(std::deque<int>(1, A[i]));
  for (unsigned i = 0; i < N1; ++i)
    v1.push_back(std::deque<int>(1, A1[i]));
  for (unsigned i = 0; i < N2; ++i)
    v2.push_back(std::deque<int>(1, A2[i]));
  for (unsigned i = 0; i < N3; ++i)
    v3.push_back(std::deque<int>(1, A3[i]));
  for (unsigned i = 0; i < N4; ++i)
    v4.push_back(std::deque<int>(1, A4[i]));
  for (unsigned i = 0; i < N5; ++i)
    v5.push_back(std::deque<int>(1, A5[i]));
  
  iterator_type it1 = v.erase(v.begin() + 1);
  VERIFY( it1 == v.begin() + 1 );
  VERIFY( v.size() == N1 );
  VERIFY( std::equal(v.begin(), v.end(), v1.begin()) );
  
  iterator_type it2 = v.erase(v.begin() + 4, v.begin() + 9);
  VERIFY( it2 == v.begin() + 4 );
  VERIFY( v.size() == N2 );
  VERIFY( std::equal(v.begin(), v.end(), v2.begin()) );
  
  iterator_type it3 = v.erase(v.begin() + 6, v.end());
  VERIFY( it3 == v.begin() + 6 );
  VERIFY( v.size() == N3 );
  VERIFY( std::equal(v.begin(), v.end(), v3.begin()) );

  iterator_type it4 = v.erase(v.begin(), v.begin() + 3);
  VERIFY( it4 == v.begin() );
  VERIFY( v.size() == N4 );
  VERIFY( std::equal(v.begin(), v.end(), v4.begin()) );

  iterator_type it5 = v.erase(v.begin() + 2);
  VERIFY( it5 == v.begin() + 2 );
  VERIFY( v.size() == N5 );
  VERIFY( std::equal(v.begin(), v.end(), v5.begin()) );

  iterator_type it6 = v.erase(v.begin(), v.end());
  VERIFY( it6 == v.begin() );
  VERIFY( v.empty() );
}

int main()
{
  test01();
  test02();
  return 0;
}
