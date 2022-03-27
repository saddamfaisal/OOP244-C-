
//Name:           SADDAM FAISAL
// Student Number: 118406198
// Email:          sfaisal6@myseneca.ca
// Date:           7/6/2020
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Engine.h"

using namespace std;

namespace sdds
{

Engine::Engine()
{
	m_type[0] = '\0';
	m_size = 0.0;
}


Engine::Engine(const char* type, double size)
{
  strcpy(m_type, type);
  m_size = size;
}


double Engine::get() const
{
  return m_size;
}

void Engine::set_engine(Engine &e)
{
  strcpy(m_type, (e.get_type()));
  m_size = e.get();
}

void Engine::set(double size, const char* type)
{
  m_size = size;
  strcpy(m_type, type);

  return;
}

void Engine::display() const
{

  cout << m_size << " liters - " << m_type << endl;
}

}
